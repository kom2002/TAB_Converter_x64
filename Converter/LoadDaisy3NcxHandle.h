#ifndef LOADDAISY3NCXHANDLE_H
#define LOADDAISY3NCXHANDLE_H

#include "AllHandle.h"

class LoadDaisy3NcxHandle : public DefaultHandler
{
public:
    LoadDaisy3NcxHandle();
    ~LoadDaisy3NcxHandle();

	void            clearVector(void);
	string			removeWhitespace(const string& str);
	//Header
	vector<string>	getVecDaisy3NcxCustomTestId(void);
	vector<string>	getVecDaisy3NcxCustomTestDefaultState(void);
	vector<string>	getVecDaisy3NcxCustomTestOverride(void);
	vector<string>	getVecDaisy3NcxCustomTestBookStruct(void);
	vector<string>	getVecDaisy3NcxMetaName(void);
	vector<string>	getVecDaisy3NcxMetaContent(void);
	vector<string>	getVecDaisy3NcxMetaScheme(void);

	string		    getStrDaisy3NcxVersion(void);	
	string		    getStrDaisy3NcxXmlLanguage(void);
	string		    getStrDaisy3NcxXmlNs(void);

	string		    getStrDaisy3NcxDocTitleText(void);	
	string		    getStrDaisy3NcxDocTitleAudioSrc(void);	
	string		    getStrDaisy3NcxDocTitleAudioBegin(void);	
	string		    getStrDaisy3NcxDocTitleAudioEnd(void);	
	string		    getStrDaisy3NcxDocTitleImageSrc(void);

	string		    getStrDaisy3NcxDocAuthorText(void);	
	string		    getStrDaisy3NcxDocAuthorAudioSrc(void);	
	string		    getStrDaisy3NcxDocAuthorAudioBegin(void);	
	string		    getStrDaisy3NcxDocAuthorAudioEnd(void);	
	string		    getStrDaisy3NcxDocAuthorImageSrc(void);	

	//Body
	vector<string>	getVecDaisy3NcxBodyKind(void);					//navPoint or pageTarget or navTarget.
	vector<string>	getVecDaisy3NcxBodyType(void);					//H1, H2, H3 ,H4 ,H5 format.
	vector<string>	getVecDaisy3NcxBodyClass(void);
	vector<string>	getVecDaisy3NcxBodyId(void);
	vector<string>	getVecDaisy3NcxBodyLinkFile(void);				//came from Content src
	vector<string>	getVecDaisy3NcxBodyLinkId(void);				//came from Content src
	vector<string>	getVecDaisy3NcxBodyName(void);					//came from NavLabel text 
	vector<string>	getVecDaisy3NcxBodyPlayOrder(void);
	vector<string>	getVecDaisy3NcxBodyAudioSrc(void);
	vector<string>	getVecDaisy3NcxBodyAudioBegin(void);
	vector<string>	getVecDaisy3NcxBodyAudioEnd(void);
	vector<string>	getVecDaisy3NcxBodyImageSrc(void);

