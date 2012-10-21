#include "LoadDaisy3NcxHandle.h"

//This code provides capability to parser NCX file of DAISY3.00/NISO_Z39.86 Standards.
//The Navigation Control file for XML applications (NCX) provides 
//the reader efficient and flexible access to the hierarchical structure of a DTB 
//as well as direct access to selected elements such as page numbers, notes, figures, etc. 

LoadDaisy3NcxHandle::LoadDaisy3NcxHandle()
{
	//Reset all variable to default.
	LoadDaisy3NcxHandle::clearVector();
}

LoadDaisy3NcxHandle::~LoadDaisy3NcxHandle()
{
}

void LoadDaisy3NcxHandle::startElement(const XMLCh* const uri,
									   const XMLCh* const localname,
									   const XMLCh* const qname,
									   const Attributes& att)
{
	char* message1 = XMLString::transcode(localname);
	char* message2;
	XMLCh* myXMLCh;

	//////////////////////////////////////////////////////////////////////////////////////
	// NCX                                                           (in)finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"ncx")  
		||!strcmp(message1,"Ncx") 
		||!strcmp(message1,"NCX"))
	{
		//xmlns (CDATA, FIXED) "http://www.daisy.org/z3986/2005/ncx/": Specifies the default XML namespace for all elements in the NCX. See [XML-Namespaces] for details on namespaces. This attribute and its value (given in DTD) must be explicitly specified in the document instance. 
		try
		{
			myXMLCh = XMLString::transcode("xmlns");
			message2 = XMLString::transcode(att.getValue(myXMLCh));
			if (message2 == NULL)	strDaisy3NcxXmlNs = "http://www.daisy.org/z3986/2005/ncx/";
			else					strDaisy3NcxXmlNs = message2;			
			XMLString::release(&myXMLCh);
			XMLString::release(&message2);


			//strDaisy3NcxXmlNs				= XMLString::transcode(att.getValue(XMLString::transcode("xmlns")));
		}
		catch (...)
		{
			strDaisy3NcxXmlNs				= "http://www.daisy.org/z3986/2005/ncx/";
			cout << "<Warning::LoadDaisy3NcxHandle::startElement::ncx> This NCX has empty xmlns in ncx tag." << endl;
		}

		//version (CDATA, FIXED) "2005-1"	: Specifies the version of the DTD used in this instance. This attribute and its value (given in DTD) must be explicitly specified in the document instance. 
		try
		{
			myXMLCh = XMLString::transcode("version");
			message2 = XMLString::transcode(att.getValue(myXMLCh));
			if (message2 == NULL)	strDaisy3NcxVersion = "2005-1";
			else					strDaisy3NcxVersion = message2;			
			XMLString::release(&myXMLCh);
			XMLString::release(&message2);


			//strDaisy3NcxVersion				= XMLString::transcode(att.getValue(XMLString::transcode("version")));
		}
		catch (...)
		{
			strDaisy3NcxVersion				= "2005-1";
			cout << "<Warning::LoadDaisy3NcxHandle::startElement::ncx> This NCX has empty version in ncx tag." << endl;
		}
		
		//xml:lang (NMTOKEN, IMPLIED)		: Specifies the [RFC 3066] language code of the language of the document.
		try
		{
			myXMLCh = XMLString::transcode("xml:lang");
			message2 = XMLString::transcode(att.getValue(myXMLCh));
			if (message2 == NULL)	strDaisy3NcxVersion = "th";
			else					strDaisy3NcxVersion = message2;			
			XMLString::release(&myXMLCh);
			XMLString::release(&message2);

			//strDaisy3NcxXmlLanguage			= XMLString::transcode(att.getValue(XMLString::transcode("xml:lang")));
		}
		catch (...)
		{
			strDaisy3NcxXmlLanguage			= "th"; //need localization
			cout << "<Warning::LoadDaisy3NcxHandle::startElement::ncx> This NCX has empty xml:lang in ncx tag." << endl;
		}

		//This is infinite element but I don't setup variable for checking the NCX level for this version.
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// smilCustomTest		                                             finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"smilCustomTest")  
		||!strcmp(message1,"smilcustomtest") 
		||!strcmp(message1,"SMILCUSTOMTEST"))
	{
		//ตรวจสอบที่ id ก่อนถ้าไม่มี id ก็ถือว่าไม่มี meta นั้นเลย
		if (att.getIndex(XMLString::transcode("id")) != -1 )
		{
			//id (ID, REQUIRED)
			try
			{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));
				vecDaisy3NcxCustomTestId.push_back(message2);
			}
			catch (...)
			{
				vecDaisy3NcxCustomTestId.push_back("EmPtY");
                cout << "<Warning::LoadDaisy3NcxHandle::startElement::smilCustomTest> This NCX has empty id in smilCustomTest tag." << endl;
				cout << "<Warning::LoadDaisy3NcxHandle::startElement::smilCustomTest> This is a serious warning on programming syntax please contact programmer." << endl;
			}
			
			//defaultState (true | false) 'false' 
			try
			{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("defaultState")));
				vecDaisy3NcxCustomTestDefaultState.push_back(message2);
			}
			catch (...)
			{
				vecDaisy3NcxCustomTestDefaultState.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3NcxHandle::startElement::smilCustomTest> This NCX has empty defaultState in smilCustomTest tag." << endl;
			}
			
			//override (visible | hidden) 'hidden' 
			try
			{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("override")));
				vecDaisy3NcxCustomTestOverride.push_back(message2);
			}
			catch (...)
			{
				vecDaisy3NcxCustomTestOverride.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3NcxHandle::startElement::smilCustomTest> This NCX has empty override in smilCustomTest tag." << endl;
			}
			
			//bookStruct (PAGE_NUMBER | NOTE | NOTE_REFERENCE | ANNOTATION | LINE_NUMBER | OPTIONAL_SIDEBAR | OPTIONAL_PRODUCER_NOTE) #IMPLIED
			try
			{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("bookStruct")));
				vecDaisy3NcxCustomTestBookStruct.push_back(message2);
			}
			catch (...)
			{
				vecDaisy3NcxCustomTestBookStruct.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3NcxHandle::startElement::smilCustomTest> This NCX has empty bookStruct in smilCustomTest tag." << endl;
			}
		}
		else
		{
			cout << "<Warning::LoadDaisy3NcxHandle::startElement::smilCustomTest>This NCX has empty id in smilCustomTest tag." << endl;
		}
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// meta																 finite element //
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
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("name")));
				vecDaisy3NcxMetaName.push_back(message2);
			}
			catch (...)
			{
				vecDaisy3NcxMetaName.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3NcxHandle::startElement::meta> This NCX has empty name in meta tag." << endl;
				cout << "<Warning::LoadDaisy3NcxHandle::startElement::meta> This is a serious warning on programming syntax please contact programmer" << endl;
			}

			//content (CDATA, REQUIRED)
			try
			{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("content")));
				vecDaisy3NcxMetaContent.push_back(message2);
			}
			catch (...)
			{
				vecDaisy3NcxMetaContent.push_back("EmPtY");
				cout << "<Warning::LoadDaisy3NcxHandle::startElement::meta> This NCX has empty content in meta tag." << endl;
			}

			//scheme (CDATA, IMPLIED) 
			try
			{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("scheme")));
				vecDaisy3NcxMetaScheme.push_back(message2);
			}
			catch (...)
			{
				vecDaisy3NcxMetaScheme.push_back("EmPtY");
			}
		}
		else
		{
			cout << "<Warning::LoadDaisy3NcxHandle::startElement::meta> This NCX has empty name in meta tag." << endl;
		}
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// docTitle                                                        infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"docTitle")  
		||!strcmp(message1,"doctitle") 
		||!strcmp(message1,"DOCTITLE"))
	{
		//id (ID, IMPLIED): Optional unique identifier
		//I've waive for this version.

		//setup variable
		boolWaitDocTitleText	= true;
		boolWaitDocTitleAudio	= true;
		boolWaitDocTitleImage	= true;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// docAuthor                                                       infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"docAuthor")  
		||!strcmp(message1,"docauthor") 
		||!strcmp(message1,"DOCAUTHOR"))
	{
		//id (ID, IMPLIED): Optional unique identifier
		//I've waive for this version.

		//setup variable
		boolWaitDocAuthorText	= true;
		boolWaitDocAuthorAudio	= true;
		boolWaitDocAuthorImage	= true;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Audio for docTitle                                                finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"audio")  
		||!strcmp(message1,"Audio") 
		||!strcmp(message1,"AUDIO")) && boolWaitDocTitleAudio)
	{
		//id (ID, IMPLIED): Optional unique identifier. 
		//I had waives it for this version.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element.
		//I had waives it for this version.

		//src (CDATA, REQUIRED): The URI of the audio media object. Ordinarily, this will point to an audio file containing the content of the DTB. However, when a DTB spans several media units, the URI can point to a file containing a clip of the heading or title referenced. See section 8.4.2, "DTBs Spanning Multiple Media Units." 
		strDaisy3NcxDocTitleAudioSrc = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		
		//clipBegin (%SMILtimeVal, REQUIRED): The clipBegin attribute specifies the beginning of a segment of a continuous media object as a time offset from the start of the media object. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. See section 7.7, "Media Clipping and Clock Values." 
		strDaisy3NcxDocTitleAudioBegin  = XMLString::transcode(att.getValue(XMLString::transcode("clipBegin")));
		
		//clipEnd (%SMILtimeVal, REQUIRED): The clipEnd attribute specifies the end of a segment of a continuous media object as a time offset from the start of the media object. It uses the same attribute value syntax as clipBegin. 
		strDaisy3NcxDocTitleAudioEnd  = XMLString::transcode(att.getValue(XMLString::transcode("clipEnd")));
		
		//setup variable
		boolWaitDocTitleAudio	= false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Audio for docAuthor                                               finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"audio")  
		||!strcmp(message1,"Audio") 
		||!strcmp(message1,"AUDIO")) && boolWaitDocAuthorAudio)
	{
		//id (ID, IMPLIED): Optional unique identifier. 
		//I had waives it for this version.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element.
		//I had waives it for this version.

		//src (CDATA, REQUIRED): The URI of the audio media object. Ordinarily, this will point to an audio file containing the content of the DTB. However, when a DTB spans several media units, the URI can point to a file containing a clip of the heading or title referenced. See section 8.4.2, "DTBs Spanning Multiple Media Units." 
		strDaisy3NcxDocAuthorAudioSrc	= XMLString::transcode(att.getValue(XMLString::transcode("src")));

		//clipBegin (%SMILtimeVal, REQUIRED): The clipBegin attribute specifies the beginning of a segment of a continuous media object as a time offset from the start of the media object. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. See section 7.7, "Media Clipping and Clock Values." 
		strDaisy3NcxDocAuthorAudioBegin	= XMLString::transcode(att.getValue(XMLString::transcode("clipBegin")));
		
		//clipEnd (%SMILtimeVal, REQUIRED): The clipEnd attribute specifies the end of a segment of a continuous media object as a time offset from the start of the media object. It uses the same attribute value syntax as clipBegin. 
		strDaisy3NcxDocAuthorAudioEnd	= XMLString::transcode(att.getValue(XMLString::transcode("clipEnd")));
		
		//setup variable
		boolWaitDocAuthorAudio	= false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Image for docTitle                                                finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"img")  
		||!strcmp(message1,"Img") 
		||!strcmp(message1,"IMG")) && boolWaitDocTitleImage)
	{
		//id (ID, IMPLIED)		: Optional unique identifier. 
		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element. 
		//I have waived for this version.
		
		//src (CDATA, REQUIRED)	: The URI of the media object.
		strDaisy3NcxDocTitleImageSrc = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		//setup variable
		boolWaitDocTitleImage = false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Image for docAuthor                                               finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"img")  
		||!strcmp(message1,"Img") 
		||!strcmp(message1,"IMG")) && boolWaitDocAuthorImage)
	{
		//id (ID, IMPLIED): Optional unique identifier.
		//I had waives it for this version.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element.
		//I had waives it for this version.

		//src (CDATA, REQUIRED): The URI of the media object.
		strDaisy3NcxDocAuthorImageSrc = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		
		//setup variable
		boolWaitDocAuthorImage = false;
		return;
	}







	//////////////////////////////////////////////////////////////////////////////////////
	// navMap, pageList, navList                                       infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	
	if  ( !strcmp(message1,"navMap")   || !strcmp(message1,"NavMap")   || !strcmp(message1,"Navmap")   || !strcmp(message1,"navmap")   || !strcmp(message1,"NAVMAP")
		||!strcmp(message1,"pageList") || !strcmp(message1,"PageList") || !strcmp(message1,"Pagelist") || !strcmp(message1,"pagelist") || !strcmp(message1,"PAGELIST")
		||!strcmp(message1,"navList")  || !strcmp(message1,"NavList")  || !strcmp(message1,"Navlist")  || !strcmp(message1,"navlist")  || !strcmp(message1,"NAVLIST"))
	{	
		//id (ID, IMPLIED): Optional unique identifier.
		try		
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));
			vecDaisy3NcxPartId.push_back(message2);
		}
		catch (...)
		{
			vecDaisy3NcxPartId.push_back("EmPtY");
		}
		
		//class (CDATA, IMPLIED): Optional descriptor of the element. Can be used to select a presentation from the resource file. See section 10.3, "Resource File Requirements." 
		char* chrThisHeadClass = ""; //สำหรับเอาไปเปรียบเทียบว่า class="pagenum" หรือไม่ เพื่อแก้ไขปัญหาของ bookshare.org
		try		
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("class")));
			vecDaisy3NcxPartClass.push_back(message2);
			chrThisHeadClass = message2;
		}
		catch (...)
		{
			vecDaisy3NcxPartClass.push_back("EmPtY");
		}

		//ตรงนี้ทำไว้สำหรับหนังสือ DAISY3 Text Only ของ Bookshare.org ที่ไม่ยอมใช้ pageTarget ในการระบุหน้าของหนังสือแต่ดันใช้ navTarget ระบุแทน
		//แต่ก็ยังดีที่บอก class="pagenum" เอาไว้เลยสามารถไปเก็บเอาตัวแปรมาตรวจสอบได้
		if (!strcmp(chrThisHeadClass,"pagenum") || !strcmp(chrThisHeadClass,"Pagenum") || !strcmp(chrThisHeadClass,"pageNum") ||!strcmp(chrThisHeadClass,"PageNum") || !strcmp(chrThisHeadClass,"PAGENUM")||
			!strcmp(chrThisHeadClass,"pagenums")|| !strcmp(chrThisHeadClass,"Pagenums")|| !strcmp(chrThisHeadClass,"pageNums")||!strcmp(chrThisHeadClass,"PageNums")|| !strcmp(chrThisHeadClass,"PAGENUMS"))
		{
			vecDaisy3NcxPartKind.push_back("pageList");
		}
		else
		{
			//automatic store a kind of part.
			vecDaisy3NcxPartKind.push_back(message1);
		}

		//automatic store the position of child items in body.
		_itoa_s(vecDaisy3NcxBodyId.size(), a, 10);
		vecDaisy3NcxPartPositionInBody.push_back(a);

		//setup variable
		boolWaitHeadNavInfoText		= true;          //character function
		boolWaitHeadNavInfoAudio	= true;			 //startElement function
		boolWaitHeadNavInfoImage	= true;			 //startElement function
		boolWaitHeadNavLabelText	= true;          //character function
		boolWaitHeadNavLabelAudio	= true;			 //startElement function
		boolWaitHeadNavLabelImage	= true;			 //startElement function
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// audio for navMap, pageList, navList								 finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"audio")
		||!strcmp(message1,"Audio")
		||!strcmp(message1,"AUDIO")) && boolWaitHeadNavInfoAudio && !boolWaitNavLabelAudio) //ถ้าส่วนที่เป็น Nav มีค่าเท่ากับ true จะไม่มีการบันทึกค่าในส่วน HeadNav
	{
		//id (ID, IMPLIED): Optional unique identifier. 
		//I had waives it for this version.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element.
		//I had waives it for this version.

		//src (CDATA, REQUIRED)				: The URI of the audio media object. Ordinarily, this will point to an audio file containing the content of the DTB. However, when a DTB spans several media units, the URI can point to a file containing a clip of the heading or title referenced. See section 8.4.2, "DTBs Spanning Multiple Media Units." 
		message2							= XMLString::transcode(att.getValue(XMLString::transcode("src")));
		vecDaisy3NcxPartNavInfoAudioSrc.push_back(message2);	

		//clipBegin (%SMILtimeVal, REQUIRED): The clipBegin attribute specifies the beginning of a segment of a continuous media object as a time offset from the start of the media object. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. See section 7.7, "Media Clipping and Clock Values." 
		message2							= XMLString::transcode(att.getValue(XMLString::transcode("clipBegin")));
		vecDaisy3NcxPartNavInfoAudioBegin.push_back(message2);

		//clipEnd (%SMILtimeVal, REQUIRED)	: The clipEnd attribute specifies the end of a segment of a continuous media object as a time offset from the start of the media object. It uses the same attribute value syntax as clipBegin. 
		message2							= XMLString::transcode(att.getValue(XMLString::transcode("clipEnd")));
		vecDaisy3NcxPartNavInfoAudioEnd.push_back(message2);

		//setup variable
		boolWaitHeadNavInfoAudio	= false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Image for navMap, pageList, navList                               finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"img")  
		||!strcmp(message1,"Img") 
		||!strcmp(message1,"IMG")) && boolWaitHeadNavInfoImage  && !boolWaitNavLabelImage) //ถ้าส่วนที่เป็น Nav มีค่าเท่ากับ true จะไม่มีการบันทึกค่าในส่วน HeadNav
	{
		//id (ID, IMPLIED): Optional unique identifier.
		//I had waives it for this version.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element.
		//I had waives it for this version.

		//src (CDATA, REQUIRED): The URI of the media object.
		message2 = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		vecDaisy3NcxPartNavInfoImageSrc.push_back(message2);
		
		//setup variable
		boolWaitHeadNavInfoImage = false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// audio for navMap, pageList, navList		                         finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"audio")  
		||!strcmp(message1,"Audio") 
		||!strcmp(message1,"AUDIO")) && boolWaitHeadNavLabelAudio && !boolWaitNavLabelAudio) //ถ้าส่วนที่เป็น Nav มีค่าเท่ากับ true จะไม่มีการบันทึกค่าในส่วน HeadNav
	{
		//id (ID, IMPLIED): Optional unique identifier. 
		//I had waives it for this version.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element.
		//I had waives it for this version.

		//src (CDATA, REQUIRED)				: The URI of the audio media object. Ordinarily, this will point to an audio file containing the content of the DTB. However, when a DTB spans several media units, the URI can point to a file containing a clip of the heading or title referenced. See section 8.4.2, "DTBs Spanning Multiple Media Units." 
		message2							= XMLString::transcode(att.getValue(XMLString::transcode("src")));
		vecDaisy3NcxPartNavLabelAudioSrc.push_back(message2);

		//clipBegin (%SMILtimeVal, REQUIRED): The clipBegin attribute specifies the beginning of a segment of a continuous media object as a time offset from the start of the media object. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. See section 7.7, "Media Clipping and Clock Values." 
		message2							= XMLString::transcode(att.getValue(XMLString::transcode("clipBegin")));
		vecDaisy3NcxPartNavLabelAudioBegin.push_back(message2);

		//clipEnd (%SMILtimeVal, REQUIRED)	: The clipEnd attribute specifies the end of a segment of a continuous media object as a time offset from the start of the media object. It uses the same attribute value syntax as clipBegin. 
		message2							= XMLString::transcode(att.getValue(XMLString::transcode("clipEnd")));
		vecDaisy3NcxPartNavLabelAudioEnd.push_back(message2);

		//setup variable
		boolWaitHeadNavLabelAudio	= false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Image for navMap, pageList, navList                               finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"img")  
		||!strcmp(message1,"Img") 
		||!strcmp(message1,"IMG")) && boolWaitHeadNavLabelImage && !boolWaitNavLabelImage) //ถ้าส่วนที่เป็น Nav มีค่าเท่ากับ true จะไม่มีการบันทึกค่าในส่วน HeadNav
	{
		//id (ID, IMPLIED): Optional unique identifier.
		//I had waives it for this version.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element.
		//I had waives it for this version.

		//src (CDATA, REQUIRED): The URI of the media object.
		message2 = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		vecDaisy3NcxPartNavLabelImageSrc.push_back(message2);
		
		//setup variable
		boolWaitHeadNavLabelImage = false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// navPoint, pageTarget, navTarget                                 infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"navPoint")   || !strcmp(message1,"NavPoint")   || !strcmp(message1,"Navpoint")   || !strcmp(message1,"navpoint")   || !strcmp(message1,"NAVPOINT")
		||!strcmp(message1,"pageTarget") || !strcmp(message1,"PageTarget") || !strcmp(message1,"Pagetarget") || !strcmp(message1,"pagetarget") || !strcmp(message1,"PAGETARGET")
		||!strcmp(message1,"navTarget")  || !strcmp(message1,"NavTarget")  || !strcmp(message1,"Navtarget")  || !strcmp(message1,"navtarget")  || !strcmp(message1,"NAVTARGET"))
	{
		//id (ID, REQUIRED): Unique identifier.
		try
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("id")));
			vecDaisy3NcxBodyId.push_back(message2);
		}
		catch (...)
		{
			vecDaisy3NcxBodyId.push_back("EmPtY");
			cout << "<Warning::LoadDaisy3NcxHandle::startElement::navPoint,pageTarget,navTarget> This NCX has empty id in " << message1 << " tag." << endl;
		}
		
		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element. Can be used to select a presentation from the resource file. See section 10.3, "Resource File Requirements." 
		char* chrThisClass = ""; //สำหรับเอาไปเปรียบเทียบว่า class="pagenum" หรือไม่ เพื่อแก้ไขปัญหาของ bookshare.org
		try		
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("class")));
			vecDaisy3NcxBodyClass.push_back(message2);
			chrThisClass = message2;
		}
		catch (...)
		{
			vecDaisy3NcxBodyClass.push_back("EmPtY");
			chrThisClass = "";
			cout << "<Warning::LoadDaisy3NcxHandle::startElement::navPoint,pageTarget,navTarget> This NCX has empty class in " << message1 << " tag." << endl;
		}

		//playOrder (CDATA, REQUIRED): Positive integer denoting the location of the content of this navPoint in the default playing sequence. See section 8.4.3, "playOrder Attribute." 
		try
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("playOrder")));
			vecDaisy3NcxBodyPlayOrder.push_back(message2);		
		}
		catch (...)
		{
			vecDaisy3NcxBodyPlayOrder.push_back("EmPtY");
			cout << "<Warning::LoadDaisy3NcxHandle::startElement::navPoint,pageTarget,navTarget> This NCX has empty playOrder in " << message1 << " tag." << endl;
		}

		if  ( !strcmp(message1,"navPoint") || !strcmp(message1,"NavPoint") || !strcmp(message1,"Navpoint") ||!strcmp(message1,"navpoint") || !strcmp(message1,"NAVPOINT"))
		{
			//genarate Heading order like DAISY 2.02 for convetion purpose! (for navPoint Only)
			string strTempInput;
			_itoa_s(intNavMapHeaderStatus, a, 10);
			strTempInput = "H";
			strTempInput.append(a);
			intNavMapHeaderStatus++;

			//Store Type & Kind of message1
			vecDaisy3NcxBodyType.push_back(strTempInput);
			vecDaisy3NcxBodyKind.push_back("navPoint");
		}
		else if ( !strcmp(message1,"pageTarget") || !strcmp(message1,"PageTarget") || !strcmp(message1,"Pagetarget") ||!strcmp(message1,"pagetarget") || !strcmp(message1,"PAGETARGET"))
		{
			//Store Type & Kind of message1
			vecDaisy3NcxBodyType.push_back("pageTarget");
			vecDaisy3NcxBodyKind.push_back("pageTarget");
		}
		else if ( !strcmp(message1,"navTarget") || !strcmp(message1,"NavTarget") || !strcmp(message1,"Navtarget") ||!strcmp(message1,"navtarget") || !strcmp(message1,"NAVTARGET"))
		{
			//ตรงนี้ทำไว้สำหรับหนังสือ DAISY3 Text Only ของ Bookshare.org ที่ไม่ยอมใช้ pageTarget ในการระบุหน้าของหนังสือแต่ดันใช้ navTarget ระบุแทน
			//แต่ก็ยังดีที่บอก class="pagenum" เอาไว้เลยสามารถไปเก็บเอาตัวแปรมาตรวจสอบได้
			if (!strcmp(chrThisClass,"pagenum") || !strcmp(chrThisClass,"Pagenum") || !strcmp(chrThisClass,"pageNum") ||!strcmp(chrThisClass,"PageNum") || !strcmp(chrThisClass,"PAGENUM")||
			    !strcmp(chrThisClass,"pagenums")|| !strcmp(chrThisClass,"Pagenums")|| !strcmp(chrThisClass,"pageNums")||!strcmp(chrThisClass,"PageNums")|| !strcmp(chrThisClass,"PAGENUMS"))
			{
				//Store Type & Kind of message1
				vecDaisy3NcxBodyType.push_back("pageTarget");
				vecDaisy3NcxBodyKind.push_back("pageTarget");
			}
			else
			{
				//Store Type & Kind of message1
				vecDaisy3NcxBodyType.push_back("navTarget");
				vecDaisy3NcxBodyKind.push_back("navTarget");
			}
		}

		//setup variable
		boolWaitNavLabelText	= true;
		boolWaitNavLabelAudio	= true;
		boolWaitNavLabelImage	= true;
		boolWaitNavLabelContent	= true;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Content for navPoint,pageList,navTarget                           finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"content")  
		||!strcmp(message1,"Content") 
		||!strcmp(message1,"CONTENT")) && boolWaitNavLabelContent)
	{
		//src (CDATA, REQUIRED): The URI of the SMIL time container corresponding to the start of the referenced part of the document. 
		message2 = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		//seperate between FileName and id
		string strTempInput = message2;
		vecDaisy3NcxBodyLinkFile.push_back(strTempInput.substr(0,strTempInput.find("#")));
		vecDaisy3NcxBodyLinkId.push_back(strTempInput.substr(strTempInput.find("#")+1));		
	
		//setup variable
		boolWaitNavLabelContent = false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Audio for navPoint,pageList,navTarget                             finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"audio")  
		||!strcmp(message1,"Audio") 
		||!strcmp(message1,"AUDIO")) && boolWaitNavLabelAudio)
	{
		//id (ID, IMPLIED): Optional unique identifier. 
		//I had waives it for this version.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element.
		//I had waives it for this version.

		//src (CDATA, REQUIRED): The URI of the audio media object. Ordinarily, this will point to an audio file containing the content of the DTB. However, when a DTB spans several media units, the URI can point to a file containing a clip of the heading or title referenced. See section 8.4.2, "DTBs Spanning Multiple Media Units." 
		message2 = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		vecDaisy3NcxBodyAudioSrc.push_back(message2);
		
		//clipBegin (%SMILtimeVal, REQUIRED): The clipBegin attribute specifies the beginning of a segment of a continuous media object as a time offset from the start of the media object. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. See section 7.7, "Media Clipping and Clock Values." 
		message2 = XMLString::transcode(att.getValue(XMLString::transcode("clipBegin")));
		vecDaisy3NcxBodyAudioBegin.push_back(message2);
		
		//clipEnd (%SMILtimeVal, REQUIRED): The clipEnd attribute specifies the end of a segment of a continuous media object as a time offset from the start of the media object. It uses the same attribute value syntax as clipBegin. 
		message2 = XMLString::transcode(att.getValue(XMLString::transcode("clipEnd")));
		vecDaisy3NcxBodyAudioEnd.push_back(message2);
		
		//setup variable
		boolWaitNavLabelAudio	= false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Image for navPoint,pageList,navTarget                             finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"img")  
		||!strcmp(message1,"Img") 
		||!strcmp(message1,"IMG")) && boolWaitNavLabelImage)
	{
		//id (ID, IMPLIED): Optional unique identifier.
		//I had waives it for this version.

		//class (CDATA, IMPLIED): Optional descriptor of this instance of the element.
		//I had waives it for this version.

		//src (CDATA, REQUIRED): The URI of the media object.
		message2 = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		vecDaisy3NcxBodyImageSrc.push_back(message2);
		
		//setup variable
		boolWaitNavLabelImage = false;
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////
	// Text for all													   infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ((!strcmp(message1,"text")  
		||!strcmp(message1,"Text") 
		||!strcmp(message1,"TEXT")))
	{
		boolWaitForAllCharacters = true;
		return;
	}
}

