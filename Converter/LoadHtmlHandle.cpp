#include "LoadHtmlHandle.h"

//Parser Html file for DAISY 2.00 and 2.02 Standards

LoadHtmlHandle::LoadHtmlHandle()
{
	LoadHtmlHandle::clearVector();
}

LoadHtmlHandle::~LoadHtmlHandle()
{
}

//void LoadHtmlHandle::characters(const XMLCh*   const chars
//							   ,const unsigned int   length)
void LoadHtmlHandle::characters(const XMLCh*   const chars
							   ,const XMLSize_t   length)
{
	tempChar =  "";
	if (boolIsBr && boolJustFound)
	{
		tempChar = XMLString::transcode(chars);	
		if (!removeWhitespace(tempChar).empty()) 
		{
			vecStringResult[intCurrentSmilId] = vecStringResult[intCurrentSmilId].append(" ").append(tempChar);
			boolJustFound   = true;
		}
	}
	boolIsBr = false;

	if (fFoundString) 
	{			
		tempChar = XMLString::transcode(chars);	
		if (!removeWhitespace(tempChar).empty()) 
		{
			vecStringResult[intCurrentSmilId] = tempChar;
			fFoundString	= false;
			boolJustFound   = true;
		}
	}
	else
	{
		boolJustFound   = false;
	}

	string message3 = removeWhitespace(XMLString::transcode(chars));
	if (!message3.empty())
	{
		message3 = XMLString::transcode(chars);
		if (strHtmlTitle.empty()) 
		{
			//Put NCC Title.  //be careful title is empty.
			strHtmlTitle = message3;
		}
	}
}

void LoadHtmlHandle::startElement(const XMLCh* const uri
                                 ,const XMLCh* const localname
                                 ,const XMLCh* const qname
                                 ,const Attributes&  att)
{
	char* message1 = XMLString::transcode(qname);
	char* message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));	
	
	if (!strcmp(message1,"br"))		//Check BR Tag (may be)
	{
		fFoundString = false;
		boolIsBr = true;
	}
	//else_if for check Null Tag (most)
	else if (message2 != NULL)		
	{
		fFoundString = cmpStringByVector(message2);
		boolIsBr = false;
	}
	//else_if for Meta TAG
	else if (!strcmp(message1,"meta") || !strcmp(message1,"META") || !strcmp(message1,"Meta"))
	{
		if (att.getIndex(XMLString::transcode("name")) != -1 )
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("name")));
			vecHtmlMetaName.push_back(message2);
	
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("content")));
			vecHtmlMetaContent.push_back(message2);

			if (att.getIndex(XMLString::transcode("scheme")) != -1 )
			{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("scheme")));
				vecHtmlMetaScheme.push_back(message2);
			}
			else
			{
				vecHtmlMetaScheme.push_back("");
			}
		}
		else if (att.getIndex(XMLString::transcode("http-equiv")) != -1 )
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("http-equiv")));
			strHtmlMetaHttpEquivName    = message2;
	
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("content")));
			strHtmlMetaHttpEquivContent = message2;
		}
	}
	//else_if for Meta Title
	else if (!strcmp(message1,"title") || !strcmp(message1,"TITLE") || !strcmp(message1,"Title"))
	{
		strHtmlTitle = "";
	}
	//else_if for Link TAG
	else if (!strcmp(message1,"link") || !strcmp(message1,"LINK") || !strcmp(message1,"Link"))
	{
		if (att.getIndex(XMLString::transcode("rel")) != -1 )
		{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("rel")));
				strHtmlLinkRel = message2;
		}

		if (att.getIndex(XMLString::transcode("href")) != -1 )
		{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("href")));
				strHtmlLinkHref = message2;
		}

		if (att.getIndex(XMLString::transcode("type")) != -1 )
		{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("type")));
				strHtmlLinkType = message2;
		}

		if (att.getIndex(XMLString::transcode("title")) != -1 )
		{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("title")));
				strHtmlLinkTitle = message2;
		}
	}
	XMLString::release(&message2);		
	XMLString::release(&message1);
}

//void LoadHtmlHandle::fatalError(const SAXParseException& e){}
//void LoadHtmlHandle::ignorableWhitespace(const XMLCh* const chars,const unsigned int length){}
//void LoadHtmlHandle::resetDocument(){}
//void LoadHtmlHandle::error(const SAXParseException& e){}
//void LoadHtmlHandle::warning(const SAXParseException& e){}
//void LoadHtmlHandle::resetErrors(){}

vector<string> LoadHtmlHandle::GetContentResult(void)				{return vecStringResult;}
vector<string> LoadHtmlHandle::getVecHtmlMetaName(void)				{return vecHtmlMetaName;}
vector<string> LoadHtmlHandle::getVecHtmlMetaContent(void)			{return vecHtmlMetaContent;}
vector<string> LoadHtmlHandle::getVecHtmlMetaScheme(void)			{return vecHtmlMetaScheme;}
string         LoadHtmlHandle::getStrHtmlMetaHttpEquivName(void)	{return strHtmlMetaHttpEquivName;}
string         LoadHtmlHandle::getStrHtmlMetaHttpEquivContent(void)	{return strHtmlMetaHttpEquivContent;}
string		   LoadHtmlHandle::getStrHtmlTitle(void)				{return strHtmlTitle;}
string		   LoadHtmlHandle::getStrHtmlLinkRel(void)				{return strHtmlLinkRel;}
string		   LoadHtmlHandle::getStrHtmlLinkHref(void)				{return strHtmlLinkHref;}
string		   LoadHtmlHandle::getStrHtmlLinkType(void)				{return strHtmlLinkType;}
string		   LoadHtmlHandle::getStrHtmlLinkTitle(void)			{return strHtmlLinkTitle;}

void LoadHtmlHandle::putVectorIdForGetString(vector<string>	_vecIdForGetString, vector<string> _vecStringResult)
{
	vecIdForGetString = _vecIdForGetString;
	vecStringResult   = _vecStringResult;
}



bool LoadHtmlHandle::cmpStringByVector(char* chrForCompare)
{
	//Loop for find Html/Audio file in Smil file.
	for (intCurrentSmilId=0; intCurrentSmilId < vecIdForGetString.size(); intCurrentSmilId++)
	{
		//For Text only 
		if (!vecStringResult[intCurrentSmilId].compare("WaItInG"))			
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

string LoadHtmlHandle::removeWhitespace(const string& str)
{
    string s;
    for (unsigned int i = 0; i < str.length(); ++i)
            if ((unsigned char)str[i] >= (unsigned char)' ')
                s += str[i];
    return s;
}


void LoadHtmlHandle::clearVector(void)
{
	fFoundString		= false;
	boolIsBr			= false;
	intCurrentSmilId	= 0;
	tempChar.clear();
	
	vecIdForGetString.clear();
	vecStringResult.clear();
	vecHtmlMetaName.clear();
	vecHtmlMetaContent.clear();
	vecHtmlMetaScheme.clear();
	strHtmlMetaHttpEquivName.clear();
	strHtmlMetaHttpEquivContent.clear();
	strHtmlTitle.clear();
	strHtmlLinkRel.clear();
	strHtmlLinkHref.clear();
	strHtmlLinkType.clear();
	strHtmlLinkTitle.clear();
}