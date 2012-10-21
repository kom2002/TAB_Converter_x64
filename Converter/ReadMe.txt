bool fnWriteNcx(char* chrEnCoding)
{
	xercesc_2_6::DOMDocumentType   *pDoctype	= NULL;
	xercesc_2_6::DOMDocument	   *pDoc		= NULL;
	xercesc_2_6::DOMNode		   *pNode		= NULL;
	xercesc_2_6::DOMImplementation *pImplement  = NULL;
	xercesc_2_6::DOMWriter		   *pSerializer = NULL;
	xercesc_2_6::XMLFormatTarget   *pTarget	    = NULL;

	try
	{
		// initialize the XML library
		XMLPlatformUtils::Initialize();
	}
	catch(...)
	{
		cout << "Error to initialize the XML library for writing XML file." << endl;
	}

	// get a serializer, an instance of DOMWriter (the "LS" stands for load-save).
	pImplement  = DOMImplementationRegistry::getDOMImplementation(XercesString("LS"));
	pSerializer = ((DOMImplementationLS*)pImplement)->createDOMWriter();
	pTarget     = new StdOutFormatTarget();

	// set user specified end of line sequence and output encoding
	pSerializer->setNewLine(XercesString("\n"));
	pSerializer->setFeature(XMLUni::fgDOMWRTSplitCdataSections, false);
	pSerializer->setFeature(XMLUni::fgDOMWRTDiscardDefaultContent, false);
	pSerializer->setFeature(XMLUni::fgDOMWRTFormatPrettyPrint, true);
	pSerializer->setFeature(XMLUni::fgDOMWRTBOM, false);

	// create a document
	//pDoctype = pImplement->createDocumentType(XercesString("XML"), NULL, NULL);
	
	
	pDoctype = pImplement->createDocumentType(XercesString("ncx"), NULL, XercesString("ncx120.dtd"));
	pDoc     = pImplement->createDocument(L"http://www.loc.gov/nls/z3986/2004/ncx", L"ncx", pDoctype);
	pDoc->
	if (pDoc)
	{
	
		pDoc->setEncoding(XercesString(chrEnCoding));
		pDoc->setStandalone(true);
		pDoc->setVersion(XercesString("1.0"));

		DOMElement *pRoot = pDoc->getDocumentElement();

		//Creating the siblings of root
		DOMElement *pHead = pDoc->createElement(XercesString("HEAD"));
		pRoot->appendChild(pHead);

		DOMElement *pBody = pDoc->createElement(XercesString("BODY"));
		pRoot->appendChild(pBody);

		DOMElement *pTitle = pDoc->createElement(XercesString("TITLE"));
		pHead->appendChild(pTitle);

		DOMText *pHeading = pDoc->createTextNode(XercesString("Document Title"));
		pTitle->appendChild(pHeading);
    
		//Attaching texts to few siblings
		DOMElement *pParagraph = pDoc->createElement(XercesString("p"));
		pBody->appendChild(pParagraph);
		
		DOMText *pFragment;
		pFragment  =  pDoc->createTextNode(XercesString("¹ÒÂ¸¹Ò¤Á µÒÌÇÑ²¹ì"));
		pParagraph -> appendChild(pFragment);
		
		DOMText *pTextnode = pDoc->createTextNode(XercesString("some <random> text goes here"));
		pBody->appendChild(pTextnode);

		DOMElement *pTable = pDoc->createElement(XercesString("table"));
		pBody->appendChild(pTable);

		DOMAttr *pAnnotate = pDoc->createAttribute(XercesString("width"));
		pAnnotate->setValue(XercesString("100%"));
		pTable->setAttributeNode(pAnnotate);

		DOMElement* pRow = pDoc->createElement(XercesString("tr"));
		pTable->appendChild(pRow);

		DOMElement* pData = pDoc->createElement(XercesString("td"));
		pRow->appendChild(pData);

		DOMText* pContent = pDoc->createTextNode(XercesString("Highlights"));
		pData->appendChild(pContent);

		fflush(stdout);
		pSerializer->writeNode(pTarget, *pDoc);
/*
		// create a walker to visit all text nodes.
		DOMNode* pCurrent = NULL;
		DOMTreeWalker* walker = pDoc->createTreeWalker(pRoot, DOMNodeFilter::SHOW_TEXT, NULL, true);
		// use the tree walker to print out the text nodes.
		std::cout<< "walker:\n";
		for (pCurrent = walker->nextNode(); pCurrent != 0; pCurrent = walker->nextNode())
		{
			char *strValue = XMLString::transcode(pCurrent->getNodeValue());
			std::cout << strValue;
			XMLString::release(&strValue);
		}
		std::cout<< '\n';

		// create an iterator to visit all text nodes.
		DOMNodeIterator* iterator = pDoc->createNodeIterator(pRoot,DOMNodeFilter::SHOW_TEXT, NULL, true);
		
		// use the tree walker to print out the text nodes.
		std::cout<< "iterator:\n";
		for (pCurrent = iterator->nextNode(); pCurrent != 0; pCurrent = iterator->nextNode())
		{
			char *strValue = XMLString::transcode(pCurrent->getNodeValue());
			std::cout << strValue;
			XMLString::release(&strValue);
		}
		std::cout<< '\n';

		// use the cloneNode to add a duplicate row to the table.
		DOMNode* pClone = pRow->cloneNode(true);
		pTable->appendChild(pClone);
		
		// add another cloned row to the table.
		pClone = pRow->cloneNode(true);
		pTable->appendChild(pClone);
		
		// dump out the modified result.
		pSerializer->writeNode(pTarget, *pDoc);

		// make another clone of the first row but this time we'll 
		// use an iterator to locate the row's text node, replace 
		// the text, and then swap out the entire row in the table.
		pClone = pRow->cloneNode(true);
		DOMNodeIterator* pZap = pDoc->createNodeIterator(pClone, DOMNodeFilter::SHOW_TEXT, NULL, true);
		
		// I can get away with the typecast here since I know 
		// the SHOW_TEXT filtering will only return text nodes.
		DOMText* pChange = static_cast<DOMText*>(pZap->nextNode());
		pChange->setData(XercesString("replacement row"));
		pTable->replaceChild(pClone, pRow);
		
		// dump out the modified result.
		pSerializer->writeNode(pTarget, *pDoc);

		// blow away the first row altogether and remove 
		// the width attribute from the table.
		pTable->removeAttribute(XercesString("width"));
		pTable->removeChild(pClone);
		
		// dump out the modified result.
		pSerializer->writeNode(pTarget, *pDoc);

*/
		// construct the LocalFileFormatTarget
		XMLFormatTarget *myFormatTarget = new LocalFileFormatTarget("c:\\TestXmlFile.xml");

		// serialize a DOMNode to the local file "myXMLFile.xml"
		pSerializer->writeNode(myFormatTarget, *pDoc);

		// optionally, you can flush the buffer to ensure all contents are written
		myFormatTarget->flush();
		delete myFormatTarget; 

		std::cout<< "\n";

		//delete walker;
		//delete iterator;

  }
  //getchar();

  delete pTarget;
  delete pSerializer;
  delete pDoc;
  delete pDoctype;
 
  // terminate the XML library
  XMLPlatformUtils::Terminate();
  return true;
}

















