#include "LoadDaisy3Smil2Handle.h"

//This code provides capability to parser SMIL 2.0 file of DAISY 3.00 and NISO_Z39.86 Standards
//Synchronization of media objects in this standard is based on the SMIL 2.0 specification. Developers are requested to reference SMIL 2.0 [SMIL] for complete background and details
LoadDaisy3Smil2Handle::LoadDaisy3Smil2Handle()
{
	//Reset all variable to default.
	LoadDaisy3Smil2Handle::clearVector();
}

LoadDaisy3Smil2Handle::~LoadDaisy3Smil2Handle()
{
}

void LoadDaisy3Smil2Handle::startElement(const XMLCh* const uri,
										 const XMLCh* const localname,
										 const XMLCh* const qname,
										 const Attributes& att)
{
	char* message1 = XMLString::transcode(localname);
	char* message2;
	XMLCh* myXMLCh;

	//////////////////////////////////////////////////////////////////////////////////////
	// smil                                                            infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"smil")  
		||!strcmp(message1,"Smil") 
		||!strcmp(message1,"SMIL"))
	{
		//xmlns (CDATA, FIXED) "http://www.w3.org/2001/Smil2/": Specifies the default XML namespace for all elements in SMIL. See [XML-Namespaces] for details on namespaces. This attribute and its value (given in DTD) must be explicitly specified in the document instance. 
		//strDaisy3Smil2HeadXmlNs = XMLString::transcode(att.getValue(XMLString::transcode("xmlns")));
		strDaisy3Smil2HeadXmlNs = "http://www.w3.org/2001/SMIL20/";     //Fixed.

		//This is infinite element but I don't setup variable for checking the SMIL level for this version.
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// meta (without scheme)                                             finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"meta")  
		||!strcmp(message1,"Meta") 
		||!strcmp(message1,"META"))
	{
		//ตรวจสอบที่ name ก่อนถ้าไม่มี name ก็ถือว่าไม่มี meta นั้นเลย
		if (att.getIndex(XMLString::transcode("name")) != -1 )
		{
			//name (CDATA, REQUIRED) 
			try
			{
				myXMLCh = XMLString::transcode("name");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadMetaName.push_back("EmPtY");
				else					vecDaisy3Smil2HeadMetaName.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("name")));
				//vecDaisy3Smil2HeadMetaName.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data.
				//vecDaisy3Smil2HeadMetaName.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::meta> This SMIL has empty name in meta tag." << endl;
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::meta> This is a serious warning on programming syntax please contact programmer" << endl;
			}

			//content (CDATA, #IMPLIED) 
			try
			{
				myXMLCh = XMLString::transcode("content");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadMetaContent.push_back("EmPtY");
				else					vecDaisy3Smil2HeadMetaContent.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);				
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("content")));
				//vecDaisy3Smil2HeadMetaContent.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data.
				//vecDaisy3Smil2HeadMetaContent.push_back("EmPtY"); 
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::meta> This SMIL has empty content in meta tag." << endl;
			}
		}
		else
		{
			cout << "<Warning::LoadDaisy3Smil2Handle::startElement::meta> Skip this meta in SMIL because it has empty name in meta tag." << endl;
		}
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// region	                                                         finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"region")  
		||!strcmp(message1,"Region") 
		||!strcmp(message1,"REGION"))
	{
		//ตรวจสอบที่ id ก่อนถ้าไม่มี id ก็ถือว่าไม่มี region นั้นเลย
		if (att.getIndex(XMLString::transcode("id")) != -1 )
		{
			//id (ID, REQUIRED) Value of region attribute on media object references the id on appropriate region element. 
			try
			{
				myXMLCh = XMLString::transcode("id");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionId.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionId.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);



				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));
				//vecDaisy3Smil2HeadRegionId.push_back(message2);		
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data.
				//vecDaisy3Smil2HeadRegionId.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty id in region tag." << endl;
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This is a serious warning on programming syntax please contact programmer" << endl;
			}
		
			//bottom (CDATA, 'auto') Locates region in display space. See SMIL 2.0 for details. 
			try
			{
				myXMLCh = XMLString::transcode("bottom");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionBottom.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionBottom.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);



				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("bottom")));
				//vecDaisy3Smil2HeadRegionBottom.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data.
				//vecDaisy3Smil2HeadRegionBottom.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty bottom in region tag." << endl;
			}
		
			//left (CDATA, 'auto' ) Locates region display space. See SMIL 2.0 for details. 
			try
			{
				myXMLCh = XMLString::transcode("left");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionLeft.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionLeft.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);




				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("left")));
				//vecDaisy3Smil2HeadRegionLeft.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data.
				//vecDaisy3Smil2HeadRegionLeft.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty left in region tag." << endl;
			}
			
			//right (CDATA, 'auto') Locates region in display space. See SMIL 2.0 for details. 
			try
			{

				myXMLCh = XMLString::transcode("right");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionRight.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionRight.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);



				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("right")));
				//vecDaisy3Smil2HeadRegionRight.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data.
				//vecDaisy3Smil2HeadRegionRight.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty right in region tag." << endl;
			}
			
			//top (CDATA, 'auto') Locates region in display space. See SMIL 2.0 for details. 
			try
			{
				myXMLCh = XMLString::transcode("top");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionTop.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionTop.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);




				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("top")));
				//vecDaisy3Smil2HeadRegionTop.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data.
				//vecDaisy3Smil2HeadRegionTop.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty top in region tag." << endl;
			}
			
			//height (CDATA, 'auto') Locates region in display space. See SMIL 2.0 for details. 
			try
			{
				myXMLCh = XMLString::transcode("height");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionHeight.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionHeight.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);

				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("height")));
				//vecDaisy3Smil2HeadRegionHeight.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data.
				//vecDaisy3Smil2HeadRegionHeight.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty height in region tag." << endl;
			}
			
			//width (CDATA, 'auto') Locates region in display space. See SMIL 2.0 for details. 
			try
			{
				myXMLCh = XMLString::transcode("width");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionWidth.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionWidth.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);


				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("width")));
				//vecDaisy3Smil2HeadRegionWidth.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadRegionWidth.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty width in region tag." << endl;
			}
			
			//fit ((hidden|fill|meet|scroll|slice) 'hidden') Specifies behavior if the intrinsic height and width of a visual media object differ from those of the region in which it is displayed. See SMIL 2.0 for definitions of attribute values. 
			try
			{
				myXMLCh = XMLString::transcode("fit");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionFit.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionFit.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);


				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("fit")));
				//vecDaisy3Smil2HeadRegionFit.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadRegionFit.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty fit in region tag." << endl;
			}
			
			//backgroundColor (CDATA, IMPLIED) Sets background color of the area of the region that is not covered by the media object(s) being displayed. 
			try
			{
				myXMLCh = XMLString::transcode("backgroundColor");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionBackgroundColor.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionBackgroundColor.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);				
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("backgroundColor")));
				//vecDaisy3Smil2HeadRegionBackgroundColor.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadRegionBackgroundColor.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty backgroundColor in region tag." << endl;
			}
			
			//showBackground ((always|whenActive) 'always') Controls whether the backgroundColor of a region is shown when no media is being rendered to the region. See SMIL 2.0 for definitions of attribute values. 
			try
			{
				myXMLCh = XMLString::transcode("showBackground");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionShowBackground.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionShowBackground.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("showBackground")));
				//vecDaisy3Smil2HeadRegionShowBackground.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadRegionShowBackground.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty showBackground in region tag." << endl;
			}
			
			//z-index (CDATA, IMPLIED) Used for control of multilayered displays. 
			try
			{
				myXMLCh = XMLString::transcode("z-index");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionZIndex.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionZIndex.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("z-index")));
				//vecDaisy3Smil2HeadRegionZIndex.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadRegionZIndex.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty z-index in region tag." << endl;
			}
			
			//xml:lang (NMTOKEN, IMPLIED)
			try
			{
				myXMLCh = XMLString::transcode("xml:lang");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadRegionXmlLang.push_back("EmPtY");
				else					vecDaisy3Smil2HeadRegionXmlLang.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("xml:lang")));
				//vecDaisy3Smil2HeadRegionXmlLang.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadRegionXmlLang.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> This SMIL has empty xml:lang in region tag." << endl;
			}
		}
		else
		{
			cout << "<Warning::LoadDaisy3Smil2Handle::startElement::region> Skip this Region in SMIL because it has empty id in region tag." << endl;
		}
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// customTest		                                                  finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"customtest")  
		||!strcmp(message1,"customTest") 
		||!strcmp(message1,"Customtest")
		||!strcmp(message1,"CustomTest") 
		||!strcmp(message1,"CUSTOMTEST"))
	{
		//ตรวจสอบที่ id ก่อนถ้าไม่มี id ก็ถือว่าไม่มี customTest นั้นเลย
		if (att.getIndex(XMLString::transcode("id")) != -1 )
		{
			//id (ID, REQUIRED) Id here serves as a unique identifier referenced by a customTest attribute on par or seq in body of SMIL. 
			try
			{
				myXMLCh = XMLString::transcode("id");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadCustomTestId.push_back("EmPtY");
				else					vecDaisy3Smil2HeadCustomTestId.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));
				//vecDaisy3Smil2HeadCustomTestId.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadCustomTestId.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::customTest> This SMIL has empty id in customTest tag." << endl;
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::customTest> This is a serious warning on programming syntax please contact programmer" << endl;
			}
			
			//defaultState ((true|false) 'false') Specifies whether player will render (value = true) or skip (value = false) the structure during sequential playback. If no value is present, the default is false and the content is skipped. 
			try
			{
				myXMLCh = XMLString::transcode("defaultState");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadCustomTestDefaultState.push_back("EmPtY");
				else					vecDaisy3Smil2HeadCustomTestDefaultState.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("defaultState")));
				//vecDaisy3Smil2HeadCustomTestDefaultState.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadCustomTestDefaultState.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::customTest> This SMIL has empty defaultState in customTest tag." << endl;
			}
			
			//override ((visible|hidden) 'hidden') Specifies whether runtime resetting of defaultState should be encouraged (value= "visible") or discouraged (value = "hidden"). See section 7.4.3, "'Skippable' Structures" for normative content. 
			try
			{		
				myXMLCh = XMLString::transcode("override");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadCustomTestOverride.push_back("EmPtY");
				else					vecDaisy3Smil2HeadCustomTestOverride.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("override")));
				//vecDaisy3Smil2HeadCustomTestOverride.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadCustomTestOverride.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::customTest> This SMIL has empty override in customTest tag." << endl;
			}
			
			//class (CDATA, IMPLIED) 
			try
			{			
				myXMLCh = XMLString::transcode("class");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadCustomTestClass.push_back("EmPtY");
				else					vecDaisy3Smil2HeadCustomTestClass.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("class")));
				//vecDaisy3Smil2HeadCustomTestClass.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadCustomTestClass.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::customTest> This SMIL has empty class in customTest tag." << endl;
			}
			
			//title (CDATA, IMPLIED) 
			try
			{			
				myXMLCh = XMLString::transcode("title");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadCustomTestTitle.push_back("EmPtY");
				else					vecDaisy3Smil2HeadCustomTestTitle.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("title")));
				//vecDaisy3Smil2HeadCustomTestTitle.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadCustomTestTitle.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::customTest> This SMIL has empty title in customTest tag." << endl;
			}
					
			//xml:lang (NMTOKEN, IMPLIED) 
			try
			{
				myXMLCh = XMLString::transcode("xml:lang");
				message2 = XMLString::transcode(att.getValue(myXMLCh));
				if (message2 == NULL)	vecDaisy3Smil2HeadCustomTestXmlLang.push_back("EmPtY");
				else					vecDaisy3Smil2HeadCustomTestXmlLang.push_back(message2);
				XMLString::release(&myXMLCh);
				XMLString::release(&message2);
				
				
				
				//message2 = XMLString::transcode(att.getValue(XMLString::transcode("xml:lang")));
				//vecDaisy3Smil2HeadCustomTestXmlLang.push_back(message2);
			}
			catch(...)
			{
				//Push "EmPtY" for ordering reason and detects there is no data
				//vecDaisy3Smil2HeadCustomTestXmlLang.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3Smil2Handle::startElement::customTest> This SMIL has empty xml:lang in customTest tag." << endl;
			}
		}
		else
		{
			cout << "<Warning::LoadDaisy3Smil2Handle::startElement::customTest> Skip this customTest in SMIL because it has empty id in customTest tag." << endl;
		}
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// seq															   infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"seq")  
		||!strcmp(message1,"Seq") 
		||!strcmp(message1,"SEQ"))
	{
		//clear value in all temporary strings.
		strDaisy3Smil2BodySeqTempId.clear();
		strDaisy3Smil2BodySeqTempClass.clear();
		strDaisy3Smil2BodySeqTempCustomTest.clear();
		strDaisy3Smil2BodySeqTempDur.clear();
		strDaisy3Smil2BodySeqTempXmlLang.clear();
		strDaisy3Smil2BodySeqTempEnd.clear();
		strDaisy3Smil2BodySeqTempFill.clear();

		//setup variable for find level of seq in this SMIL.
		intDaisy3Smil2BodySeqTempLevel++;

		//id (ID, REQUIRED): 
		if (att.getIndex(XMLString::transcode("id")) != -1 )
			strDaisy3Smil2BodySeqTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		else
			strDaisy3Smil2BodySeqTempId = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element. Can be used to identify structures such as tables and lists for which special navigation functions should be automatically invoked when entered. See section 7.4.2, "Automatic Invocation of Special Navigation Modes." Can also be used to select a presentation from the resource file. See section 10.3, "Resource File Requirements." 
		if (att.getIndex(XMLString::transcode("class")) != -1 )
			strDaisy3Smil2BodySeqTempClass = XMLString::transcode(att.getValue(XMLString::transcode("class")));
		else
			strDaisy3Smil2BodySeqTempClass = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//customTest (IDREF, IMPLIED): ID reference linking seq with matching customTest element in head. 
		if (att.getIndex(XMLString::transcode("customTest")) != -1 )
			strDaisy3Smil2BodySeqTempCustomTest = XMLString::transcode(att.getValue(XMLString::transcode("customTest")));
		else
			strDaisy3Smil2BodySeqTempCustomTest = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//dur (CDATA, IMPLIED) The duration of the seq. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. 
		if (att.getIndex(XMLString::transcode("dur")) != -1 )
			strDaisy3Smil2BodySeqTempDur = XMLString::transcode(att.getValue(XMLString::transcode("dur")));
		else
			strDaisy3Smil2BodySeqTempDur = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//xml:lang (NMTOKEN, IMPLIED) 
		if (att.getIndex(XMLString::transcode("xml:lang")) != -1 )		
			strDaisy3Smil2BodySeqTempXmlLang = XMLString::transcode(att.getValue(XMLString::transcode("xml:lang")));
		else
			strDaisy3Smil2BodySeqTempXmlLang = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//end (CDATA, IMPLIED) Determines the active duration of Escapable or Producer Pause content. See section 7.8, "End Attribute Values", for end value syntax. See also sections 7.4.1, "'Escapable' Structures" and 7.4.11, "Producer Pauses." 
		if (att.getIndex(XMLString::transcode("end")) != -1 )			
			strDaisy3Smil2BodySeqTempEnd = XMLString::transcode(att.getValue(XMLString::transcode("end")));
		else
			strDaisy3Smil2BodySeqTempEnd = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//fill ((freeze | remove) 'remove')Determines whether a visual element is frozen at its final state or is no longer presented. See section 7.4.11, "Producer Pauses" and section 10.3.1 of "SMIL 2.0." 
		if (att.getIndex(XMLString::transcode("fill")) != -1 )			
			strDaisy3Smil2BodySeqTempFill = XMLString::transcode(att.getValue(XMLString::transcode("fill")));
		else
			strDaisy3Smil2BodySeqTempFill = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//setup variable
		if (intCountImg   > 0) 
			intCountImg++;
		if (intCountText  > 0) 
			intCountText++;
		if (intCountAudio > 0) 
			intCountAudio++;

		boolNewImg		= false;
		boolNewText		= false;
		boolNewAudio	= false;
		return;
	}

	  //////////////////////////////////////////////////////////////////////////////////////
	 // a 																infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"a")  
		||!strcmp(message1,"A"))
	{
		//clear value in all temporary strings.
		strDaisy3Smil2BodyAnchorTempId.clear();
		strDaisy3Smil2BodyAnchorTempClass.clear();
		strDaisy3Smil2BodyAnchorTempTitle.clear();
		strDaisy3Smil2BodyAnchorTempXmlLang.clear();
		strDaisy3Smil2BodyAnchorTempHref.clear();
		strDaisy3Smil2BodyAnchorTempExternal.clear();
		
		//id (ID, REQUIRED): 
		if (att.getIndex(XMLString::transcode("id")) != -1 )	
			strDaisy3Smil2BodyAnchorTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		else
			strDaisy3Smil2BodyAnchorTempId = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element. Can be used to identify structures such as tables and lists for which special navigation functions should be automatically invoked when entered. See section 7.4.2, "Automatic Invocation of Special Navigation Modes." Can also be used to select a presentation from the resource file. See section 10.3, "Resource File Requirements." 
		if (att.getIndex(XMLString::transcode("class")) != -1 )		
			strDaisy3Smil2BodyAnchorTempClass = XMLString::transcode(att.getValue(XMLString::transcode("class")));
		else
			strDaisy3Smil2BodyAnchorTempClass = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//title (CDATA, IMPLIED) 
		if (att.getIndex(XMLString::transcode("title")) != -1 )		
			strDaisy3Smil2BodyAnchorTempTitle = XMLString::transcode(att.getValue(XMLString::transcode("title")));
		else
			strDaisy3Smil2BodyAnchorTempTitle = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//xml:lang (NMTOKEN, IMPLIED) 
		if (att.getIndex(XMLString::transcode("xml:lang")) != -1 )
			strDaisy3Smil2BodyParTempXmlLang = XMLString::transcode(att.getValue(XMLString::transcode("xml:lang")));
		else
			strDaisy3Smil2BodyParTempXmlLang = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//href (%URI;, REQUIRED) Specifies the URI of the target of the link. The URI may include a fragment identifier. 
		if (att.getIndex(XMLString::transcode("href")) != -1 )	
			strDaisy3Smil2BodyAnchorTempHref = XMLString::transcode(att.getValue(XMLString::transcode("href")));
		else
			strDaisy3Smil2BodyAnchorTempHref = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//external ((true|false) 'false')An external link points to media content that is not part of the DTB. The external media content must be rendered by an external application, whether or not that content is renderable by the DTB player. 
		if (att.getIndex(XMLString::transcode("external")) != -1 )	
			strDaisy3Smil2BodyAnchorTempExternal = XMLString::transcode(att.getValue(XMLString::transcode("external")));
		else
			strDaisy3Smil2BodyAnchorTempExternal = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//setup variable
		if (intCountImg   > 0) 
			intCountImg++;
		if (intCountText  > 0) 
			intCountText++;
		if (intCountAudio > 0) 
			intCountAudio++;

		boolNewImg		= false;
		boolNewText		= false;
		boolNewAudio	= false;
		return;
	}

	  //////////////////////////////////////////////////////////////////////////////////////
	 // par																infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"par")  
		||!strcmp(message1,"Par") 
		||!strcmp(message1,"PAR"))
	{
		//clear value in all temporary strings.
		strDaisy3Smil2BodyParTempId.clear();
		strDaisy3Smil2BodyParTempClass.clear();
		strDaisy3Smil2BodyParTempCustomTest.clear();
		strDaisy3Smil2BodyParTempXmlLang.clear();
			
		//setup variable for find level of par in this SMIL.
		intDaisy3Smil2BodyParTempLevel++;

		//id (ID, REQUIRED): 
		if (att.getIndex(XMLString::transcode("id")) != -1 )		
			strDaisy3Smil2BodyParTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		else
			strDaisy3Smil2BodyParTempId = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element. Can be used to identify structures such as tables and lists for which special navigation functions should be automatically invoked when entered. See section 7.4.2, "Automatic Invocation of Special Navigation Modes." Can also be used to select a presentation from the resource file. See section 10.3, "Resource File Requirements." 
		if (att.getIndex(XMLString::transcode("class")) != -1 )
			strDaisy3Smil2BodyParTempClass = XMLString::transcode(att.getValue(XMLString::transcode("class")));
		else
			strDaisy3Smil2BodyParTempClass = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//customTest (IDREF, IMPLIED): ID referencing matching customTest element in head. 
		if (att.getIndex(XMLString::transcode("customTest")) != -1 )		
			strDaisy3Smil2BodyParTempCustomTest = XMLString::transcode(att.getValue(XMLString::transcode("customTest")));
		else
			strDaisy3Smil2BodyParTempCustomTest = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//xml:lang (NMTOKEN, IMPLIED) 
		if (att.getIndex(XMLString::transcode("xml:lang")) != -1 )	
			strDaisy3Smil2BodyParTempXmlLang = XMLString::transcode(att.getValue(XMLString::transcode("xml:lang")));
		else
			strDaisy3Smil2BodyParTempXmlLang = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//setup variable
		if (intCountImg   > 0) 
			intCountImg++;
		if (intCountText  > 0) 
			intCountText++;
		if (intCountAudio > 0) 
			intCountAudio++;

		boolNewImg		= false;
		boolNewText		= false;
		boolNewAudio	= false;
		return;
	}

	  //////////////////////////////////////////////////////////////////////////////////////
	 // img																  finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"img")  
		||!strcmp(message1,"Img") 
		||!strcmp(message1,"IMG"))
	{
		//clear value in all temporary strings.
		strDaisy3Smil2BodyImgTempRegion.clear();
		strDaisy3Smil2BodyImgTempSrc.clear();
		strDaisy3Smil2BodyImgTempId.clear();
		strDaisy3Smil2BodyImgTempType.clear();
		strDaisy3Smil2BodyImgTempXmlLang.clear();
		
		//id (ID, IMPLIED): Optional identifier. 
		if (att.getIndex(XMLString::transcode("id")) != -1 )		
			strDaisy3Smil2BodyImgTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		else
			strDaisy3Smil2BodyImgTempId = "EmPtY";   //Set value to "EmPtY" because there is no data.
			
		//src (CDATA, REQUIRED): URI of image file to be rendered. 
		if (att.getIndex(XMLString::transcode("src")) != -1 )		
			strDaisy3Smil2BodyImgTempSrc = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		else
			strDaisy3Smil2BodyImgTempSrc = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//type (CDATA, IMPLIED): Type of media file. 
		if (att.getIndex(XMLString::transcode("type")) != -1 )		
			strDaisy3Smil2BodyImgTempType = XMLString::transcode(att.getValue(XMLString::transcode("type")));
		else
			strDaisy3Smil2BodyImgTempType = "EmPtY";   //Set value to "EmPtY" because there is no data.
			
		//region (CDATA, IMPLIED): Specifies the region (defined in layout in document head) in which the image will be presented. References the id of the appropriate region. 
		if (att.getIndex(XMLString::transcode("region")) != -1 )		
			strDaisy3Smil2BodyImgTempRegion = XMLString::transcode(att.getValue(XMLString::transcode("region")));
		else
			strDaisy3Smil2BodyImgTempRegion = "EmPtY";   //Set value to "EmPtY" because there is no data.
			
		//xml:lang (NMTOKEN, IMPLIED) 
		if (att.getIndex(XMLString::transcode("xml:lang")) != -1 )
			strDaisy3Smil2BodyImgTempXmlLang = XMLString::transcode(att.getValue(XMLString::transcode("xml:lang")));
		else
			strDaisy3Smil2BodyImgTempXmlLang = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//setup variable
		intCountImg++;
		boolNewImg = true;
		return;
	}

	  //////////////////////////////////////////////////////////////////////////////////////
	 // text															  finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"text")  
		||!strcmp(message1,"Text") 
		||!strcmp(message1,"TEXT"))
	{
		//clear value in all temporary strings.
		strDaisy3Smil2BodyTextTempId.clear();
		strDaisy3Smil2BodyTextTempSrc.clear();
		strDaisy3Smil2BodyTextTempType.clear();
		strDaisy3Smil2BodyTextTempRegion.clear();
		strDaisy3Smil2BodyTextTempXmlLang.clear();


		//id (ID, IMPLIED): Optional identifier. 
		if (att.getIndex(XMLString::transcode("id")) != -1 )	
			strDaisy3Smil2BodyTextTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		else
			strDaisy3Smil2BodyTextTempId = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//src (CDATA, REQUIRED): URI of fragment of textual content file to be rendered. 
		if (att.getIndex(XMLString::transcode("src")) != -1 )		
			strDaisy3Smil2BodyTextTempSrc = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		else
			strDaisy3Smil2BodyTextTempSrc = "EmPtY#EmPtY";   //Set value to "EmPtY" because there is no data.

		//type (CDATA, IMPLIED): Type of media file. 
		if (att.getIndex(XMLString::transcode("type")) != -1 )		
			strDaisy3Smil2BodyTextTempType = XMLString::transcode(att.getValue(XMLString::transcode("type")));
		else
			strDaisy3Smil2BodyTextTempType = "EmPtY";   //Set value to "EmPtY" because there is no data.	

		//region (CDATA, IMPLIED): Specifies the region (defined in layout in document head) in which the text will be presented. References the id of the appropriate region. All types of text objects that are to appear in the same rendering space would be assigned the same value for region. For example, page numbers and producer's notes might both be displayed in the main text area of a screen (region="text"), while notes (e.g., footnotes) might be displayed in a separate area at the bottom of the screen (region="notes"). 
		if (att.getIndex(XMLString::transcode("region")) != -1 )		
			strDaisy3Smil2BodyTextTempRegion = XMLString::transcode(att.getValue(XMLString::transcode("region")));
		else
			strDaisy3Smil2BodyTextTempRegion = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//xml:lang (NMTOKEN, IMPLIED) 
		if (att.getIndex(XMLString::transcode("xml:lang")) != -1 )	
			strDaisy3Smil2BodyTextTempXmlLang = XMLString::transcode(att.getValue(XMLString::transcode("xml:lang")));
		else
			strDaisy3Smil2BodyTextTempXmlLang = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//setup variable
		intCountText++;
		boolNewText = true;
		return;
	}
	
	  //////////////////////////////////////////////////////////////////////////////////////
	 // audio														      finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"audio")  
		||!strcmp(message1,"Audio") 
		||!strcmp(message1,"AUDIO"))
	{
		//clear value in all temporary strings.
		strDaisy3Smil2BodyAudioTempId.clear();
		strDaisy3Smil2BodyAudioTempSrc.clear();
		strDaisy3Smil2BodyAudioTempType.clear();
		strDaisy3Smil2BodyAudioTempClipBegin.clear();
		strDaisy3Smil2BodyAudioTempClipEnd.clear();
		strDaisy3Smil2BodyAudioTempRegion.clear();
		strDaisy3Smil2BodyAudioTempXmlLang.clear();
		
		//id (ID, IMPLIED): Optional identifier. 
		if (att.getIndex(XMLString::transcode("id")) != -1 )
			strDaisy3Smil2BodyAudioTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		else
			strDaisy3Smil2BodyAudioTempId = "EmPtY";   //Set value to "EmPtY" because there is no data.
		
		//src (CDATA, REQUIRED): URI of audio file containing clip to be rendered. 
		if (att.getIndex(XMLString::transcode("src")) != -1 )
			strDaisy3Smil2BodyAudioTempSrc = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		else
			strDaisy3Smil2BodyAudioTempSrc = "EmPtY";   //Set value to "EmPtY" because there is no data.
		
		//type (CDATA, IMPLIED): Type of media file. 
		if (att.getIndex(XMLString::transcode("type")) != -1 )
			strDaisy3Smil2BodyAudioTempType = XMLString::transcode(att.getValue(XMLString::transcode("type")));
		else
			strDaisy3Smil2BodyAudioTempType = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//clipBegin (CDATA, REQUIRED): Specifies the beginning of a segment of a continuous audio file as a time offset from the start of the audio file. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. See section 7.7, "Media Clipping and Clock Values." 
		if (att.getIndex(XMLString::transcode("clipBegin")) != -1 )
			strDaisy3Smil2BodyAudioTempClipBegin = XMLString::transcode(att.getValue(XMLString::transcode("clipBegin")));
		else
			strDaisy3Smil2BodyAudioTempClipBegin = "EmPtY";   //Set value to "EmPtY" because there is no data.
		
		//clipEnd (CDATA, REQUIRED): Specifies the end of a segment of a continuous audio file as a time offset from the start of the audio file. It uses the same attribute value syntax as clipBegin. 
		if (att.getIndex(XMLString::transcode("clipEnd")) != -1 )
			strDaisy3Smil2BodyAudioTempClipEnd = XMLString::transcode(att.getValue(XMLString::transcode("clipEnd")));
		else
			strDaisy3Smil2BodyAudioTempClipEnd = "EmPtY";   //Set value to "EmPtY" because there is no data.
		
		//region (CDATA, IMPLIED): Specifies the region (defined in layout in document head) in which the audio object will be presented. References the id of the appropriate region. 
		if (att.getIndex(XMLString::transcode("region")) != -1 )
			strDaisy3Smil2BodyAudioTempRegion = XMLString::transcode(att.getValue(XMLString::transcode("region")));
		else
			strDaisy3Smil2BodyAudioTempRegion = "EmPtY";   //Set value to "EmPtY" because there is no data.
		
		//xml:lang (NMTOKEN, IMPLIED) 
		if (att.getIndex(XMLString::transcode("xml:lang")) != -1 )
			strDaisy3Smil2BodyAudioTempXmlLang = XMLString::transcode(att.getValue(XMLString::transcode("xml:lang")));
		else
			strDaisy3Smil2BodyAudioTempXmlLang = "EmPtY";   //Set value to "EmPtY" because there is no data.
		
		//setup variable
		intCountAudio++;
		boolNewAudio = true;
		return;
	}
}

