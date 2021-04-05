/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef H_SHELL_MGMT_CONFIG_
#define H_SHELL_MGMT_CONFIG_

#if defined MYNEWT

#include "syscfg/syscfg.h"

#define SHELL_MGMT_MAX_LINE_LEN     MYNEWT_VAL(SHELL_BRIDGE_MAX_IN_LEN)
#define SHELL_MGMT_MAX_ARGC         MYNEWT_VAL(SHELL_CMD_ARGC_MAX)

#elif defined __ZEPHYR__

#define SHELL_MGMT_MAX_LINE_LEN     CONFIG_SHELL_CMD_BUFF_SIZE
#define SHELL_MGMT_MAX_ARGC         CONFIG_SHELL_ARGC_MAX

#else

/* No direct support for this OS.  The application needs to define the above
 * settings itself.
 */

#endif

#endif
