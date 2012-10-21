/*
** Copyright (C) 1999-2004 Erik de Castro Lopo <erikd@mega-nerd.com>
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation; either version 2.1 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	<time.h>

#include	"sndfile.h"
#include	"config.h"
#include	"sfendian.h"
#include	"common.h"
#include	"wav_w64.h"

/*------------------------------------------------------------------------------
 * Private static functions.
 */

int
wav_w64_read_fmt_chunk (SF_PRIVATE *psf, WAV_FMT *wav_fmt, int structsize)
{	int	bytesread, k, bytespersec = 0 ;

	memset (wav_fmt, 0, sizeof (WAV_FMT)) ;

	if (structsize < 16)
		return SFE_WAV_FMT_SHORT ;
	if (structsize > SIGNED_SIZEOF (WAV_FMT))
		return SFE_WAV_FMT_TOO_BIG ;

	/* Read the minimal WAV file header here. */
	bytesread =
	psf_binheader_readf (psf, "e224422", &(wav_fmt->format), &(wav_fmt->min.channels),
			&(wav_fmt->min.samplerate), &(wav_fmt->min.bytespersec),
			&(wav_fmt->min.blockalign), &(wav_fmt->min.bitwidth)) ;

	psf_log_printf (psf, "  Format        : 0x%X => %s\n", wav_fmt->format, wav_w64_format_str (wav_fmt->format)) ;
	psf_log_printf (psf, "  Channels      : %d\n", wav_fmt->min.channels) ;
	psf_log_printf (psf, "  Sample Rate   : %d\n", wav_fmt->min.samplerate) ;
	psf_log_printf (psf, "  Block Align   : %d\n", wav_fmt->min.blockalign) ;

	if (wav_fmt->format == WAVE_FORMAT_PCM && wav_fmt->min.bitwidth == 24 &&
			wav_fmt->min.blockalign == 4 * wav_fmt->min.channels)
	{
		psf_log_printf (psf, "\nInvalid file generated by Syntrillium's Cooledit!\n"
				"Treating as WAVE_FORMAT_IEEE_FLOAT 32 bit floating point file.\n\n") ;
		psf_log_printf (psf, "  Bit Width     : 24 (should be 32)\n") ;
		wav_fmt->min.bitwidth = 32 ;
		wav_fmt->format = WAVE_FORMAT_IEEE_FLOAT ;
		}
	else if (wav_fmt->format == WAVE_FORMAT_GSM610 && wav_fmt->min.bitwidth != 0)
		psf_log_printf (psf, "  Bit Width     : %d (should be 0)\n", wav_fmt->min.bitwidth) ;
	else
		psf_log_printf (psf, "  Bit Width     : %d\n", wav_fmt->min.bitwidth) ;


	psf->sf.samplerate	= wav_fmt->min.samplerate ;
	psf->sf.frames 		= 0 ;					/* Correct this when reading data chunk. */
	psf->sf.channels	= wav_fmt->min.channels ;

	switch (wav_fmt->format)
	{	case WAVE_FORMAT_PCM :
		case WAVE_FORMAT_IEEE_FLOAT :
				bytespersec = wav_fmt->min.samplerate * wav_fmt->min.blockalign ;
				if (wav_fmt->min.bytespersec != (unsigned) bytespersec)
					psf_log_printf (psf, "  Bytes/sec     : %d (should be %d)\n", wav_fmt->min.bytespersec, bytespersec) ;
				else
					psf_log_printf (psf, "  Bytes/sec     : %d\n", wav_fmt->min.bytespersec) ;

				psf->bytewidth = BITWIDTH2BYTES (wav_fmt->min.bitwidth) ;
				break ;

		case WAVE_FORMAT_ALAW :
		case WAVE_FORMAT_MULAW :
				if (wav_fmt->min.bytespersec / wav_fmt->min.blockalign != wav_fmt->min.samplerate)
					psf_log_printf (psf, "  Bytes/sec     : %d (should be %d)\n", wav_fmt->min.bytespersec, wav_fmt->min.samplerate * wav_fmt->min.blockalign) ;
				else
					psf_log_printf (psf, "  Bytes/sec     : %d\n", wav_fmt->min.bytespersec) ;

				psf->bytewidth = 1 ;
				if (structsize >= 18)
				{	bytesread += psf_binheader_readf (psf, "e2", &(wav_fmt->size20.extrabytes)) ;
					psf_log_printf (psf, "  Extra Bytes   : %d\n", wav_fmt->size20.extrabytes) ;
					} ;
				break ;

		case WAVE_FORMAT_IMA_ADPCM :
				if (wav_fmt->min.bitwidth != 4)
					return SFE_WAV_ADPCM_NOT4BIT ;
				if (wav_fmt->min.channels < 1 || wav_fmt->min.channels > 2)
					return SFE_WAV_ADPCM_CHANNELS ;

				bytesread +=
				psf_binheader_readf (psf, "e22", &(wav_fmt->ima.extrabytes), &(wav_fmt->ima.samplesperblock)) ;

				bytespersec = (wav_fmt->ima.samplerate * wav_fmt->ima.blockalign) / wav_fmt->ima.samplesperblock ;
				if (wav_fmt->ima.bytespersec != (unsigned) bytespersec)
					psf_log_printf (psf, "  Bytes/sec     : %d (should be %d)\n", wav_fmt->ima.bytespersec, bytespersec) ;
				else
					psf_log_printf (psf, "  Bytes/sec     : %d\n", wav_fmt->ima.bytespersec) ;

				psf->bytewidth = 2 ;
				psf_log_printf (psf, "  Extra Bytes   : %d\n", wav_fmt->ima.extrabytes) ;
				psf_log_printf (psf, "  Samples/Block : %d\n", wav_fmt->ima.samplesperblock) ;
				break ;

		case WAVE_FORMAT_MS_ADPCM :
				if (wav_fmt->msadpcm.bitwidth != 4)
					return SFE_WAV_ADPCM_NOT4BIT ;
				if (wav_fmt->msadpcm.channels < 1 || wav_fmt->msadpcm.channels > 2)
					return SFE_WAV_ADPCM_CHANNELS ;

				bytesread +=
				psf_binheader_readf (psf, "e222", &(wav_fmt->msadpcm.extrabytes),
						&(wav_fmt->msadpcm.samplesperblock), &(wav_fmt->msadpcm.numcoeffs)) ;

				bytespersec = (wav_fmt->min.samplerate * wav_fmt->min.blockalign) / wav_fmt->msadpcm.samplesperblock ;
				if (wav_fmt->min.bytespersec == (unsigned) bytespersec)
					psf_log_printf (psf, "  Bytes/sec     : %d\n", wav_fmt->min.bytespersec) ;
				else if (wav_fmt->min.bytespersec == (wav_fmt->min.samplerate / wav_fmt->msadpcm.samplesperblock) * wav_fmt->min.blockalign)
					psf_log_printf (psf, "  Bytes/sec     : %d (should be %d (MS BUG!))\n", wav_fmt->min.bytespersec, bytespersec) ;
				else
					psf_log_printf (psf, "  Bytes/sec     : %d (should be %d)\n", wav_fmt->min.bytespersec, bytespersec) ;


				psf->bytewidth = 2 ;
				psf_log_printf (psf, "  Extra Bytes   : %d\n", wav_fmt->msadpcm.extrabytes) ;
				psf_log_printf (psf, "  Samples/Block : %d\n", wav_fmt->msadpcm.samplesperblock) ;
				if (wav_fmt->msadpcm.numcoeffs > SIGNED_SIZEOF (MS_ADPCM_WAV_FMT) / SIGNED_SIZEOF (int))
				{	psf_log_printf (psf, "  No. of Coeffs : %d ****\n", wav_fmt->msadpcm.numcoeffs) ;
					wav_fmt->msadpcm.numcoeffs = SIGNED_SIZEOF (MS_ADPCM_WAV_FMT) / SIGNED_SIZEOF (int) ;
					}
				else
					psf_log_printf (psf, "  No. of Coeffs : %d\n", wav_fmt->msadpcm.numcoeffs) ;

				psf_log_printf (psf, "    Index   Coeffs1   Coeffs2\n") ;
				for (k = 0 ; k < wav_fmt->msadpcm.numcoeffs ; k++)
				{	bytesread +=
					psf_binheader_readf (psf, "e22", &(wav_fmt->msadpcm.coeffs [k].coeff1), &(wav_fmt->msadpcm.coeffs [k].coeff2)) ;
					LSF_SNPRINTF (psf->u.cbuf, sizeof (psf->u.cbuf), "     %2d     %7d   %7d\n", k, wav_fmt->msadpcm.coeffs [k].coeff1, wav_fmt->msadpcm.coeffs [k].coeff2) ;
					psf_log_printf (psf, psf->u.cbuf) ;
					} ;
				break ;

		case WAVE_FORMAT_GSM610 :
				if (wav_fmt->gsm610.channels != 1 || wav_fmt->gsm610.blockalign != 65)
					return SFE_WAV_GSM610_FORMAT ;

				bytesread +=
				psf_binheader_readf (psf, "e22", &(wav_fmt->gsm610.extrabytes), &(wav_fmt->gsm610.samplesperblock)) ;

				if (wav_fmt->gsm610.samplesperblock != 320)
					return SFE_WAV_GSM610_FORMAT ;

				bytespersec = (wav_fmt->gsm610.samplerate * wav_fmt->gsm610.blockalign) / wav_fmt->gsm610.samplesperblock ;
				if (wav_fmt->gsm610.bytespersec != (unsigned) bytespersec)
					psf_log_printf (psf, "  Bytes/sec     : %d (should be %d)\n", wav_fmt->gsm610.bytespersec, bytespersec) ;
				else
					psf_log_printf (psf, "  Bytes/sec     : %d\n", wav_fmt->gsm610.bytespersec) ;

				psf->bytewidth = 2 ;
				psf_log_printf (psf, "  Extra Bytes   : %d\n", wav_fmt->gsm610.extrabytes) ;
				psf_log_printf (psf, "  Samples/Block : %d\n", wav_fmt->gsm610.samplesperblock) ;
				break ;

		case WAVE_FORMAT_EXTENSIBLE :
				if (wav_fmt->ext.bytespersec / wav_fmt->ext.blockalign != wav_fmt->ext.samplerate)
					psf_log_printf (psf, "  Bytes/sec     : %d (should be %d)\n", wav_fmt->ext.bytespersec, wav_fmt->ext.samplerate * wav_fmt->ext.blockalign) ;
				else
					psf_log_printf (psf, "  Bytes/sec     : %d\n", wav_fmt->ext.bytespersec) ;

				bytesread +=
				psf_binheader_readf (psf, "e224", &(wav_fmt->ext.extrabytes), &(wav_fmt->ext.validbits),
						&(wav_fmt->ext.channelmask)) ;

				psf_log_printf (psf, "  Valid Bits    : %d\n", wav_fmt->ext.validbits) ;
				psf_log_printf (psf, "  Channel Mask  : 0x%X\n", wav_fmt->ext.channelmask) ;

				bytesread +=
				psf_binheader_readf (psf, "e422", &(wav_fmt->ext.esf.esf_field1), &(wav_fmt->ext.esf.esf_field2),
						&(wav_fmt->ext.esf.esf_field3)) ;

                /* compare the esf_fields with each known GUID? and print?*/
				psf_log_printf (psf, "  Subformat\n") ;
				psf_log_printf (psf, "    esf_field1 : 0x%X\n", wav_fmt->ext.esf.esf_field1) ;
				psf_log_printf (psf, "    esf_field2 : 0x%X\n", wav_fmt->ext.esf.esf_field2) ;
				psf_log_printf (psf, "    esf_field3 : 0x%X\n", wav_fmt->ext.esf.esf_field3) ;
				psf_log_printf (psf, "    esf_field4 : ") ;
				for (k = 0 ; k < 8 ; k++)
				{	bytesread += psf_binheader_readf (psf, "1", &(wav_fmt->ext.esf.esf_field4 [k])) ;
					psf_log_printf (psf, "0x%X ", wav_fmt->ext.esf.esf_field4 [k] & 0xFF) ;
					} ;
				psf_log_printf (psf, "\n") ;
				psf->bytewidth = BITWIDTH2BYTES (wav_fmt->ext.bitwidth) ;
				break ;

		default : break ;
		} ;

	if (bytesread > structsize)
	{	psf_log_printf (psf, "*** wav_w64_read_fmt_chunk (bytesread > structsize)\n") ;
		return SFE_W64_FMT_SHORT ;
		}
	else
		psf_binheader_readf (psf, "j", structsize - bytesread) ;

	psf->blockwidth = wav_fmt->min.channels * psf->bytewidth ;

	return 0 ;
} /* wav_w64_read_fmt_chunk */

