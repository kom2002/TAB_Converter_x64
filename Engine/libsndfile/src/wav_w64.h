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

/* This file contains definitions commong to WAV and W64 files. */


#ifndef WAV_W64_H_INCLUDED
#define WAV_W64_H_INCLUDED

/*------------------------------------------------------------------------------
** List of known WAV format tags
*/

enum
{
  /* keep sorted for wav_w64_format_str() */
	WAVE_FORMAT_UNKNOWN					= 0x0000,		/* Microsoft Corporation */
	WAVE_FORMAT_PCM	 					= 0x0001, 		/* Microsoft PCM format */
	WAVE_FORMAT_MS_ADPCM				= 0x0002,		/* Microsoft ADPCM */
	WAVE_FORMAT_IEEE_FLOAT				= 0x0003,		/* Micrososft 32 bit float format */
	WAVE_FORMAT_VSELP					= 0x0004,		/* Compaq Computer Corporation */
	WAVE_FORMAT_IBM_CVSD				= 0x0005,		/* IBM Corporation */
	WAVE_FORMAT_ALAW					= 0x0006,		/* Microsoft Corporation */
	WAVE_FORMAT_MULAW					= 0x0007,		/* Microsoft Corporation */
	WAVE_FORMAT_OKI_ADPCM				= 0x0010,		/* OKI */
	WAVE_FORMAT_IMA_ADPCM				= 0x0011,		/* Intel Corporation */
	WAVE_FORMAT_MEDIASPACE_ADPCM		= 0x0012,		/* Videologic */
	WAVE_FORMAT_SIERRA_ADPCM			= 0x0013,		/* Sierra Semiconductor Corp */
	WAVE_FORMAT_G723_ADPCM				= 0x0014,		/* Antex Electronics Corporation */
	WAVE_FORMAT_DIGISTD					= 0x0015,		/* DSP Solutions, Inc. */
	WAVE_FORMAT_DIGIFIX					= 0x0016,		/* DSP Solutions, Inc. */
	WAVE_FORMAT_DIALOGIC_OKI_ADPCM		= 0x0017,		/*  Dialogic Corporation  */
	WAVE_FORMAT_MEDIAVISION_ADPCM		= 0x0018,		/*  Media Vision, Inc. */
	WAVE_FORMAT_CU_CODEC				= 0x0019,		/* Hewlett-Packard Company */
	WAVE_FORMAT_YAMAHA_ADPCM			= 0x0020,		/* Yamaha Corporation of America */
	WAVE_FORMAT_SONARC					= 0x0021,		/* Speech Compression */
	WAVE_FORMAT_DSPGROUP_TRUESPEECH 	= 0x0022,		/* DSP Group, Inc */
	WAVE_FORMAT_ECHOSC1					= 0x0023,		/* Echo Speech Corporation */
	WAVE_FORMAT_AUDIOFILE_AF36			= 0x0024,		/* Audiofile, Inc. */
	WAVE_FORMAT_APTX					= 0x0025,		/* Audio Processing Technology */
	WAVE_FORMAT_AUDIOFILE_AF10			= 0x0026,		/* Audiofile, Inc. */
	WAVE_FORMAT_PROSODY_1612			= 0x0027,		/* Aculab plc */
	WAVE_FORMAT_LRC						= 0x0028,		/* Merging Technologies S.A. */
	WAVE_FORMAT_DOLBY_AC2				= 0x0030,		/* Dolby Laboratories */
	WAVE_FORMAT_GSM610					= 0x0031,		/* Microsoft Corporation */
	WAVE_FORMAT_MSNAUDIO				= 0x0032,		/* Microsoft Corporation */
	WAVE_FORMAT_ANTEX_ADPCME			= 0x0033, 		/* Antex Electronics Corporation */
	WAVE_FORMAT_CONTROL_RES_VQLPC		= 0x0034,		/* Control Resources Limited */
	WAVE_FORMAT_DIGIREAL				= 0x0035,		/* DSP Solutions, Inc. */
	WAVE_FORMAT_DIGIADPCM				= 0x0036,		/* DSP Solutions, Inc. */
	WAVE_FORMAT_CONTROL_RES_CR10		= 0x0037,		/* Control Resources Limited */
	WAVE_FORMAT_NMS_VBXADPCM			= 0x0038,		/* Natural MicroSystems */
	WAVE_FORMAT_ROLAND_RDAC				= 0x0039,		/* Roland */
	WAVE_FORMAT_ECHOSC3					= 0x003A,		/* Echo Speech Corporation */
	WAVE_FORMAT_ROCKWELL_ADPCM			= 0x003B,		/* Rockwell International */
	WAVE_FORMAT_ROCKWELL_DIGITALK		= 0x003C, 		/* Rockwell International */
	WAVE_FORMAT_XEBEC					= 0x003D,		/* Xebec Multimedia Solutions Limited */
	WAVE_FORMAT_G721_ADPCM				= 0x0040,		/* Antex Electronics Corporation */
	WAVE_FORMAT_G728_CELP				= 0x0041,		/* Antex Electronics Corporation */
	WAVE_FORMAT_MSG723					= 0x0042,		/* Microsoft Corporation */
	WAVE_FORMAT_MPEG					= 0x0050,		/* Microsoft Corporation */
	WAVE_FORMAT_RT24					= 0x0052,		/* InSoft Inc. */
	WAVE_FORMAT_PAC						= 0x0053,		/* InSoft Inc. */
	WAVE_FORMAT_MPEGLAYER3				= 0x0055,		/* MPEG 3 Layer 1 */
	WAVE_FORMAT_LUCENT_G723				= 0x0059,		/* Lucent Technologies */
	WAVE_FORMAT_CIRRUS					= 0x0060,		/* Cirrus Logic */
	WAVE_FORMAT_ESPCM					= 0x0061,		/* ESS Technology */
	WAVE_FORMAT_VOXWARE					= 0x0062,		/* Voxware Inc */
	WAVE_FORMAT_CANOPUS_ATRAC			= 0x0063,		/* Canopus, Co., Ltd. */
	WAVE_FORMAT_G726_ADPCM				= 0x0064,		/* APICOM */
	WAVE_FORMAT_G722_ADPCM				= 0x0065,		/* APICOM */
	WAVE_FORMAT_DSAT					= 0x0066,		/* Microsoft Corporation */
	WAVE_FORMAT_DSAT_DISPLAY			= 0x0067,		/* Microsoft Corporation */
	WAVE_FORMAT_VOXWARE_BYTE_ALIGNED	= 0x0069,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_AC8				= 0x0070,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_AC10			= 0x0071,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_AC16			= 0x0072,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_AC20			= 0x0073,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_RT24			= 0x0074,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_RT29			= 0x0075,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_RT29HW			= 0x0076,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_VR12			= 0x0077,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_VR18			= 0x0078,		/* Voxware Inc. */
	WAVE_FORMAT_VOXWARE_TQ40			= 0x0079,		/* Voxware Inc. */
	WAVE_FORMAT_SOFTSOUND				= 0x0080,		/* Softsound, Ltd. */
	WAVE_FORMAT_VOXARE_TQ60				= 0x0081,		/* Voxware Inc. */
	WAVE_FORMAT_MSRT24					= 0x0082,		/* Microsoft Corporation */
	WAVE_FORMAT_G729A					= 0x0083,		/* AT&T Laboratories */
	WAVE_FORMAT_MVI_MV12				= 0x0084,		/* Motion Pixels */
	WAVE_FORMAT_DF_G726					= 0x0085,		/* DataFusion Systems (Pty) (Ltd) */
	WAVE_FORMAT_DF_GSM610				= 0x0086,		/* DataFusion Systems (Pty) (Ltd) */
	/* removed because duplicate */
	/* WAVE_FORMAT_ISIAUDIO				= 0x0088, */	/* Iterated Systems, Inc. */
	WAVE_FORMAT_ONLIVE					= 0x0089,		/* OnLive! Technologies, Inc. */
	WAVE_FORMAT_SBC24					= 0x0091,		/* Siemens Business Communications Systems */
	WAVE_FORMAT_DOLBY_AC3_SPDIF			= 0x0092,		/* Sonic Foundry */
	WAVE_FORMAT_ZYXEL_ADPCM				= 0x0097,		/* ZyXEL Communications, Inc. */
	WAVE_FORMAT_PHILIPS_LPCBB			= 0x0098,		/* Philips Speech Processing */
	WAVE_FORMAT_PACKED					= 0x0099,		/* Studer Professional Audio AG */
	WAVE_FORMAT_RHETOREX_ADPCM			= 0x0100,		/* Rhetorex, Inc. */

