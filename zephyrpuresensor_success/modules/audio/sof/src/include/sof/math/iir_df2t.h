/* SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright(c) 2017 Intel Corporation. All rights reserved.
 *
 * Author: Seppo Ingalsuo <seppo.ingalsuo@linux.intel.com>
 *         Liam Girdwood <liam.r.girdwood@linux.intel.com>
 *         Keyon Jie <yang.jie@linux.intel.com>
 */

#ifndef __SOF_MATH_IIR_DF2T_H__
#define __SOF_MATH_IIR_DF2T_H__

#include <stddef.h>
#include <stdint.h>

/* Get platforms configuration */

/* If next defines are set to 1 the EQ is configured automatically. Setting
 * to zero temporarily is useful is for testing needs.
 * Setting EQ_FIR_AUTOARCH to 0 allows to manually set the code variant.
 */
#define IIR_AUTOARCH    1

/* Force manually some code variant when IIR_AUTOARCH is set to zero. These
 * are useful in code debugging.
 */
#if IIR_AUTOARCH == 0
#define IIR_GENERIC	1
#define IIR_HIFI3	0
#endif

/* Select optimized code variant when xt-xcc compiler is used */
#if IIR_AUTOARCH == 1
#if defined __XCC__
#include <xtensa/config/core-isa.h>
#if XCHAL_HAVE_HIFI3 == 1
#define IIR_GENERIC	0
#define IIR_HIFI3	1
#else
#define IIR_GENERIC	1
#define IIR_HIFI3	0
#endif /* XCHAL_HAVE_HIFI3 */
#else
/* GCC */
#define IIR_GENERIC	1
#define IIR_HIFI3	0
#endif /* __XCC__ */
#endif /* IIR_AUTOARCH */

#define IIR_DF2T_NUM_DELAYS 2

struct iir_state_df2t {
	unsigned int biquads; /* Number of IIR 2nd order sections total */
	unsigned int biquads_in_series; /* Number of IIR 2nd order sections
					 * in series.
					 */
	int32_t *coef; /* Pointer to IIR coefficients */
	int64_t *delay; /* Pointer to IIR delay line */
};

int32_t iir_df2t(struct iir_state_df2t *iir, int32_t x);

#endif /* __SOF_MATH_IIR_DF2T_H__ */
