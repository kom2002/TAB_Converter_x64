#ifndef LOADNCCHANDLE_H
#define LOADNCCHANDLE_H

#include "AllHandle.h"

class LoadNccHandle : public DefaultHandler
{
public:
    LoadNccHandle();
    ~LoadNccHandle();

	void            clearVector(void);
	vector<string>	getVecNccType(void);
	vector<string>	getVecNccClass(void);
	vector<string>	getVecNccId(void);
	vector<string>	getVecNccLinkFile(void);
	vector<string>	getVecNccLinkId(void);
	vector<string>	getVecNccName(void);
	vector<string>	getVecNccMetaName(void);
	vector<string>	getVecNccMetaContent(void);
	vector<string>	getVecNccMetaScheme(void);
	string          getStrNccMetaHttpEquivName(void);
	string          getStrNccMetaHttpEquivContent(void);
	string		    getStrNccTitle(void);

private:
	//Pre-definition function.
    void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const Attributes& attrs);
    //void characters(const XMLCh* const chars, const unsigned int length);
	void characters(const XMLCh* const chars, const XMLSize_t length);
	

    //void fatalError(const SAXParseException& exc);
	//void ignorableWhitespace(const XMLCh* const chars, const unsigned int length);
	//void resetDocument();
	//void warning(const SAXParseException& exc);
	//void error(const SAXParseException& exc);
	//void resetErrors();

	//Variable
	vector<string> vecNccType;
	vector<string> vecNccClass;
	vector<string> vecNccId;
	vector<string> vecNccLinkFile;
	vector<string> vecNccLinkId;
	vector<string> vecNccName;
	vector<string> vecNccMetaName;
	vector<string> vecNccMetaContent;
	vector<string> vecNccMetaScheme;
	string         strNccMetaHttpEquivName;
	string         strNccMetaHttpEquivContent;
	string		   strNccTitle;
	bool		   boolWaitForName;
	
	//Function
	string		   removeWhitespace(const string& str);
};
#endif