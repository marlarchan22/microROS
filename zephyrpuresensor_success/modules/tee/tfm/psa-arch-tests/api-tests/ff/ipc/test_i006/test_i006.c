/** @file
 * Copyright (c) 2018-2019, Arm Limited or its affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/

#ifdef NONSECURE_TEST_BUILD
#include "val_interfaces.h"
#include "val_target.h"
#else
#include "val_client_defs.h"
#include "val_service_defs.h"
#endif

#include "test_i006.h"

client_test_t test_i006_client_tests_list[] = {
    NULL,
    client_test_strict_policy_lower_version,
    NULL,
};

int32_t client_test_strict_policy_lower_version(caller_security_t caller)
{
   psa_handle_t       handle = 0;
   boot_state_t       boot_state;

   val->print(PRINT_TEST, "[Check 1] Test STRICT policy with lower version\n", 0);

   /*
    * This test checks for the PROGRAMMER ERROR condition for the PSA API. API's respond to
    * PROGRAMMER ERROR could be either to return appropriate status code or panic the caller.
    * When a Secure Partition panics, the SPE cannot continue normal execution, as defined
    * in this specification. The behavior of the SPM following a Secure Partition panic is
    * IMPLEMENTATION DEFINED- Arm recommends that the SPM causes the system to restart in
    * this situation. Refer PSA-FF for more information on panic.
    * For the cases where, SPM cannot capable to reboot the system (just hangs or power down),
    * a watchdog timer set by val_test_init can reboot the system on timeout event. This will
    * tests continuity and able to jump to next tests. Therefore, each test who checks for
    * PROGRAMMER ERROR condition, expects system to get reset either by SPM or watchdog set by
    * the test harness function.
    *
    * If programmed timeout value isn't sufficient for your system, it can be reconfigured using
    * timeout entries available in target.cfg.
    *
    * To decide, a reboot happened as intended by test scenario or it happended
    * due to other reasons, test is setting a boot signature into non-volatile memory before and
    * after targeted test check. After a reboot, these boot signatures are being read by the
    * VAL APIs to decide test status.
    */

   /* Setting boot.state before test check */
   boot_state = (caller == CALLER_NONSECURE) ? BOOT_EXPECTED_NS : BOOT_EXPECTED_S;
   if (val->set_boot_flag(boot_state))
   {
       val->print(PRINT_ERROR, "\tFailed to set boot flag before check\n", 0);
       return VAL_STATUS_ERROR;
   }

   /* Version policy is strict and requested version is smaller than the minimum version */
   handle = psa->connect(SERVER_STRICT_VERSION_SID, SERVER_STRICT_VERSION_VERSION - 1);

   /*
    * If the caller is in the NSPE, it is IMPLEMENTATION DEFINED whether
    * a PROGRAMMER ERROR will panic or return PSA_ERROR_CONNECTION_REFUSED.
    * For SPE caller, it must panic.
    */
   if (caller == CALLER_NONSECURE && handle == PSA_ERROR_CONNECTION_REFUSED)
   {
       return VAL_STATUS_SUCCESS;
   }

   /* If PROGRAMMER ERROR results into panic then control shouldn't have reached here */
   val->print(PRINT_ERROR,
           "\tSTRICT policy with lower version should have failed but succeeded\n", 0);

   /* Resetting boot.state to catch unwanted reboot */
   if (val->set_boot_flag(BOOT_EXPECTED_BUT_FAILED))
   {
       val->print(PRINT_ERROR, "\tFailed to set boot flag after check\n", 0);
       return VAL_STATUS_ERROR;
   }

   return VAL_STATUS_SPM_FAILED;
}