void LoadDaisy3NcxHandle::characters(const XMLCh*   const chars,
									 const unsigned int   length)
{
	if (boolWaitForAllCharacters == false)
	{
		return;
	}
	else
	{
		boolWaitForAllCharacters = false;
	}
	string message3 = removeWhitespace(XMLString::transcode(chars));

	//Description: Contains the text of a <docTitle> or <docAuthor> or text content of a <navLabel> or <navInfo>.
	if (!message3.empty())
	{
		message3 = XMLString::transcode(chars);
		
		//Description: Contains the text of a <docTitle>
		//Syntax: <text ...attributes...>...content...</text>
		if (boolWaitDocTitleText == true)
		{
			strDaisy3NcxDocTitleText = message3;
 			boolWaitDocTitleText	 = false;
			return;
		}
		
		//Description: Contains the text of a <docAuthor>
		//Syntax: <text ...attributes...>...content...</text>
		if (boolWaitDocAuthorText == true)
		{
			strDaisy3NcxDocAuthorText = message3;
 			boolWaitDocAuthorText	 = false;
			return;
		}

		//Description: Contains the text of a <navInfo>
		//Syntax: <text ...attributes...>...content...</text>
		//ถ้าส่วนที่เป็น Nav มีค่าเท่ากับ true จะไม่มีการบันทึกค่าในส่วน HeadNav
		if ((boolWaitHeadNavInfoText == true) && !boolWaitNavLabelText)
		{
			vecDaisy3NcxPartNavInfoText.push_back(message3);
			boolWaitHeadNavInfoText = false;
			return;
		}

		//Description: Contains the text of a <navLabel> (Part)
		//Syntax: <text ...attributes...>...content...</text>
		//ถ้าส่วนที่เป็น Nav มีค่าเท่ากับ true จะไม่มีการบันทึกค่าในส่วน HeadNav
		if ((boolWaitHeadNavLabelText == true) && !boolWaitNavLabelText)
		{
			vecDaisy3NcxPartNavLabelText.push_back(message3);
			boolWaitHeadNavLabelText = false;
			return;
		}

		//Description: Contains the text of a <navLabel> (Body)
		//Syntax: <text ...attributes...>...content...</text>
		if (boolWaitNavLabelText == true) 
		{
			vecDaisy3NcxBodyName.push_back(message3);
			boolWaitNavLabelText = false;
			return;
		}
	}
}

