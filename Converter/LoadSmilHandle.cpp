#include "LoadSmilHandle.h"

//Parser SMIL file for DAISY 2.00 and 2.02 Standards

LoadSmilHandle::LoadSmilHandle() //: fElementCount(0), fAttrCount(0), fCharacterCount(0), fSpaceCount(0), fSawErrors(false)
{
	LoadSmilHandle::clearVector();
}

LoadSmilHandle::~LoadSmilHandle()
{
}

void LoadSmilHandle::startElement(const XMLCh* const uri
                                 ,const XMLCh* const localname
                                 ,const XMLCh* const qname
                                 ,const Attributes& att)
{
	char* message1 = XMLString::transcode(qname);
	char* message2;

	  //////////////////////////////////////////////////////////////////////////////////////
	 // meta with scheme                                                  finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if (!strcmp(message1,"meta") || !strcmp(message1,"META") || !strcmp(message1,"Meta"))
	{
		if (att.getIndex(XMLString::transcode("name")) != -1 )
		{
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("name")));
			vecDaisy2Smil1MetaName.push_back(message2);
	
			message2 = XMLString::transcode(att.getValue(XMLString::transcode("content")));
			vecDaisy2Smil1MetaContent.push_back(message2);

			if (att.getIndex(XMLString::transcode("scheme")) != -1 )
			{
				message2 = XMLString::transcode(att.getValue(XMLString::transcode("scheme")));
				vecDaisy2Smil1MetaScheme.push_back(message2);
			}
			else
			{
				//Put "EmPtY" -> vecSmilMetaScheme for sequential issue.
				vecDaisy2Smil1MetaScheme.push_back("EmPtY");
			}
		}
		return;
	}

      //////////////////////////////////////////////////////////////////////////////////////
	 // audio														       finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"audio")
	   || !strcmp(message1,"AUDIO")
	   || !strcmp(message1,"Audio"))
	{


		//Set temporary SMIL ID.
		if (att.getIndex(XMLString::transcode("id")) != -1 )
			vecDaisy2Smil1BodyAudioTempId.push_back (XMLString::transcode(att.getValue(XMLString::transcode("id"))));
		else
			vecDaisy2Smil1BodyAudioTempId.push_back ("EmPtY");   //Set value to "EmPtY" because there is no data.
		
		//Set temporary SMIL Source.
		if (att.getIndex(XMLString::transcode("src")) != -1 )
			vecDaisy2Smil1BodyAudioTempSrc.push_back (XMLString::transcode(att.getValue(XMLString::transcode("src"))));
		else
			vecDaisy2Smil1BodyAudioTempSrc.push_back ("EmPtY");   //Set value to "EmPtY" because there is no data.
	
		//Put temporary SMIL Clip Begin.
		if (att.getIndex(XMLString::transcode("clip-begin")) != -1 )
			vecDaisy2Smil1BodyAudioTempClipBegin.push_back (XMLString::transcode(att.getValue(XMLString::transcode("clip-begin"))));
		else
			vecDaisy2Smil1BodyAudioTempClipBegin.push_back ("EmPtY");;   //Set value to "EmPtY" because there is no data.
		
		//Put temporary SMIL Clip End.
		if (att.getIndex(XMLString::transcode("clip-end")) != -1 )
			vecDaisy2Smil1BodyAudioTempClipEnd.push_back (XMLString::transcode(att.getValue(XMLString::transcode("clip-end"))));
		else
			vecDaisy2Smil1BodyAudioTempClipEnd.push_back ("EmPtY");   //Set value to "EmPtY" because there is no data.
		
		//setup variable
		intCountAudio++;
		boolNewAudio = true;
		return;
	}

	  //////////////////////////////////////////////////////////////////////////////////////
	 // text															  finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  (!strcmp(message1,"text") 
	   || !strcmp(message1,"TEXT")
	   || !strcmp(message1,"Text"))
	{
		//clear value in all temporary strings.
		//strDaisy2Smil1BodyTextTempId.clear();       //ยกเลิกการ clear ค่าตรงนี้  เพราะไป clear ค่าตั้งแต่ตอน push_back แล้ว เพื่อตรวจสอบว่า text ที่มานั้นเป็น text ซ้ำหรือเปล่า
		//strDaisy2Smil1BodyTextTempSrc.clear();	  //ยกเลิกการ clear ค่าตรงนี้  เพราะไป clear ค่าตั้งแต่ตอน push_back แล้ว เพื่อตรวจสอบว่า text ที่มานั้นเป็น text ซ้ำหรือเปล่า

		if (strDaisy2Smil1BodyTextTempSrc.empty())    //ทำขึ้นเพื่อตรวจสอบในกรณีที่มี text 2 อันใน Par เดียวกันจะเลือกเอาต้วแรก ถ้าจะเอา 2 อันให้เอาชุดของ ID และ src ออกมานอก if นี้ คงเหลือไว้แต่ setup variable
		{
			//ID.
			if (att.getIndex(XMLString::transcode("id")) != -1 )	
				strDaisy2Smil1BodyTextTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
			else
				strDaisy2Smil1BodyTextTempId = "EmPtY";   //Set value to "EmPtY" because there is no data.

			//src
			if (att.getIndex(XMLString::transcode("src")) != -1 )		
				strDaisy2Smil1BodyTextTempSrc = XMLString::transcode(att.getValue(XMLString::transcode("src")));
			else
				strDaisy2Smil1BodyTextTempSrc = "EmPtY#EmPtY";   //Set value to "EmPtY" because there is no data.
			
			//setup variable
			intCountText++;
			boolNewText = true;
			return;
		}
	}
	
	  //////////////////////////////////////////////////////////////////////////////////////
	 // img																  finite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"img")
	   || !strcmp(message1,"IMG") 
	   || !strcmp(message1,"Img"))
	{
		//clear value in all temporary strings.
		strDaisy2Smil1BodyImgTempId.clear();
		strDaisy2Smil1BodyImgTempSrc.clear();

		//id (ID, IMPLIED): Optional identifier. 
		if (att.getIndex(XMLString::transcode("id")) != -1)		
			strDaisy2Smil1BodyImgTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		else
			strDaisy2Smil1BodyImgTempId = "EmPtY";   //Set value to "EmPtY" because there is no data.
			
		//src (CDATA, REQUIRED): URI of image file to be rendered.
		if (att.getIndex(XMLString::transcode("src")) != -1)
			strDaisy2Smil1BodyImgTempSrc = XMLString::transcode(att.getValue(XMLString::transcode("src")));
		else
			strDaisy2Smil1BodyImgTempSrc = "EmPtY";   //Set value to "EmPtY" because there is no data.

		//setup variable
		intCountImg++;
		boolNewImg = true;
		return;
	}

	  //////////////////////////////////////////////////////////////////////////////////////
	 // par	(without endsync)											infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"par")
	   || !strcmp(message1,"PAR") 
	   || !strcmp(message1,"Par"))
	{
		//clear value in all temporary strings.
		strDaisy2Smil1BodyParTempId.clear();
		strDaisy2Smil1BodyParTempCustomTest.clear();

		//setup variable for find level of par in this SMIL.
		intDaisy2Smil1BodyParTempLevel++;
			
		//Set temporary par ID.
		if (att.getIndex(XMLString::transcode("id")) != -1 )		
			strDaisy2Smil1BodyParTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		else
		{
			_itoa_s(i, a, 10);										
			strDaisy2Smil1BodyParTempId = "ParImageTextAudio-";	
			strDaisy2Smil1BodyParTempId.append(a);
			strDaisy2Smil1BodyParTempId.append("-");
			i++;
		}
		
		//Set temporary par customTest from system-required tag. 
		if (att.getIndex(XMLString::transcode("system-required")) != -1 )		
			strDaisy2Smil1BodyParTempCustomTest = XMLString::transcode(att.getValue(XMLString::transcode("system-required")));
		else
			strDaisy2Smil1BodyParTempCustomTest = "EmPtY";   //Set value to "EmPtY" because there is no data.
	}

	  //////////////////////////////////////////////////////////////////////////////////////
	 // seq																infinite element //
	//////////////////////////////////////////////////////////////////////////////////////
	if  ( !strcmp(message1,"seq")
	   || !strcmp(message1,"SEQ") 
	   || !strcmp(message1,"Seq"))
	{
		//clear value in all temporary strings.
		strDaisy2Smil1BodySeqTempId.clear();
		strDaisy2Smil1BodySeqTempDur.clear();

		//setup variable for find level of seq in this SMIL.
		intDaisy2Smil1BodySeqTempLevel++;

		//id (ID, REQUIRED): 
		if (att.getIndex(XMLString::transcode("id")) != -1 )
			strDaisy2Smil1BodySeqTempId = XMLString::transcode(att.getValue(XMLString::transcode("id")));
		else
		{
			_itoa_s(j, a, 10);
			strDaisy2Smil1BodySeqTempId = "SeqImageTextAudio-";
			strDaisy2Smil1BodySeqTempId.append(a);
			j++;
		}

		//dur (CDATA, IMPLIED) The duration of the seq. The value syntax is defined by the SMIL 2.0 Timing and Synchronization Module [SMIL]. 
		if (att.getIndex(XMLString::transcode("dur")) != -1 )
			strDaisy2Smil1BodySeqTempDur = XMLString::transcode(att.getValue(XMLString::transcode("dur")));
		else
			strDaisy2Smil1BodySeqTempDur = "EmPtY";   //Set value to "EmPtY" because there is no data.


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
}

