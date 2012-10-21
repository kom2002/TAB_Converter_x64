#ifndef CONVERTER_H
#define CONVERTER_H

#ifdef CONVERTER_EXPORTS
#define CONVERTER_API __declspec(dllexport)
#else
#define CONVERTER_API __declspec(dllimport)
#endif

#include "AllHandle.h"
#include "LoadNccHandle.h"
#include "LoadSmilHandle.h"
#include "LoadHtmlHandle.h"
#include "LoadDaisy3NcxHandle.h"
#include "LoadDaisy3Smil2Handle.h"
#include "LoadDaisy3XmlHandle.h"

//Include Xerces
//#include "XMLString::transcode.h"

//Include libsamplerate
#include <math.h>
#include "./../Engine/libsamplerate/config.h"
#include "./../Engine/libsamplerate/unistd.h"
#include "./../Engine/libsamplerate/samplerate.h"
#include "./../Engine/libsamplerate/sndfile.h"
#define	 BUFFER_LEN		4096	/*-(1<<16)-*/

//Include MAD
#include "./../Engine/madlldlib/madlldlib.h"

//Include SAPI for convert Text2Wave
#include "./Include/SAPI5/sphelper.h"

//Include Tidy dll
#include <errno.h>
#include "tidy.h"
#include "fileio.h"
#include "buffio.h"

//Include File system
#include <fstream>
#include <sstream>




using namespace std;
		template class			CONVERTER_API allocator<string>;
		template class			CONVERTER_API vector<string,allocator<string> >;

		template class			CONVERTER_API allocator<bool>;
		template class			CONVERTER_API vector<bool,allocator<bool> >;
class CONVERTER_API Converter 
{
public:
								~Converter					(void);		//!destructor
								Converter					(void);		//!default constructor
		int						Starter						(char * chrNcPath, char * chrDestFolder, bool boolMakeSyntheticSound, int intOrderText2Speech, char * chrOutputAudioFormat);
		int						GetCpuSpeed					();
//private:


		//vector for Html
		vector<string>			myVecHtmlParagraphID;   //gather from myVecSmilBegin (ID) in each smill then no need to clean.
		vector<string>			myVecHtmlContent;		//gather from myVecSmilEnd (Content) in each smill then no need to clean.
		vector<bool>			myVecHtmlPageNumberDetect;
		vector<string>			myVecHtmlMetaName;
		vector<string>			myVecHtmlMetaContent;
		vector<string>			myVecHtmlMetaScheme;
		string					myStrHtmlMetaHttpEquivName;
		string					myStrHtmlMetaHttpEquivContent;
		string					myStrHtmlTitle;
		string					myStrHtmlLinkRel;
		string					myStrHtmlLinkHref;
		string					myStrHtmlLinkType;
		string					myStrHtmlLinkTitle;

		//Vector for collect audio files in each smil to write opf file. 
		vector<string>			myVecOpfStoreAudio;

		//Handle for parser
		LoadNccHandle			*MyLoadNccHandle;
		LoadSmilHandle			*MyLoadSmilHandle;
		LoadHtmlHandle			*MyLoadHtmlHandle;
		LoadDaisy3NcxHandle		*MyLoadDaisy3NcxHandle;
		LoadDaisy3Smil2Handle	*MyLoadDaisy3Smil2Handle;
		LoadDaisy3XmlHandle		*MyLoadDaisy3XmlHandle;

		//local funtion
		bool					fnLoadNcc						(string myNccPath, int intOrderText2Speech, char * chrOutputAudioFormat);
		bool					fnLoadSmil						(string mySmilFileName);
		bool					fnLoadHtml						(string myStrSourcePathHtml);

		bool				    fnLoadDaisy3Ncx					(string myDaisy3NcxPath, int intOrderText2Speech, char * chrOutputAudioFormat);
		bool					fnLoadDaisy3Smil2				(string myDaisy3Smil2Path);
		bool					fnLoadDaisy3Xml					(string myDaisy3XmlPath);