	/* removed because of the following */
	/* WAVE_FORMAT_IRAT					= 0x0101,*/		/* BeCubed Software Inc. */

	/* these three are unofficial */
	IBM_FORMAT_MULAW					= 0x0101,		/* IBM mu-law format */
	IBM_FORMAT_ALAW						= 0x0102,		/* IBM a-law format */
	IBM_FORMAT_ADPCM					= 0x0103,		/* IBM AVC Adaptive Differential PCM format */

	WAVE_FORMAT_VIVO_G723				= 0x0111,		/* Vivo Software */
	WAVE_FORMAT_VIVO_SIREN				= 0x0112,		/* Vivo Software */
	WAVE_FORMAT_DIGITAL_G723			= 0x0123,		/* Digital Equipment Corporation */
	WAVE_FORMAT_CREATIVE_ADPCM			= 0x0200,		/* Creative Labs, Inc */
	WAVE_FORMAT_CREATIVE_FASTSPEECH8 	= 0x0202,		/* Creative Labs, Inc */
	WAVE_FORMAT_CREATIVE_FASTSPEECH10 	= 0x0203,		/* Creative Labs, Inc */
	WAVE_FORMAT_QUARTERDECK				= 0x0220,		/* Quarterdeck Corporation */
	WAVE_FORMAT_FM_TOWNS_SND			= 0x0300,		/* Fujitsu Corporation */
	WAVE_FORMAT_BZV_DIGITAL				= 0x0400,		/* Brooktree Corporation */
	WAVE_FORMAT_VME_VMPCM				= 0x0680,		/* AT&T Labs, Inc. */
	WAVE_FORMAT_OLIGSM					= 0x1000,		/* Ing C. Olivetti & C., S.p.A. */
	WAVE_FORMAT_OLIADPCM				= 0x1001,		/* Ing C. Olivetti & C., S.p.A. */
	WAVE_FORMAT_OLICELP					= 0x1002,		/* Ing C. Olivetti & C., S.p.A. */
	WAVE_FORMAT_OLISBC					= 0x1003,		/* Ing C. Olivetti & C., S.p.A. */
	WAVE_FORMAT_OLIOPR					= 0x1004,		/* Ing C. Olivetti & C., S.p.A. */
	WAVE_FORMAT_LH_CODEC				= 0x1100,		/* Lernout & Hauspie */
	WAVE_FORMAT_NORRIS					= 0x1400,		/* Norris Communications, Inc. */
	/* removed because duplicate */
	/* WAVE_FORMAT_ISIAUDIO				= 0x1401, */	/* AT&T Labs, Inc. */
	WAVE_FORMAT_SOUNDSPACE_MUSICOMPRESS	= 0x1500,		/* AT&T Labs, Inc. */
	WAVE_FORMAT_DVM						= 0x2000,		/* FAST Multimedia AG */
	WAVE_FORMAT_INTERWAV_VSC112			= 0x7150,		/* ????? */
	WAVE_FORMAT_EXTENSIBLE				= 0xFFFE
} ;