void LoadSmilHandle::endElement  (const XMLCh *const uri, 
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
		if ( ((intCountAudio >= 1) && (boolNewAudio = true))
		   ||((intCountText  == 1) && (boolNewText  = true))	 
		   ||((intCountImg   == 1) && (boolNewImg   = true)))
		{
			string strTempId;
			int    jjj = vecDaisy2Smil1BodyAudioTempId.size();

			for (int iii=0;iii<jjj;iii++)
			{
				//push back seq information
				vecDaisy2Smil1BodySeqId.push_back			(strDaisy2Smil1BodySeqTempId);	
				vecDaisy2Smil1BodySeqDur.push_back			(strDaisy2Smil1BodySeqTempDur);
				_itoa_s(intDaisy2Smil1BodySeqTempLevel, a, 10);		//convert int to string
				vecDaisy2Smil1BodySeqLevel.push_back		(a);	//store that string to vector
				//push back par information
				_itoa_s(iii, a, 10);	
				strTempId = strDaisy2Smil1BodyParTempId;
				strTempId.append(a);
				vecDaisy2Smil1BodyParId.push_back			(strTempId);
				vecDaisy2Smil1BodyParCustomTest.push_back	(strDaisy2Smil1BodyParTempCustomTest);
				_itoa_s(intDaisy2Smil1BodyParTempLevel, a, 10);		//convert int to string
				vecDaisy2Smil1BodyParLevel.push_back		(a);	//store that string to vector
				//push back image information
				vecDaisy2Smil1BodyImgId.push_back			(strDaisy2Smil1BodyImgTempId);
				vecDaisy2Smil1BodyImgSrc.push_back			(strDaisy2Smil1BodyImgTempSrc);
				//push back text infomation
				vecDaisy2Smil1BodyTextId.push_back			(strDaisy2Smil1BodyTextTempId);
				vecDaisy2Smil1BodyTextSrcFile.push_back		(strDaisy2Smil1BodyTextTempSrc.substr(0,strDaisy2Smil1BodyTextTempSrc.find("#")));		//Seperte File and ID
				vecDaisy2Smil1BodyTextSrcId.push_back		(strDaisy2Smil1BodyTextTempSrc.substr(strDaisy2Smil1BodyTextTempSrc.find("#")+1));		//Seperte File and ID	
				vecDaisy2Smil1BodyTextContent.push_back		("WaItInG");
				//push back audio infomation
				vecDaisy2Smil1BodyAudioId.push_back			(vecDaisy2Smil1BodyAudioTempId[iii].data());
				vecDaisy2Smil1BodyAudioSrc.push_back		(vecDaisy2Smil1BodyAudioTempSrc[iii].data());
				vecDaisy2Smil1BodyAudioClipBegin.push_back	(vecDaisy2Smil1BodyAudioTempClipBegin[iii].data());
				vecDaisy2Smil1BodyAudioClipEnd.push_back	(vecDaisy2Smil1BodyAudioTempClipEnd[iii].data());
	
			}

			//Clear temporary variable about Image (it must be available.)
			intCountAudio =  0;
			vecDaisy2Smil1BodyAudioTempId.clear();			//clear value in all temporary vector.
			vecDaisy2Smil1BodyAudioTempSrc.clear();			//clear value in all temporary vector.
			vecDaisy2Smil1BodyAudioTempClipBegin.clear();	//clear value in all temporary vector.
			vecDaisy2Smil1BodyAudioTempClipEnd.clear();		//clear value in all temporary vector.

			//Clear temporary variable about Image (if it available.)
			intCountImg   =  0;
			strDaisy2Smil1BodyImgTempId.clear();
			strDaisy2Smil1BodyImgTempSrc.clear();
			
			//Clear temporary variable about Text (if it available.)
			intCountText  =  0;
			strDaisy2Smil1BodyTextTempId.clear();		//ต้อง clear ตรงนี้เพราะจะได้ตรวจสอบการซ้ำซ้อนของ text ใน smil เช่นเรื่องขนมลูกๆทองแดง
			strDaisy2Smil1BodyTextTempSrc.clear();		//ต้อง clear ตรงนี้เพราะจะได้ตรวจสอบการซ้ำซ้อนของ text ใน smil เช่นเรื่องขนมลูกๆทองแดง
		}

		//setup variable for find level of par in this SMIL.
		intDaisy2Smil1BodyParTempLevel--;
		return;
	}
	  //////////////////
	 // Checking seq //
	//////////////////
	if  ( !strcmp(message4,"seq") 
		||!strcmp(message4,"Seq") 
		||!strcmp(message4,"SEQ"))
	{
		//setup variable for find position to store all string to vector.
		if (intCountImg   > 0)
			intCountImg--;
		if (intCountText  > 0)
			intCountText--;
		if (intCountAudio > 0)
			intCountAudio--;

		//setup variable for find level od seq in this SMIL.
		intDaisy2Smil1BodySeqTempLevel--;
		return;
	}
}
//void LoadSmilHandle::characters(const XMLCh*   const chars ,const unsigned int   length){}
//void LoadSmilHandle::fatalError(const SAXParseException& e){}
//void LoadSmilHandle::ignorableWhitespace(const XMLCh* const chars,const unsigned int length){}
//void LoadSmilHandle::resetDocument(){}
//void LoadSmilHandle::error(const SAXParseException& e){}
//void LoadSmilHandle::warning(const SAXParseException& e){}
//void LoadSmilHandle::resetErrors(){}


