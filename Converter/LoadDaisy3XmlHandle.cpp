#include "LoadDaisy3XmlHandle.h"

//Parser Xml file for ANSI/NISO Z39.86 Standards

LoadDaisy3XmlHandle::LoadDaisy3XmlHandle()
{
	LoadDaisy3XmlHandle::clearVector();
}

LoadDaisy3XmlHandle::~LoadDaisy3XmlHandle()
{
}

void LoadDaisy3XmlHandle::startElement(const XMLCh* const uri
                                 ,const XMLCh* const localname
                                 ,const XMLCh* const qname
                                 ,const Attributes&  att)
{
	char* message1 = XMLString::transcode(att.getValue(XMLString::transcode("id")));	

	//if for checks null tag. (most found!)
	if (message1 != NULL)		
	{
		fFoundString = cmpStringByVector(message1);
	}

	XMLString::release(&message1);		
}

//void LoadDaisy3XmlHandle::characters(const XMLCh*   const chars
//							        ,const unsigned int   length)
void LoadDaisy3XmlHandle::characters(const     XMLCh* const    chars
                                   , const		XMLSize_t       length)
{
	tempChar =  "";

	if (fFoundString) 
	{			
		tempChar = XMLString::transcode(chars);	
		if (!removeWhitespace(tempChar).empty()) 
		{
			vecStringResult[intCurrentSmilId] = tempChar;
			fFoundString	= false;
		}
	}
}

//void LoadDaisy3XmlHandle::fatalError(const SAXParseException& e){}
//void LoadDaisy3XmlHandle::ignorableWhitespace(const XMLCh* const chars,const unsigned int length){}
//void LoadDaisy3XmlHandle::resetDocument(){}
//void LoadDaisy3XmlHandle::error(const SAXParseException& e){}
//void LoadDaisy3XmlHandle::warning(const SAXParseException& e){}
//void LoadDaisy3XmlHandle::resetErrors(){}

//vector<string> LoadDaisy3XmlHandle::getVecDaisy3XmlMetaName(void)				{return vecDaisy3XmlMetaName;}
//vector<string> LoadDaisy3XmlHandle::getVecDaisy3XmlMetaContent(void)			{return vecDaisy3XmlMetaContent;}
//vector<string> LoadDaisy3XmlHandle::getVecDaisy3XmlMetaScheme(void)			{return vecDaisy3XmlMetaScheme;}
//string         LoadDaisy3XmlHandle::getStrDaisy3XmlMetaHttpEquivName(void)	{return strDaisy3XmlMetaHttpEquivName;}
//string         LoadDaisy3XmlHandle::getStrDaisy3XmlMetaHttpEquivContent(void)	{return strDaisy3XmlMetaHttpEquivContent;}
//string		 LoadDaisy3XmlHandle::getStrDaisy3XmlTitle(void)				{return strDaisy3XmlTitle;}
//string		 LoadDaisy3XmlHandle::getStrDaisy3XmlLinkRel(void)				{return strDaisy3XmlLinkRel;}
//string		 LoadDaisy3XmlHandle::getStrDaisy3XmlLinkHref(void)				{return strDaisy3XmlLinkHref;}
//string		 LoadDaisy3XmlHandle::getStrDaisy3XmlLinkType(void)				{return strDaisy3XmlLinkType;}
//string		 LoadDaisy3XmlHandle::getStrDaisy3XmlLinkTitle(void)			{return strDaisy3XmlLinkTitle;}

void LoadDaisy3XmlHandle::putVectorIdForGetString(vector<string>	_vecIdForGetString, vector<string> _vecStringResult)
{
	vecIdForGetString = _vecIdForGetString;
	vecStringResult   = _vecStringResult;
}

vector<string> LoadDaisy3XmlHandle::GetContentResult(void)
{
	return vecStringResult;
}


bool LoadDaisy3XmlHandle::cmpStringByVector(char* chrForCompare)
{
	//Loop for find XML/Audio file in Smil file.
	for (intCurrentSmilId=0; intCurrentSmilId < vecIdForGetString.size(); intCurrentSmilId++)
	{
		//For Text only 
		if (!vecStringResult[intCurrentSmilId].compare("EmPtY"))			
		{
			if (!strcmp(vecIdForGetString[intCurrentSmilId].data(),chrForCompare))
			{
				//Id matching.
				return true;
			}
		}
	}
	return false;
}

string LoadDaisy3XmlHandle::removeWhitespace(const string& str)
{
    string s;
    for (unsigned int i = 0; i < str.length(); ++i)
            if ((unsigned char)str[i] >= (unsigned char)' ')
                s += str[i];
    return s;
}


void LoadDaisy3XmlHandle::clearVector(void)
{
	fFoundString		= false;
	intCurrentSmilId	= 0;
	tempChar.clear();
	
	vecIdForGetString.clear();
	vecStringResult.clear();
}