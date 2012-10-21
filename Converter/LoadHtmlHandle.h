#ifndef LOADHTMLHANDLE_H
#define LOADHTMLHANDLE_H

#include "AllHandle.h"

class LoadHtmlHandle : public DefaultHandler
{
public:
	//constructor and deconstructor
    LoadHtmlHandle();
    ~LoadHtmlHandle();

	bool			cmpStringByVector			(char* chrForCompare);

	//Receive 2 vectors from SMIL Loading to find string in HTML.
	//use id (of HTML) from _vecIdForGetString to find string and store in into _vecStringResult
	void			putVectorIdForGetString		(vector<string>	_vecIdForGetString
												,vector<string> _vecStringResult); 
	
	//Return _vecStringResult after collects after completed parser HTML.
	vector<string>	GetContentResult			(void);
	string			removeWhitespace			(const string& str);

	void            clearVector(void);
	vector<string>	getVecHtmlMetaName				(void);
	vector<string>	getVecHtmlMetaContent			(void);
	vector<string>	getVecHtmlMetaScheme			(void);
	string			getStrHtmlMetaHttpEquivName		(void);
	string			getStrHtmlMetaHttpEquivContent	(void);
	string			getStrHtmlTitle					(void);
	string			getStrHtmlLinkRel				(void);
	string			getStrHtmlLinkHref				(void);
	string			getStrHtmlLinkType				(void);
	string			getStrHtmlLinkTitle				(void);

private:
    void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const Attributes& attrs);
    //void characters(const XMLCh* const chars, const unsigned int length);
	void characters(const XMLCh* const chars, const XMLSize_t length);
    //void fatalError(const SAXParseException& exc);
	//void ignorableWhitespace(const XMLCh* const chars, const unsigned int length);
	//void resetDocument();
	//void warning(const SAXParseException& exc);
	//void error(const SAXParseException& exc);
	//void resetErrors();

	//local variable
	//bool			fWaitTagA;
	bool			boolJustFound;
	bool			fFoundString;
	bool			boolIsBr;
	unsigned int	intCurrentSmilId;
	//string		currentId;
	string			tempChar;

	vector<string> vecIdForGetString;
	vector<string> vecStringResult;
	
	vector<string> vecHtmlMetaName;
	vector<string> vecHtmlMetaContent;
	vector<string> vecHtmlMetaScheme;
	string         strHtmlMetaHttpEquivName;
	string         strHtmlMetaHttpEquivContent;
	string		   strHtmlTitle;
	string		   strHtmlLinkRel;
	string		   strHtmlLinkHref;
	string		   strHtmlLinkType;
	string		   strHtmlLinkTitle;
};

#endif