typedef	struct
{	unsigned short	format ;
	unsigned short	channels ;
	unsigned int	samplerate ;
	unsigned int	bytespersec ;
	unsigned short	blockalign ;
	unsigned short	bitwidth ;
} MIN_WAV_FMT ;

typedef	struct
{	unsigned short	format ;
	unsigned short	channels ;
	unsigned int	samplerate ;
	unsigned int	bytespersec ;
	unsigned short	blockalign ;
	unsigned short	bitwidth ;
	unsigned short	extrabytes ;
	unsigned short	dummy ;
} WAV_FMT_SIZE20 ;

typedef	struct
{	unsigned short	format ;
	unsigned short	channels ;
	unsigned int	samplerate ;
	unsigned int	bytespersec ;
	unsigned short	blockalign ;
	unsigned short	bitwidth ;
	unsigned short	extrabytes ;
	unsigned short	samplesperblock ;
	unsigned short	numcoeffs ;
	struct
	{	short	coeff1 ;
		short	coeff2 ;
	}	coeffs [7] ;
} MS_ADPCM_WAV_FMT ;

typedef	struct
{	unsigned short	format ;
	unsigned short	channels ;
	unsigned int	samplerate ;
	unsigned int	bytespersec ;
	unsigned short	blockalign ;
	unsigned short	bitwidth ;
	unsigned short	extrabytes ;
	unsigned short	samplesperblock ;
} IMA_ADPCM_WAV_FMT ;

