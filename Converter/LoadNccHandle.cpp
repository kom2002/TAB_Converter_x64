#include "LoadNccHandle.h"

//Parser NCC file for DAISY 2.00 and 2.02 Standards

LoadNccHandle::LoadNccHandle() //: fElementCount(0), fAttrCount(0), fCharacterCount(0), fSpaceCount(0), fSawErrors(false)
{
	cout << "Completed :: Create LoadNccHandle." << endl;
	LoadNccHandle::clearVector();
}

LoadNccHandle::~LoadNccHandle()
{
	cout << "Completed :: Destroy LoadNccHandle." << endl;
}

void LoadNccHandle::startElement(const XMLCh* const uri
                                ,const XMLCh* const localname
                                ,const XMLCh* const qname
                                ,const Attributes& att)
{
	cout << "Completed :: Begin StartElement. " << XMLString::transcode(localname) << "  "  << endl;

	char* message1 = XMLString::transcode(localname);
	char* message2;
	
	if  (!strcmp(message1,"H1")  || !strcmp(message1,"h1")
	   ||!strcmp(message1,"H2")  || !strcmp(message1,"h2")
	   ||!strcmp(message1,"H3")  || !strcmp(message1,"h3")
	   ||!strcmp(message1,"H4")  || !strcmp(message1,"h4")
	   ||!strcmp(message1,"H5")  || !strcmp(message1,"h5")
	   ||!strcmp(message1,"SPAN")|| !strcmp(message1,"span") || !strcmp(message1,"Span")
	   ||!strcmp(message1,"DIV") || !strcmp(message1,"div")  || !strcmp(message1,"Div"))
	{
		//Put NCC Type.
		vecNccType.push_back(message1);
		boolWaitForName = true;

		try
		{
			//Put NCC Class name.
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("class")));
			if (message2 != NULL)
				vecNccClass.push_back(message2);
			else
				vecNccClass.push_back("EmPtY");
		}
		catch (...)
		{
			//Put NCC Class name empty.
			vecNccClass.push_back("EmPtY");
		}
		
		try
		{
			//Put NCC ID
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));
			if (message2 != NULL)
				vecNccId.push_back(message2);
			else
				vecNccClass.push_back("EmPtY");
		}
		catch (...)
		{
			//Put NCC ID empty.
			vecNccId.push_back("EmPtY");
		}
	}

	else if (!strcmp(message1,"A") || !strcmp(message1,"a"))
	{
		//Put NCC Link to SMIL file.
		message2 = XMLString::transcode(att.getValue(XMLString::transcode("href")));
		//seperate FileName#id
		string strTempInput = message2;
		vecNccLinkFile.push_back(strTempInput.substr(0,strTempInput.find("#")));
		vecNccLinkId.push_back(strTempInput.substr(strTempInput.find("#")+1));
	}

	else if (!strcmp(message1,"meta") || !strcmp(message1,"META") || !strcmp(message1,"Meta"))
	{
		if (att.getIndex(XMLString::transcode("name")) != -1 )
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("name")));
			vecNccMetaName.push_back(message2);
	
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("content")));
			vecNccMetaContent.push_back(message2);

			if (att.getIndex(XMLString::transcode("scheme")) != -1 )
			{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("scheme")));
				vecNccMetaScheme.push_back(message2);
			}
			else
			{
				vecNccMetaScheme.push_back("");
			}
		}
		else if (att.getIndex(XMLString::transcode("http-equiv")) != -1 )
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("http-equiv")));
			strNccMetaHttpEquivName    = message2;
	
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("content")));
			strNccMetaHttpEquivContent = message2;
		}
	}

	else if (!strcmp(message1,"title") || !strcmp(message1,"TITLE") || !strcmp(message1,"Title"))
	{
		strNccTitle = "";
	}
}

void LoadNccHandle::characters(const XMLCh*   const chars
							  ,const XMLSize_t  length)
							 // ,const unsigned int   length)
{
	string message3 = removeWhitespace(XMLString::transcode(chars));
	
	if (!message3.empty())
	{
		message3 = XMLString::transcode(chars);
		if (strNccTitle.empty()) 
		{
			//Put NCC Title.  //be careful title is empty.
			strNccTitle = message3;
		}
		else
		{
			if (boolWaitForName == true)
			{
				//Put NCC char.
				vecNccName.push_back(message3);
				boolWaitForName = false;
			}
		}
	}
}

string LoadNccHandle::removeWhitespace(const string& str)
{
    string s;
    for (unsigned int i = 0; i < str.length(); ++i)
		if ((unsigned char)str[i] >= (unsigned char)' ')
			s += str[i];
    return s;
}

vector<string> LoadNccHandle::getVecNccType(void)					{return vecNccType;}
vector<string> LoadNccHandle::getVecNccClass(void)					{return vecNccClass;}
vector<string> LoadNccHandle::getVecNccId(void)						{return vecNccId;}
vector<string> LoadNccHandle::getVecNccLinkFile(void)				{return vecNccLinkFile;}
vector<string> LoadNccHandle::getVecNccLinkId(void)					{return vecNccLinkId;}
vector<string> LoadNccHandle::getVecNccName(void)					{return vecNccName;}
vector<string> LoadNccHandle::getVecNccMetaName(void)				{return vecNccMetaName;}
vector<string> LoadNccHandle::getVecNccMetaContent(void)			{return vecNccMetaContent;}
vector<string> LoadNccHandle::getVecNccMetaScheme(void)				{return vecNccMetaScheme;}
string         LoadNccHandle::getStrNccMetaHttpEquivName(void)		{return strNccMetaHttpEquivName;}
string         LoadNccHandle::getStrNccMetaHttpEquivContent(void)	{return strNccMetaHttpEquivContent;}
string		   LoadNccHandle::getStrNccTitle(void)					{return strNccTitle;}

void LoadNccHandle::clearVector(void)
{
	vecNccType.clear();
	vecNccClass.clear();
	vecNccId.clear();
	vecNccLinkFile.clear();
	vecNccLinkId.clear();
	vecNccName.clear();
	vecNccMetaName.clear();
	vecNccMetaContent.clear();
	vecNccMetaScheme.clear();
	strNccMetaHttpEquivName.clear();
	strNccMetaHttpEquivContent.clear();
	strNccTitle.clear();
	boolWaitForName = false;
}