////////////////////////////////////////////////////


	char* message1 = XMLString::transcode(qname);
	char* message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));	
	
	if (!strcmp(message1,"br"))		//Check BR Tag (may be) message1.compare("br")
	{
		fFoundString = false;
		boolIsBr = true;
	}
	else if (message2 != NULL)		//Check Null Tag (most)
	{
		fFoundString = cmpStringByVector(message2);
		boolIsBr = false;
	}

	XMLString::release(&message2);		
	XMLString::release(&message1);






bool LoadHtmlHandle::cmpStringByVector(char* chrForCompare)
{
	//Loop for find Html/Audio file in Smil file.
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





//Open file for replace [encoding="tis-620"] to [encoding="ISO-8859-11"]
	FILE* fileStream;
	if ((fileStream = fopen( "c:\\nuk.html", "r+" )) != NULL )
	{
		char   chrBuffer[128];
		fgets(chrBuffer, 125, fileStream);
		string strPhrase      = chrBuffer;
		string strSought      = "encoding=\"tis-620\"";
		string strReplacement = "encoding=\"iso-8859-11\"";
		int    intPosition    = strPhrase.find(strSought); 

		//Check existing of [encoding="tis-620"]
		if(intPosition!= string::npos)
		{
			//Replace [encoding="tis-620"]
			strPhrase.replace(intPosition, strSought.size(), strReplacement); 
			cout<<strPhrase<<endl;

			//Write back to file.
			rewind(fileStream);    //fseek(fileStream, 0L, SEEK_SET);


			fputs(strPhrase.c_str(), fileStream);

		}
	}
	fclose(fileStream);
	getchar();
	return 0;
	
	
	
	
	
	
	
	
	
	////////////////////////////////////////////////////
	
	
	
	
	
	
	
	
	
	ifstream myFileStream ("c:\\ncc_en.html");
	if (!myFileStream.is_open())
	{
		cout << "The file was opened." << endl;
		return 0;
	}
	stringstream ssInput;
	char buffer[2] = {0};
	while (myFileStream)
	{
		myFileStream.read(buffer, 1);
		ssInput << buffer;
	}
	
	//Replace encoding="tis-620"   =>  encoding="ISO-8859-11" 
	//string phrase      = ssInput.str();
	string sought      = "encoding=\"tis-620\"";
	string replacement = "encoding=\"iso-8859-11\"";
	findandreplace(ssInput, sought, replacement);
	
	//phrase.replace(phrase.find(sought), sought.size(), replacement);
	
	cout << ssInput << endl;



unsigned long duration;
const unsigned long startMillis = XMLPlatformUtils::getCurrentMillis();
doc = parser->parseURI(xmlFile);
const unsigned long endMillis = XMLPlatformUtils::getCurrentMillis();
duration = endMillis - startMillis;

<!=Thai (ISO-8859-11) -->
<mm:entityname type="both" platform="both" decode=34 encode="quot"/>
<mm:entityname type="both" platform="both" decode=38 encode="amp"/>
<mm:entityname type="both" platform="both" decode=60 encode="lt"/>
<mm:entityname type="both" platform="both" decode=62 encode="gt"/>
<mm:entityname type="decode" platform="Mac" decode=202 encode="nbsp"/>
<mm:entityname type="decode" platform="Win" decode=160 encode="nbsp"/>


// Class Xerces-C Template.

#include "LoadNccHandle.h"
#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax/SAXParseException.hpp>
#include <xercesc/sax/SAXException.hpp>

//Parser NCC file for DAISY 2.00 and 2.02 Standards

LoadNccHandle::LoadNccHandle() //: fElementCount(0), fAttrCount(0), fCharacterCount(0), fSpaceCount(0), fSawErrors(false)
{
}

LoadNccHandle::~LoadNccHandle()
{
}


void LoadNccHandle::startElement(const XMLCh* const uri
                                ,const XMLCh* const localname
                                ,const XMLCh* const qname
                                ,const Attributes& attrs)
{

}

void LoadNccHandle::characters(const XMLCh*   const chars
							  ,const unsigned int   length)
{
  
}

void LoadNccHandle::ignorableWhitespace(const XMLCh*   const chars
									   ,const unsigned int   length)
{

}

void LoadNccHandle::resetDocument()
{

}


void LoadNccHandle::error(const SAXParseException& e)
{

}

void LoadNccHandle::fatalError(const SAXParseException& e)
{

}

void LoadNccHandle::warning(const SAXParseException& e)
{

}

void LoadNccHandle::resetErrors()
{
  
}



/////////////////////////////////////////////////////////////////////





#ifndef LOADNCCHANDLE_H
#define LOADNCCHANDLE_H

#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>

XERCES_CPP_NAMESPACE_USE

class LoadNccHandle : public DefaultHandler
{
public:
    LoadNccHandle();
    ~LoadNccHandle();

    void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const Attributes& attrs);
    void characters(const XMLCh* const chars, const unsigned int length);
    void ignorableWhitespace(const XMLCh* const chars, const unsigned int length);
    void resetDocument();

	void warning(const SAXParseException& exc);
    void error(const SAXParseException& exc);
    void fatalError(const SAXParseException& exc);
    void resetErrors();


private:
};