		bool					fnWriteNcx						(char*  chrEnCoding, const char* chrOutputFileName);
		bool					fnWriteSmil2					(char*  chrEnCoding, const char* chrOutputFileName, string strAudioType);
		bool					fnWriteXml						(char*  chrEnCoding, const char* chrOutputFileName);
		bool					fnWriteOpf						(char*  chrEnCoding, const char* chrOutputFileName);
		
		bool					fnCheckDupSmil					(void);
		vector<string>			fnGetVecUniqueHtml				(void);
		bool					fnCleanSmilVariable				(void);
		bool					fnWriteCss						(string strOutputFileName);
		bool					fnReportingStatusToFile			(int intPercent, string strDtbStatus, string strFileName, string strFileStatus);
		bool					fnChangeEncoding				(string strOutputFileName,string strSought, string strReplacement); 
		string					fnGetSourceDirectoryFromNccPath	(string strMyNcc);
		bool					fnConvertMpeg2Wav				(const char* chrInMpegFileName, const char* chrOutWavFileName);
		bool					fnFindAndConvertMpegInSmilToVox	(int intOrderSmil, char * chrOutputAudioFormat, int intOrderText2Speech);
		bool					fnConvertText2Wave				(const char* chrData, const char* chrFileName, int intOrderText2Speech, int intTryingNumber);
		bool					fnCopyBinaryFile				(const char* chrSourceFile, const char* chrDestinationFile);
		bool					fnCompareString					(char* chrFirstString, char* chrSecondString, bool boolCaseInsensitive);
		bool					fnConvertOrGenerateAudio		(string strAudioSrc,
																 string strAudioText, 
																 string strAudioExpectFileName,
																 char*  chrOutputAudioFormat,
																 int    intOrderText2Speech);

		wchar_t*				fnCodePageToUnicode(int codePage, const char *src);
		char*					fnUnicodeToCodePage(int codePage, const wchar_t *src);
		int						fnIsUnicodeFile(const char* szFileName);
		//CString					fnConvertFile(char *szFileName);

		//Wave 8K Conversion Function (Secret Rabbit Code (aka libsamplerate) is a Sample Rate Converter for audio)
		bool					fnConvertWave2Wave8K			(string strInputFileName, string strOutputFileName);
		bool					fnConvertWave2Vox				(string strInputFileName, string strOutputFileName);
		string					fnGetDuration					(string strInputFileName);
		static	const char*		generate_duration_str			(SF_INFO *sfinfo);
		static	sf_count_t		sample_rate_convert				(SNDFILE *infile, SNDFILE *outfile, int converter, double src_ratio, int channels, double * gain) ; // call from fnConvertWave2Wave8K
		static	double			apply_gain						(float * data, long frames, int channels, double max, double gain) ; // call from fnConvertWave2Wave8K
		//string					strLastDurationFile;
		
		static bool _stdcall	mycb						(unsigned long fcnt, unsigned long bcnt, struct mad_header *mhdr);
	
		//Tidy Clear file before parser
		bool					fnTidyClean						(string strSourceFileName, string strOutputFileName);

		//local variable
		string					strSourcePathNcc;
		string					strSourcePathBook;
		string					strSourcePathSmil;
		string					strSourcePathHtml;
		string					strDestinationFolder;
		string					strSourceTempFolder;
		string					strSourceTempPathFileName;
		string					strNcxDestinationFileName;
		string					strSmilDestinationFileName;
		string					strText2WaveDestinationFileName;
		string					strWave2VoxDestinationFileName;
		bool					boolReturnResult;
		bool					boolIsDaisy3;

		string					HtmlForGetString;
		string					IdForGetString;					// use compare for get correct string from HTML. 
		string					strHtmlFileNameForCheckDup;