void LoadDaisy3Smil2Handle::endElement  (const XMLCh *const uri, 
										 const XMLCh *const localname, 
										 const XMLCh *const qName)
{
	char* message4 = XMLString::transcode(localname);
	
	//Check the variable which its value are true;
	//		TRUE  means don't pass its function for store data from file to our variable.
	//		FALSE means complete, don't do anything more!

	  //////////////////
	 // Checking par //
	//////////////////
	if  (!strcmp(message4,"par") || !strcmp(message4,"Par") || !strcmp(message4,"PAR")) 
	{		
		if ( ((intCountAudio == 1) && (boolNewAudio = true))
		   ||((intCountText  == 1) && (boolNewText  = true))	 
		   ||((intCountImg   == 1) && (boolNewImg   = true)))
		{
			//push back seq information
			vecDaisy3Smil2BodySeqId.push_back			(strDaisy3Smil2BodySeqTempId);
			vecDaisy3Smil2BodySeqClass.push_back		(strDaisy3Smil2BodySeqTempClass);	
			vecDaisy3Smil2BodySeqCustomTest.push_back	(strDaisy3Smil2BodySeqTempCustomTest);
			vecDaisy3Smil2BodySeqDur.push_back			(strDaisy3Smil2BodySeqTempDur);
			vecDaisy3Smil2BodySeqXmlLang.push_back		(strDaisy3Smil2BodySeqTempXmlLang);
			vecDaisy3Smil2BodySeqEnd.push_back			(strDaisy3Smil2BodySeqTempEnd);
			vecDaisy3Smil2BodySeqFill.push_back			(strDaisy3Smil2BodySeqTempFill);
			_itoa_s(intDaisy3Smil2BodySeqTempLevel, a, 10);		//convert int to string
			vecDaisy3Smil2BodySeqLevel.push_back		(a);	//store that string to vector
			//push back par information
			vecDaisy3Smil2BodyParId.push_back			(strDaisy3Smil2BodyParTempId);
			vecDaisy3Smil2BodyParClass.push_back		(strDaisy3Smil2BodyParTempClass);
			vecDaisy3Smil2BodyParCustomTest.push_back	(strDaisy3Smil2BodyParTempCustomTest);
			vecDaisy3Smil2BodyParXmlLang.push_back		(strDaisy3Smil2BodyParTempXmlLang);
			_itoa_s(intDaisy3Smil2BodyParTempLevel, a, 10);		//convert int to string
			vecDaisy3Smil2BodyParLevel.push_back		(a);	//store that string to vector

			//push back Anchor <a> information
			vecDaisy3Smil2BodyAnchorId.push_back		(strDaisy3Smil2BodyAnchorTempId);
			vecDaisy3Smil2BodyAnchorClass.push_back		(strDaisy3Smil2BodyAnchorTempClass);
			vecDaisy3Smil2BodyAnchorTitle.push_back		(strDaisy3Smil2BodyAnchorTempTitle);
			vecDaisy3Smil2BodyAnchorXmlLang.push_back	(strDaisy3Smil2BodyAnchorTempXmlLang);
			vecDaisy3Smil2BodyAnchorHref.push_back		(strDaisy3Smil2BodyAnchorTempHref);
			vecDaisy3Smil2BodyAnchorExternal.push_back	(strDaisy3Smil2BodyAnchorTempExternal);
			//push back image information
			vecDaisy3Smil2BodyImgId.push_back			(strDaisy3Smil2BodyImgTempId);
			vecDaisy3Smil2BodyImgRegion.push_back		(strDaisy3Smil2BodyImgTempRegion);
			vecDaisy3Smil2BodyImgSrc.push_back			(strDaisy3Smil2BodyImgTempSrc);
			vecDaisy3Smil2BodyImgType.push_back			(strDaisy3Smil2BodyImgTempType);
			vecDaisy3Smil2BodyImgXmlLang.push_back		(strDaisy3Smil2BodyImgTempXmlLang);
			//push back text infomation
			vecDaisy3Smil2BodyTextId.push_back			(strDaisy3Smil2BodyTextTempId);
			vecDaisy3Smil2BodyTextSrcFile.push_back		(strDaisy3Smil2BodyTextTempSrc.substr(0,strDaisy3Smil2BodyTextTempSrc.find("#")));		//Seperte File and ID
			vecDaisy3Smil2BodyTextSrcId.push_back		(strDaisy3Smil2BodyTextTempSrc.substr(strDaisy3Smil2BodyTextTempSrc.find("#")+1));		//Seperte File and ID	
			vecDaisy3Smil2BodyTextType.push_back		(strDaisy3Smil2BodyTextTempType);
			vecDaisy3Smil2BodyTextRegion.push_back		(strDaisy3Smil2BodyTextTempRegion);
			vecDaisy3Smil2BodyTextXmlLang.push_back		(strDaisy3Smil2BodyTextTempXmlLang);
			vecDaisy3Smil2BodyTextContent.push_back		("WaItInG");
			//push back audio infomation
			vecDaisy3Smil2BodyAudioId.push_back			(strDaisy3Smil2BodyAudioTempId);
			vecDaisy3Smil2BodyAudioSrc.push_back		(strDaisy3Smil2BodyAudioTempSrc);
			vecDaisy3Smil2BodyAudioType.push_back		(strDaisy3Smil2BodyAudioTempType);
			vecDaisy3Smil2BodyAudioClipBegin.push_back	(strDaisy3Smil2BodyAudioTempClipBegin);
			vecDaisy3Smil2BodyAudioClipEnd.push_back	(strDaisy3Smil2BodyAudioTempClipEnd);
			vecDaisy3Smil2BodyAudioRegion.push_back		(strDaisy3Smil2BodyAudioTempRegion);
			vecDaisy3Smil2BodyAudioXmlLang.push_back	(strDaisy3Smil2BodyAudioTempXmlLang);

			//setup variable
			if (intCountImg   == 1)
				intCountImg   =  0;
			if (intCountText  == 1)
				intCountText  =  0;
			if (intCountAudio == 1)
				intCountAudio =  0;
		}

		//setup variable for find level of par in this SMIL.
		intDaisy3Smil2BodyParTempLevel--;
		return;
	}

	  ////////////////////////
	 // Checking seq and a //
	////////////////////////
	if  ( !strcmp(message4,"seq") 
		||!strcmp(message4,"Seq") 
		||!strcmp(message4,"SEQ")
		||!strcmp(message4,"a")
		||!strcmp(message4,"A"))
	{
		//setup variable
		if (intCountImg   > 0)
			intCountImg--;
		if (intCountText  > 0)
			intCountText--;
		if (intCountAudio > 0)
			intCountAudio--;

		//only seq
		if  (!strcmp(message4,"seq") || !strcmp(message4,"Seq") || !strcmp(message4,"SEQ")) 
		{
			//setup variable for find level od seq in this SMIL.
			intDaisy3Smil2BodySeqTempLevel--;
		}
		return;
	}
}

