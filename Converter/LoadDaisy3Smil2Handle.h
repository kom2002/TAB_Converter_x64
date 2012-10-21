#ifndef LOADDAISY3SMIL2HANDLE_H
#define LOADDAISY3SMIL2HANDLE_H

#include "AllHandle.h"

class LoadDaisy3Smil2Handle : public DefaultHandler
{
public:
    LoadDaisy3Smil2Handle();
    ~LoadDaisy3Smil2Handle();

	void			clearVector(void);

	//Header
	string			getStrDaisy3Smil2HeadXmlNs(void);
	vector<string>	getVecDaisy3Smil2HeadMetaName(void);
	vector<string>	getVecDaisy3Smil2HeadMetaContent(void);
	vector<string>	getVecDaisy3Smil2HeadRegionId(void);
	vector<string>	getVecDaisy3Smil2HeadRegionTop(void);
	vector<string>	getVecDaisy3Smil2HeadRegionLeft(void);
	vector<string>	getVecDaisy3Smil2HeadRegionRight(void);
	vector<string>	getVecDaisy3Smil2HeadRegionBottom(void);
	vector<string>	getVecDaisy3Smil2HeadRegionHeight(void);
	vector<string>	getVecDaisy3Smil2HeadRegionWidth(void);
	vector<string>	getVecDaisy3Smil2HeadRegionFit(void);
	vector<string>	getVecDaisy3Smil2HeadRegionBackgroundColor(void);
	vector<string>	getVecDaisy3Smil2HeadRegionShowBackground(void);
	vector<string>	getVecDaisy3Smil2HeadRegionZIndex(void);
	vector<string>	getVecDaisy3Smil2HeadRegionXmlLang(void);
	vector<string>	getVecDaisy3Smil2HeadCustomTestId(void);
	vector<string>	getVecDaisy3Smil2HeadCustomTestDefaultState(void);
	vector<string>	getVecDaisy3Smil2HeadCustomTestOverride(void);
	vector<string>	getVecDaisy3Smil2HeadCustomTestClass(void);
	vector<string>	getVecDaisy3Smil2HeadCustomTestTitle(void);
	vector<string>	getVecDaisy3Smil2HeadCustomTestXmlLang(void); 

	//Body
	vector<string>	getVecDaisy3Smil2BodySeqId(void);
	vector<string>	getVecDaisy3Smil2BodySeqClass(void);
	vector<string>	getVecDaisy3Smil2BodySeqCustomTest(void);
	vector<string>	getVecDaisy3Smil2BodySeqDur(void);
	vector<string>	getVecDaisy3Smil2BodySeqXmlLang(void);
	vector<string>	getVecDaisy3Smil2BodySeqEnd(void);
	vector<string>	getVecDaisy3Smil2BodySeqFill(void);
	vector<string>	getVecDaisy3Smil2BodySeqLevel(void);

	vector<string>	getVecDaisy3Smil2BodyParId(void);
	vector<string>	getVecDaisy3Smil2BodyParClass(void);
	vector<string>	getVecDaisy3Smil2BodyParCustomTest(void);
	vector<string>	getVecDaisy3Smil2BodyParXmlLang(void);
	vector<string>	getVecDaisy3Smil2BodyParLevel(void);
	
	vector<string>	getVecDaisy3Smil2BodyAnchorId(void);
	vector<string>	getVecDaisy3Smil2BodyAnchorClass(void);
	vector<string>	getVecDaisy3Smil2BodyAnchorTitle(void);
	vector<string>	getVecDaisy3Smil2BodyAnchorXmlLang(void);
	vector<string>	getVecDaisy3Smil2BodyAnchorHref(void);
	vector<string>	getVecDaisy3Smil2BodyAnchorExternal(void);

	vector<string>	getVecDaisy3Smil2BodyImgId(void);
	vector<string>	getVecDaisy3Smil2BodyImgRegion(void);
	vector<string>	getVecDaisy3Smil2BodyImgSrc(void);
	vector<string>	getVecDaisy3Smil2BodyImgType(void);
	vector<string>	getVecDaisy3Smil2BodyImgXmlLang(void);
	