		///////////////////////////////////////////////////////////////////////////////////
		//vector to store navigation control variable from both Daisy 2,3 for writing NCX//
		///////////////////////////////////////////////////////////////////////////////////
		//root
		string					myStrDaisy3NcxVersion;
		string					myStrDaisy3NcxXmlNs;
		string					myStrDaisy3NcxXmlLanguage;
		//Header	
		vector<string>			myVecDaisy3NcxCustomTestId;
		vector<string>			myVecDaisy3NcxCustomTestDefaultState;
		vector<string>			myVecDaisy3NcxCustomTestOverride;
		vector<string>			myVecDaisy3NcxCustomTestBookStruct;
		vector<string>			myVecDaisy3NcxMetaName;
		vector<string>			myVecDaisy3NcxMetaContent;
		vector<string>			myVecDaisy3NcxMetaScheme;
		//docTitle
		string					myStrDaisy3NcxDocTitleText;
		string					myStrDaisy3NcxDocTitleAudioSrc;
		string					myStrDaisy3NcxDocTitleAudioBegin;
		string					myStrDaisy3NcxDocTitleAudioEnd;
		string					myStrDaisy3NcxDocTitleImageSrc;
		//docAuthor
		string				    myStrDaisy3NcxDocAuthorText;
		string					myStrDaisy3NcxDocAuthorAudioSrc;
		string					myStrDaisy3NcxDocAuthorAudioBegin;
		string					myStrDaisy3NcxDocAuthorAudioEnd;
		string					myStrDaisy3NcxDocAuthorImageSrc;
		//Body
		vector<string>			myVecDaisy3NcxBodyKind;			//navPoint or pageTarget or navTarget.	
		vector<string>			myVecDaisy3NcxBodyType;			//H1, H2, H3 ,H4 ,H5 ,span,	navPoint, pageTarget, navTarget.			
		vector<string>			myVecDaisy3NcxBodyClass;	
		vector<string>			myVecDaisy3NcxBodyId;
		vector<string>			myVecDaisy3NcxBodyLinkFile;	
		vector<string>			myVecDaisy3NcxBodyLinkId;
		vector<string>			myVecDaisy3NcxBodyName;			//text
		vector<string>			myVecDaisy3NcxBodyPlayOrder;
		vector<string>			myVecDaisy3NcxBodyAudioSrc;
		vector<string>			myVecDaisy3NcxBodyAudioBegin;
		vector<string>			myVecDaisy3NcxBodyAudioEnd;
		vector<string>			myVecDaisy3NcxBodyImageSrc;

		//Part (Section)
		vector<string>			myVecDaisy3NcxPartKind;			//navMap, PageList, navList				
		vector<string>			myVecDaisy3NcxPartId;
		vector<string>			myVecDaisy3NcxPartClass;
		vector<string>			myVecDaisy3NcxPartPositionInBody; //unnecessary 
		vector<string>			myVecDaisy3NcxPartNavInfoText;
		vector<string>			myVecDaisy3NcxPartNavInfoAudioSrc;
		vector<string>			myVecDaisy3NcxPartNavInfoAudioBegin;
		vector<string>			myVecDaisy3NcxPartNavInfoAudioEnd;
		vector<string>			myVecDaisy3NcxPartNavInfoImageSrc;
		vector<string>			myVecDaisy3NcxPartNavLabelText;
		vector<string>			myVecDaisy3NcxPartNavLabelAudioSrc;
		vector<string>			myVecDaisy3NcxPartNavLabelAudioBegin;
		vector<string>			myVecDaisy3NcxPartNavLabelAudioEnd;
		vector<string>			myVecDaisy3NcxPartNavLabelImageSrc;

