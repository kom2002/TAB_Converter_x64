
#include "Converter.h"

bool fnLoadNcc(char* myNccPath)
{
    try 
	{
		MyLoadNccHandle = new LoadNccHandle();
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) 
	{
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n" << message << "\n";
        XMLString::release(&message);
        return false;
    }

	SAX2XMLReader *MyReaderNcc = XMLReaderFactory::createXMLReader();	

	MyReaderNcc->setContentHandler(MyLoadNccHandle);
	MyReaderNcc->setErrorHandler(MyLoadNccHandle);

	MyReaderNcc->setFeature(XMLUni::fgXercesLoadExternalDTD, false);
	MyReaderNcc->setFeature(XMLUni::fgSAX2CoreValidation, false);
	MyReaderNcc->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
	MyReaderNcc->setFeature(XMLUni::fgXercesSchema, true);
	MyReaderNcc->setFeature(XMLUni::fgXercesSchemaFullChecking, false);
	MyReaderNcc->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
	
	try	
	{	
		MyReaderNcc -> parse(myNccPath);	
	}
	catch (const XMLException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadNccHandle;
		delete MyReaderNcc;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (const SAXParseException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadNccHandle;
		delete MyReaderNcc;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (...) 
	{
		cout << "Unexpected Exception \n" ;
		delete MyLoadNccHandle;
		delete MyReaderNcc;
		XMLPlatformUtils::Terminate();
		return false;
	}

	//Copy all Ncc vector to local
	myVecNccType	 = MyLoadNccHandle->getVecNccType(); 
	myVecNccClass	 = MyLoadNccHandle->getVecNccClass();
	myVecNccId		 = MyLoadNccHandle->getVecNccId();
	myVecNccLinkFile = MyLoadNccHandle->getVecNccLinkFile();
	myVecNccLinkId   = MyLoadNccHandle->getVecNccLinkId();
	myVecNccName	 = MyLoadNccHandle->getVecNccName();
	MyLoadNccHandle->clearVector();

	delete MyLoadNccHandle;
	delete MyReaderNcc;
	XMLPlatformUtils::Terminate(); 
	cout << myNccPath << " Loaded" << endl;
	return true;
}




bool fnLoadSmil(string mySmilPath)
{
    try 
	{
		MyLoadSmilHandle = new LoadSmilHandle();
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) 
	{
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n" << message << "\n";
        XMLString::release(&message);
        return false;
    }

	SAX2XMLReader *MyReaderSmil = XMLReaderFactory::createXMLReader();	

	MyReaderSmil->setContentHandler(MyLoadSmilHandle);
	MyReaderSmil->setErrorHandler(MyLoadSmilHandle);

	MyReaderSmil->setFeature(XMLUni::fgXercesLoadExternalDTD, false);
	MyReaderSmil->setFeature(XMLUni::fgSAX2CoreValidation, false);
	MyReaderSmil->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
	MyReaderSmil->setFeature(XMLUni::fgXercesSchema, true);
	MyReaderSmil->setFeature(XMLUni::fgXercesSchemaFullChecking, false);
	MyReaderSmil->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
	
	try	
	{	
		MyReaderSmil -> parse(mySmilPath.c_str());	
	}
	catch (const XMLException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadSmilHandle;
		delete MyReaderSmil;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (const SAXParseException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadSmilHandle;
		delete MyReaderSmil;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (...) 
	{
		cout << "Unexpected Exception \n" ;
		delete MyLoadSmilHandle;
		delete MyReaderSmil;
		XMLPlatformUtils::Terminate();
		return false;
	}

	//Copy all Smil vector to local
	myVecSmilType  = MyLoadSmilHandle->getVecSmilType();
	myVecSmilId    = MyLoadSmilHandle->getVecSmilId();
	myVecSmilLinkFile  = MyLoadSmilHandle->getVecSmilLinkFile();
	myVecSmilBegin = MyLoadSmilHandle->getVecSmilBegin();
	myVecSmilEnd   = MyLoadSmilHandle->getVecSmilEnd();
	MyLoadSmilHandle->clearVector();

	delete MyLoadSmilHandle;
	delete MyReaderSmil;
	XMLPlatformUtils::Terminate(); 
	cout << mySmilPath << " Loaded" << endl;
	return true;
}



bool fnLoadHtml(string myStrSourcePathHtml)  //use parameter from 4 vectors {myVecSmilType, myVecSmilLinkFile, myVecSmilBegin, myVecSmilEnd}
{
	//Intial LoadHtmlClass
	MyLoadHtmlHandle = new LoadHtmlHandle();

	//send vector to class for get variable
	MyLoadHtmlHandle->putVectorIdForGetString(myVecSmilBegin,myVecSmilEnd);
	
	try 
	{
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) 
	{
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n" << message << "\n";
        XMLString::release(&message);
        return false;
    }

	SAX2XMLReader *MyReaderHtml = XMLReaderFactory::createXMLReader();	

	MyReaderHtml->setContentHandler(MyLoadHtmlHandle);
	MyReaderHtml->setErrorHandler(MyLoadHtmlHandle);

	MyReaderHtml->setFeature(XMLUni::fgXercesLoadExternalDTD, false);
	MyReaderHtml->setFeature(XMLUni::fgSAX2CoreValidation, false);
	MyReaderHtml->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
	MyReaderHtml->setFeature(XMLUni::fgXercesSchema, true);
	MyReaderHtml->setFeature(XMLUni::fgXercesSchemaFullChecking, false);
	MyReaderHtml->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
	
	try	
	{
		MyReaderHtml -> parse(myStrSourcePathHtml.c_str());	
	}
	catch (const XMLException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadHtmlHandle;
		delete MyReaderHtml;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (const SAXParseException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadHtmlHandle;
		delete MyReaderHtml;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (...) 
	{
		cout << "Unexpected Exception \n" ;
		delete MyLoadHtmlHandle;
		delete MyReaderHtml;
		XMLPlatformUtils::Terminate();
		return false;
	}

	delete MyLoadHtmlHandle;
	delete MyReaderHtml;
	XMLPlatformUtils::Terminate(); 
	return true;
}