void LoadDaisy3NcxHandle::endElement  (const XMLCh *const uri, 
									   const XMLCh *const localname, 
									   const XMLCh *const qName)
{
	char* message4 = XMLString::transcode(localname);
	
	//Check the variable which there are value is true;
	//		TRUE  means don't pass its function for store data from file to our variable.
	//		FALSE means complete, don't do anything more!
	
	/////////////////////////////////////
	// Checking endElement of docTitle //
	/////////////////////////////////////
	if  ( !strcmp(message4,"docTitle")  
		||!strcmp(message4,"doctitle") 
		||!strcmp(message4,"DOCTITLE"))
	{
		if (boolWaitDocTitleText == true)
		{
			//Incomplete (without text in docTitle) but don't worry because if there values are exist, there will be store in string. Then its position order is insignificant.
			//However I added "EmPtY" value for convenient to check when I's reading it from variable.

			//Description: Contains the text of a <docTitle>
			//Syntax: <text ...attributes...>...content...</text>
			strDaisy3NcxDocTitleText	= "EmPtY";
			//setup variable
			boolWaitDocTitleText		= false;
		}
		
		if (boolWaitDocTitleAudio == true)
		{
			//Incomplete (without Audio in docTitle) but don't worry because if there values are exist, there will be store in string. Then its position order is insignificant.
			//However I added "EmPtY" values for convenient to check when I's read it from variable.

			//src (CDATA, REQUIRED): The URI of the audio media object. Ordinarily, this will point to an audio file containing the content of the DTB. However, when a DTB spans several media units, the URI can point to a file containing a clip of the heading or title referenced. See section 8.4.2, "DTBs Spanning Multiple Media Units." 
			strDaisy3NcxDocTitleAudioSrc	= "EmPtY";
			//clipBegin (%SMILtimeVal, REQUIRED): The clipBegin attribute specifies the beginning of a segment of a continuous media object as a time offset from the start of the media object. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. See section 7.7, "Media Clipping and Clock Values." 
			strDaisy3NcxDocTitleAudioBegin	= "EmPtY";
			//clipEnd (%SMILtimeVal, REQUIRED): The clipEnd attribute specifies the end of a segment of a continuous media object as a time offset from the start of the media object. It uses the same attribute value syntax as clipBegin. 
			strDaisy3NcxDocTitleAudioEnd	= "EmPtY";
			//setup variable
			boolWaitDocTitleAudio	= false;
		}

		if (boolWaitDocTitleImage == true)
		{
			//Incomplete (without Image in docTitle) but don't worry because if there values are exist, there will be store in string. Then its position order is insignificant.
			//However I added "EmPtY" value for convenient to check when I's reading it from variable.

			//src (CDATA, REQUIRED)	: The URI of the media object.
			strDaisy3NcxDocTitleImageSrc	= "EmPtY";
			//setup variable
			boolWaitDocTitleImage			= false;
		}
		return;
	}

	//////////////////////////////////////
	// Checking endElement of docAuthor //
	//////////////////////////////////////
	if  ( !strcmp(message4,"docAuthor")  
		||!strcmp(message4,"docauthor") 
		||!strcmp(message4,"DOCAUTHOR"))
	{
		
		if (boolWaitDocAuthorText == true)
		{
			//Incomplete (without text in docAuthor) but don't worry because if there values are exist, there will be store in string. Then its position order is insignificant.
			//However I added "EmPtY" value for convenient to check when I's reading it from variable.

			//Description: Contains the text of a <docAuthor>
			//Syntax: <text ...attributes...>...content...</text>
			strDaisy3NcxDocAuthorText	= "EmPtY";
			//setup variable
			boolWaitDocAuthorText		= false;
		}
		
		if (boolWaitDocAuthorAudio == true)
		{
			//Incomplete (without Audio in docAuthor) but don't worry because if there values are exist, there will be store in string. Then its position order is insignificant.
			//However I added "EmPtY" values for convenient to check when I's reading it from variable.

			//src (CDATA, REQUIRED): The URI of the audio media object. Ordinarily, this will point to an audio file containing the content of the DTB. However, when a DTB spans several media units, the URI can point to a file containing a clip of the heading or title referenced. See section 8.4.2, "DTBs Spanning Multiple Media Units." 
			strDaisy3NcxDocAuthorAudioSrc	= "EmPtY";
			//clipBegin (%SMILtimeVal, REQUIRED): The clipBegin attribute specifies the beginning of a segment of a continuous media object as a time offset from the start of the media object. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. See section 7.7, "Media Clipping and Clock Values." 
			strDaisy3NcxDocAuthorAudioBegin	= "EmPtY";
			//clipEnd (%SMILtimeVal, REQUIRED): The clipEnd attribute specifies the end of a segment of a continuous media object as a time offset from the start of the media object. It uses the same attribute value syntax as clipBegin. 
			strDaisy3NcxDocAuthorAudioEnd	= "EmPtY";
			//setup variable
			boolWaitDocAuthorAudio	= false;
		}

		if (boolWaitDocAuthorImage == true)
		{
			//Incomplete (without Image in docImage) but don't worry because if there values are exist, there will be store in string. Then its position order is insignificant.
			//However I added "EmPtY" value for convenient to check when I's reading it from variable.

			//src (CDATA, REQUIRED)	: The URI of the media object.
			strDaisy3NcxDocAuthorImageSrc	= "EmPtY";
			//setup variable		
			boolWaitDocAuthorImage			= false;
		}	
		return;
	}

	////////////////////////////////////////////////////////////
	// Checking endElement of navMap, pageList, navList(Part) //
	////////////////////////////////////////////////////////////
	if  ( !strcmp(message4,"navMap")   || !strcmp(message4,"NavMap")   || !strcmp(message4,"Navmap")   || !strcmp(message4,"navmap")   || !strcmp(message4,"NAVMAP")
		||!strcmp(message4,"pageList") || !strcmp(message4,"PageList") || !strcmp(message4,"Pagelist") || !strcmp(message4,"pagelist") || !strcmp(message4,"PAGELIST")
		||!strcmp(message4,"navList")  || !strcmp(message4,"NavList")  || !strcmp(message4,"Navlist")  || !strcmp(message4,"navlist")  || !strcmp(message4,"NAVLIST"))
	{
		//Don't concern 4 vectors below because it was concern during startElement.
		//  1.vecDaisy3NcxPartKind   //navMap, PageList, navList
		//  2.vecDaisy3NcxPartId
		//  3.vecDaisy3NcxPartClass
		//  4.vecDaisy3NcxPartPositionInBody
	
		if (boolWaitHeadNavInfoText == true)
		{
			vecDaisy3NcxPartNavInfoText.push_back("EmPtY");
			//setup variable
			boolWaitHeadNavInfoText = false;
		}
		
		if (boolWaitHeadNavInfoAudio == true)
		{
			vecDaisy3NcxPartNavInfoAudioSrc.push_back("EmPtY");
			vecDaisy3NcxPartNavInfoAudioBegin.push_back("EmPtY");
			vecDaisy3NcxPartNavInfoAudioEnd.push_back("EmPtY");
			//setup variable
			boolWaitHeadNavInfoAudio = false;
		}

		if (boolWaitHeadNavInfoImage == true)
		{
			vecDaisy3NcxPartNavInfoImageSrc.push_back("EmPtY");
			//setup variable
			boolWaitHeadNavInfoImage = false;
		}

		if (boolWaitHeadNavLabelText == true) 
		{
			vecDaisy3NcxPartNavLabelText.push_back("EmPtY");
			//setup variable
			boolWaitHeadNavLabelText = false;
		}
		
		if (boolWaitHeadNavLabelAudio == true)
		{
			vecDaisy3NcxPartNavLabelAudioSrc.push_back("EmPtY");
			vecDaisy3NcxPartNavLabelAudioBegin.push_back("EmPtY");
			vecDaisy3NcxPartNavLabelAudioEnd.push_back("EmPtY");
			//setup variable
			boolWaitHeadNavLabelAudio = false;
		}
		
		if (boolWaitHeadNavLabelImage == true)
		{
			vecDaisy3NcxPartNavLabelImageSrc.push_back("EmPtY");
			//setup variable
			boolWaitHeadNavLabelImage = false;
		}
		return;
	}

	/////////////////////////////////////////////////////////////////////
	// Checking endElement of navPoint, pageTarget, navTarget(Element) //
	/////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message4,"navPoint")   || !strcmp(message4,"NavPoint")   || !strcmp(message4,"Navpoint")   || !strcmp(message4,"navpoint")   || !strcmp(message4,"NAVPOINT")
		||!strcmp(message4,"pageTarget") || !strcmp(message4,"PageTarget") || !strcmp(message4,"Pagetarget") || !strcmp(message4,"pagetarget") || !strcmp(message4,"PAGETARGET")
		||!strcmp(message4,"navTarget")  || !strcmp(message4,"NavTarget")  || !strcmp(message4,"Navtarget")  || !strcmp(message4,"navtarget")  || !strcmp(message4,"NAVTARGET"))
	{	
		if (boolWaitNavLabelContent	== true)
		{
			vecDaisy3NcxBodyLinkFile.push_back("EmPtY");
			vecDaisy3NcxBodyLinkId.push_back("EmPtY");		
			//setup variable
			boolWaitNavLabelContent = false;
		}

		if (boolWaitNavLabelText == true)
		{
			vecDaisy3NcxBodyName.push_back("EmPtY");
			//setup variable
			boolWaitNavLabelText = false;
		}
		
		if (boolWaitNavLabelAudio == true)
		{
			//src (CDATA, REQUIRED): The URI of the audio media object. Ordinarily, this will point to an audio file containing the content of the DTB. However, when a DTB spans several media units, the URI can point to a file containing a clip of the heading or title referenced. See section 8.4.2, "DTBs Spanning Multiple Media Units." 
			vecDaisy3NcxBodyAudioSrc.push_back("EmPtY");
			//clipBegin (%SMILtimeVal, REQUIRED): The clipBegin attribute specifies the beginning of a segment of a continuous media object as a time offset from the start of the media object. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. See section 7.7, "Media Clipping and Clock Values." 
			vecDaisy3NcxBodyAudioBegin.push_back("EmPtY");
			//clipEnd (%SMILtimeVal, REQUIRED): The clipEnd attribute specifies the end of a segment of a continuous media object as a time offset from the start of the media object. It uses the same attribute value syntax as clipBegin. 
			vecDaisy3NcxBodyAudioEnd.push_back("EmPtY");
			//setup variable
			boolWaitNavLabelAudio = false;
		}

		if (boolWaitNavLabelImage == true)
		{
			vecDaisy3NcxBodyImageSrc.push_back("EmPtY");
			//setup variable
			boolWaitNavLabelImage = false;
		}

		//Decrese Heading level H1, H2, H3, H4, H5.
		if ( !strcmp(message4,"navPoint") || !strcmp(message4,"NavPoint") 
		   ||!strcmp(message4,"Navpoint") || !strcmp(message4,"navpoint") || !strcmp(message4,"NAVPOINT"))
		{	
			intNavMapHeaderStatus--;	
		}
		return;
	}
}