		///////////////////////////////////////////////////////////////////////////////////
		//vector to store synchronize variable from both Daisy 2,3 for writing SMIL file //
		///////////////////////////////////////////////////////////////////////////////////
		//Head
		string					myStrDaisy3Smil2HeadXmlNs;
		vector<string>			myVecDaisy3Smil2HeadMetaName;
		vector<string>			myVecDaisy3Smil2HeadMetaContent;
		vector<string>			myVecDaisy3Smil2HeadRegionId;
		vector<string>			myVecDaisy3Smil2HeadRegionTop;
		vector<string>			myVecDaisy3Smil2HeadRegionLeft;
		vector<string>			myVecDaisy3Smil2HeadRegionRight;
		vector<string>			myVecDaisy3Smil2HeadRegionBottom;
		vector<string>			myVecDaisy3Smil2HeadRegionHeight;
		vector<string>			myVecDaisy3Smil2HeadRegionWidth;
		vector<string>			myVecDaisy3Smil2HeadRegionFit;
		vector<string>			myVecDaisy3Smil2HeadRegionBackgroundColor;
		vector<string>			myVecDaisy3Smil2HeadRegionShowBackground;
		vector<string>			myVecDaisy3Smil2HeadRegionZIndex;
		vector<string>			myVecDaisy3Smil2HeadRegionXmlLang;
		vector<string>			myVecDaisy3Smil2HeadCustomTestId;
		vector<string>			myVecDaisy3Smil2HeadCustomTestDefaultState;
		vector<string>			myVecDaisy3Smil2HeadCustomTestOverride;
		vector<string>			myVecDaisy3Smil2HeadCustomTestClass;
		vector<string>			myVecDaisy3Smil2HeadCustomTestTitle;
		vector<string>			myVecDaisy3Smil2HeadCustomTestXmlLang;
		//Body
		vector<string>			myVecDaisy3Smil2BodySeqId;						//Primary Vector which used to cound number of body vectors.
		vector<string>			myVecDaisy3Smil2BodySeqClass;	
		vector<string>			myVecDaisy3Smil2BodySeqCustomTest;
		vector<string>			myVecDaisy3Smil2BodySeqDur;
		vector<string>			myVecDaisy3Smil2BodySeqXmlLang;
		vector<string>			myVecDaisy3Smil2BodySeqEnd;
		vector<string>			myVecDaisy3Smil2BodySeqFill;
		vector<string>			myVecDaisy3Smil2BodySeqLevel;
		vector<string>			myVecDaisy3Smil2BodyParId;
		vector<string>			myVecDaisy3Smil2BodyParClass;
		vector<string>			myVecDaisy3Smil2BodyParCustomTest;
		vector<string>			myVecDaisy3Smil2BodyParXmlLang;
		vector<string>			myVecDaisy3Smil2BodyParLevel;
		vector<string>			myVecDaisy3Smil2BodyAnchorId;
		vector<string>			myVecDaisy3Smil2BodyAnchorClass;
		vector<string>			myVecDaisy3Smil2BodyAnchorTitle;
		vector<string>			myVecDaisy3Smil2BodyAnchorXmlLang;
		vector<string>			myVecDaisy3Smil2BodyAnchorHref;
		vector<string>			myVecDaisy3Smil2BodyAnchorExternal;
		vector<string>			myVecDaisy3Smil2BodyImgId;
		vector<string>			myVecDaisy3Smil2BodyImgRegion;
		vector<string>			myVecDaisy3Smil2BodyImgSrc;
		vector<string>			myVecDaisy3Smil2BodyImgType;
		vector<string>			myVecDaisy3Smil2BodyImgXmlLang;
		vector<string>			myVecDaisy3Smil2BodyTextId;
		vector<string>			myVecDaisy3Smil2BodyTextType;
		vector<string>			myVecDaisy3Smil2BodyTextSrcFile;
		vector<string>			myVecDaisy3Smil2BodyTextSrcId;
		vector<string>			myVecDaisy3Smil2BodyTextContent;
		vector<string>			myVecDaisy3Smil2BodyTextRegion;
		vector<string>			myVecDaisy3Smil2BodyTextXmlLang;
		vector<string>			myVecDaisy3Smil2BodyAudioId;
		vector<string>			myVecDaisy3Smil2BodyAudioSrc;
		vector<string>			myVecDaisy3Smil2BodyAudioType;
		vector<string>			myVecDaisy3Smil2BodyAudioClipBegin;
		vector<string>			myVecDaisy3Smil2BodyAudioClipEnd;
		vector<string>			myVecDaisy3Smil2BodyAudioRegion;
		vector<string>			myVecDaisy3Smil2BodyAudioXmlLang;
		//below are not to write to SMIL2. It used for DAISY2 operation only.
		vector<string>			myVecDaisy2Smil1HeadMetaScheme;
};


//Function for using as DLL.
		void *	__stdcall		CreateConverterDll			();
		void	__stdcall		DestroyConverterDll			(void * objptr);
		int		__stdcall		GetCpuSpeedConverterDll		(void * objptr);
		int		__stdcall		StartConverterDll			(char * chrNcPath, char * chrDestFolder, bool boolMakeSyntheticSound, int intOrderText2Speech, char * chrOutputAudioFormat, void * objptr );

#endif