	vector<string>	getVecDaisy3Smil2BodyTextId(void);
	vector<string>	getVecDaisy3Smil2BodyTextSrcFile(void);
	vector<string>	getVecDaisy3Smil2BodyTextSrcId(void);
	vector<string>	getVecDaisy3Smil2BodyTextType(void);
	vector<string>	getVecDaisy3Smil2BodyTextRegion(void);
	vector<string>	getVecDaisy3Smil2BodyTextXmlLang(void);
	vector<string>	getVecDaisy3Smil2BodyTextContent(void);

	vector<string>	getVecDaisy3Smil2BodyAudioId(void);
	vector<string>	getVecDaisy3Smil2BodyAudioSrc(void);
	vector<string>	getVecDaisy3Smil2BodyAudioType(void);
	vector<string>	getVecDaisy3Smil2BodyAudioClipBegin(void);
	vector<string>	getVecDaisy3Smil2BodyAudioClipEnd(void);
	vector<string>	getVecDaisy3Smil2BodyAudioRegion(void);
	vector<string>	getVecDaisy3Smil2BodyAudioXmlLang(void);

private:
    void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const Attributes& attrs);
    void endElement  (const XMLCh *const uri, const XMLCh *const localname, const XMLCh *const qName);
	//void characters(const XMLCh* const chars, const unsigned int length);
    //void fatalError(const SAXParseException& exc);
	//void ignorableWhitespace(const XMLCh* const chars, const unsigned int length);
	//void resetDocument();
	//void warning(const SAXParseException& exc);
	//void error(const SAXParseException& exc);
	//void resetErrors();

	//Header
	string			strDaisy3Smil2HeadXmlNs;
	
	vector<string>	vecDaisy3Smil2HeadMetaName;
	vector<string>	vecDaisy3Smil2HeadMetaContent;
	
	vector<string>	vecDaisy3Smil2HeadRegionId;
	vector<string>	vecDaisy3Smil2HeadRegionTop;
	vector<string>	vecDaisy3Smil2HeadRegionLeft;
	vector<string>	vecDaisy3Smil2HeadRegionRight;
	vector<string>	vecDaisy3Smil2HeadRegionBottom;
	vector<string>	vecDaisy3Smil2HeadRegionHeight;
	vector<string>	vecDaisy3Smil2HeadRegionWidth;
	vector<string>	vecDaisy3Smil2HeadRegionFit;
	vector<string>	vecDaisy3Smil2HeadRegionBackgroundColor;
	vector<string>	vecDaisy3Smil2HeadRegionShowBackground;
	vector<string>	vecDaisy3Smil2HeadRegionZIndex;
	vector<string>	vecDaisy3Smil2HeadRegionXmlLang;
	
	vector<string>	vecDaisy3Smil2HeadCustomTestId;
	vector<string>	vecDaisy3Smil2HeadCustomTestDefaultState;
	vector<string>	vecDaisy3Smil2HeadCustomTestOverride;
	vector<string>	vecDaisy3Smil2HeadCustomTestClass;
	vector<string>	vecDaisy3Smil2HeadCustomTestTitle;
	vector<string>	vecDaisy3Smil2HeadCustomTestXmlLang;

	//Body
	int				intCountImg;
	int				intCountText;
	int				intCountAudio;
	bool			boolNewImg;
	bool			boolNewText;
	bool			boolNewAudio;
	char			a[5];			//use to convert int to string
	string			strDaisy3Smil2BodySeqTempId;
	string			strDaisy3Smil2BodySeqTempClass;	
	string			strDaisy3Smil2BodySeqTempCustomTest;
	string			strDaisy3Smil2BodySeqTempDur;
	string			strDaisy3Smil2BodySeqTempXmlLang;
	string			strDaisy3Smil2BodySeqTempEnd;
	string			strDaisy3Smil2BodySeqTempFill;
	int				intDaisy3Smil2BodySeqTempLevel;
	
	string			strDaisy3Smil2BodyParTempId;
	string			strDaisy3Smil2BodyParTempClass;
	string			strDaisy3Smil2BodyParTempCustomTest;
	string			strDaisy3Smil2BodyParTempXmlLang;
	int				intDaisy3Smil2BodyParTempLevel;

	string			strDaisy3Smil2BodyAnchorTempId;
	string			strDaisy3Smil2BodyAnchorTempClass;
	string			strDaisy3Smil2BodyAnchorTempTitle;
	string			strDaisy3Smil2BodyAnchorTempXmlLang;
	string			strDaisy3Smil2BodyAnchorTempHref;
	string			strDaisy3Smil2BodyAnchorTempExternal;
	
	string			strDaisy3Smil2BodyImgTempId;
	string			strDaisy3Smil2BodyImgTempRegion;
	string			strDaisy3Smil2BodyImgTempSrc;
	string			strDaisy3Smil2BodyImgTempType;
	string			strDaisy3Smil2BodyImgTempXmlLang;
	
	string			strDaisy3Smil2BodyTextTempId;
	string			strDaisy3Smil2BodyTextTempSrc;
	string			strDaisy3Smil2BodyTextTempType;
	string			strDaisy3Smil2BodyTextTempRegion;
	string			strDaisy3Smil2BodyTextTempXmlLang;
	
	string			strDaisy3Smil2BodyAudioTempId;
	string			strDaisy3Smil2BodyAudioTempSrc;
	string			strDaisy3Smil2BodyAudioTempType;
	string			strDaisy3Smil2BodyAudioTempClipBegin;
	string			strDaisy3Smil2BodyAudioTempClipEnd;
	string			strDaisy3Smil2BodyAudioTempRegion;
	string			strDaisy3Smil2BodyAudioTempXmlLang;

	vector<string>	vecDaisy3Smil2BodySeqId;
	vector<string>	vecDaisy3Smil2BodySeqClass;	
	vector<string>	vecDaisy3Smil2BodySeqCustomTest;
	vector<string>	vecDaisy3Smil2BodySeqDur;
	vector<string>	vecDaisy3Smil2BodySeqXmlLang;
	vector<string>	vecDaisy3Smil2BodySeqEnd;
	vector<string>	vecDaisy3Smil2BodySeqFill;
	vector<string>	vecDaisy3Smil2BodySeqLevel;

	vector<string>	vecDaisy3Smil2BodyParId;
	vector<string>	vecDaisy3Smil2BodyParClass;
	vector<string>	vecDaisy3Smil2BodyParCustomTest;
	vector<string>	vecDaisy3Smil2BodyParXmlLang;
	vector<string>	vecDaisy3Smil2BodyParLevel;

	vector<string>	vecDaisy3Smil2BodyAnchorId;
	vector<string>	vecDaisy3Smil2BodyAnchorClass;
	vector<string>	vecDaisy3Smil2BodyAnchorTitle;
	vector<string>	vecDaisy3Smil2BodyAnchorXmlLang;
	vector<string>	vecDaisy3Smil2BodyAnchorHref;
	vector<string>	vecDaisy3Smil2BodyAnchorExternal;

	vector<string>	vecDaisy3Smil2BodyImgId;
	vector<string>	vecDaisy3Smil2BodyImgRegion;
	vector<string>	vecDaisy3Smil2BodyImgSrc;
	vector<string>	vecDaisy3Smil2BodyImgType;
	vector<string>	vecDaisy3Smil2BodyImgXmlLang;
	
	vector<string>	vecDaisy3Smil2BodyTextId;
	vector<string>	vecDaisy3Smil2BodyTextSrcFile;
	vector<string>	vecDaisy3Smil2BodyTextSrcId;
	vector<string>	vecDaisy3Smil2BodyTextType;
	vector<string>	vecDaisy3Smil2BodyTextRegion;
	vector<string>	vecDaisy3Smil2BodyTextXmlLang;
	vector<string>	vecDaisy3Smil2BodyTextContent;

	vector<string>	vecDaisy3Smil2BodyAudioId;
	vector<string>	vecDaisy3Smil2BodyAudioSrc;
	vector<string>	vecDaisy3Smil2BodyAudioType;
	vector<string>	vecDaisy3Smil2BodyAudioClipBegin;
	vector<string>	vecDaisy3Smil2BodyAudioClipEnd;
	vector<string>	vecDaisy3Smil2BodyAudioRegion;
	vector<string>	vecDaisy3Smil2BodyAudioXmlLang;
};

#endif