typedef	struct
{	unsigned short	format ;
	unsigned short	channels ;
	unsigned int	samplerate ;
	unsigned int	bytespersec ;
	unsigned short	blockalign ;
	unsigned short	bitwidth ;
	unsigned short	extrabytes ;
	unsigned short	auxblocksize ;
} G72x_ADPCM_WAV_FMT ;


typedef	struct
{	unsigned short	format ;
	unsigned short	channels ;
	unsigned int	samplerate ;
	unsigned int	bytespersec ;
	unsigned short	blockalign ;
	unsigned short	bitwidth ;
	unsigned short	extrabytes ;
	unsigned short	samplesperblock ;
} GSM610_WAV_FMT ;

typedef struct
{	unsigned int	esf_field1 ;
	unsigned short	esf_field2 ;
	unsigned short	esf_field3 ;
	char			esf_field4 [8] ;
} EXT_SUBFORMAT ;

typedef	struct
{	unsigned short	format ;
	unsigned short	channels ;
	unsigned int	samplerate ;
	unsigned int	bytespersec ;
	unsigned short	blockalign ;
	unsigned short	bitwidth ;
	unsigned short	extrabytes ;
	unsigned short	validbits ;
	unsigned int	channelmask ;
	EXT_SUBFORMAT	esf ;
} EXTENSIBLE_WAV_FMT ;

typedef union
{	unsigned short		format ;
	MIN_WAV_FMT			min ;
	IMA_ADPCM_WAV_FMT	ima ;
	MS_ADPCM_WAV_FMT	msadpcm ;
	G72x_ADPCM_WAV_FMT	g72x ;
	EXTENSIBLE_WAV_FMT	ext ;
	GSM610_WAV_FMT		gsm610 ;
	WAV_FMT_SIZE20		size20 ;
	char				padding [512] ;
} WAV_FMT ;

typedef struct
{	int frames ;
} FACT_CHUNK ;

#define		WAV_W64_GSM610_BLOCKSIZE	65
#define		WAV_W64_GSM610_SAMPLES		320

/*------------------------------------------------------------------------------------
**	Functions defined in wav_ms_adpcm.c
*/

#define	MSADPCM_ADAPT_COEFF_COUNT	7

void	msadpcm_write_adapt_coeffs (SF_PRIVATE *psf) ;

/*------------------------------------------------------------------------------------
**	Functions defined in wav_gsm610.c
*/

int 	wav_w64_srate2blocksize (int srate_chan_product) ;
char const* wav_w64_format_str (int k) ;
int		wav_w64_read_fmt_chunk (SF_PRIVATE *psf, WAV_FMT *wav_fmt, int structsize) ;

#endif
/*
** Do not edit or modify anything in this comment block.
** The arch-tag line is a file identity tag for the GNU Arch 
** revision control system.
**
** arch-tag: 877fde12-9be3-4a31-8a5a-fdae39958613
*/
