// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2020 Intel Corporation. All rights reserved.
//
// Author: Seppo Ingalsuo <seppo.ingalsuo@linux.intel.com>

#include <sof/common.h>
#include <user/tdfb.h>
#include <sof/audio/audio_stream.h>
#include <sof/audio/tdfb/tdfb_comp.h>
#include <user/fir.h>
#include <user/tdfb.h>

#if TDFB_HIFIEP

#include <sof/math/fir_hifi2ep.h>

#if CONFIG_FORMAT_S16LE
void tdfb_fir_s16(struct tdfb_comp_data *cd,
		  const struct audio_stream *source,
		  struct audio_stream *sink, int frames)
{
	struct sof_tdfb_config *cfg = cd->config;
	struct fir_state_32x16 *f;
	int32_t y0;
	int32_t y1;
	int16_t *x;
	int16_t *y;
	int rshift;
	int lshift;
	int is2;
	int is;
	int om;
	int i;
	int j;
	int k;
	int in_nch = source->channels;
	int out_nch = sink->channels;
	int idx_in = 0;
	int idx_out = 0;

	for (j = 0; j < (frames >> 1); j++) {
		/* Clear output mix*/
		memset(cd->out, 0,  2 * out_nch * sizeof(int32_t));

		/* Read two frames from all input channels */
		for (i = 0; i < 2 * in_nch; i++) {
			x = audio_stream_read_frag_s16(source, idx_in++);
			cd->in[i] = *x << 16;
		}

		/* Run and mix all filters to their output channel */
		for (i = 0; i < cfg->num_filters; i++) {
			is = cd->input_channel_select[i];
			is2 = is + in_nch;
			om = cd->output_channel_mix[i];
			/* Prepare FIR */
			f = &cd->fir[i];
			fir_hifiep_setup_circular(f);
			fir_get_lrshifts(f, &lshift, &rshift);
			/* Process two samples */
			fir_32x16_2x_hifiep(f, cd->in[is], cd->in[is2],
					    &y0, &y1, lshift, rshift);
			/* Mix as Q5.27 */
			for (k = 0; k < out_nch; k++) {
				if (om & 1) {
					cd->out[k] += y0 >> 4;
					cd->out[k + out_nch] += y1 >> 4;
				}
				om = om >> 1;
			}
		}

		/* Write two frames of output */
		for (i = 0; i < 2 * out_nch; i++) {
			y = audio_stream_write_frag_s16(sink, idx_out++);
			*y = sat_int16(Q_SHIFT_RND(cd->out[i], 27, 15));
		}
	}
}
#endif

#if CONFIG_FORMAT_S24LE
void tdfb_fir_s24(struct tdfb_comp_data *cd,
		  const struct audio_stream *source,
		  struct audio_stream *sink, int frames)
{
	struct sof_tdfb_config *cfg = cd->config;
	struct fir_state_32x16 *f;
	int32_t y0;
	int32_t y1;
	int32_t *x;
	int32_t *y;
	int rshift;
	int lshift;
	int is2;
	int is;
	int om;
	int i;
	int j;
	int k;
	int in_nch = source->channels;
	int out_nch = sink->channels;
	int idx_in = 0;
	int idx_out = 0;

	for (j = 0; j < (frames >> 1); j++) {
		/* Clear output mix*/
		memset(cd->out, 0,  2 * out_nch * sizeof(int32_t));

		/* Read two frames from all input channels */
		for (i = 0; i < 2 * in_nch; i++) {
			x = audio_stream_read_frag_s32(source, idx_in++);
			cd->in[i] = *x << 8;
		}

		/* Run and mix all filters to their output channel */
		for (i = 0; i < cfg->num_filters; i++) {
			is = cd->input_channel_select[i];
			is2 = is + in_nch;
			om = cd->output_channel_mix[i];
			/* Prepare FIR */
			f = &cd->fir[i];
			fir_hifiep_setup_circular(f);
			fir_get_lrshifts(f, &lshift, &rshift);
			/* Process two samples */
			fir_32x16_2x_hifiep(f, cd->in[is], cd->in[is2],
					    &y0, &y1, lshift, rshift);
			/* Mix as Q5.27 */
			for (k = 0; k < out_nch; k++) {
				if (om & 1) {
					cd->out[k] += y0 >> 4;
					cd->out[k + out_nch] += y1 >> 4;
				}
				om = om >> 1;
			}
		}

		/* Write two frames of output */
		for (i = 0; i < 2 * out_nch; i++) {
			y = audio_stream_write_frag_s32(sink, idx_out++);
			*y = sat_int24(Q_SHIFT_RND(cd->out[i], 27, 23));
		}
	}
}
#endif

#if CONFIG_FORMAT_S32LE
void tdfb_fir_s32(struct tdfb_comp_data *cd,
		  const struct audio_stream *source,
		  struct audio_stream *sink, int frames)
{
	struct sof_tdfb_config *cfg = cd->config;
	struct fir_state_32x16 *f;
	int32_t y0;
	int32_t y1;
	int32_t *x;
	int32_t *y;
	int lshift;
	int rshift;
	int is2;
	int is;
	int om;
	int i;
	int j;
	int k;
	int in_nch = source->channels;
	int out_nch = sink->channels;
	int idx_in = 0;
	int idx_out = 0;

	for (j = 0; j < (frames >> 1); j++) {
		/* Clear output mix*/
		memset(cd->out, 0,  2 * out_nch * sizeof(int32_t));

		/* Read two frames from all input channels */
		for (i = 0; i < 2 * in_nch; i++) {
			x = audio_stream_read_frag_s32(source, idx_in++);
			cd->in[i] = *x;
		}

		/* Run and mix all filters to their output channel */
		for (i = 0; i < cfg->num_filters; i++) {
			is = cd->input_channel_select[i];
			is2 = is + in_nch;
			om = cd->output_channel_mix[i];
			/* Prepare FIR */
			f = &cd->fir[i];
			fir_hifiep_setup_circular(f);
			fir_get_lrshifts(f, &lshift, &rshift);
			/* Process two samples */
			fir_32x16_2x_hifiep(f, cd->in[is], cd->in[is2],
					    &y0, &y1, lshift, rshift);
			/* Mix as Q5.27 */
			for (k = 0; k < out_nch; k++) {
				if (om & 1) {
					cd->out[k] += y0 >> 4;
					cd->out[k + out_nch] += y1 >> 4;
				}
				om = om >> 1;
			}
		}

		/* Write two frames of output. In Q5.27 to Q1.31 conversion
		 * rounding is not applicable so just shift left by 4.
		 */
		for (i = 0; i < 2 * out_nch; i++) {
			y = audio_stream_write_frag_s32(sink, idx_out++);
			*y = sat_int32((int64_t)cd->out[i] << 4);
		}
	}
}
#endif

#endif /* TDFB_HIFIEP */

