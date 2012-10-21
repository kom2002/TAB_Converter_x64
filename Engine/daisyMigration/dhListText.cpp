#include "dhListText.h"

// parse SMIL file
dhListText::dhListText()
{
//	cout<<"CONSTRUCTOR : dhListText"<<endl;
}

dhListText::~dhListText()
{
//	cout<<"DESTRUCTOR : dhListText"<<endl;
}

void dhListText::startElement(const   XMLCh*      const    uri,
	                          const   XMLCh*      const    localname,
	                          const   XMLCh*      const    qname,
   	                          const   Attributes&          att)
{
	string message1 = XMLString::transcode(qname);
	if  (!message1.compare("text") || !message1.compare("TEXT"))
	{
		string message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		tempVecTextIDList.push_back(message2);

		message2 = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		tempVecTextFileList.push_back(message2);
	}
}
	
void dhListText::fatalError(const SAXParseException& exception)
{
	string message = XMLString::transcode(exception.getMessage());
//	cout << "Fatal Error: " 		 << message
  //       << " at line: "     		 << exception.getLineNumber()
	//	 << endl;
}

vector<string> dhListText::getVecTextFileList(void)
{
	return tempVecTextFileList;
}

vector<string> dhListText::getVecTextIDList(void)
{
	return tempVecTextIDList;
}

void dhListText::clearTempVector(void)
{
	tempVecTextIDList.clear();
	tempVecTextFileList.clear();
}