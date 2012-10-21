#ifndef LOADSMILHANDLE_H
#define LOADSMILHANDLE_H

#include "AllHandle.h"

class LoadSmilHandle : public DefaultHandler
{
public:
    LoadSmilHandle();
    ~LoadSmilHandle();

	void			clearVector(void);
	//Head
	vector<string>	getVecDaisy2Smil1MetaName(void);
	vector<string>	getVecDaisy2Smil1MetaContent(void);
	vector<string>	getVecDaisy2Smil1MetaScheme(void);
	//Body
	vector<string>	getVecDaisy2Smil1BodySeqId(void);
	vector<string>	getVecDaisy2Smil1BodySeqDur(void);
	vector<string>	getVecDaisy2Smil1BodySeqLevel(void);
	vector<string>	getVecDaisy2Smil1BodyParId(void);
	vector<string>	getVecDaisy2Smil1BodyParCustomTest(void); //use to store "system-requested" however we remove endsync
	vector<string>	getVecDaisy2Smil1BodyParLevel(void);
	vector<string>	getVecDaisy2Smil1BodyImgId(void);
	vector<string>	getVecDaisy2Smil1BodyImgSrc(void);
	vector<string>	getVecDaisy2Smil1BodyTextId(void);
	vector<string>	getVecDaisy2Smil1BodyTextSrcFile(void);
	vector<string>	getVecDaisy2Smil1BodyTextSrcId(void);
	vector<string>	getVecDaisy2Smil1BodyTextContent(void);		//use to wait xhtml parser for its data then it will be only empty data now.
	vector<string>	getVecDaisy2Smil1BodyAudioId(void);
	vector<string>	getVecDaisy2Smil1BodyAudioSrc(void);
	vector<string>	getVecDaisy2Smil1BodyAudioClipBegin(void);
	vector<string>	getVecDaisy2Smil1BodyAudioClipEnd(void);

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
	
	//Head
	vector<string>	vecDaisy2Smil1MetaName;
	vector<string>	vecDaisy2Smil1MetaContent;
	vector<string>	vecDaisy2Smil1MetaScheme;

	//Body
	int				i;				//for Counting and add generate ID in PAR 
	int				j;				//for Counting and add generate ID in SEQ
	char			a[5];			//use to convert int to string
		
	int				intCountImg;
	int				intCountText;
	int				intCountAudio;
	bool			boolNewImg;
	bool			boolNewText;
	bool			boolNewAudio;
	string			strDaisy2Smil1BodySeqTempId;
	string			strDaisy2Smil1BodySeqTempDur;
	int				intDaisy2Smil1BodySeqTempLevel;			//count in int    //store in string
	string			strDaisy2Smil1BodyParTempId;
	string			strDaisy2Smil1BodyParTempCustomTest;	
	int				intDaisy2Smil1BodyParTempLevel;			//count in int    //store in string
	string			strDaisy2Smil1BodyImgTempId;
	string			strDaisy2Smil1BodyImgTempSrc;
	string			strDaisy2Smil1BodyTextTempId;
	string			strDaisy2Smil1BodyTextTempSrc;
	vector<string>	vecDaisy2Smil1BodyAudioTempId;			//this is the temp the aupport multi audio in one par.
	vector<string>	vecDaisy2Smil1BodyAudioTempSrc;			//this is the temp the aupport multi audio in one par.
	vector<string>	vecDaisy2Smil1BodyAudioTempClipBegin;	//this is the temp the aupport multi audio in one par.
	vector<string>	vecDaisy2Smil1BodyAudioTempClipEnd;		//this is the temp the aupport multi audio in one par.
	vector<string>	vecDaisy2Smil1BodySeqId;
	vector<string>	vecDaisy2Smil1BodySeqDur;
	vector<string>	vecDaisy2Smil1BodySeqLevel;
	vector<string>	vecDaisy2Smil1BodyParId;
	vector<string>	vecDaisy2Smil1BodyParCustomTest; //use to store "system-requested" however we remove endsync
	vector<string>	vecDaisy2Smil1BodyParLevel;
	vector<string>	vecDaisy2Smil1BodyImgId;
	vector<string>	vecDaisy2Smil1BodyImgSrc;
	vector<string>	vecDaisy2Smil1BodyTextId;
	vector<string>	vecDaisy2Smil1BodyTextSrcFile;
	vector<string>	vecDaisy2Smil1BodyTextSrcId;
	vector<string>	vecDaisy2Smil1BodyTextContent;		//use to wait xhtml parser for its data then it will be only empty data now.
	vector<string>	vecDaisy2Smil1BodyAudioId;
	vector<string>	vecDaisy2Smil1BodyAudioSrc;
	vector<string>	vecDaisy2Smil1BodyAudioClipBegin;
	vector<string>	vecDaisy2Smil1BodyAudioClipEnd;
};

#endif