//void LoadDaisy3Smil2Handle::characters(const XMLCh*   const chars,	const unsigned int   length){}
//void LoadDaisy3Smil2Handle::fatalError(const SAXParseException& e){}
//void LoadDaisy3Smil2Handle::ignorableWhitespace(const XMLCh* const chars,const unsigned int length){}
//void LoadDaisy3Smil2Handle::resetDocument(){}
//void LoadDaisy3Smil2Handle::error(const SAXParseException& e){}
//void LoadDaisy3Smil2Handle::warning(const SAXParseException& e){}
//void LoadDaisy3Smil2Handle::resetErrors(){}				

//Header
string			LoadDaisy3Smil2Handle::getStrDaisy3Smil2HeadXmlNs(void)						{return strDaisy3Smil2HeadXmlNs;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadMetaName(void)					{return vecDaisy3Smil2HeadMetaName;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadMetaContent(void)				{return vecDaisy3Smil2HeadMetaContent;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionId(void)					{return vecDaisy3Smil2HeadRegionId;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionTop(void)					{return vecDaisy3Smil2HeadRegionTop;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionLeft(void)				{return vecDaisy3Smil2HeadRegionLeft;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionRight(void)				{return vecDaisy3Smil2HeadRegionRight;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionBottom(void)				{return vecDaisy3Smil2HeadRegionBottom;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionHeight(void)				{return vecDaisy3Smil2HeadRegionHeight;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionWidth(void)				{return vecDaisy3Smil2HeadRegionWidth;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionFit(void)					{return vecDaisy3Smil2HeadRegionFit;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionBackgroundColor(void)		{return vecDaisy3Smil2HeadRegionBackgroundColor;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionShowBackground(void)		{return vecDaisy3Smil2HeadRegionShowBackground;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionZIndex(void)				{return vecDaisy3Smil2HeadRegionZIndex;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadRegionXmlLang(void)				{return vecDaisy3Smil2HeadRegionXmlLang;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadCustomTestId(void)				{return vecDaisy3Smil2HeadCustomTestId;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadCustomTestDefaultState(void)	{return vecDaisy3Smil2HeadCustomTestDefaultState;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadCustomTestOverride(void)		{return vecDaisy3Smil2HeadCustomTestOverride;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadCustomTestClass(void)			{return vecDaisy3Smil2HeadCustomTestClass;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadCustomTestTitle(void)			{return vecDaisy3Smil2HeadCustomTestTitle;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2HeadCustomTestXmlLang(void) 		{return vecDaisy3Smil2HeadCustomTestXmlLang;}

//Body
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodySeqId(void)						{return vecDaisy3Smil2BodySeqId;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodySeqClass(void)					{return vecDaisy3Smil2BodySeqClass;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodySeqCustomTest(void)				{return vecDaisy3Smil2BodySeqCustomTest;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodySeqDur(void)					{return vecDaisy3Smil2BodySeqDur;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodySeqXmlLang(void)				{return vecDaisy3Smil2BodySeqXmlLang;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodySeqEnd(void)					{return vecDaisy3Smil2BodySeqEnd;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodySeqFill(void)					{return vecDaisy3Smil2BodySeqFill;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodySeqLevel(void)					{return vecDaisy3Smil2BodySeqLevel;}

vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyParId(void)						{return vecDaisy3Smil2BodyParId;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyParClass(void)					{return vecDaisy3Smil2BodyParClass;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyParCustomTest(void)				{return vecDaisy3Smil2BodyParCustomTest;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyParXmlLang(void)				{return vecDaisy3Smil2BodyParXmlLang;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyParLevel(void)					{return vecDaisy3Smil2BodyParLevel;}

vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAnchorId(void)					{return vecDaisy3Smil2BodyAnchorId;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAnchorClass(void)				{return vecDaisy3Smil2BodyAnchorClass;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAnchorTitle(void)				{return vecDaisy3Smil2BodyAnchorTitle;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAnchorXmlLang(void)				{return vecDaisy3Smil2BodyAnchorXmlLang;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAnchorHref(void)				{return vecDaisy3Smil2BodyAnchorHref;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAnchorExternal(void)			{return vecDaisy3Smil2BodyAnchorExternal;}

vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyImgId(void)						{return vecDaisy3Smil2BodyImgId;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyImgRegion(void)					{return vecDaisy3Smil2BodyImgRegion;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyImgSrc(void)					{return vecDaisy3Smil2BodyImgSrc;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyImgType(void)					{return vecDaisy3Smil2BodyImgType;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyImgXmlLang(void)				{return vecDaisy3Smil2BodyImgXmlLang;}

vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyTextId(void)					{return vecDaisy3Smil2BodyTextId;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyTextSrcFile(void)				{return vecDaisy3Smil2BodyTextSrcFile;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyTextSrcId(void)					{return vecDaisy3Smil2BodyTextSrcId;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyTextType(void)					{return vecDaisy3Smil2BodyTextType;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyTextRegion(void)				{return vecDaisy3Smil2BodyTextRegion;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyTextXmlLang(void)				{return vecDaisy3Smil2BodyTextXmlLang;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyTextContent(void)				{return vecDaisy3Smil2BodyTextContent;}

vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAudioId(void)					{return vecDaisy3Smil2BodyAudioId;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAudioSrc(void)					{return vecDaisy3Smil2BodyAudioSrc;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAudioType(void)					{return vecDaisy3Smil2BodyAudioType;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAudioClipBegin(void)			{return vecDaisy3Smil2BodyAudioClipBegin;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAudioClipEnd(void)				{return vecDaisy3Smil2BodyAudioClipEnd;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAudioRegion(void)				{return vecDaisy3Smil2BodyAudioRegion;}
vector<string>	LoadDaisy3Smil2Handle::getVecDaisy3Smil2BodyAudioXmlLang(void)				{return vecDaisy3Smil2BodyAudioXmlLang;}

void LoadDaisy3Smil2Handle::clearVector(void)
{
	//Header
	strDaisy3Smil2HeadXmlNs = "EmPtY";

	vecDaisy3Smil2HeadMetaName.clear();
	vecDaisy3Smil2HeadMetaContent.clear();
	
	vecDaisy3Smil2HeadRegionId.clear();
	vecDaisy3Smil2HeadRegionTop.clear();
	vecDaisy3Smil2HeadRegionLeft.clear();
	vecDaisy3Smil2HeadRegionRight.clear();
	vecDaisy3Smil2HeadRegionBottom.clear();
	vecDaisy3Smil2HeadRegionHeight.clear();
	vecDaisy3Smil2HeadRegionWidth.clear();
	vecDaisy3Smil2HeadRegionFit.clear();
	vecDaisy3Smil2HeadRegionBackgroundColor.clear();
	vecDaisy3Smil2HeadRegionShowBackground.clear();
	vecDaisy3Smil2HeadRegionZIndex.clear();
	vecDaisy3Smil2HeadRegionXmlLang.clear();
	
	vecDaisy3Smil2HeadCustomTestId.clear();
	vecDaisy3Smil2HeadCustomTestDefaultState.clear();
	vecDaisy3Smil2HeadCustomTestOverride.clear();
	vecDaisy3Smil2HeadCustomTestClass.clear();
	vecDaisy3Smil2HeadCustomTestTitle.clear();
	vecDaisy3Smil2HeadCustomTestXmlLang.clear();

	//Body
	intCountImg		= 0;
	intCountText	= 0;
	intCountAudio	= 0;
	boolNewImg		= false;
	boolNewText		= false;
	boolNewAudio	= false;
	
	strDaisy3Smil2BodySeqTempId = "EmPtY";
	strDaisy3Smil2BodySeqTempClass = "EmPtY";
	strDaisy3Smil2BodySeqTempCustomTest = "EmPtY";
	strDaisy3Smil2BodySeqTempDur = "EmPtY";
	strDaisy3Smil2BodySeqTempXmlLang = "EmPtY";
	strDaisy3Smil2BodySeqTempEnd = "EmPtY";
	strDaisy3Smil2BodySeqTempFill = "EmPtY";
	intDaisy3Smil2BodySeqTempLevel = 0;
	
	strDaisy3Smil2BodyParTempId = "EmPtY";
	strDaisy3Smil2BodyParTempClass = "EmPtY";
	strDaisy3Smil2BodyParTempCustomTest = "EmPtY";
	strDaisy3Smil2BodyParTempXmlLang = "EmPtY";
	intDaisy3Smil2BodyParTempLevel = 0;

	strDaisy3Smil2BodyAnchorTempId = "EmPtY";
	strDaisy3Smil2BodyAnchorTempClass = "EmPtY";
	strDaisy3Smil2BodyAnchorTempTitle = "EmPtY";
	strDaisy3Smil2BodyAnchorTempXmlLang = "EmPtY";
	strDaisy3Smil2BodyAnchorTempHref = "EmPtY";
	strDaisy3Smil2BodyAnchorTempExternal = "EmPtY";
	
	strDaisy3Smil2BodyImgTempId = "EmPtY";
	strDaisy3Smil2BodyImgTempRegion = "EmPtY";
	strDaisy3Smil2BodyImgTempSrc = "EmPtY";
	strDaisy3Smil2BodyImgTempType = "EmPtY";
	strDaisy3Smil2BodyImgTempXmlLang = "EmPtY";
	
	strDaisy3Smil2BodyTextTempId = "EmPtY";
	strDaisy3Smil2BodyTextTempSrc = "EmPtY";
	strDaisy3Smil2BodyTextTempType = "EmPtY";
	strDaisy3Smil2BodyTextTempRegion = "EmPtY";
	strDaisy3Smil2BodyTextTempXmlLang = "EmPtY";
	
	strDaisy3Smil2BodyAudioTempId = "EmPtY";
	strDaisy3Smil2BodyAudioTempSrc = "EmPtY";
	strDaisy3Smil2BodyAudioTempType = "EmPtY";
	strDaisy3Smil2BodyAudioTempClipBegin = "EmPtY";
	strDaisy3Smil2BodyAudioTempClipEnd = "EmPtY";
	strDaisy3Smil2BodyAudioTempRegion = "EmPtY";
	strDaisy3Smil2BodyAudioTempXmlLang = "EmPtY";

	vecDaisy3Smil2BodySeqId.clear();
	vecDaisy3Smil2BodySeqClass.clear();	
	vecDaisy3Smil2BodySeqCustomTest.clear();
	vecDaisy3Smil2BodySeqDur.clear();
	vecDaisy3Smil2BodySeqXmlLang.clear();
	vecDaisy3Smil2BodySeqEnd.clear();
	vecDaisy3Smil2BodySeqFill.clear();
	vecDaisy3Smil2BodySeqLevel.clear();
	
	vecDaisy3Smil2BodyParId.clear();
	vecDaisy3Smil2BodyParClass.clear();
	vecDaisy3Smil2BodyParCustomTest.clear();
	vecDaisy3Smil2BodyParXmlLang.clear();
	vecDaisy3Smil2BodyParLevel.clear();
	
	vecDaisy3Smil2BodyAnchorId.clear();
	vecDaisy3Smil2BodyAnchorClass.clear();
	vecDaisy3Smil2BodyAnchorTitle.clear();
	vecDaisy3Smil2BodyAnchorXmlLang.clear();
	vecDaisy3Smil2BodyAnchorHref.clear();
	vecDaisy3Smil2BodyAnchorExternal.clear();

	vecDaisy3Smil2BodyImgId.clear();
	vecDaisy3Smil2BodyImgRegion.clear();
	vecDaisy3Smil2BodyImgSrc.clear();
	vecDaisy3Smil2BodyImgType.clear();
	vecDaisy3Smil2BodyImgXmlLang.clear();
	
	vecDaisy3Smil2BodyTextId.clear();
	vecDaisy3Smil2BodyTextSrcFile.clear();
	vecDaisy3Smil2BodyTextSrcId.clear();
	vecDaisy3Smil2BodyTextType.clear();
	vecDaisy3Smil2BodyTextRegion.clear();
	vecDaisy3Smil2BodyTextXmlLang.clear();
	vecDaisy3Smil2BodyTextContent.clear();

	vecDaisy3Smil2BodyAudioId.clear();
	vecDaisy3Smil2BodyAudioSrc.clear();
	vecDaisy3Smil2BodyAudioType.clear();
	vecDaisy3Smil2BodyAudioClipBegin.clear();
	vecDaisy3Smil2BodyAudioClipEnd.clear();
	vecDaisy3Smil2BodyAudioRegion.clear();
	vecDaisy3Smil2BodyAudioXmlLang.clear();
}