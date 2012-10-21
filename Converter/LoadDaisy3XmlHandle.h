#ifndef LOADDAISY3XMLHANDLE_H
#define LOADDAISY3XMLHANDLE_H

#include "AllHandle.h"

class LoadDaisy3XmlHandle : public DefaultHandler
{
public:
	//constructor and deconstructor
    LoadDaisy3XmlHandle();
    ~LoadDaisy3XmlHandle();

	bool			cmpStringByVector			(char* chrForCompare);
	
	//Receive 2 vectors from SMIL Loading to find string in html
	//use id (of HTML) from _vecIdForGetString to find string and store in into _vecStringResult
	void			putVectorIdForGetString		(vector<string>	_vecIdForGetString
												,vector<string> _vecStringResult); 
	vector<string>	GetContentResult			(void);
	string			removeWhitespace			(const string& str);

	void            clearVector(void);

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
	bool			fFoundString;
	unsigned int	intCurrentSmilId;
	string			tempChar;

	vector<string> vecIdForGetString;
	vector<string> vecStringResult;
};

#endif