#endif






//////////////////////////////






/*
	if  (!strcmp(message1,"h1")   || !strcmp(message1,"H1")
	||	 !strcmp(message1,"h2")   || !strcmp(message1,"H2")
	|| 	 !strcmp(message1,"h3")   || !strcmp(message1,"H3")
	||	 !strcmp(message1,"h4")   || !strcmp(message1,"H4")
	||	 !strcmp(message1,"h5")   || !strcmp(message1,"H5")
	||	 !strcmp(message1,"h6")   || !strcmp(message1,"H6")
	||   !strcmp(message1,"span") || !strcmp(message1,"SPAN"))
	{	//Have ID
		if (message2 != NULL)
		{	//Tag Hx
			fWaitTagA = cmpStringByVector(message2);
		}
	}

	else if (!strcmp(message1,"td") || !strcmp(message1,"TD")
	       || !strcmp(message1,"Td") || !strcmp(message1,"tD"))
	{	//Maybe not have ID.
		if (message2 != NULL)
		{	//Tag Td
			fWaitTagP = cmpStringByVector(message2);
		}
	}

	else if (!strcmp(message1,"li") || !strcmp(message1,"LI")
	       || !strcmp(message1,"Li") || !strcmp(message1,"lI"))
	{	//Maybe not have ID.
		if (message2 != NULL)
		{	//Tag Li
			fWaitTagP = cmpStringByVector(message2);
		}
	}

	else if  ((!strcmp(message1,"a") || !strcmp(message1,"A")))
	{
		if (fWaitTagA) 
		{
			fFoundString = true;	
			fWaitTagA = false;
		}
	}
	
	else if  ((!strcmp(message1,"p") || !strcmp(message1,"P")))
	{
		if (fWaitTagP) 
		{
			if (message2 == NULL)
			{ 
				fFoundString = false;	
				fWaitTagA = true;
			}
			else
			{
				fFoundString = true;	
				fWaitTagP = false;			
			}
		}
		else
		{
			if (message2 != NULL)
			{
				fFoundString = cmpStringByVector(message2);
			}
		}
	}
	
	else  || !strcmp(message1,"IMG")	|| !strcmp(message1,"Img"))
	{
		if (message2 != NULL)
		{
			if (cmpStringByVector(message2))
			{	
				//Tag Img: Clear text.
				tempChar = XMLString::transcode(att.getValue(XMLString::transcode("alt")));
				fFoundString = false;	
			}
		}
	}
*/