//void LoadDaisy3NcxHandle::fatalError(const SAXParseException& e){}
//void LoadDaisy3NcxHandle::ignorableWhitespace(const XMLCh* const chars,const unsigned int length){}
//void LoadDaisy3NcxHandle::resetDocument(){}
//void LoadDaisy3NcxHandle::error(const SAXParseException& e){}
//void LoadDaisy3NcxHandle::warning(const SAXParseException& e){}
//void LoadDaisy3NcxHandle::resetErrors(){}

//Header
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxCustomTestId(void)				{return vecDaisy3NcxCustomTestId;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxCustomTestDefaultState(void)	{return vecDaisy3NcxCustomTestDefaultState;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxCustomTestOverride(void)		{return vecDaisy3NcxCustomTestOverride;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxCustomTestBookStruct(void)		{return vecDaisy3NcxCustomTestBookStruct;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxMetaName(void)					{return vecDaisy3NcxMetaName;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxMetaContent(void)				{return vecDaisy3NcxMetaContent;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxMetaScheme(void)				{return vecDaisy3NcxMetaScheme;}

string		    LoadDaisy3NcxHandle::getStrDaisy3NcxVersion(void)					{return strDaisy3NcxVersion;}	
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxXmlLanguage(void)				{return strDaisy3NcxXmlLanguage;}
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxXmlNs(void)						{return strDaisy3NcxXmlNs;}

string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocTitleText(void)				{return strDaisy3NcxDocTitleText;}	
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocTitleAudioSrc(void)			{return strDaisy3NcxDocTitleAudioSrc;}	
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocTitleAudioBegin(void)		{return strDaisy3NcxDocTitleAudioBegin;}	
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocTitleAudioEnd(void)			{return strDaisy3NcxDocTitleAudioEnd;}	
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocTitleImageSrc(void)			{return strDaisy3NcxDocTitleImageSrc;}

string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocAuthorText(void)				{return strDaisy3NcxDocAuthorText;}	
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocAuthorAudioSrc(void)			{return strDaisy3NcxDocAuthorAudioSrc;}	
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocAuthorAudioBegin(void)		{return strDaisy3NcxDocAuthorAudioBegin;}	
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocAuthorAudioEnd(void)			{return strDaisy3NcxDocAuthorAudioEnd;}	
string		    LoadDaisy3NcxHandle::getStrDaisy3NcxDocAuthorImageSrc(void)			{return strDaisy3NcxDocAuthorImageSrc;}	

vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyKind(void)					{return vecDaisy3NcxBodyKind;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyType(void)					{return vecDaisy3NcxBodyType;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyClass(void)					{return vecDaisy3NcxBodyClass;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyId(void)					{return vecDaisy3NcxBodyId;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyLinkFile(void)				{return vecDaisy3NcxBodyLinkFile;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyLinkId(void)				{return vecDaisy3NcxBodyLinkId;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyName(void)					{return vecDaisy3NcxBodyName;} 
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyPlayOrder(void)				{return vecDaisy3NcxBodyPlayOrder;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyAudioSrc(void)				{return vecDaisy3NcxBodyAudioSrc;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyAudioBegin(void)			{return vecDaisy3NcxBodyAudioBegin;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyAudioEnd(void)				{return vecDaisy3NcxBodyAudioEnd;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxBodyImageSrc(void)				{return vecDaisy3NcxBodyImageSrc;}

vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartKind(void)					{return vecDaisy3NcxPartKind;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartId(void)					{return vecDaisy3NcxPartId;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartClass(void)					{return vecDaisy3NcxPartClass;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavInfoText(void)			{return vecDaisy3NcxPartNavInfoText;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavInfoAudioSrc(void)		{return vecDaisy3NcxPartNavInfoAudioSrc;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavInfoAudioBegin(void)		{return vecDaisy3NcxPartNavInfoAudioBegin;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavInfoAudioEnd(void)		{return vecDaisy3NcxPartNavInfoAudioEnd;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavInfoImageSrc(void)		{return vecDaisy3NcxPartNavInfoImageSrc;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavLabelText(void)			{return vecDaisy3NcxPartNavLabelText;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavLabelAudioSrc(void)		{return vecDaisy3NcxPartNavLabelAudioSrc;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavLabelAudioBegin(void)	{return vecDaisy3NcxPartNavLabelAudioBegin;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavLabelAudioEnd(void)		{return vecDaisy3NcxPartNavLabelAudioEnd;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartNavLabelImageSrc(void)		{return vecDaisy3NcxPartNavLabelImageSrc;}
vector<string>	LoadDaisy3NcxHandle::getVecDaisy3NcxPartPositionInBody(void)		{return vecDaisy3NcxPartPositionInBody;}

void LoadDaisy3NcxHandle::clearVector(void)
{
	//docTitle
	boolWaitDocTitleText		= false;
	boolWaitDocTitleAudio		= false;
	boolWaitDocTitleImage		= false;

	//docAuthor
	boolWaitDocAuthorText		= false;
	boolWaitDocAuthorAudio		= false;
	boolWaitDocAuthorImage		= false;

	//body
	boolWaitNavLabelText		= false;
	boolWaitNavLabelAudio		= false;
	boolWaitNavLabelImage		= false;
	boolWaitNavLabelContent		= false;

	//head of (navMap or pageList or navList)
	boolWaitHeadNavInfoText		= false;
	boolWaitHeadNavInfoAudio	= false;
	boolWaitHeadNavInfoImage	= false;
	boolWaitHeadNavLabelText	= false;
	boolWaitHeadNavLabelAudio	= false;
	boolWaitHeadNavLabelImage	= false;
	
	boolWaitForAllCharacters    = false;

	intNavMapHeaderStatus		= 1;

	//root
	strDaisy3NcxVersion		= "EmPtY";
	strDaisy3NcxXmlNs		= "EmPtY";
	strDaisy3NcxXmlLanguage	= "EmPtY";

	//Header
	vecDaisy3NcxCustomTestId.clear();
	vecDaisy3NcxCustomTestDefaultState.clear();
	vecDaisy3NcxCustomTestOverride.clear();
	vecDaisy3NcxCustomTestBookStruct.clear();
	vecDaisy3NcxMetaName.clear();
	vecDaisy3NcxMetaContent.clear();
	vecDaisy3NcxMetaScheme.clear();

	//docTitle
	strDaisy3NcxDocTitleText		= "EmPtY";
	strDaisy3NcxDocTitleAudioSrc	= "EmPtY";
	strDaisy3NcxDocTitleAudioBegin	= "EmPtY";
	strDaisy3NcxDocTitleAudioEnd	= "EmPtY";
	strDaisy3NcxDocTitleImageSrc	= "EmPtY";

	//docAuthor
	strDaisy3NcxDocAuthorText		= "EmPtY";
	strDaisy3NcxDocAuthorAudioSrc	= "EmPtY";
	strDaisy3NcxDocAuthorAudioBegin	= "EmPtY";
	strDaisy3NcxDocAuthorAudioEnd	= "EmPtY";
	strDaisy3NcxDocAuthorImageSrc	= "EmPtY";

	//Body
	vecDaisy3NcxBodyKind.clear();		//navPoint or pageTarget or navTarget.
	vecDaisy3NcxBodyType.clear();		//H1, H2, H3 ,H4 ,H5 format.
	vecDaisy3NcxBodyClass.clear();
	vecDaisy3NcxBodyId.clear();
	vecDaisy3NcxBodyLinkFile.clear();
	vecDaisy3NcxBodyLinkId.clear();
	vecDaisy3NcxBodyName.clear();
	vecDaisy3NcxBodyPlayOrder.clear();
	vecDaisy3NcxBodyAudioSrc.clear();
	vecDaisy3NcxBodyAudioBegin.clear();
	vecDaisy3NcxBodyAudioEnd.clear();
	vecDaisy3NcxBodyImageSrc.clear();

	//Part (Section)
	vecDaisy3NcxPartKind.clear();   //navMap, PageList, navList
	vecDaisy3NcxPartId.clear();
	vecDaisy3NcxPartClass.clear();
	vecDaisy3NcxPartNavInfoText.clear();
	vecDaisy3NcxPartNavInfoAudioSrc.clear();
	vecDaisy3NcxPartNavInfoAudioBegin.clear();
	vecDaisy3NcxPartNavInfoAudioEnd.clear();
	vecDaisy3NcxPartNavInfoImageSrc.clear();
	vecDaisy3NcxPartNavLabelText.clear();
	vecDaisy3NcxPartNavLabelAudioSrc.clear();
	vecDaisy3NcxPartNavLabelAudioBegin.clear();
	vecDaisy3NcxPartNavLabelAudioEnd.clear();
	vecDaisy3NcxPartNavLabelImageSrc.clear();
	vecDaisy3NcxPartPositionInBody.clear();
}

string LoadDaisy3NcxHandle::removeWhitespace(const string& str)
{
    string s;
    for (unsigned int i = 0; i < str.length(); ++i)
            if ((unsigned char)str[i] >= (unsigned char)' ')
                s += str[i];
    return s;
}