vector<string>	LoadSmilHandle::getVecDaisy2Smil1MetaName(void)			{return vecDaisy2Smil1MetaName;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1MetaContent(void)		{return vecDaisy2Smil1MetaContent;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1MetaScheme(void)		{return vecDaisy2Smil1MetaScheme;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodySeqId(void)		{return vecDaisy2Smil1BodySeqId;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodySeqDur(void)		{return vecDaisy2Smil1BodySeqDur;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodySeqLevel(void)		{return vecDaisy2Smil1BodySeqLevel;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyParId(void)		{return vecDaisy2Smil1BodyParId;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyParCustomTest(void){return vecDaisy2Smil1BodyParCustomTest;} 
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyParLevel(void)		{return vecDaisy2Smil1BodyParLevel;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyImgId(void)		{return vecDaisy2Smil1BodyImgId;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyImgSrc(void)		{return vecDaisy2Smil1BodyImgSrc;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyTextId(void)		{return vecDaisy2Smil1BodyTextId;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyTextSrcFile(void)	{return vecDaisy2Smil1BodyTextSrcFile;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyTextSrcId(void)	{return vecDaisy2Smil1BodyTextSrcId;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyTextContent(void)	{return vecDaisy2Smil1BodyTextContent;}		
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyAudioId(void)		{return vecDaisy2Smil1BodyAudioId;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyAudioSrc(void)		{return vecDaisy2Smil1BodyAudioSrc;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyAudioClipBegin(void){return vecDaisy2Smil1BodyAudioClipBegin;}
vector<string>	LoadSmilHandle::getVecDaisy2Smil1BodyAudioClipEnd(void)	{return vecDaisy2Smil1BodyAudioClipEnd;}


//string LoadSmilHandle::convertClockValue(string strOldClockValue, int newFormatType)
//{
	//newFormatType = 1 is "Full-clock-value"    ::= Hours ":" Minutes ":" Seconds ("." Fraction)?
	//newFormatType = 2 is "Partial-clock-value" ::= Minutes ":" Seconds ("." Fraction)?
	//newFormatType = 3 is "Timecount-value"     ::= Timecount ("." Fraction)? (Metric)?

//}

void LoadSmilHandle::clearVector(void)
{
	//Head
	vecDaisy2Smil1MetaName.clear();
	vecDaisy2Smil1MetaContent.clear();
	vecDaisy2Smil1MetaScheme.clear();

	//Body
	i				= 1;
	j				= 1;
	intCountImg		= 0;
	intCountText	= 0;
	intCountAudio	= 0;
	boolNewImg		= false;
	boolNewText		= false;
	boolNewAudio	= false;
	strDaisy2Smil1BodySeqTempId = "EmPtY";
	strDaisy2Smil1BodySeqTempDur = "EmPtY";
	intDaisy2Smil1BodySeqTempLevel = 0;			//in this version we no use level 
	strDaisy2Smil1BodyParTempId = "EmPtY";
	strDaisy2Smil1BodyParTempCustomTest = "EmPtY";
	intDaisy2Smil1BodyParTempLevel = 0;			//in this version we no use level 
	strDaisy2Smil1BodyImgTempId = "EmPtY";
	strDaisy2Smil1BodyImgTempSrc = "EmPtY";
	strDaisy2Smil1BodyTextTempId = "EmPtY";
	strDaisy2Smil1BodyTextTempSrc.clear();// = "EmPtY#EmPtY";
	//strDaisy2Smil1BodyAudioTempId = "EmPtY";			// upgrade to vector for supporting multiple audio in one par.
	//strDaisy2Smil1BodyAudioTempSrc = "EmPtY";			// upgrade to vector for supporting multiple audio in one par.
	//strDaisy2Smil1BodyAudioTempClipBegin = "EmPtY";	// upgrade to vector for supporting multiple audio in one par.
	//strDaisy2Smil1BodyAudioTempClipEnd = "EmPtY";		// upgrade to vector for supporting multiple audio in one par.
	vecDaisy2Smil1BodyAudioTempId.clear();
	vecDaisy2Smil1BodyAudioTempSrc.clear();
	vecDaisy2Smil1BodyAudioTempClipBegin.clear();
	vecDaisy2Smil1BodyAudioTempClipEnd.clear();

	vecDaisy2Smil1BodySeqId.clear();
	vecDaisy2Smil1BodySeqDur.clear();
	vecDaisy2Smil1BodySeqLevel.clear();
	vecDaisy2Smil1BodyParId.clear();
	vecDaisy2Smil1BodyParCustomTest.clear(); //use to store "system-requested" however we remove endsync
	vecDaisy2Smil1BodyParLevel.clear();
	vecDaisy2Smil1BodyImgId.clear();
	vecDaisy2Smil1BodyImgSrc.clear();
	vecDaisy2Smil1BodyTextId.clear();
	vecDaisy2Smil1BodyTextSrcFile.clear();
	vecDaisy2Smil1BodyTextSrcId.clear();
	vecDaisy2Smil1BodyTextContent.clear();	//use to wait xhtml parser for its data then it will be only empty data now.
	vecDaisy2Smil1BodyAudioId.clear();
	vecDaisy2Smil1BodyAudioSrc.clear();
	vecDaisy2Smil1BodyAudioClipBegin.clear();
	vecDaisy2Smil1BodyAudioClipEnd.clear();

}