/*==============================================================================
*/

typedef struct
{	int			ID ;
	const char	*name ;
} WAV_FORMAT_DESC ;

#define STR(x)			#x
#define FORMAT_TYPE(x)	{ x, STR (x) }

static WAV_FORMAT_DESC wave_descs [] =
{	FORMAT_TYPE	(WAVE_FORMAT_PCM),
	FORMAT_TYPE (WAVE_FORMAT_MS_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_IEEE_FLOAT),
	FORMAT_TYPE (WAVE_FORMAT_VSELP),
	FORMAT_TYPE (WAVE_FORMAT_IBM_CVSD),
	FORMAT_TYPE (WAVE_FORMAT_ALAW),
	FORMAT_TYPE (WAVE_FORMAT_MULAW),
	FORMAT_TYPE (WAVE_FORMAT_OKI_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_IMA_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_MEDIASPACE_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_SIERRA_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_G723_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_DIGISTD),
	FORMAT_TYPE (WAVE_FORMAT_DIGIFIX),
	FORMAT_TYPE (WAVE_FORMAT_DIALOGIC_OKI_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_MEDIAVISION_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_CU_CODEC),
	FORMAT_TYPE (WAVE_FORMAT_YAMAHA_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_SONARC),
	FORMAT_TYPE (WAVE_FORMAT_DSPGROUP_TRUESPEECH),
	FORMAT_TYPE (WAVE_FORMAT_ECHOSC1),
	FORMAT_TYPE (WAVE_FORMAT_AUDIOFILE_AF36),
	FORMAT_TYPE (WAVE_FORMAT_APTX),
	FORMAT_TYPE (WAVE_FORMAT_AUDIOFILE_AF10),
	FORMAT_TYPE (WAVE_FORMAT_PROSODY_1612),
	FORMAT_TYPE (WAVE_FORMAT_LRC),
	FORMAT_TYPE (WAVE_FORMAT_DOLBY_AC2),
	FORMAT_TYPE (WAVE_FORMAT_GSM610),
	FORMAT_TYPE (WAVE_FORMAT_MSNAUDIO),
	FORMAT_TYPE (WAVE_FORMAT_ANTEX_ADPCME),
	FORMAT_TYPE (WAVE_FORMAT_CONTROL_RES_VQLPC),
	FORMAT_TYPE (WAVE_FORMAT_DIGIREAL),
	FORMAT_TYPE (WAVE_FORMAT_DIGIADPCM),
	FORMAT_TYPE (WAVE_FORMAT_CONTROL_RES_CR10),
	FORMAT_TYPE (WAVE_FORMAT_NMS_VBXADPCM),
	FORMAT_TYPE (WAVE_FORMAT_ROLAND_RDAC),
	FORMAT_TYPE (WAVE_FORMAT_ECHOSC3),
	FORMAT_TYPE (WAVE_FORMAT_ROCKWELL_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_ROCKWELL_DIGITALK),
	FORMAT_TYPE (WAVE_FORMAT_XEBEC),
	FORMAT_TYPE (WAVE_FORMAT_G721_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_G728_CELP),
	FORMAT_TYPE (WAVE_FORMAT_MSG723),
	FORMAT_TYPE (WAVE_FORMAT_MPEG),
	FORMAT_TYPE (WAVE_FORMAT_RT24),
	FORMAT_TYPE (WAVE_FORMAT_PAC),
	FORMAT_TYPE (WAVE_FORMAT_MPEGLAYER3),
	FORMAT_TYPE (WAVE_FORMAT_LUCENT_G723),
	FORMAT_TYPE (WAVE_FORMAT_CIRRUS),
	FORMAT_TYPE (WAVE_FORMAT_ESPCM),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE),
	FORMAT_TYPE (WAVE_FORMAT_CANOPUS_ATRAC),
	FORMAT_TYPE (WAVE_FORMAT_G726_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_G722_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_DSAT),
	FORMAT_TYPE (WAVE_FORMAT_DSAT_DISPLAY),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_BYTE_ALIGNED),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_AC8),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_AC10),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_AC16),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_AC20),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_RT24),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_RT29),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_RT29HW),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_VR12),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_VR18),
	FORMAT_TYPE (WAVE_FORMAT_VOXWARE_TQ40),
	FORMAT_TYPE (WAVE_FORMAT_SOFTSOUND),
	FORMAT_TYPE (WAVE_FORMAT_VOXARE_TQ60),
	FORMAT_TYPE (WAVE_FORMAT_MSRT24),
	FORMAT_TYPE (WAVE_FORMAT_G729A),
	FORMAT_TYPE (WAVE_FORMAT_MVI_MV12),
	FORMAT_TYPE (WAVE_FORMAT_DF_G726),
	FORMAT_TYPE (WAVE_FORMAT_DF_GSM610),
	FORMAT_TYPE (WAVE_FORMAT_ONLIVE),
	FORMAT_TYPE (WAVE_FORMAT_SBC24),
	FORMAT_TYPE (WAVE_FORMAT_DOLBY_AC3_SPDIF),
	FORMAT_TYPE (WAVE_FORMAT_ZYXEL_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_PHILIPS_LPCBB),
	FORMAT_TYPE (WAVE_FORMAT_PACKED),
	FORMAT_TYPE (WAVE_FORMAT_RHETOREX_ADPCM),
	FORMAT_TYPE (IBM_FORMAT_MULAW),
	FORMAT_TYPE (IBM_FORMAT_ALAW),
	FORMAT_TYPE (IBM_FORMAT_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_VIVO_G723),
	FORMAT_TYPE (WAVE_FORMAT_VIVO_SIREN),
	FORMAT_TYPE (WAVE_FORMAT_DIGITAL_G723),
	FORMAT_TYPE (WAVE_FORMAT_CREATIVE_ADPCM),
	FORMAT_TYPE (WAVE_FORMAT_CREATIVE_FASTSPEECH8),
	FORMAT_TYPE (WAVE_FORMAT_CREATIVE_FASTSPEECH10),
	FORMAT_TYPE (WAVE_FORMAT_QUARTERDECK),
	FORMAT_TYPE (WAVE_FORMAT_FM_TOWNS_SND),
	FORMAT_TYPE (WAVE_FORMAT_BZV_DIGITAL),
	FORMAT_TYPE (WAVE_FORMAT_VME_VMPCM),
	FORMAT_TYPE (WAVE_FORMAT_OLIGSM),
	FORMAT_TYPE (WAVE_FORMAT_OLIADPCM),
	FORMAT_TYPE (WAVE_FORMAT_OLICELP),
	FORMAT_TYPE (WAVE_FORMAT_OLISBC),
	FORMAT_TYPE (WAVE_FORMAT_OLIOPR),
	FORMAT_TYPE (WAVE_FORMAT_LH_CODEC),
	FORMAT_TYPE (WAVE_FORMAT_NORRIS),
	FORMAT_TYPE (WAVE_FORMAT_SOUNDSPACE_MUSICOMPRESS),
	FORMAT_TYPE (WAVE_FORMAT_DVM),
	FORMAT_TYPE (WAVE_FORMAT_INTERWAV_VSC112),
	FORMAT_TYPE (WAVE_FORMAT_EXTENSIBLE),
} ;

char const*
wav_w64_format_str (int k)
{	int lower, upper, mid ;

	lower = -1 ;
	upper = sizeof (wave_descs) / sizeof (WAV_FORMAT_DESC) ;

	/* binary search */
	if ((wave_descs [0].ID <= k) & (k <= wave_descs [upper - 1].ID))
	{
		while (lower + 1 < upper)
		{	mid = (upper + lower) / 2 ;

			if (k == wave_descs [mid].ID)
				return wave_descs [mid].name ;
			if (k < wave_descs [mid].ID)
				upper = mid ;
			else
				lower = mid ;
			} ;
		} ;

	return "Unknown format" ;
} /* wav_w64_format_str */

int
wav_w64_srate2blocksize (int srate_chan_product)
{	if (srate_chan_product < 12000)
		return 256 ;
	if (srate_chan_product < 23000)
		return 512 ;
	if (srate_chan_product < 44000)
		return 1024 ;
	return 2048 ;
} /* srate2blocksize */
/*
** Do not edit or modify anything in this comment block.
** The arch-tag line is a file identity tag for the GNU Arch
** revision control system.
**
** arch-tag: 43c1b1dd-8abd-43da-a8cd-44da914b64a5
*/