	//Part (Section)
	vector<string>	getVecDaisy3NcxPartKind(void);						//navMap, PageList, navList
	vector<string>	getVecDaisy3NcxPartId(void);
	vector<string>	getVecDaisy3NcxPartClass(void);
	vector<string>	getVecDaisy3NcxPartNavInfoText(void);
	vector<string>	getVecDaisy3NcxPartNavInfoAudioSrc(void);
	vector<string>	getVecDaisy3NcxPartNavInfoAudioBegin(void);
	vector<string>	getVecDaisy3NcxPartNavInfoAudioEnd(void);
	vector<string>	getVecDaisy3NcxPartNavInfoImageSrc(void);
	vector<string>	getVecDaisy3NcxPartNavLabelText(void);
	vector<string>	getVecDaisy3NcxPartNavLabelAudioSrc(void);
	vector<string>	getVecDaisy3NcxPartNavLabelAudioBegin(void);
	vector<string>	getVecDaisy3NcxPartNavLabelAudioEnd(void);
	vector<string>	getVecDaisy3NcxPartNavLabelImageSrc(void);
	vector<string>	getVecDaisy3NcxPartPositionInBody(void);

private:
	//Pre-definition function.
    void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const Attributes& attrs);
    //void characters  (const XMLCh* const chars, const unsigned int length);
	void characters(const XMLCh* const chars, const XMLSize_t length);
    void endElement  (const XMLCh *const uri, const XMLCh *const localname, const XMLCh *const qName);

	//void fatalError(const SAXParseException& exc);
	//void ignorableWhitespace(const XMLCh* const chars, const unsigned int length);
	//void resetDocument();
	//void warning(const SAXParseException& exc);
	//void error(const SAXParseException& exc);
	//void resetErrors();
	
	//docTitle
	bool boolWaitDocTitleText;
	bool boolWaitDocTitleAudio;
	bool boolWaitDocTitleImage;

	//docAuthor
	bool boolWaitDocAuthorText;
	bool boolWaitDocAuthorAudio;
	bool boolWaitDocAuthorImage;

	//navLabel (in Element)
	bool boolWaitNavLabelText;
	bool boolWaitNavLabelAudio;
	bool boolWaitNavLabelImage;
	bool boolWaitNavLabelContent;

	//navInfo and navLabel (in head of Part)
	bool boolWaitHeadNavInfoText;
	bool boolWaitHeadNavInfoAudio;
	bool boolWaitHeadNavInfoImage;
	bool boolWaitHeadNavLabelText;
	bool boolWaitHeadNavLabelAudio;
	bool boolWaitHeadNavLabelImage;

	bool boolWaitForAllCharacters;
	
	int  intNavMapHeaderStatus;
	char a[5];						//use to convert int to string

	//root
	string		    strDaisy3NcxVersion;
	string		    strDaisy3NcxXmlNs;
	string		    strDaisy3NcxXmlLanguage;
	
	//Header
	vector<string>	vecDaisy3NcxCustomTestId;
	vector<string>	vecDaisy3NcxCustomTestDefaultState;
	vector<string>	vecDaisy3NcxCustomTestOverride;
	vector<string>	vecDaisy3NcxCustomTestBookStruct;
	vector<string>	vecDaisy3NcxMetaName;
	vector<string>	vecDaisy3NcxMetaContent;
	vector<string>	vecDaisy3NcxMetaScheme;

	//docTitle
	string		    strDaisy3NcxDocTitleText;
	string		    strDaisy3NcxDocTitleAudioSrc;
	string		    strDaisy3NcxDocTitleAudioBegin;
	string		    strDaisy3NcxDocTitleAudioEnd;
	string		    strDaisy3NcxDocTitleImageSrc;
	
	//docAuthor
	string		    strDaisy3NcxDocAuthorText;
	string		    strDaisy3NcxDocAuthorAudioSrc;
	string		    strDaisy3NcxDocAuthorAudioBegin;
	string		    strDaisy3NcxDocAuthorAudioEnd;
	string		    strDaisy3NcxDocAuthorImageSrc;

	//Body
	vector<string>	vecDaisy3NcxBodyKind;		//navPoint or pageTarget or navTarget.	//startElement checking
	vector<string>	vecDaisy3NcxBodyType;		//H1, H2, H3 ,H4 ,H5 format.			//startElement checking
	vector<string>	vecDaisy3NcxBodyClass;												//startElement checking
	vector<string>	vecDaisy3NcxBodyId;													//startElement checking
	vector<string>	vecDaisy3NcxBodyLinkFile;											//endElement Checking
	vector<string>	vecDaisy3NcxBodyLinkId;												//endElement Checking
	vector<string>	vecDaisy3NcxBodyName;		//text									//endElement Checking
	vector<string>	vecDaisy3NcxBodyPlayOrder;											//startElement checking
	vector<string>	vecDaisy3NcxBodyAudioSrc;											//endElement Checking
	vector<string>	vecDaisy3NcxBodyAudioBegin;											//endElement Checking
	vector<string>	vecDaisy3NcxBodyAudioEnd;											//endElement Checking
	vector<string>	vecDaisy3NcxBodyImageSrc;											//endElement Checking

	//Part (Section)
	vector<string>	vecDaisy3NcxPartKind;   //navMap, PageList, navList				//startElement checking
	vector<string>	vecDaisy3NcxPartId;												//startElement checking
	vector<string>	vecDaisy3NcxPartClass;											//startElement checking
	vector<string>	vecDaisy3NcxPartPositionInBody;									//startElement checking
	vector<string>	vecDaisy3NcxPartNavInfoText;									//endElement Checking
	vector<string>	vecDaisy3NcxPartNavInfoAudioSrc;								//endElement Checking
	vector<string>	vecDaisy3NcxPartNavInfoAudioBegin;								//endElement Checking
	vector<string>	vecDaisy3NcxPartNavInfoAudioEnd;								//endElement Checking
	vector<string>	vecDaisy3NcxPartNavInfoImageSrc;								//endElement Checking
	vector<string>	vecDaisy3NcxPartNavLabelText;									//endElement Checking
	vector<string>	vecDaisy3NcxPartNavLabelAudioSrc;								//endElement Checking
	vector<string>	vecDaisy3NcxPartNavLabelAudioBegin;								//endElement Checking
	vector<string>	vecDaisy3NcxPartNavLabelAudioEnd;								//endElement Checking
	vector<string>	vecDaisy3NcxPartNavLabelImageSrc;								//endElement Checking

};
#endif