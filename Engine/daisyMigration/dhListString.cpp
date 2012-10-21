#include "dhListString.h"

//parse HTML/XML File

dhListString::dhListString()
{
	fWaitTagA		= false;
	fWaitTagP		= false;
	fFoundString	= false;
//	cout << "CONSTRUCTOR : dhListString" << endl;
}

dhListString::~dhListString()
{
//	cout << "DESTRUCTOR : dhListString" << endl;
}

void dhListString::characters(const XMLCh* const chars,const unsigned int length)
{
	if (fFoundString == true) 
	{			
		char* myString = XMLString::transcode(chars);
		tempResult = myString;
		fFoundString = false;
		XMLString::release(&myString);
	}
}

void dhListString::startElement(const XMLCh*      const    i,
	                            const XMLCh*      const    localname,
	                            const XMLCh*      const    qname,
   	                            const Attributes&          att)
{
	char* message1 = XMLString::transcode(qname);
	char* message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));
 
	fFoundString = false;

	if  (!strcmp(message1,"h1")   || !strcmp(message1,"H1")
	||	 !strcmp(message1,"h2")   || !strcmp(message1,"H2")
	|| 	 !strcmp(message1,"h3")   || !strcmp(message1,"H3")
	||	 !strcmp(message1,"h4")   || !strcmp(message1,"H4")
	||	 !strcmp(message1,"h5")   || !strcmp(message1,"H5")
	||	 !strcmp(message1,"h6")   || !strcmp(message1,"H6")
	||   !strcmp(message1,"span") || !strcmp(message1,"SPAN"))
	{	//Have ID
		if (message2 != NULL)
		{	
			if (!strcmp(message2,fIdForGetString.c_str()))
			{				
				//Tag Hx
				fWaitTagA = true;
			}
		}
	}

	if  (!strcmp(message1,"li") || !strcmp(message1,"LI")
	||   !strcmp(message1,"Li") || !strcmp(message1,"lI"))
	{	//Maybe not have ID.
		if (message2 != NULL)
		{
			if (!strcmp(message2,fIdForGetString.c_str()))
			{	
				// Tag Li
				fWaitTagP = true;
			}
		}
	}

	if  ((!strcmp(message1,"a") || !strcmp(message1,"A")))
	{
		if (fWaitTagA) 
		{
			fFoundString = true;	
			fWaitTagA = false;
		}
	}
	
	if  ((!strcmp(message1,"p") || !strcmp(message1,"P")))
	{
		if (fWaitTagP) 
		{
			fFoundString = true;	
			fWaitTagP = false;
		}
		else
		{
			if (message2 != NULL)
			{
				if (!strcmp(message2,fIdForGetString.c_str()))
				{	
					//Tag P
					fFoundString = true;	
				}
			}
		}
	}
	
	if  (!strcmp(message1,"img") || !strcmp(message1,"IMG")	|| !strcmp(message1,"Img"))
	{
		if (!strcmp(message2,fIdForGetString.c_str()))
		{	
			//Tag Img: Clear text.
			tempResult= "";
			fFoundString = false;	
		}
	}

	XMLString::release(&message2);		
	XMLString::release(&message1);
}
	

void dhListString::fatalError(const SAXParseException& exception)
{
	char* message = XMLString::transcode(exception.getMessage());
//	cout << "Fatal Error: "	<< message
  //       << " at line: "	<< exception.getLineNumber()
	//	 << endl;
	XMLString::release(&message);
}


void dhListString::putIdForGetString(string _IdForGetString)
{
	fIdForGetString = _IdForGetString;
}

string dhListString::getTempResult(void)
{
	return tempResult;
}





/*#include "dhListString.h"

dhListString::dhListString()
{
	waitTagA = false;
	waitTagP = false;
	foundString = false;
	cout<<"CONSTRUCTOR : dhListString"<<endl;
}

dhListString::~dhListString()
{
	cout<<"DESTRUCTOR : dhListString"<<endl;
}

void dhListString::characters(const XMLCh* const chars,const unsigned int length)
{
	if (foundString == true) 
	{
		string myString = XMLString::transcode(chars);
		foundString = false;
		tempResult = myString;
	}
}

void dhListString::startElement(const   XMLCh*      const    uri,
	                            const   XMLCh*      const    localname,
	                            const   XMLCh*      const    qname,
   	                            const   Attributes&          att)
{
	string message1 = XMLString::transcode(qname);
	string message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));
 
	foundString = false;

	if  (!message1.compare("h1")   || !message1.compare("H1")
	||	 !message1.compare("h2")   || !message1.compare("H2")
	|| 	 !message1.compare("h3")   || !message1.compare("H3")
	||	 !message1.compare("h4")   || !message1.compare("H4")
	||	 !message1.compare("h5")   || !message1.compare("H5")
	||	 !message1.compare("h6")   || !message1.compare("H6")
	||   !message1.compare("span") || !message1.compare("SPAN"))
	{	//Have ID Sure.
		if (!message2.empty())
		{	
			if (!message2.compare(fIdForGetString))
			{				
				cout << "I Found from Hx.";
				waitTagA = true;
			}
		}
	}

	if  (!message1.compare("li") || !message1.compare("LI")
	||   !message1.compare("Li") || !message1.compare("lI"))
	{	//Maybe not have ID.
		if (!message2.empty())
		{
			if (!message2.compare(fIdForGetString))
			{	
				cout << "I Found from Li.";
				waitTagP = true;
			}
		}
	}

	if  ((!message1.compare("a") || !message1.compare("A")))
	{
		if (waitTagA) 
		{
			foundString = true;	
			waitTagA = false;
		}
	}
	
	if  ((!message1.compare("p") || !message1.compare("P")))
	{
		if (waitTagP) 
		{
			foundString = true;	
			waitTagP = false;
		}
		else
		{
			if (!message2.empty())
			{
				if (!message2.compare(fIdForGetString))
				{	
					cout << "I Found from p.";
					foundString = true;	
				}
			}
		}
	}
	
	if  (!message1.compare("img") || !message1.compare("IMG") || !message1.compare("Img"))
	{
		if (!message1.compare(fIdForGetString))
		{	
			tempResult = "";
			foundString = false;	
		}
	}
}
	

void dhListString::fatalError(const SAXParseException& exception)
{
	string message = XMLString::transcode(exception.getMessage());
	cout << "Fatal Error: " 		 << message
         << " at line: "     		 << exception.getLineNumber()
		 << endl;
}

void dhListString::putIdForGetString(string _IdForGetString)
{
	fIdForGetString = _IdForGetString;
	cout << "RECIEVED IdForGetString: " << fIdForGetString << endl;
}

string dhListString::getTempResult(void)
{
	return tempResult;
}


*/