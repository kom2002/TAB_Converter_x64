
#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override something,
//but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>



#include "Converter.h"
#pragma warning( disable : 4244 )	//for snd error
#pragma warning( disable : 4251 )	//for ms.vector error

// DllMain function - This function is an optional entry point into a dynamic-link library (DLL)	
BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

// Constructor
Converter::Converter(void)
{
	return;
}

// Deconstructor
Converter::~Converter(void)
{
	return;
}

// GetCycleCount - private function of DLL3.cpp.  The static keyword ensures that this function name is not visible outside DLL3.cpp.
static inline unsigned __int64 GetCycleCount()
{
    unsigned int timehi, timelo;
    __asm    // Use the assembly instruction rdtsc, which gets the current cycle count (since the process started) and puts it in edx:eax.
    {
        rdtsc
        mov timehi, edx;
        mov timelo, eax;
    }

    return ((unsigned __int64)timehi << 32) + (unsigned __int64)timelo;
}

// CreateConverterDll - create an instance of the class Converter
void * __stdcall CreateConverterDll()
{
	cout << "Starting...." << endl;
	cout << "Completed :: Create Converter Dll instant." << endl;
    return new Converter;
}

// DestroyConverterDll - free the memory for the class instance 
void __stdcall DestroyConverterDll(void * objptr)
{
    Converter *myConverter = (Converter *) objptr;
    if (myConverter)
	{
        delete myConverter;
	}
	cout << "Completed :: Destroy Converter Dll instant." << endl;
	return;
}

// GetCpuSpeedConverterDll - This is trail path of calling function from external DLL.
int __stdcall GetCpuSpeedConverterDll(void * objptr)
{
    Converter *myConverter = (Converter *) objptr;
    if (myConverter)
        return myConverter->GetCpuSpeed();
    else
        return 0;
}

// StartConverterDll - This is trail path of calling function from external DLL.
int __stdcall StartConverterDll (char * chrNcPath, char * chrDestFolder, bool boolMakeSyntheticSound, int intOrderText2Speech, char * chrOutputAudioFormat, void * objptr)
{
    Converter *myConverter = (Converter *) objptr;
    if (myConverter)
        return myConverter->Starter(chrNcPath, chrDestFolder, boolMakeSyntheticSound, intOrderText2Speech, chrOutputAudioFormat);   
	else
        return 4;
}

// GetCpuSpeed 
int Converter::GetCpuSpeed()
{
    const unsigned __int64 ui64StartCycle = GetCycleCount();
    Sleep(1000);
    return static_cast<int>((GetCycleCount() - ui64StartCycle) / 1000000);
}

// Starter
int Converter::Starter (char * chrNcPath, char * chrDestFolder, bool boolMakeSyntheticSound, int intOrderText2Speech, char * chrOutputAudioFormat)
{
	//Come From Parameter.
	strSourcePathNcc		= chrNcPath;
	strDestinationFolder	= chrDestFolder;

	//Start Logging file.
	ofstream file; 
	string   strLogFileName;
	strLogFileName = chrDestFolder;
	strLogFileName.append("result.log");
	file.open (strLogFileName.c_str(), ios::app);
	streambuf* sbuf = cout.rdbuf(); 
	cout.rdbuf(file.rdbuf());
	fnReportingStatusToFile(2,"Start Logging","result.log","Creating");

	//Display all parameters
	cout << "Logging Information of TAB-Converter update September 29, 2010" << endl;
	cout << "Started   :: Open Starter module with chrNcPath              = " << chrNcPath << endl;
	cout << "Started   :: Open Starter module with chrDestFolder          = " << chrDestFolder << endl;
	cout << "Started   :: Open Starter module with boolMakeSyntheticSound = " << boolMakeSyntheticSound << endl;
	cout << "Started   :: Open Starter module with intOrderText2Speech    = " << intOrderText2Speech << endl;
	cout << "Started   :: Open Starter module with chrOutputAudioFormat   = " << chrOutputAudioFormat << endl;
	
	//Automatic Generate.
	strSourcePathBook	= fnGetSourceDirectoryFromNccPath(strSourcePathNcc); 
	strSourceTempFolder	= strDestinationFolder;
	strSourceTempFolder.append("temp\\");
	CreateDirectory(strDestinationFolder.c_str(), NULL);
	CreateDirectory(strSourceTempFolder.c_str(), NULL);

	//ตรวจสอบ Version ของ DTB จากชื่อหรือนามสกุลของ Navigation Control File
	if		(strSourcePathNcc.find(".ncx")		!= string::npos)	{ boolIsDaisy3 = true; }
	else if (strSourcePathNcc.find(".Ncx")		!= string::npos)	{ boolIsDaisy3 = true; }
	else if (strSourcePathNcc.find(".NCX")		!= string::npos)	{ boolIsDaisy3 = true; }
	else if (strSourcePathNcc.find("ncc.htm")	!= string::npos)	{ boolIsDaisy3 = false;}
	else if (strSourcePathNcc.find("Ncc.htm")	!= string::npos)	{ boolIsDaisy3 = false;}
	else if (strSourcePathNcc.find("Ncc.Htm")	!= string::npos)	{ boolIsDaisy3 = false;}
	else if (strSourcePathNcc.find("NCC.HTM")	!= string::npos)	{ boolIsDaisy3 = false;}
	else
	{	
		cout << "Failed    :: Cann't detected version of DAISY" << endl;
		return 1000;
	}

	if (boolIsDaisy3 == true)
	{
		cout << "Detected  :: This book is ANSI/NISO Z39.86-2002 or 2005 Format" << endl;
	}
	else
	{
		cout << "Detected  :: This book is DAISY2.00 or DAISY2.02 Format" << endl;
	}
 
	strSourcePathSmil.clear();
	strSourcePathHtml.clear();
	myVecHtmlParagraphID.clear();
	myVecHtmlContent.clear();
	myVecOpfStoreAudio.clear();


	//load NCC or NCX and check error.
	fnReportingStatusToFile(3,"Start Load NCC/NCX",strSourcePathNcc,"Loading");
	if (boolIsDaisy3)
	{	
		if (!fnLoadDaisy3Ncx(strSourcePathNcc, intOrderText2Speech, chrOutputAudioFormat))
		{
			cout << "Failed    :: Loading NCX ( " << strSourcePathNcc <<" )" << endl;
			fnReportingStatusToFile(100,"Failed loading NCX",strSourcePathNcc,"Loaded");
			return 1001;	//fail to load Ncc file.
		}
		else
		{
			cout << "Completed :: Loading NCX ( " << strSourcePathNcc <<" )" << endl;
			fnReportingStatusToFile(7,"Completed loading NCX",strSourcePathNcc,"Loaded");
		}
	}
	else
	{
		if (!fnLoadNcc(strSourcePathNcc, intOrderText2Speech, chrOutputAudioFormat))
		{
			cout << "Failed    :: Loading NCC ( " << strSourcePathNcc <<" )" << endl;
			fnReportingStatusToFile(100,"Failed loading NCC",strSourcePathNcc,"Loaded");
			return 1002;	//fail to load Ncc file.
		}
		else
		{
			cout << "Completed :: Loading NCC ( " << strSourcePathNcc <<" )" << endl;
			fnReportingStatusToFile(7,"Completed loading NCC",strSourcePathNcc,"Loaded");
		}
	}

	//Check Duplicate Smil file in Ncc vector.
	if (!fnCheckDupSmil())
	{
		cout << "Failed    :: Checking duplicated SMIL in navigation control file (NCC/NCX)" << endl;	
		//return 1003; //fail because Ncc has duplicate smil.
	}
	else
	{
		cout << "Completed :: Checking duplicated SMIL in navigation control file (NCC/NCX)" << endl;
		cout << "Info      :: There are " << myVecDaisy3NcxBodyType.size() << " SMILs in this NCC/NCX." << endl;
		fnReportingStatusToFile(8,"Completed checking duplicate SMIL",strSourcePathNcc,"Checking Duplicate SMIL");
	}

	//Loop for find Smil file in Ncc file.
	unsigned int intCurrNcc;
	for (intCurrNcc=0; intCurrNcc < myVecDaisy3NcxBodyType.size(); intCurrNcc++)
	{
		//Debug and Logging information.
		cout << "Started   :: Processing SMIL #" << intCurrNcc << " (" << myVecDaisy3NcxBodyLinkFile[intCurrNcc].data() << ") in this navigation control file" << endl;
	
		//select only heading
		if (!myVecDaisy3NcxBodyType[intCurrNcc].compare(0,1,"H") || !myVecDaisy3NcxBodyType[intCurrNcc].compare(0,1,"h"))
		{
			//Prepare Smil Path before loading.
			strSourcePathSmil = strSourcePathBook;
			strSourcePathSmil.append("\\");
			strSourcePathSmil.append(myVecDaisy3NcxBodyLinkFile[intCurrNcc].data());
			fnReportingStatusToFile(10+(intCurrNcc*80/myVecDaisy3NcxBodyType.size())+ ((80/myVecDaisy3NcxBodyType.size())*(0/100)) ,"Loading SMIL",myVecDaisy3NcxBodyLinkFile[intCurrNcc].data(),"Loading");

			//load SMIL and check error.
			if (boolIsDaisy3)
			{	
				if (!fnLoadDaisy3Smil2(strSourcePathSmil))
				{
					//fail to load Smil 2 file.
					cout << "Failed    :: Loading SMIL Version 2 ( " << strSourcePathSmil <<" )" << endl;
					fnReportingStatusToFile(100 ,"Fail Loading SMIL Version 2.0",myVecDaisy3NcxBodyLinkFile[intCurrNcc].data(),"Loaded");
					return 1004;	
				}
				else
				{
					cout << "Completed :: Loading SMIL Version 2 ( " << strSourcePathSmil <<" )" << endl;
					fnReportingStatusToFile(10+(intCurrNcc*80/myVecDaisy3NcxBodyType.size())+ ((80/myVecDaisy3NcxBodyType.size())*(5/100)) ,"Success Loading SMIL Version 2.0",myVecDaisy3NcxBodyLinkFile[intCurrNcc].data(),"Loaded");
				}
			}
			else
			{
				if (!fnLoadSmil(strSourcePathSmil))
				{
					//fail to load Smil2 file.
					cout << "Failed    :: Loading SMIL Version 1 ( " << strSourcePathSmil <<" )" << endl;
					fnReportingStatusToFile(100 ,"Fail Loading SMIL Version 1",myVecDaisy3NcxBodyLinkFile[intCurrNcc].data(),"Loaded");
					return 1005;	
				}
				else
				{
					cout << "Completed :: Loading SMIL Version 1 ( " << strSourcePathSmil <<" )" << endl;
					fnReportingStatusToFile(10+(intCurrNcc*80/myVecDaisy3NcxBodyType.size())+ ((80/myVecDaisy3NcxBodyType.size())*(5/100)) ,"Success Loading SMIL Version 1.0",myVecDaisy3NcxBodyLinkFile[intCurrNcc].data(),"Loaded");
				}
			}

			//get unique Html file in Smil vector.
			vector<string> vecUniqueHtmlInSmil;
			vecUniqueHtmlInSmil = fnGetVecUniqueHtml();
			unsigned int intCurrentUniqueHtmlInSmil;

			fnReportingStatusToFile(10+(intCurrNcc*80/myVecDaisy3NcxBodyType.size())+ ((80/myVecDaisy3NcxBodyType.size())*(6/100)),"Loading HTML","*.hml","Loading");
			for (intCurrentUniqueHtmlInSmil=0; intCurrentUniqueHtmlInSmil < vecUniqueHtmlInSmil.size() ; intCurrentUniqueHtmlInSmil++)
			{
				//Prepare path to parser this Html
				strSourcePathHtml =	strSourcePathBook;
				strSourcePathHtml.append("\\");
				strSourcePathHtml.append(vecUniqueHtmlInSmil[intCurrentUniqueHtmlInSmil]);

				//full fill string in myVecDaisy2Smil1End follow ID from myVecDaisy2Smil1Begin.
				if (!fnLoadHtml(strSourcePathHtml))
				{
					cout << "Failed    :: Loading HTML file for gather string in HTML ("  << strSourcePathHtml << ")" << endl;
					fnReportingStatusToFile(100 ,"Fail loading HTML",vecUniqueHtmlInSmil[intCurrentUniqueHtmlInSmil].data(),"Loaded");
					return 1006;	//fail to load Html file.
				}
				else 
				{
					cout << "Completed :: Loading HTML file for gather string in HTML ("  << strSourcePathHtml << ")" << endl;
					fnReportingStatusToFile(10+(intCurrNcc*80/myVecDaisy3NcxBodyType.size())+ ((80/myVecDaisy3NcxBodyType.size())*(10/100)) ,"Success loading HTML",vecUniqueHtmlInSmil[intCurrentUniqueHtmlInSmil].data(),"Loaded");
				}
			}

			//loop for append HTML ID&content to vector for generate XML.
			int  i,j;
			bool boolPageNumDetect = false;
			j	 = myVecDaisy3Smil2BodySeqId.size();					
			for(i=0; i < j ; i++)
			{
				if (!myVecDaisy3Smil2BodyParCustomTest[i].compare("pagenumber-on"))					
				{
					boolPageNumDetect = true;
				}

				if ( myVecDaisy3Smil2BodyTextSrcFile[i].compare("EmPtY"))			
				{
					if (!boolPageNumDetect)
					{
						myVecHtmlParagraphID.push_back(myVecDaisy3Smil2BodyTextSrcId[i].data());
						myVecHtmlContent.push_back(myVecDaisy3Smil2BodyTextContent[i].data());
						myVecHtmlPageNumberDetect.push_back(false);
					}
					else
					{
						myVecHtmlParagraphID.push_back(myVecDaisy3Smil2BodyTextSrcId[i].data());
						myVecHtmlContent.push_back(myVecDaisy3Smil2BodyTextContent[i].data());
						myVecHtmlPageNumberDetect.push_back(true);
						boolPageNumDetect = false;
					}
				}
			}

			//Manage about audio in this SMIL.
			if (boolMakeSyntheticSound == true)
			{
				//Don't use in this version เพราะใน version นี้จะหาว่าส่วนไหนบ้างที่ไม่มีไฟล์เสียงแล้วเขียนไฟล์เสียงขึ้นมาด้วย Text to speech
				//1. Call function to convert string in HTML to audio file (Synthetic)
				//2. Specific position of sound in to smil vector
			}
			else
			{
				//write group of audio file
				if (!fnFindAndConvertMpegInSmilToVox(intCurrNcc, chrOutputAudioFormat, intOrderText2Speech))
				{
					cout << "Failed    :: Conversion audio in SMIL file name "  << strSmilDestinationFileName << endl;
					fnReportingStatusToFile(100 ,"Fail conversion audio in SMIL",strSmilDestinationFileName,"Converted Audio");
					return 1008; //fail to write audio from SMIL file.
				}
				else
				{
					cout << "Completed :: Conversion audio in SMIL file name "  << strSmilDestinationFileName << endl;
					fnReportingStatusToFile(10+(intCurrNcc*80/myVecDaisy3NcxBodyType.size())+ ((80/myVecDaisy3NcxBodyType.size())*(80/100)) ,"Success conversion audio in SMIL",strSmilDestinationFileName,"Converted Audio");
				}
			}

			//write smil file
			strSmilDestinationFileName = strDestinationFolder;
			strSmilDestinationFileName.append(myVecDaisy3NcxBodyLinkFile[intCurrNcc].data());
			if (!fnWriteSmil2("iso-8859-11", strSmilDestinationFileName.c_str(), chrOutputAudioFormat))   //ISO-8859-11   ,    Windows-874
			{
				cout << "Failed    :: Writing new SMIL file on Z39.86 standard ("  << strSmilDestinationFileName << ")" << endl;
				fnReportingStatusToFile(100 ,"Writing SMIL",myVecDaisy3NcxBodyLinkFile[intCurrNcc].data(),"Writing Smil");
				return 1007; //fail to write SMIL file.
			}
			else
			{
				cout << "Completed :: Writing new SMIL file on Z39.86 standard ("  << strSmilDestinationFileName << ")" << endl;
				fnReportingStatusToFile(10+(intCurrNcc*80/myVecDaisy3NcxBodyType.size())+ ((80/myVecDaisy3NcxBodyType.size())*(100/100)) ,"Success Writing SMIL",myVecDaisy3NcxBodyLinkFile[intCurrNcc].data(),"Writed SMIL");
			}
		}
	}
	cout << "Completed :: Processing All SMILs in this navigation control file" << endl;
		
	//write xml file
	strNcxDestinationFileName = strDestinationFolder;
	strNcxDestinationFileName.append("dtb.xml");
	if (!fnWriteXml("iso-8859-11",strNcxDestinationFileName.c_str()))   //ISO-8859-11   ,    Windows-874
	{
		cout << "Failed    :: Writing XML file ("  << strNcxDestinationFileName << ")" << endl;
		fnReportingStatusToFile(100 ,"Fail writing XML file","dtb.xml","Writing XML file");
		return 1009; //fail to write OPF file.
	}
	else
	{
		cout << "Completed :: Writing XML file ("  << strNcxDestinationFileName << ")" << endl;
		fnReportingStatusToFile(92 ,"Success writing XML file","dtb.xml","Writing XML file");
	}
	
	//write ncx file
	strNcxDestinationFileName = strDestinationFolder;
	strNcxDestinationFileName.append("dtb.ncx");
	if (!fnWriteNcx("iso-8859-11", strNcxDestinationFileName.c_str()))   //ISO-8859-11   ,    Windows-874
	{
		cout << "Failed    :: Writing NCX file ( "  << strNcxDestinationFileName << ")" << endl;
		fnReportingStatusToFile(100 ,"Fail writing NCX file","dtb.ncx","Writing NCX file");
		return 1010; //fail to write NCX file.
	}
	else
	{
		cout << "Completed :: Writing NCX file ("  << strNcxDestinationFileName << ")" << endl;
		fnReportingStatusToFile(95 ,"Success writing NCX file","dtb.ncx","Writing NCX file");
	}

	//write opf file
	strNcxDestinationFileName = strDestinationFolder;
	strNcxDestinationFileName.append("dtb.opf");
	if (!fnWriteOpf("iso-8859-11",strNcxDestinationFileName.c_str()))   //ISO-8859-11   ,    Windows-874
	{
		cout << "Failed    :: Writing OPF file ( "  << strNcxDestinationFileName << ")" << endl;
		fnReportingStatusToFile(100 ,"Fail writing OPF file","dtb.opf","Writing OPF file");
		return 1011; //fail to write OPF file.
	}
	else
	{
		cout << "Completed :: Writing OPF file ("  << strNcxDestinationFileName << ")" << endl;
		fnReportingStatusToFile(97 ,"Success writing OPF file","dtb.opf","Writing OPF file");
	}

	//write css file
	strNcxDestinationFileName = strDestinationFolder;
	strNcxDestinationFileName.append("dtb.css");
	if (!fnWriteCss(strNcxDestinationFileName.c_str()))  
	{
		cout << "Failed    :: Writing CSS file ( "  << strNcxDestinationFileName << ")" << endl;
		fnReportingStatusToFile(100 ,"Fail writing CSS file","dtb.css","Writing CSS file");
		return 1012; //fail to write CSS file.
	}
	else
	{
		cout << "Completed :: Writing CSS file ("  << strNcxDestinationFileName << ")" << endl;
		fnReportingStatusToFile(99 ,"Success writing CSS file","dtb.css","Writing CSS file");
	}

	cout << "Succeeds :: Conversion this book to ANSI/NISO Z39.86-2005" << endl;
	cout << " _______________________________________________________________ " << endl;
	cout << "|                                                               |" << endl;
	cout << "|Info    :: Thank you for taking advantage of TAB-Conversion.   |" << endl;
	cout << "|Info    :: Any comments, Please mail to kom2002@yahoo.com      |" << endl;
	cout << "|Info    :: Try to visit our website at www.tab.or.th/daisy     |" << endl;
	cout << "|_______________________________________________________________|" << endl;
	cout.rdbuf(sbuf);
	fnReportingStatusToFile(100 ,"Success conversion DTB","","");
	return 9999;
}

bool Converter::fnCheckDupSmil(void) //Check Duplicate Smil file in Ncc vector.
{
	unsigned int intCheckDupSmil1;
	unsigned int intCheckDupSmil2;
	int intNumberOfDupSmil = 0;
	bool boolIsFoundDuplicate = false;

	for (intCheckDupSmil1=0; intCheckDupSmil1 < myVecDaisy3NcxBodyType.size(); intCheckDupSmil1++)
	{
		//select only heading
		if (!myVecDaisy3NcxBodyType[intCheckDupSmil1].compare(0,1,"H") || !myVecDaisy3NcxBodyType[intCheckDupSmil1].compare(0,1,"h"))
		{
			for (intCheckDupSmil2=0; intCheckDupSmil2 < myVecDaisy3NcxBodyType.size(); intCheckDupSmil2++)
			{
				//select only heading
				if (!myVecDaisy3NcxBodyType[intCheckDupSmil2].compare(0,1,"H") || !myVecDaisy3NcxBodyType[intCheckDupSmil2].compare(0,1,"h"))
				{
					if (myVecDaisy3NcxBodyLinkFile[intCheckDupSmil1] == myVecDaisy3NcxBodyLinkFile[intCheckDupSmil2])
					{
						intNumberOfDupSmil++;
					}
				}
			}
						
			if (intNumberOfDupSmil != 1)
			{
				//ถ้าเป็น Daisy3 แล้วเจอ duplicate SMIL จะเปลี่ยนค่าจาก Header (Hx) ให้เป็นพวก navPoint ซึ่งจะไม่นับว่าเป็น Header ทำให้ดูเหมือนว่าไม่ Dup 
				if ((boolIsDaisy3 == true) && (boolIsFoundDuplicate == true))
				{
					myVecDaisy3NcxBodyType[intCheckDupSmil1] = "navPoint"; //DAISY3
					myVecDaisy3NcxBodyKind[intCheckDupSmil1] = "navPoint"; //DAISY3
				}
				////สำหรับ Daisy2 ยังไม่ได้ออกแบบตรงนี้ไว้ให้
				//else
				//{
				//	myVecDaisy3NcxBodyType[intCheckDupSmil1] = "span";		//DAISY2 ยังไม่ได้ตรวจสอบ
				//}
				
				//Error : บอกว่าเจอ SMIL Duplication
				boolIsFoundDuplicate = true;
			}

			if ((intNumberOfDupSmil == 1) && (boolIsFoundDuplicate == true) && (boolIsDaisy3 == true) )
			{
					myVecDaisy3NcxBodyType[intCheckDupSmil1] = "navPoint"; //DAISY3
					myVecDaisy3NcxBodyKind[intCheckDupSmil1] = "navPoint"; //DAISY3
			}

			intNumberOfDupSmil = 0;
		}
	}
	return !boolIsFoundDuplicate;
}

vector<string> Converter::fnGetVecUniqueHtml(void) //Check Duplicate Html file in Smil vector.
{
	//Check number (differential) of html file name.
	vector<string> vecUniqueHtmlName;
	int i,j;
	j = myVecDaisy3Smil2BodySeqId.size();
	strHtmlFileNameForCheckDup.clear();
	for (i=0;i<j;i++)
	{
		//For Text only 																		
		if ( myVecDaisy3Smil2BodyTextSrcFile[i].compare("EmPtY"))							 
		{
			if (strHtmlFileNameForCheckDup.empty())
			{
				strHtmlFileNameForCheckDup = myVecDaisy3Smil2BodyTextSrcFile[i];			
				vecUniqueHtmlName.push_back (strHtmlFileNameForCheckDup);
			}

			if (strHtmlFileNameForCheckDup != myVecDaisy3Smil2BodyTextSrcFile[i])			
			{
				//!!!DUPLICATE!!!
				vecUniqueHtmlName.push_back (myVecDaisy3Smil2BodyTextSrcFile[i].data());
				//cout << "Smil Error : Html wasn't unique" << endl;
				//return false;
			}
		}
	}
	//Checking Completed : Html in Smil was unique.
	return vecUniqueHtmlName;
}

bool Converter::fnReportingStatusToFile(int intPercent, string strDtbStatus, string strFileName, string strFileStatus)
{
	//declare variable
	char b[5];
	string strForWriting;
	string strStatusFileName;
	//assign value to variable
	itoa(intPercent, b, 10);
	strStatusFileName = strDestinationFolder;
	strStatusFileName.append("status.log");
	//create string fo writing
	strForWriting = b;						//Percent
	strForWriting.append("\n");
	strForWriting.append(myStrHtmlTitle);   //DTB Name
	strForWriting.append("\n");
	strForWriting.append(strDtbStatus);		//DTB Status
	strForWriting.append("\n");
	strForWriting.append(strFileName);		//File Name
	strForWriting.append("\n");
	strForWriting.append(strFileStatus);	//File Status
	
	//Write status to file
	FILE* stmFileWrite;
	if ((stmFileWrite = fopen(strStatusFileName.c_str(), "w+" )) != NULL )
	{
		fputs(strForWriting.c_str(), stmFileWrite);
	}
	else
	{
		return false;
	}
	fclose(stmFileWrite);
	return true;
}



//This function designed for both tasks are
//	1. convert from the one to the another encoding.
//	2. If there are no or incompleted <?xml ....> this function will be complete it.
//  3. Replace all of ":</" with ":  </" because it will be error at xerces. most of them store at html files.
bool Converter::fnChangeEncoding (string strFileName,string strSought, string strReplacement)
{
	cout << "fnChangeEncoding strFileName =" << strFileName << endl;
	vector<string> vecPhrase;
	string         strReadLine;

	std::locale::global(std::locale(""));
	//cout << "start[" <<      fnIsUnicodeFile(strFileName.c_str()) << "]" << endl;



	//Solve Unicode by     staying in unicode using stackoverflow 1138863
	ifstream       stmFileRead (strFileName.c_str());
	
	int			   currentPhrase = 0;
	int			   intPosition   = 0;



	while (getline(stmFileRead,strReadLine,'\n'))
	{
		//cout << "เดซี่" << endl;

		//cout << strReadLine.c_str() << endl;
		

		
		//wchar_t *wText = fnCodePageToUnicode(65001, strReadLine.c_str());   //65001 = ANSI
		//strReadLine = fnUnicodeToCodePage(874, wText);						//874   = TIS-620
		//delete [] wText;


		//cout << strReadLine.c_str() << endl;

		vecPhrase.push_back (strReadLine.append("\n") );

		

		// Replace all of ":<" with ":  </"
		intPosition = vecPhrase[currentPhrase].find(":</");
		if(intPosition != string::npos)
		{
			vecPhrase[currentPhrase].replace(intPosition, 3, ":  </" );
		}

		// Replace all of "Ý" with ""
		intPosition = string::npos;
		intPosition = vecPhrase[currentPhrase].find("Ý");
		if(intPosition != string::npos)
		{
			vecPhrase[currentPhrase].replace(intPosition, 1, "" );
		}
		currentPhrase++;
	}
	stmFileRead.close();

	//Check existing of encoding in first line for replace.  (most of DAISY2.02)
	intPosition = vecPhrase[0].find(strSought); 	
	if(intPosition != string::npos)
	{
		//Case 1. Convert from the one to the another encoding.
		vecPhrase[0].replace(intPosition, strSought.size(), strReplacement); 

		//Check existing of "\n" in last line.
		intPosition = vecPhrase[vecPhrase.size()-1].find("\n"); 	
		if(intPosition != string::npos)
		{
			//Found - Replace "\n" in last line.
			vecPhrase[vecPhrase.size()-1].replace(intPosition, 2, "");
		}

		//Write back to file
		FILE* stmFileWrite;
		int i,j;
		j = vecPhrase.size();
		if ((stmFileWrite = fopen( strFileName.c_str(), "w+" )) != NULL )
		{
			for(i=0; i < j ; i++)
			{
				fputs(vecPhrase[i].c_str(), stmFileWrite);
			}
		}
		else
		{
			return false;
		}
		fclose(stmFileWrite);
	}
	else		
	{
		//Check existing of DOCTYPE in first line for Add <?xml.....>.  (most of DAISY2.00)
		//Case 2. There are no or incompleted xml tag <?xml ....> this function will be complete it.
		intPosition = vecPhrase[0].find("DOCTYPE");
		
		if(intPosition != string::npos)
		{
			//Case 2.1 If there are no <?xml ....> this function will be complete it.
			
			//Check existing of "\n" in last line.
			intPosition = vecPhrase[vecPhrase.size()-1].find("\n"); 	
			if(intPosition!= string::npos)
			{
				//Found - Replace "\n" in last line.
				vecPhrase[vecPhrase.size()-1].replace(intPosition, 2, "");
			}

			//Create string for first line.
			string strFirstLine;
			strFirstLine = "<?xml version=\"1.0\" ";
			strFirstLine.append(strReplacement);
			strFirstLine.append(" ?>\n");
		
			//Write back to file
			FILE* stmFileWrite;
			int i,j;
			j = vecPhrase.size();
			if ((stmFileWrite = fopen( strFileName.c_str(), "w+" )) != NULL )
			{
				fputs(strFirstLine.c_str(), stmFileWrite);
				for(i=0; i < j ; i++)
				{
					fputs(vecPhrase[i].c_str(), stmFileWrite);
				}
			}
			else
			{
				return false;
			}
			fclose(stmFileWrite);
		}
		else
		{
			//Case 2.2 There are incomplete xml tag <?xml ....> this function will be complete it.
			
			//Check existing of "\n" in last line.
			intPosition = vecPhrase[vecPhrase.size()-1].find("\n"); 	
			if(intPosition!= string::npos)
			{
				//Found - Replace "\n" in last line.
				vecPhrase[vecPhrase.size()-1].replace(intPosition, 2, "");
			}

			//Create string for first line.
			string strFirstLine;
			strFirstLine = "<?xml version=\"1.0\" ";
			strFirstLine.append(strReplacement);
			strFirstLine.append(" ?>\n");
		
			//Write back to file
			FILE* stmFileWrite;
			int i,j;
			j = vecPhrase.size();
			if ((stmFileWrite = fopen( strFileName.c_str(), "w+" )) != NULL )
			{
				fputs(strFirstLine.c_str(), stmFileWrite);
				for(i=1; i < j ; i++)					//start at secound line.
				{
					fputs(vecPhrase[i].c_str(), stmFileWrite);
				}
			}
			else
			{
				return false;
			}
			fclose(stmFileWrite);
		}
	}
	cout << "Finished fnChangeEncoding" << endl;
	return true;
}

//
//
////Convert the file to ASCII type 
//CString Converter::fnConvertFile(char *szFileName)
// {
//      CString strTempFileName ;
//      CString strInputFileName;
//      strInputFileName = szFileName;
//      char TempPathBuffer[255];
//      GetTempPath(255,TempPathBuffer);
//      FILE *fpASCII;
//      CStdioFileEx fpUnicode;
//
//      strTempFileName = TempPathBuffer;
//      strTempFileName += "TempUnicodecheck.txt";
//
//      if(fnIsUnicodeFile(szFileName) == 2)      {
//          //Open the UNICODE file
//         if(!fpUnicode.Open(szFileName,CFile::modeRead|CFile::typeBinary))
//         {
//            printf("Unable to open the unicode file\n");
//            return strInputFileName ;
//          }
//
//      //Create the temporary file
//      if((fpASCII = fopen(strTempFileName.operator LPCTSTR(),"w+"))==NULL)
//      {
//          fpUnicode.Close();
//          printf("Unable to open the output file\n");
//          return strInputFileName;
//       }
//
//      CString strData;
//      while(fpUnicode.ReadString(strData))
//      {
//          strData += "\n";
//          fwrite(strData,sizeof(char),strData.GetLength(),fpASCII);
//      }
//      fflush(fpASCII);
//      fclose(fpASCII);
//      fpUnicode.Close();
//      return strTempFileName;
//     }
//     else
//     {
//         return strInputFileName;
//     }
//
// } 




//Check if the file is UNICODE
 int Converter::fnIsUnicodeFile(const char* szFileName)
 {
     FILE *fpUnicode;
     char l_szCharBuffer[80];

     //Open the file
     if((fpUnicode= fopen(szFileName,"r")) == NULL)
     return 0; //Unable to open file

     if(!feof(fpUnicode))
     {
         fread(l_szCharBuffer,80,1,fpUnicode);
		 cout << l_szCharBuffer;
         fclose(fpUnicode);
         if(IsTextUnicode(l_szCharBuffer,80,NULL))
         {
             return 2; //Text is Unicode
         }
        else
        {
            return 1; //Text is ASCII
        }
     }
     return 0; // Some error happened
 }



// 65001 is utf-8.
wchar_t* Converter::fnCodePageToUnicode(int codePage, const char *src)
    {
    if (!src) return 0;
    int srcLen = strlen(src);
    if (!srcLen)
	{
	wchar_t *w = new wchar_t[1];
	w[0] = 0;
	return w;
	}
	
    int requiredSize = MultiByteToWideChar(codePage,
        0,
        src,srcLen,0,0);
	
    if (!requiredSize)
        {
        return 0;
        }
	
    wchar_t *w = new wchar_t[requiredSize+1];
    w[requiredSize] = 0;
	
    int retval = MultiByteToWideChar(codePage,
        0,
        src,srcLen,w,requiredSize);
    if (!retval)
        {
        delete [] w;
        return 0;
        }
	
    return w;
}


char* Converter::fnUnicodeToCodePage(int codePage, const wchar_t *src)
{
    if (!src) return 0;
    int srcLen = wcslen(src);
    if (!srcLen)
	{
	char *x = new char[1];
	x[0] = '\0';
	return x;
	}
	
    int requiredSize = WideCharToMultiByte(codePage,
        0,
        src,srcLen,0,0,0,0);
	
    if (!requiredSize)
        {
        return 0;
        }
	
    char *x = new char[requiredSize+1];
    x[requiredSize] = 0;
	
    int retval = WideCharToMultiByte(codePage,
        0,
        src,srcLen,x,requiredSize,0,0);
    if (!retval)
        {
        delete [] x;
        return 0;
        }
	
    return x;
}


string Converter::fnGetSourceDirectoryFromNccPath(string strMyNcc)
{
	return strMyNcc.substr(0,strMyNcc.find_last_of("\\"));
}


//static 
bool _stdcall Converter::mycb(unsigned long fcnt, unsigned long bcnt, struct mad_header *mhdr)
{
    /*
     * If this is the first iteration (frame count is one)
     * then print out the MP3 layer information. Using this logic
     * one can retrieve information about the MP3 file, such as 
     * channels, layer, etc., that might be useful to the calling
     * code.
     */ 

	//if (fcnt == 1) 
	//{
	//	printf("frame:%d, tot. bytes:%d, layer:%d, mode:%d\n", fcnt, bcnt, mhdr->layer, mhdr->mode);
	//}
	//else 
	//{
	//	printf("frame:%d, tot. bytes:%d\n",fcnt,bcnt);
	//}
	return true;
}

bool Converter::fnConvertMpeg2Wav(const char* chrInMpegFileName, const char* chrOutWavFileName)
{
	char  statmsg[256];
	int   status;

	/* output as WAV */
	//unsigned long fcnt;
	//unsigned long bcnt;
	//struct mad_header *mhdr;

	status = CbMpegAudioDecoder(chrInMpegFileName,
								chrOutWavFileName,
								1, 
								statmsg,
								mycb);

	if (statmsg)
	{
		printf("%s", statmsg);		
	}
	else
	{
		return false;
	}

	return true;
}

bool Converter::fnFindAndConvertMpegInSmilToVox(int intOrderSmil, char * chrOutputAudioFormat, int intOrderText2Speech)
{
	int		i,j;
	char	b[5];
	char	c[5];
	string	tempForProtectDuplicateConversion;
	string  strTempFileNameForGetDur;
	string  strTempExpectFileName;
	bool	myReturnValue;
	bool	boolDuplicate;			
	bool	boolIsTextConversion;					//ถ้า true แสดงว่าเป็นการ

	myReturnValue = false;
	boolDuplicate = false;
	boolIsTextConversion = false;

	//string	tempForInputFileName;
	//string	tempForOutputFileName;
	//bool	boolIsWAV = false;

	tempForProtectDuplicateConversion = "";
	j                                 = myVecDaisy3Smil2BodySeqId.size();									

	for (i=0; i<j; i++)
	{
		//ตรวจสอบการแปลงไฟล์เดิม ซึ่งจะทำให้เสียเวลามาก
		if (!myVecDaisy3Smil2BodyAudioSrc[i].empty() && myVecDaisy3Smil2BodyAudioSrc[i].compare("EmPtY"))												
		{
			//แบบแปลงไฟล์ MP3->WAV44kHz->WAV8kHz->VOX
			boolIsTextConversion = false;		
			if (tempForProtectDuplicateConversion.compare(myVecDaisy3Smil2BodyAudioSrc[i].data()))
			{
				tempForProtectDuplicateConversion = myVecDaisy3Smil2BodyAudioSrc[i].data();
				boolDuplicate = false;
			}
			else
			{
				boolDuplicate = true;
			}
		}
		else
		{
			//แบบแปลงข้อความ text->WAV8kHz->VOX
			boolIsTextConversion = true;
			if (tempForProtectDuplicateConversion.compare(myVecDaisy3Smil2BodyTextContent[i].data()))
			{
				tempForProtectDuplicateConversion = myVecDaisy3Smil2BodyTextContent[i].data();
				boolDuplicate = false;
			}
			else
			{
				boolDuplicate = true;
			}
		}
		
		//ถ้าไม่ใช่ไฟล์เดิมก็เริ่มแปลงได้เลย
		if (boolDuplicate == false)
		{
			itoa(intOrderSmil, b, 10);	//ลำดับของ SMIL  ใน NC_  นี้
			itoa(i+1, c, 10);			//ลำดับของ audio ใน SMIL นี้

			strTempExpectFileName = "Smil";
			strTempExpectFileName.append(b);
			strTempExpectFileName.append("Audio");
			strTempExpectFileName.append(c);
			
			myReturnValue = fnConvertOrGenerateAudio(myVecDaisy3Smil2BodyAudioSrc[i].data(), myVecDaisy3Smil2BodyTextContent[i].data(),strTempExpectFileName,chrOutputAudioFormat,intOrderText2Speech);
		}	
		
		if (myReturnValue == true)	
		{
			myVecDaisy3Smil2BodyAudioSrc[i]	= strTempExpectFileName;
			myVecDaisy3Smil2BodyAudioSrc[i].append(".");
			myVecDaisy3Smil2BodyAudioSrc[i].append(chrOutputAudioFormat);
			
			if (boolIsTextConversion == true) //เป็นการสร้างไฟล์ใหม่ดังนั้นต้องหาจุดหยุด
			{
				strTempFileNameForGetDur = strDestinationFolder;
				strTempFileNameForGetDur.append(strTempExpectFileName); 
				strTempFileNameForGetDur.append(".");
				strTempFileNameForGetDur.append(chrOutputAudioFormat);		
				myVecDaisy3Smil2BodyAudioClipBegin[i] = "npt=0.000s";
				myVecDaisy3Smil2BodyAudioClipEnd[i]   = fnGetDuration(strTempFileNameForGetDur);
			}
		}
		else
		{
			return false;
		}
		
	}
	return true;
}

bool Converter::fnLoadNcc(string myNccPath, int intOrderText2Speech, char * chrOutputAudioFormat)
{
	//Create temporary path file after clean ncc file via tidy. 
	strSourceTempPathFileName =  strSourceTempFolder;
	strSourceTempPathFileName.append("ncc.html");
	
	//Tidy Clean
	fnTidyClean(myNccPath, strSourceTempPathFileName);
	myNccPath = strSourceTempPathFileName;
	
	//Change XML Encoding
	if (!fnChangeEncoding(myNccPath, "encoding=\"tis-620\"", "encoding=\"iso-8859-11\""))
	{
		return false;
	}
    
	try 
	{
		MyLoadNccHandle = new LoadNccHandle();
        XMLPlatformUtils::Initialize("th_TH");
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
		MyReaderNcc -> parse(myNccPath.c_str());	
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

	//Copy all Ncc variable to local variable.
	myVecDaisy3NcxBodyType		= MyLoadNccHandle->getVecNccType(); 
	myVecDaisy3NcxBodyClass		= MyLoadNccHandle->getVecNccClass();
	myVecDaisy3NcxBodyId		= MyLoadNccHandle->getVecNccId();
	myVecDaisy3NcxBodyLinkFile	= MyLoadNccHandle->getVecNccLinkFile();
	myVecDaisy3NcxBodyLinkId	= MyLoadNccHandle->getVecNccLinkId();
	myVecDaisy3NcxBodyName		= MyLoadNccHandle->getVecNccName();
	myVecDaisy3NcxMetaName		= MyLoadNccHandle->getVecNccMetaName();
	myVecDaisy3NcxMetaContent	= MyLoadNccHandle->getVecNccMetaContent();
	myVecDaisy3NcxMetaScheme	= MyLoadNccHandle->getVecNccMetaScheme();
	myStrDaisy3NcxDocTitleText	= MyLoadNccHandle->getStrNccTitle();

	//Prepare to store myVecDaisy3NcxBodyKind & myVecDaisy3NcxBodyPlayOrder vector.
	int i, j;
	char b[5];
	string strTempFileNameForGetDur;              //สำหรับเก็บ Path+ชื่อไว้ ไว้หาความยาวของไฟล์เสียง
	j = myVecDaisy3NcxBodyType.size();
	for (i=0; i<j; i++)
	{
		//Store myVecDaisy3NcxBodyPlayOrder vector.
		itoa(i+1, b, 10);
		myVecDaisy3NcxBodyPlayOrder.push_back(b);

		//Store myVecDaisy3NcxBodyKind vector.
		if (( !myVecDaisy3NcxBodyType[i].compare("SPAN") 
		   || !myVecDaisy3NcxBodyType[i].compare("span") 
		   || !myVecDaisy3NcxBodyType[i].compare("Span")) 
		   &&(!myVecDaisy3NcxBodyClass[i].compare("page-normal")))
		{
			myVecDaisy3NcxBodyKind.push_back("pageList");
		}
		else
		{
			myVecDaisy3NcxBodyKind.push_back("navMap");
		}

		//create destination for result of Text2Wave and Wave2Vox funciton.
		strText2WaveDestinationFileName = strDestinationFolder;
		strText2WaveDestinationFileName.append("BodyAudio");
		strText2WaveDestinationFileName.append(b);
		strText2WaveDestinationFileName.append(".wav");

		strWave2VoxDestinationFileName  = strDestinationFolder;
		strWave2VoxDestinationFileName.append("BodyAudio");
		strWave2VoxDestinationFileName.append(b);
		strWave2VoxDestinationFileName.append(".vox");

		//Conversion Text to WAV@8kHz via Microsoft Text to speech.
 		boolReturnResult = false;
		boolReturnResult = fnConvertText2Wave(myVecDaisy3NcxBodyName[i].c_str(), strText2WaveDestinationFileName.c_str(), intOrderText2Speech, 0);
		
		if (strcmp(chrOutputAudioFormat,"vox") == 0)
		{
			//Convert WAV@8kHz to VOX and get length of VOX file via libsndfile.
			if (boolReturnResult == true)
			{		
				boolReturnResult = fnConvertWave2Vox(strText2WaveDestinationFileName, strWave2VoxDestinationFileName);
			}

			//Delete WAV@8kHz because it has no longer use.
			if( remove(strText2WaveDestinationFileName.c_str()) == -1 )
			{
				cout << "Warning :: Can't delete WAV@8kHz file name = " << strText2WaveDestinationFileName << endl;
			}
		}

		//Store all remain information.
		if (boolReturnResult == true)
		{
			strWave2VoxDestinationFileName.clear();
			strWave2VoxDestinationFileName.append("BodyAudio");
			strWave2VoxDestinationFileName.append(b);
			strWave2VoxDestinationFileName.append(".");			
			strWave2VoxDestinationFileName.append(chrOutputAudioFormat);//fix WAV or VOX file extention for this version.

			//สร้าง path+ชื่อไฟล์ ไว้ชั่วคราวสำหรับหาความยาวของไฟล์นั้น
			strTempFileNameForGetDur = strDestinationFolder;
			strTempFileNameForGetDur.append(strWave2VoxDestinationFileName);
			myVecDaisy3NcxBodyAudioSrc.push_back(strWave2VoxDestinationFileName);
			myVecDaisy3NcxBodyAudioBegin.push_back("npt=0.000s");
			myVecDaisy3NcxBodyAudioEnd.push_back(fnGetDuration(strTempFileNameForGetDur));	
		}
	}
	
	//Waive HttpEquiv for this version because them no need to write NCX.
	//myStrNccMetaHttpEquivName		= MyLoadNccHandle->getStrNccMetaHttpEquivName();
	//myStrNccMetaHttpEquivContent	= MyLoadNccHandle->getStrNccMetaHttpEquivContent();
	
	//Generate FIX string to remain local variable
	myStrDaisy3NcxVersion		= "2005-1";
	myStrDaisy3NcxXmlNs			= "http://www.daisy.org/z39.86/2005/ncx";
	myStrDaisy3NcxXmlLanguage	= "th";
	myVecDaisy3NcxCustomTestId.push_back("pagenum");
	myVecDaisy3NcxCustomTestDefaultState.push_back("false");
	myVecDaisy3NcxCustomTestOverride.push_back("visible");
	myVecDaisy3NcxCustomTestBookStruct.push_back("PAGE_NUMBER");

	//Find & Convert Text 2 Wav of NccTitle for DocTitle.
	if (!myStrDaisy3NcxDocTitleText.empty())
	{
		//create destination for result of Text2Wave and Wave2Vox funciton.
		strText2WaveDestinationFileName = strDestinationFolder;
		strText2WaveDestinationFileName.append("dtb_docTitleText.wav");
		strWave2VoxDestinationFileName  = strDestinationFolder;
		strWave2VoxDestinationFileName.append("dtb_docTitleText.vox");
		//Check availability of myStrDaisy3NcxDocTitleText
		if (myStrDaisy3NcxDocTitleText == "" )
		{
			myStrDaisy3NcxDocTitleText = "This book have no title.";
		}
		//Conversion from Text to WAV@8kHz via Microsoft Text to speech.
		boolReturnResult = fnConvertText2Wave(myStrDaisy3NcxDocTitleText.c_str(), strText2WaveDestinationFileName.c_str(), intOrderText2Speech, 0);
		
		//Checking for convert and delete
		if (strcmp(chrOutputAudioFormat,"vox") == 0)
		{
			//Conversion WAV@8kHz to VOX and get length of VOX file via libsndfile.
			if (boolReturnResult == true)
			{		
				boolReturnResult = fnConvertWave2Vox(strText2WaveDestinationFileName, strWave2VoxDestinationFileName);
			}

			//Delete WAV@8kHz because it has no longer use.
			if( remove(strText2WaveDestinationFileName.c_str()) == -1 )
			{
				cout << "Warning :: Can't delete WAV@8kHz file name = " << strText2WaveDestinationFileName << endl;
			}
		}
		
		//Store all remain information.
		if (boolReturnResult == true)
		{
			myStrDaisy3NcxDocTitleAudioSrc		= "dtb_docTitleText.";
			myStrDaisy3NcxDocTitleAudioSrc.append(chrOutputAudioFormat);	//fix VOX or WAV file extention for this version.
						
			//สร้าง path+ชื่อไฟล์ ไว้ชั่วคราวสำหรับหาความยาวของไฟล์นั้น
			strTempFileNameForGetDur			= strDestinationFolder;
			strTempFileNameForGetDur.append(myStrDaisy3NcxDocTitleAudioSrc);
			
			myStrDaisy3NcxDocTitleAudioBegin	= "npt=0.000s";
			myStrDaisy3NcxDocTitleAudioEnd		= fnGetDuration(strTempFileNameForGetDur);	
		}
	}

	//Find & Convert Text 2 Wav of dc:creator in MetaName for DocAuthor.
	j = myVecDaisy3NcxMetaName.size();
	for (i=0; i < j; i++)
	{
		if ( !myVecDaisy3NcxMetaName[i].compare("dc:creator") || !myVecDaisy3NcxMetaName[i].compare("Dc:creator") || !myVecDaisy3NcxMetaName[i].compare("DC:creator")
	   	  || !myVecDaisy3NcxMetaName[i].compare("dc:CREATOR") || !myVecDaisy3NcxMetaName[i].compare("Dc:CREATOR") || !myVecDaisy3NcxMetaName[i].compare("DC:CREATOR")
		  || !myVecDaisy3NcxMetaName[i].compare("dc:Creator") || !myVecDaisy3NcxMetaName[i].compare("Dc:Creator") || !myVecDaisy3NcxMetaName[i].compare("DC:Creator"))
		{
			//create destination for result of Text2Wave and Wave2Vox funciton.
			strText2WaveDestinationFileName = strDestinationFolder;
			strText2WaveDestinationFileName.append("dtb_docAuthorText.wav");
			strWave2VoxDestinationFileName  = strDestinationFolder;
			strWave2VoxDestinationFileName.append("dtb_docAuthorText.vox");

			//Conversion from Text to WAV@8kHz via Microsoft Text to speech.
			boolReturnResult = fnConvertText2Wave(myVecDaisy3NcxMetaContent[i].c_str(), strText2WaveDestinationFileName.c_str(), intOrderText2Speech, 0);
			
			//Checking for convert and delete
			if (strcmp(chrOutputAudioFormat,"vox") == 0)
			{
				//Convert Wave to VOX and get length of VOX file via libsndfile.
				if (boolReturnResult == true)
				{		
					boolReturnResult = fnConvertWave2Vox(strText2WaveDestinationFileName, strWave2VoxDestinationFileName);
				}

				//Delete WAV@8kHz because it has no longer use.
				if( remove(strText2WaveDestinationFileName.c_str()) == -1 )
				{
					cout << "Warning :: Can't delete WAV@8kHz file name = " << strText2WaveDestinationFileName << endl;
				}
			}

			if (boolReturnResult == true)
			{
				myStrDaisy3NcxDocAuthorText			= myVecDaisy3NcxMetaContent[i].data();
				myStrDaisy3NcxDocAuthorAudioSrc		= "dtb_docAuthorText."; 
				myStrDaisy3NcxDocAuthorAudioSrc.append(chrOutputAudioFormat);	//fix VOX or WAV file extention for this version.
				
				//สร้าง path+ชื่อไฟล์ ไว้ชั่วคราวสำหรับหาความยาวของไฟล์นั้น
				strTempFileNameForGetDur			= strDestinationFolder;
				strTempFileNameForGetDur.append(myStrDaisy3NcxDocAuthorAudioSrc);

				myStrDaisy3NcxDocAuthorAudioBegin	= "npt=0.000s";
				myStrDaisy3NcxDocAuthorAudioEnd		= fnGetDuration(strTempFileNameForGetDur);
			}
		}
	}

	myVecDaisy3NcxPartKind.push_back("navMap");			
	myVecDaisy3NcxPartId.push_back("EmPtY");
	myVecDaisy3NcxPartClass.push_back("EmPtY");
	myVecDaisy3NcxPartPositionInBody.push_back("EmPtY");
	myVecDaisy3NcxPartNavInfoText.push_back("EmPtY");
	myVecDaisy3NcxPartNavInfoAudioSrc.push_back("EmPtY");
	myVecDaisy3NcxPartNavInfoAudioBegin.push_back("EmPtY");
	myVecDaisy3NcxPartNavInfoAudioEnd.push_back("EmPtY");
	myVecDaisy3NcxPartNavLabelText.push_back("EmPtY");
	myVecDaisy3NcxPartNavLabelAudioSrc.push_back("EmPtY");
	myVecDaisy3NcxPartNavLabelAudioBegin.push_back("EmPtY");
	myVecDaisy3NcxPartNavLabelAudioEnd.push_back("EmPtY");

	myVecDaisy3NcxPartKind.push_back("pageList");			
	myVecDaisy3NcxPartId.push_back("pages");
	myVecDaisy3NcxPartClass.push_back("EmPtY");
	myVecDaisy3NcxPartPositionInBody.push_back("EmPtY");
	myVecDaisy3NcxPartNavInfoText.push_back("EmPtY");
	myVecDaisy3NcxPartNavInfoAudioSrc.push_back("EmPtY");
	myVecDaisy3NcxPartNavInfoAudioBegin.push_back("EmPtY");
	myVecDaisy3NcxPartNavInfoAudioEnd.push_back("EmPtY");
	myVecDaisy3NcxPartNavLabelText.push_back("EmPtY");
	myVecDaisy3NcxPartNavLabelAudioSrc.push_back("EmPtY");
	myVecDaisy3NcxPartNavLabelAudioBegin.push_back("EmPtY");
	myVecDaisy3NcxPartNavLabelAudioEnd.push_back("EmPtY");

	//Clear value & Destroy constructor
	MyLoadNccHandle->clearVector();
	delete MyLoadNccHandle;
	delete MyReaderNcc;
	XMLPlatformUtils::Terminate(); 
	//cout << myNccPath << " Loaded" << endl;
	return true;
}

bool Converter::fnLoadSmil(string mySmilPath)
{
	//Create temporary path file after clean SMIL file via tidy. 
	strSourceTempPathFileName =  strSourceTempFolder;
	strSourceTempPathFileName.append(mySmilPath.substr(mySmilPath.find_last_of("\\")+1));
	
	//Tidy Clean
	fnTidyClean(mySmilPath, strSourceTempPathFileName);
	mySmilPath = strSourceTempPathFileName;
	
	//Change XML Encoding
	if (!fnChangeEncoding(mySmilPath, "encoding=\"tis-620\"", "encoding=\"iso-8859-11\""))
	{
		return false;
	}
    
    try 
	{
		MyLoadSmilHandle = new LoadSmilHandle();
        XMLPlatformUtils::Initialize("th_TH");
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
	//Clear value in SMIL varibles because We are going to reuse it again.
	fnCleanSmilVariable();

	//Copy all Smil of Daisy2 vector to Daisy3 framework.
	//Copy Head-Meta
	myStrDaisy3Smil2HeadXmlNs		= "http://www.w3.org/2001/SMIL20/";     //Fixed.
	myVecDaisy3Smil2HeadMetaName	= MyLoadSmilHandle->getVecDaisy2Smil1MetaName();
	myVecDaisy3Smil2HeadMetaContent	= MyLoadSmilHandle->getVecDaisy2Smil1MetaContent();
	myVecDaisy2Smil1HeadMetaScheme	= MyLoadSmilHandle->getVecDaisy2Smil1MetaScheme();
	//loop for concat Content and Scheme belong together because in DAISY3 there are no scheme.
	int i, j;
	j = myVecDaisy3Smil2HeadMetaName.size();
	for (i=0; i<j; i++)
	{
		if (myVecDaisy2Smil1HeadMetaScheme[i].compare("EmPtY"))
		{
			myVecDaisy3Smil2HeadMetaContent[i].append(" Scheme=");
			myVecDaisy3Smil2HeadMetaContent[i].append(myVecDaisy2Smil1HeadMetaScheme[i].data());
		}
	}
	myVecDaisy3Smil2HeadMetaName.push_back("dtb:generator");
	myVecDaisy3Smil2HeadMetaContent.push_back("TAB-Telephony Project 1.0");
	
	//Fixed generate Head-Region #1 (fix for text area)
	myVecDaisy3Smil2HeadRegionId.push_back("text");
	myVecDaisy3Smil2HeadRegionTop.push_back("0%");
	myVecDaisy3Smil2HeadRegionLeft.push_back("0%");
	myVecDaisy3Smil2HeadRegionRight.push_back("0%");
	myVecDaisy3Smil2HeadRegionBottom.push_back("15%");
	myVecDaisy3Smil2HeadRegionHeight.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionWidth.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionFit.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionBackgroundColor.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionShowBackground.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionZIndex.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionXmlLang.push_back("EmPtY");
	
	//Fixed generate Head-Region #2 (fix for notes area)
	myVecDaisy3Smil2HeadRegionId.push_back("notes");
	myVecDaisy3Smil2HeadRegionTop.push_back("85%");
	myVecDaisy3Smil2HeadRegionLeft.push_back("0%");
	myVecDaisy3Smil2HeadRegionRight.push_back("0%");
	myVecDaisy3Smil2HeadRegionBottom.push_back("0%");
	myVecDaisy3Smil2HeadRegionHeight.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionWidth.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionFit.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionBackgroundColor.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionShowBackground.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionZIndex.push_back("EmPtY");
	myVecDaisy3Smil2HeadRegionXmlLang.push_back("EmPtY");
	
	//Fixed generate CustomTest #1 (fix for pagenum)
	myVecDaisy3Smil2HeadCustomTestId.push_back("pagenum");
	myVecDaisy3Smil2HeadCustomTestDefaultState.push_back("false");
	myVecDaisy3Smil2HeadCustomTestOverride.push_back("visible");
	myVecDaisy3Smil2HeadCustomTestClass.push_back("EmPtY");
	myVecDaisy3Smil2HeadCustomTestTitle.push_back("EmPtY");
	myVecDaisy3Smil2HeadCustomTestXmlLang.push_back("EmPtY");

	//Body
	myVecDaisy3Smil2BodySeqId					= MyLoadSmilHandle->getVecDaisy2Smil1BodySeqId();
	myVecDaisy3Smil2BodySeqDur					= MyLoadSmilHandle->getVecDaisy2Smil1BodySeqDur();
	myVecDaisy3Smil2BodySeqLevel				= MyLoadSmilHandle->getVecDaisy2Smil1BodySeqLevel();
	myVecDaisy3Smil2BodyParId					= MyLoadSmilHandle->getVecDaisy2Smil1BodyParId();
	myVecDaisy3Smil2BodyParCustomTest			= MyLoadSmilHandle->getVecDaisy2Smil1BodyParCustomTest();
	myVecDaisy3Smil2BodyParLevel				= MyLoadSmilHandle->getVecDaisy2Smil1BodyParLevel();	
	myVecDaisy3Smil2BodyImgId					= MyLoadSmilHandle->getVecDaisy2Smil1BodyImgId();
	myVecDaisy3Smil2BodyImgSrc					= MyLoadSmilHandle->getVecDaisy2Smil1BodyImgSrc();
	myVecDaisy3Smil2BodyTextId					= MyLoadSmilHandle->getVecDaisy2Smil1BodyTextId();
	myVecDaisy3Smil2BodyTextSrcFile				= MyLoadSmilHandle->getVecDaisy2Smil1BodyTextSrcFile();
	myVecDaisy3Smil2BodyTextSrcId				= MyLoadSmilHandle->getVecDaisy2Smil1BodyTextSrcId();
	myVecDaisy3Smil2BodyTextContent				= MyLoadSmilHandle->getVecDaisy2Smil1BodyTextContent();
	myVecDaisy3Smil2BodyAudioId					= MyLoadSmilHandle->getVecDaisy2Smil1BodyAudioId();
	myVecDaisy3Smil2BodyAudioSrc				= MyLoadSmilHandle->getVecDaisy2Smil1BodyAudioSrc();
	myVecDaisy3Smil2BodyAudioClipBegin			= MyLoadSmilHandle->getVecDaisy2Smil1BodyAudioClipBegin();
	myVecDaisy3Smil2BodyAudioClipEnd			= MyLoadSmilHandle->getVecDaisy2Smil1BodyAudioClipEnd();

	//push "EmPtY" to vecter that on tag in Daisy2
	j = myVecDaisy3Smil2BodySeqId.size();
	for (i=0; i<j; i++)
	{
		myVecDaisy3Smil2BodySeqClass.push_back("EmPtY");
		myVecDaisy3Smil2BodySeqCustomTest.push_back("EmPtY");
		myVecDaisy3Smil2BodySeqXmlLang.push_back("EmPtY");
		myVecDaisy3Smil2BodySeqEnd.push_back("EmPtY");
		myVecDaisy3Smil2BodySeqFill.push_back("EmPtY");
		myVecDaisy3Smil2BodyParClass.push_back("EmPtY");
		myVecDaisy3Smil2BodyParXmlLang.push_back("EmPtY");
		myVecDaisy3Smil2BodyAnchorId.push_back("EmPtY");
		myVecDaisy3Smil2BodyAnchorClass.push_back("EmPtY");
		myVecDaisy3Smil2BodyAnchorTitle.push_back("EmPtY");
		myVecDaisy3Smil2BodyAnchorXmlLang.push_back("EmPtY");
		myVecDaisy3Smil2BodyAnchorHref.push_back("EmPtY");
		myVecDaisy3Smil2BodyAnchorExternal.push_back("EmPtY");
		myVecDaisy3Smil2BodyImgRegion.push_back("EmPtY");
		myVecDaisy3Smil2BodyImgType.push_back("EmPtY");
		myVecDaisy3Smil2BodyImgXmlLang.push_back("EmPtY");
		myVecDaisy3Smil2BodyTextType.push_back("EmPtY");
		myVecDaisy3Smil2BodyTextRegion.push_back("EmPtY");
		myVecDaisy3Smil2BodyTextXmlLang.push_back("EmPtY");
		myVecDaisy3Smil2BodyAudioType.push_back("EmPtY");
		myVecDaisy3Smil2BodyAudioRegion.push_back("EmPtY");
		myVecDaisy3Smil2BodyAudioXmlLang.push_back("EmPtY");
	}

	MyLoadSmilHandle->clearVector();
	delete MyLoadSmilHandle;
	delete MyReaderSmil;
	XMLPlatformUtils::Terminate(); 
	//cout << mySmilPath << " Loaded" << endl;
	return true;
}

bool Converter::fnLoadHtml(string myStrSourcePathHtml)  //use parameter from 4 vectors {myVecDaisy2Smil1BodyType, myVecDaisy2Smil1LinkFile, myVecDaisy2Smil1Begin, myVecDaisy2Smil1End}
{
	//Create temporary path file after clean Html file via tidy. 
	strSourceTempPathFileName =  strSourceTempFolder;
	strSourceTempPathFileName.append(myStrSourcePathHtml.substr(myStrSourcePathHtml.find_last_of("\\")+1));
	
	//Tidy Clean
	fnTidyClean(myStrSourcePathHtml, strSourceTempPathFileName);
	myStrSourcePathHtml = strSourceTempPathFileName;
	
	//Change XML Encoding
	if (!fnChangeEncoding(myStrSourcePathHtml, "encoding=\"tis-620\"", "encoding=\"iso-8859-11\""))
	{
		return false;
	}

	//Tidy Clean
	fnTidyClean(myStrSourcePathHtml, myStrSourcePathHtml);


	//Intial LoadHtmlClass
	MyLoadHtmlHandle = new LoadHtmlHandle();

	//send vector to class for get variable
	MyLoadHtmlHandle->putVectorIdForGetString(myVecDaisy3Smil2BodyTextSrcId,myVecDaisy3Smil2BodyTextContent);

	try 
	{
        XMLPlatformUtils::Initialize("th_TH");
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
	MyReaderHtml->setFeature(XMLUni::fgXercesSchema, false);
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

	myVecHtmlMetaName				= MyLoadHtmlHandle->getVecHtmlMetaName();
	myVecHtmlMetaContent			= MyLoadHtmlHandle->getVecHtmlMetaContent();
	myVecHtmlMetaScheme				= MyLoadHtmlHandle->getVecHtmlMetaScheme();
	myStrHtmlMetaHttpEquivName		= MyLoadHtmlHandle->getStrHtmlMetaHttpEquivName();
	myStrHtmlMetaHttpEquivContent	= MyLoadHtmlHandle->getStrHtmlMetaHttpEquivContent();
	myStrHtmlTitle					= MyLoadHtmlHandle->getStrHtmlTitle();
	myStrHtmlLinkRel				= MyLoadHtmlHandle->getStrHtmlLinkRel();
	myStrHtmlLinkHref				= MyLoadHtmlHandle->getStrHtmlLinkHref();
	myStrHtmlLinkType				= MyLoadHtmlHandle->getStrHtmlLinkType();
	myStrHtmlLinkTitle				= MyLoadHtmlHandle->getStrHtmlLinkTitle();
	myVecDaisy3Smil2BodyTextContent	= MyLoadHtmlHandle->GetContentResult();				

	delete MyLoadHtmlHandle;
	delete MyReaderHtml;
	XMLPlatformUtils::Terminate(); 
	return true;
}


bool Converter::fnLoadDaisy3Ncx (string myDaisy3NcxPath, int intOrderText2Speech, char * chrOutputAudioFormat)
{
	//Create temporary path file after clean ncc file via tidy. 
	strSourceTempPathFileName =  strSourceTempFolder;
	strSourceTempPathFileName.append("dtb.ncx");
	
	//Tidy Clean
	fnTidyClean(myDaisy3NcxPath, strSourceTempPathFileName);
	myDaisy3NcxPath = strSourceTempPathFileName;
	
	//Change XML Encoding
	if (!fnChangeEncoding(myDaisy3NcxPath, "encoding=\"tis-620\"", "encoding=\"iso-8859-11\""))
	{
		return false;
	}
    
	try 
	{
		MyLoadDaisy3NcxHandle = new LoadDaisy3NcxHandle();
        XMLPlatformUtils::Initialize("th_TH");
    }
    catch (const XMLException& toCatch) 
	{
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n" << message << "\n";
        XMLString::release(&message);
        return false;
    }

	SAX2XMLReader *MyReaderDaisy3Ncx = XMLReaderFactory::createXMLReader();	

	MyReaderDaisy3Ncx->setContentHandler(MyLoadDaisy3NcxHandle);
	MyReaderDaisy3Ncx->setErrorHandler(MyLoadDaisy3NcxHandle);

	MyReaderDaisy3Ncx->setFeature(XMLUni::fgXercesLoadExternalDTD, false);
	MyReaderDaisy3Ncx->setFeature(XMLUni::fgSAX2CoreValidation, false);
	MyReaderDaisy3Ncx->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
	MyReaderDaisy3Ncx->setFeature(XMLUni::fgXercesSchema, true);
	MyReaderDaisy3Ncx->setFeature(XMLUni::fgXercesSchemaFullChecking, false);
	MyReaderDaisy3Ncx->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
	
	try	
	{	
		MyReaderDaisy3Ncx -> parse(myDaisy3NcxPath.c_str());	
	}
	catch (const XMLException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadDaisy3NcxHandle;
		delete MyReaderDaisy3Ncx;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (const SAXParseException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadDaisy3NcxHandle;
		delete MyReaderDaisy3Ncx;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (...) 
	{
		cout << "Unexpected Exception \n" ;
		delete MyLoadDaisy3NcxHandle;
		delete MyReaderDaisy3Ncx;
		XMLPlatformUtils::Terminate();
		return false;
	}

	//Copy all Daisy3Ncx vector to local
	//root
	myStrDaisy3NcxVersion					= MyLoadDaisy3NcxHandle->getStrDaisy3NcxVersion();
	myStrDaisy3NcxXmlNs						= MyLoadDaisy3NcxHandle->getStrDaisy3NcxXmlNs();
	myStrDaisy3NcxXmlLanguage				= MyLoadDaisy3NcxHandle->getStrDaisy3NcxXmlLanguage();
	//Header
	myVecDaisy3NcxCustomTestId				= MyLoadDaisy3NcxHandle->getVecDaisy3NcxCustomTestId();
	myVecDaisy3NcxCustomTestDefaultState	= MyLoadDaisy3NcxHandle->getVecDaisy3NcxCustomTestDefaultState();
	myVecDaisy3NcxCustomTestOverride		= MyLoadDaisy3NcxHandle->getVecDaisy3NcxCustomTestOverride();
	myVecDaisy3NcxCustomTestBookStruct		= MyLoadDaisy3NcxHandle->getVecDaisy3NcxCustomTestBookStruct();
	myVecDaisy3NcxMetaName					= MyLoadDaisy3NcxHandle->getVecDaisy3NcxMetaName();
	myVecDaisy3NcxMetaContent				= MyLoadDaisy3NcxHandle->getVecDaisy3NcxMetaContent();
	myVecDaisy3NcxMetaScheme				= MyLoadDaisy3NcxHandle->getVecDaisy3NcxMetaScheme();
	//docTitle
	myStrDaisy3NcxDocTitleText				= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocTitleText();
	myStrDaisy3NcxDocTitleAudioSrc			= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocTitleAudioSrc();
	myStrDaisy3NcxDocTitleAudioBegin		= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocTitleAudioBegin();
	myStrDaisy3NcxDocTitleAudioEnd			= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocTitleAudioEnd();
	myStrDaisy3NcxDocTitleImageSrc			= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocTitleImageSrc();
	//docAuthor
	myStrDaisy3NcxDocAuthorText				= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocAuthorText();
	myStrDaisy3NcxDocAuthorAudioSrc			= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocAuthorAudioSrc();
	myStrDaisy3NcxDocAuthorAudioBegin		= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocAuthorAudioBegin();
	myStrDaisy3NcxDocAuthorAudioEnd			= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocAuthorAudioEnd();
	myStrDaisy3NcxDocAuthorImageSrc			= MyLoadDaisy3NcxHandle->getStrDaisy3NcxDocAuthorImageSrc();
	//Body
	myVecDaisy3NcxBodyKind					= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyKind();			//navPoint or pageTarget or navTarget.	
	myVecDaisy3NcxBodyType					= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyType();			//H1, H2, H3 ,H4 ,H5 ,span,	navPoint, pageTarget, navTarget.			
	myVecDaisy3NcxBodyClass					= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyClass();	
	myVecDaisy3NcxBodyId					= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyId();
	myVecDaisy3NcxBodyLinkFile				= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyLinkFile();	
	myVecDaisy3NcxBodyLinkId				= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyLinkId();
	myVecDaisy3NcxBodyName					= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyName();			//text
	myVecDaisy3NcxBodyPlayOrder				= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyPlayOrder();
	myVecDaisy3NcxBodyAudioSrc				= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyAudioSrc();
	myVecDaisy3NcxBodyAudioBegin			= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyAudioBegin();
	myVecDaisy3NcxBodyAudioEnd				= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyAudioEnd();
	myVecDaisy3NcxBodyImageSrc		/*new*/	= MyLoadDaisy3NcxHandle->getVecDaisy3NcxBodyImageSrc();			/*new*/
	//Part (Section)
	myVecDaisy3NcxPartKind					= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartKind();			//navMap, PageList, navList				
	myVecDaisy3NcxPartId					= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartId();
	myVecDaisy3NcxPartClass					= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartClass();
	myVecDaisy3NcxPartPositionInBody		= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartPositionInBody(); //unnecessary 
	myVecDaisy3NcxPartNavInfoText			= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavInfoText();
	myVecDaisy3NcxPartNavInfoAudioSrc		= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavInfoAudioSrc();
	myVecDaisy3NcxPartNavInfoAudioBegin		= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavInfoAudioBegin();
	myVecDaisy3NcxPartNavInfoAudioEnd		= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavInfoAudioEnd();
	myVecDaisy3NcxPartNavInfoImageSrc/*new*/= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavInfoImageSrc();	/*new*/
	myVecDaisy3NcxPartNavLabelText			= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavLabelText();
	myVecDaisy3NcxPartNavLabelAudioSrc		= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavLabelAudioSrc();
	myVecDaisy3NcxPartNavLabelAudioBegin	= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavLabelAudioBegin();
	myVecDaisy3NcxPartNavLabelAudioEnd		= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavLabelAudioEnd();
	myVecDaisy3NcxPartNavLabelImageSrc/*new*/= MyLoadDaisy3NcxHandle->getVecDaisy3NcxPartNavLabelImageSrc();/*new*/

	//จัดการกับไฟล์ที่เกี่ยวกับเสียงของ NCX ตัวเก่ามาไว้ที่ใหม่ สำหรับไฟล์เสียง 5 ชนิดคือ
	// 1. myStrDaisy3NcxDocTitleAudioSrc		(เป็น sting)
	// 2. myStrDaisy3NcxDocAuthorAudioSrc		(เป็น sting)
	// 3. myVecDaisy3NcxBodyAudioSrc			(เป็น vecter ต้องทำ loop)
	// 4. myVecDaisy3NcxPartNavInfoAudioSrc		(เป็น vecter ต้องทำ loop)
	// 5. myVecDaisy3NcxPartNavLabelAudioSrc	(เป็น vecter ต้องทำ loop)
	string strTempFileNameForGetDur;
	string strTempExpectFileName;
	bool   myReturnValue;
	myReturnValue = false;
	
	//จัดการไฟล์เสียงของ docTitle
	strTempExpectFileName = "dtb_docTitleText";
	myReturnValue = fnConvertOrGenerateAudio(myStrDaisy3NcxDocTitleAudioSrc.c_str(),myStrDaisy3NcxDocTitleText.c_str(),strTempExpectFileName.c_str(),chrOutputAudioFormat,intOrderText2Speech);
	if (myReturnValue == true)
	{
		strTempFileNameForGetDur = strDestinationFolder;
		strTempFileNameForGetDur.append(strTempExpectFileName); 
		strTempFileNameForGetDur.append(".");
		strTempFileNameForGetDur.append(chrOutputAudioFormat);
		myStrDaisy3NcxDocTitleAudioSrc	 = strTempExpectFileName;
		myStrDaisy3NcxDocTitleAudioSrc.append(".");
		myStrDaisy3NcxDocTitleAudioSrc.append(chrOutputAudioFormat);
		myStrDaisy3NcxDocTitleAudioBegin = "npt=0.000s";
		myStrDaisy3NcxDocTitleAudioEnd   = fnGetDuration(strTempFileNameForGetDur);
	}

	//จัดการไฟล์เสียงของ docAuthor
	strTempExpectFileName = "dtb_docAuthorText";
	myReturnValue = fnConvertOrGenerateAudio(myStrDaisy3NcxDocAuthorAudioSrc,myStrDaisy3NcxDocAuthorText,strTempExpectFileName,chrOutputAudioFormat,intOrderText2Speech);
	if (myReturnValue == true)
	{
		strTempFileNameForGetDur = strDestinationFolder;
		strTempFileNameForGetDur.append(strTempExpectFileName); 
		strTempFileNameForGetDur.append(".");
		strTempFileNameForGetDur.append(chrOutputAudioFormat);
		myStrDaisy3NcxDocAuthorAudioSrc	 = strTempExpectFileName;
		myStrDaisy3NcxDocAuthorAudioSrc.append(".");
		myStrDaisy3NcxDocAuthorAudioSrc.append(chrOutputAudioFormat);
		myStrDaisy3NcxDocAuthorAudioBegin = "npt=0.000s";
		myStrDaisy3NcxDocAuthorAudioEnd   = fnGetDuration(strTempFileNameForGetDur);
	}

	//วน loop เพื่อจัดการไฟล์เสียงของ  myVecDaisy3NcxBodyAudioSrc
	int  i,j;
	char b[5];
	j	 = myVecDaisy3NcxBodyId.size();
	for(i=0; i<j; i++)
	{
		itoa(i+1, b, 10);
		strTempExpectFileName = "BodyAudio";
		strTempExpectFileName.append(b);
		myReturnValue = fnConvertOrGenerateAudio(myVecDaisy3NcxBodyAudioSrc[i].data(),myVecDaisy3NcxBodyName[i].data(),strTempExpectFileName,chrOutputAudioFormat,intOrderText2Speech);
		if (myReturnValue == true)
		{
			strTempFileNameForGetDur = strDestinationFolder;
			strTempFileNameForGetDur.append(strTempExpectFileName); 
			strTempFileNameForGetDur.append(".");
			strTempFileNameForGetDur.append(chrOutputAudioFormat);
			myVecDaisy3NcxBodyAudioSrc[i]	 = strTempExpectFileName;
			myVecDaisy3NcxBodyAudioSrc[i].append(".");
			myVecDaisy3NcxBodyAudioSrc[i].append(chrOutputAudioFormat);
			myVecDaisy3NcxBodyAudioBegin[i] = "npt=0.000s";
			myVecDaisy3NcxBodyAudioEnd[i]   = fnGetDuration(strTempFileNameForGetDur);
		}
	}

/*	ส่วนนี้คือ การแปลง Audio ในส่วนของ Info และ Label ใน Head(Part) 
	แต่ละเอาไว้ก่อน เพราะใน fnLoadNcc ยังไม่มี
	//วน loop เพื่อเอาค่าของ myVecDaisy3NcxPartNavInfoAudioSrc มา copy
	j	 = //myVecDaisy3NcxPartNavInfoAudioSrc.size();
	for(i=0; i<j; i++)
	{
		itoa(i+1, b, 10);
		strTempExpectFileName = "InfoAudio";
		strTempExpectFileName.append(b);
		myReturnValue = fnConvertOrGenerateAudio(myVecDaisy3NcxPartNavInfoAudioSrc[i].data(), myVecDaisy3NcxPartNavInfoText[i].data(),strTempExpectFileName,chrOutputAudioFormat,intOrderText2Speech);
		if (myReturnValue == true)
		{
			strTempFileNameForGetDur = strDestinationFolder;
			strTempFileNameForGetDur.append(strTempExpectFileName); 
			strTempFileNameForGetDur.append(".");
			strTempFileNameForGetDur.append(chrOutputAudioFormat);
			myVecDaisy3NcxPartNavInfoAudioSrc[i]   = strTempExpectFileName;
			myVecDaisy3NcxPartNavInfoAudioSrc[i].append(".");
			myVecDaisy3NcxPartNavInfoAudioSrc[i].append(chrOutputAudioFormat);
			myVecDaisy3NcxPartNavInfoAudioBegin[i] = "npt=0.000s";
			myVecDaisy3NcxPartNavInfoAudioEnd[i]   = fnGetDuration(strTempFileNameForGetDur);
		}
	}

	//วน loop เพื่อเอาค่าของ myVecDaisy3NcxPartNavLabelAudioSrc มา copy
	j	 = myVecDaisy3NcxPartNavLabelAudioSrc.size();
	for(i=0; i<j; i++)
	{
		itoa(i+1, b, 10);
		strTempExpectFileName = "LabelAudio";
		strTempExpectFileName.append(b);
		myReturnValue = fnConvertOrGenerateAudio(myVecDaisy3NcxPartNavLabelAudioSrc[i].data(), myVecDaisy3NcxPartNavLabelText[i].data(),strTempExpectFileName,chrOutputAudioFormat,intOrderText2Speech);
		if (myReturnValue == true)
		{
			strTempFileNameForGetDur = strDestinationFolder;
			strTempFileNameForGetDur.append(strTempExpectFileName); 
			strTempFileNameForGetDur.append(".");
			strTempFileNameForGetDur.append(chrOutputAudioFormat);
			myVecDaisy3NcxPartNavLabelAudioSrc[i]	= strTempExpectFileName;
			myVecDaisy3NcxPartNavLabelAudioSrc[i].append(".");
			myVecDaisy3NcxPartNavLabelAudioSrc[i].append(chrOutputAudioFormat);
			myVecDaisy3NcxPartNavLabelAudioBegin[i] = "npt=0.000s";
			myVecDaisy3NcxPartNavLabelAudioEnd[i]   = fnGetDuration(strTempFileNameForGetDur);
		}
	}*/


	j = myVecDaisy3NcxCustomTestId.size();
	if (j == 0) 
	{
		myVecDaisy3NcxCustomTestId.push_back("pagenum");
		myVecDaisy3NcxCustomTestDefaultState.push_back("false");
		myVecDaisy3NcxCustomTestOverride.push_back("visible");
		myVecDaisy3NcxCustomTestBookStruct.push_back("PAGE_NUMBER");
	}


	//Clear All variable in class before delete it!
	MyLoadDaisy3NcxHandle->clearVector();

	delete MyLoadDaisy3NcxHandle;
	delete MyReaderDaisy3Ncx;
	XMLPlatformUtils::Terminate(); 
	cout << myDaisy3NcxPath << " Loaded" << endl;
	return true;
}

bool Converter::fnConvertOrGenerateAudio(string strAudioSrc,
										 string strAudioText,
										 string strAudioExpectFileName,
										 char*  chrOutputAudioFormat,
										 int    intOrderText2Speech)
{
	string tempForInputFileName;		//สำหรับพักค่าของ InputFileName
	string tempForOutputFileName;		//สำหรับพักค่าของ OutputFileName
	bool   boolIsWAV = false;			//เพื่อตรวจสอบว่าเป็นไฟล์ WAV หรือ MP3
	boolReturnResult = false;           //มีการประกาศเป็น Global Variable ไว้อยู่แล้ว
	
	cout << "DEBUG :: fnConvertOrGenerateAudio strAudioExpectFileName = " << strAudioExpectFileName << endl;
	//ตรวจดูว่าต้นฉบับระบุไฟล์เสียงใน strAudioSrc ไว้หรือเปล่า 
	if (!strAudioSrc.empty()&& strAudioSrc.compare("EmPtY"))
	{	
		cout << "DEBUG :: fnConvertOrGenerateAudio (Convert) strAudioSrc = " << strAudioSrc << endl;
		//มีการระบุไฟล์เสียงไว้ใน strAudioSrc
		// - ให้เช็คชนิดของไฟล์ต้นทางและปลายทาง ถ้าตรงกันก็คัดลอกไปลงที่ปลายทางได้เลย
		// - ถ้าไม่ตรงกันต้องทำการแปลงก่อน (MP3->WAV@44k->WAV@8k->VOX)
		
		//Conversion from MP3 to WAV@44kHz
		tempForInputFileName = strSourcePathBook;
		tempForInputFileName.append("\\");
		tempForInputFileName.append(strAudioSrc);
		tempForOutputFileName = strDestinationFolder;
		tempForOutputFileName.append(strAudioExpectFileName);
		tempForOutputFileName.append("_@44kHz.wav");				//fixed as wav
		
		//ตรวจชนิดของไฟล์ก่อนถ้าเป็น WAV อยู่แล้วก็ไม่ต้องเปลี่ยนเพียงแค่ copy ก็พอ
		if		(tempForInputFileName.find(".wav")!= string::npos)	{ boolIsWAV = true; }
		else if (tempForInputFileName.find(".Wav")!= string::npos)	{ boolIsWAV = true; }
		else if (tempForInputFileName.find(".WAV")!= string::npos)	{ boolIsWAV = true; }
		else if (tempForInputFileName.find(".mp3")!= string::npos)	{ boolIsWAV = false;}
		else if (tempForInputFileName.find(".Mp3")!= string::npos)	{ boolIsWAV = false;}
		else if (tempForInputFileName.find(".MP3")!= string::npos)	{ boolIsWAV = false;}
		else
		{
			cout << "Error :: this Audio Input file is not supported. " << tempForInputFileName << endl;
			return false;
		}

		//ถ้าไม่ใช่ WAV (เป็น MP3) ให้แปลงจาก MP3 เป็น WAV
		if (boolIsWAV == false)
		{
			//Conversion from MP3 to WAV
			if (fnConvertMpeg2Wav(tempForInputFileName.c_str(),tempForOutputFileName.c_str()) == false)
			{
				return false;
			}
		}
		else //ในกรณีเป็น WAV อยู่แล้วให้ทำการ Copy มาไว้ที่ output directory
		{
			//Copy file.
			cout << "DEBUG :: copy WAV to WAV44k" << endl;
			if (fnCopyBinaryFile(tempForInputFileName.c_str(),tempForOutputFileName.c_str()) == false)
			{
				return false;
			}
		}

		//Conversion from WAV@44kHz to WAV@8kHz
		cout << "DEBUG :: convert to WAV8k" << endl;
		tempForInputFileName  = tempForOutputFileName;
		tempForOutputFileName = strDestinationFolder;
		tempForOutputFileName.append(strAudioExpectFileName);
		tempForOutputFileName.append(".wav");						//fixed as _8K.wav
		if (fnConvertWave2Wave8K(tempForInputFileName,tempForOutputFileName) == false)
		{
			return false;
		}

		//Delete WAV@44kHz because it has a large size and no longer use.
		if( remove(tempForInputFileName.c_str()) == -1 )
		{
			cout << "Warning :: Can't delete WAV@44kHz file name = " << tempForInputFileName << endl;
		}

		//Checking type of output file before convert and delete
		if (strcmp(chrOutputAudioFormat,"vox") == 0)
		{
			//Conversion from WAV@8kHz to VOX
			cout << "DEBUG :: convert to VOX" << endl;
			tempForInputFileName  = tempForOutputFileName;
			tempForOutputFileName = strDestinationFolder;
			tempForOutputFileName.append(strAudioExpectFileName);
			tempForOutputFileName.append(".vox");	//fixed as .vox
			if (fnConvertWave2Vox(tempForInputFileName,tempForOutputFileName) == false)
			{
				return false;
			}

			//Delete WAV@8kHz because it has no longer use.
			if( remove(tempForInputFileName.c_str()) == -1 )
			{
				cout << "Warning :: Can't delete WAV@8kHz file name = " << tempForInputFileName << endl;
			}
		}
	}
	else
	{
		cout << "DEBUG :: fnConvertOrGenerateAudio (Generate) strAudioSrc = " << strAudioSrc << endl;
		cout << "DEBUG :: fnConvertOrGenerateAudio (Generate) strAudioText = " << strAudioText << endl;
		//ไม่มีการระบุไฟล์เสียงของ strAudioSrc ไว้ (ส่วนนี้จะคล้ายกับ fnLoadNcc)
		// - ตรวจสอบว่า Text ไม่ว่างเปล่า 
		// - นำ Text นั้นไปให้ Microsoft Text to Speech แปลงเป็น WAV@8k
		// - ถ้า Output ต้องการเป็น VOX ให้แปลงเป็น VOX แล้วลบ WAV@8k ทิ้ง
		if(!strAudioText.empty() && strAudioText.compare("EmPtY"))
		{
			//Setting destination path for result of Text2Wave and Wave2Vox funciton.
			strText2WaveDestinationFileName = strDestinationFolder;
			strText2WaveDestinationFileName.append(strAudioExpectFileName);
			strText2WaveDestinationFileName.append(".wav");
			strWave2VoxDestinationFileName  = strDestinationFolder;
			strWave2VoxDestinationFileName.append(strAudioExpectFileName);
			strWave2VoxDestinationFileName.append(".vox");		
			//Conversion Text to WAV@8kHz via Microsoft Text to speech.
 			boolReturnResult = false;
			boolReturnResult = fnConvertText2Wave(strAudioText.c_str(), strText2WaveDestinationFileName.c_str(), intOrderText2Speech, 0);
			//Check for VOX case.
			if (strcmp(chrOutputAudioFormat,"vox") == 0)
			{
				//Convert WAV@8kHz to VOX and get length of VOX file via libsndfile.
				if (boolReturnResult == true)
				{		
					boolReturnResult = fnConvertWave2Vox(strText2WaveDestinationFileName, strWave2VoxDestinationFileName);
				}
				//Delete WAV@8kHz because it has no longer use.
				if( remove(strText2WaveDestinationFileName.c_str()) == -1 )
				{
					cout << "Warning :: Can't delete WAV@8kHz file name = " << strText2WaveDestinationFileName << endl;
				}
			}
		}	
		else
		{
			return false;
		}
	}
	return true;
}


bool Converter::fnLoadDaisy3Smil2 (string myDaisy3Smil2Path)
{
	//Create temporary path file after clean SMIL file via tidy. 
	strSourceTempPathFileName =  strSourceTempFolder;
	strSourceTempPathFileName.append(myDaisy3Smil2Path.substr(myDaisy3Smil2Path.find_last_of("\\")+1));
	
	//Tidy Clean
	fnTidyClean(myDaisy3Smil2Path, strSourceTempPathFileName);
	myDaisy3Smil2Path = strSourceTempPathFileName;
	
	//Change XML Encoding
	if (!fnChangeEncoding(myDaisy3Smil2Path, "encoding=\"tis-620\"", "encoding=\"iso-8859-11\""))
	{
		return false;
	}
    
    try 
	{
		MyLoadDaisy3Smil2Handle = new LoadDaisy3Smil2Handle();
        XMLPlatformUtils::Initialize("th_TH");
    }
    catch (const XMLException& toCatch) 
	{
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n" << message << "\n";
        XMLString::release(&message);
        return false;
    }

	SAX2XMLReader *MyReaderDaisy3Smil2 = XMLReaderFactory::createXMLReader();	

	MyReaderDaisy3Smil2->setContentHandler(MyLoadDaisy3Smil2Handle);
	MyReaderDaisy3Smil2->setErrorHandler(MyLoadDaisy3Smil2Handle);

	MyReaderDaisy3Smil2->setFeature(XMLUni::fgXercesLoadExternalDTD, false);
	MyReaderDaisy3Smil2->setFeature(XMLUni::fgSAX2CoreValidation, false);
	MyReaderDaisy3Smil2->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
	MyReaderDaisy3Smil2->setFeature(XMLUni::fgXercesSchema, true);
	MyReaderDaisy3Smil2->setFeature(XMLUni::fgXercesSchemaFullChecking, false);
	MyReaderDaisy3Smil2->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
	
	try	
	{	
		MyReaderDaisy3Smil2 -> parse(myDaisy3Smil2Path.c_str());	
	}
	catch (const XMLException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadDaisy3Smil2Handle;
		delete MyReaderDaisy3Smil2;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (const SAXParseException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadDaisy3Smil2Handle;
		delete MyReaderDaisy3Smil2;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (...) 
	{
		cout << "Unexpected Exception \n" ;
		delete MyLoadDaisy3Smil2Handle;
		delete MyReaderDaisy3Smil2;
		XMLPlatformUtils::Terminate();
		return false;
	}

	//Copy all Daisy3Smil2 vector to local
	//Header
	myStrDaisy3Smil2HeadXmlNs					= MyLoadDaisy3Smil2Handle->getStrDaisy3Smil2HeadXmlNs();
	myVecDaisy3Smil2HeadMetaName				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadMetaName();
	myVecDaisy3Smil2HeadMetaContent				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadMetaContent();
	myVecDaisy3Smil2HeadRegionId				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionId();
	myVecDaisy3Smil2HeadRegionTop				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionTop();
	myVecDaisy3Smil2HeadRegionLeft				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionLeft();
	myVecDaisy3Smil2HeadRegionRight				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionRight();
	myVecDaisy3Smil2HeadRegionBottom			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionBottom();
	myVecDaisy3Smil2HeadRegionHeight			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionHeight();
	myVecDaisy3Smil2HeadRegionWidth				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionWidth();
	myVecDaisy3Smil2HeadRegionFit				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionFit();
	myVecDaisy3Smil2HeadRegionBackgroundColor	= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionBackgroundColor();
	myVecDaisy3Smil2HeadRegionShowBackground	= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionShowBackground();
	myVecDaisy3Smil2HeadRegionZIndex			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionZIndex();
	myVecDaisy3Smil2HeadRegionXmlLang			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadRegionXmlLang();
	myVecDaisy3Smil2HeadCustomTestId			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadCustomTestId();
	myVecDaisy3Smil2HeadCustomTestDefaultState	= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadCustomTestDefaultState();
	myVecDaisy3Smil2HeadCustomTestOverride		= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadCustomTestOverride();
	myVecDaisy3Smil2HeadCustomTestClass			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadCustomTestClass();
	myVecDaisy3Smil2HeadCustomTestTitle			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadCustomTestTitle();
	myVecDaisy3Smil2HeadCustomTestXmlLang		= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2HeadCustomTestXmlLang(); 

	//Body
	myVecDaisy3Smil2BodySeqId					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodySeqId();
	myVecDaisy3Smil2BodySeqClass				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodySeqClass();
	myVecDaisy3Smil2BodySeqCustomTest			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodySeqCustomTest();
	myVecDaisy3Smil2BodySeqDur					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodySeqDur();
	myVecDaisy3Smil2BodySeqXmlLang				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodySeqXmlLang();
	myVecDaisy3Smil2BodySeqEnd					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodySeqEnd();
	myVecDaisy3Smil2BodySeqFill					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodySeqFill();
	
	myVecDaisy3Smil2BodyParId					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyParId();
	myVecDaisy3Smil2BodyParClass				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyParClass();
	myVecDaisy3Smil2BodyParCustomTest			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyParCustomTest();
	myVecDaisy3Smil2BodyParXmlLang				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyParXmlLang();
	
	myVecDaisy3Smil2BodyAnchorId				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAnchorId();
	myVecDaisy3Smil2BodyAnchorClass				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAnchorClass();
	myVecDaisy3Smil2BodyAnchorTitle				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAnchorTitle();
	myVecDaisy3Smil2BodyAnchorXmlLang			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAnchorXmlLang();
	myVecDaisy3Smil2BodyAnchorHref				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAnchorHref();
	myVecDaisy3Smil2BodyAnchorExternal			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAnchorExternal();

	myVecDaisy3Smil2BodyImgId					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyImgId();
	myVecDaisy3Smil2BodyImgRegion				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyImgRegion();
	myVecDaisy3Smil2BodyImgSrc					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyImgSrc();
	myVecDaisy3Smil2BodyImgType					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyImgType();
	myVecDaisy3Smil2BodyImgXmlLang				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyImgXmlLang();
	
	myVecDaisy3Smil2BodyTextId					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyTextId();
	myVecDaisy3Smil2BodyTextSrcFile				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyTextSrcFile();
	myVecDaisy3Smil2BodyTextSrcId				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyTextSrcId();
	myVecDaisy3Smil2BodyTextType				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyTextType();
	myVecDaisy3Smil2BodyTextRegion				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyTextRegion();
	myVecDaisy3Smil2BodyTextXmlLang				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyTextXmlLang();
	myVecDaisy3Smil2BodyTextContent				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyTextContent();

	myVecDaisy3Smil2BodyAudioId					= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAudioId();
	myVecDaisy3Smil2BodyAudioSrc				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAudioSrc();
	myVecDaisy3Smil2BodyAudioType				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAudioType();
	myVecDaisy3Smil2BodyAudioClipBegin			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAudioClipBegin();
	myVecDaisy3Smil2BodyAudioClipEnd			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAudioClipEnd();
	myVecDaisy3Smil2BodyAudioRegion				= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAudioRegion();
	myVecDaisy3Smil2BodyAudioXmlLang			= MyLoadDaisy3Smil2Handle->getVecDaisy3Smil2BodyAudioXmlLang();

	MyLoadDaisy3Smil2Handle->clearVector();
	delete MyLoadDaisy3Smil2Handle;
	delete MyReaderDaisy3Smil2;
	XMLPlatformUtils::Terminate(); 
	cout << myDaisy3Smil2Path << " Loaded" << endl;
	return true;
}
	
bool Converter::fnLoadDaisy3Xml(string myDaisy3XmlPath)
{
	//Create temporary path file after clean Xml file via tidy. 
	strSourceTempPathFileName =  strSourceTempFolder;
	strSourceTempPathFileName.append(myDaisy3XmlPath.substr(myDaisy3XmlPath.find_last_of("\\")+1));
	
	//Tidy Clean
	fnTidyClean(myDaisy3XmlPath, strSourceTempPathFileName);
	myDaisy3XmlPath = strSourceTempPathFileName;
	
	//Change XML Encoding
	if (!fnChangeEncoding(myDaisy3XmlPath, "encoding=\"tis-620\"", "encoding=\"iso-8859-11\""))
	{
		return false;
	}
    
	//Intial LoadDaisy3Xml Class
	MyLoadDaisy3XmlHandle = new LoadDaisy3XmlHandle();
    
	//send vector to class for get variable
	//look at this point again. (and below in this function too)
	//MyLoadDaisy3XmlHandle->putVectorIdForGetString(myVecDaisy2Smil1Begin,myVecDaisy2Smil1End);
	
	try 
	{
        XMLPlatformUtils::Initialize("th_TH");
    }
    catch (const XMLException& toCatch) 
	{
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization! :\n" << message << "\n";
        XMLString::release(&message);
        return false;
    }

	SAX2XMLReader *MyReaderDaisy3Xml = XMLReaderFactory::createXMLReader();	

	MyReaderDaisy3Xml->setContentHandler(MyLoadDaisy3XmlHandle);
	MyReaderDaisy3Xml->setErrorHandler(MyLoadDaisy3XmlHandle);

	MyReaderDaisy3Xml->setFeature(XMLUni::fgXercesLoadExternalDTD, false);
	MyReaderDaisy3Xml->setFeature(XMLUni::fgSAX2CoreValidation, false);
	MyReaderDaisy3Xml->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
	MyReaderDaisy3Xml->setFeature(XMLUni::fgXercesSchema, true);
	MyReaderDaisy3Xml->setFeature(XMLUni::fgXercesSchemaFullChecking, false);
	MyReaderDaisy3Xml->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);
	
	try	
	{
		MyReaderDaisy3Xml -> parse(myDaisy3XmlPath.c_str());	
	}
	catch (const XMLException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadDaisy3XmlHandle;
		delete MyReaderDaisy3Xml;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (const SAXParseException& toCatch) 
	{
		char* message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n" << message << "\n";
		XMLString::release(&message);
		delete MyLoadDaisy3XmlHandle;
		delete MyReaderDaisy3Xml;
		XMLPlatformUtils::Terminate();
		return false;
	}
	catch (...) 
	{
		cout << "Unexpected Exception \n" ;
		delete MyLoadDaisy3XmlHandle;
		delete MyReaderDaisy3Xml;
		XMLPlatformUtils::Terminate();
		return false;
	}

	//look at this point agin.
	//myVecDaisy2Smil1End	= MyLoadDaisy3XmlHandle->GetContentResult();
	
	delete MyLoadDaisy3XmlHandle;
	delete MyReaderDaisy3Xml;
	XMLPlatformUtils::Terminate(); 
	return true;
}

//ฟังก์ชั่นการเขียนไฟล์ Ncx
bool Converter::fnWriteNcx(char* chrEnCoding, const char* chrOutputFileName)
{
	xercesc_3_1::DOMDocumentType   *pDoctype	= NULL;
	xercesc_3_1::DOMDocument	   *pDoc		= NULL;
	xercesc_3_1::DOMNode		   *pNode		= NULL;
	xercesc_3_1::DOMImplementation *pImplement  = NULL;
	xercesc_3_1::XMLFormatTarget   *pTarget	    = NULL;
	xercesc_3_1::DOMLSSerializer   *pSerializer = NULL;
	xercesc_3_1::DOMDocumentImpl   *pDocImpl	= NULL;
	xercesc_3_1::DOMLSOutput	   *pOutput		= NULL;

	try
	{
		// initialize the XML library
		XMLPlatformUtils::Initialize("th_TH");
	}
	catch(...)
	{
		cout << "Error to initialize the XML library for writing XML file." << endl;
	}

	// get a serializer, an instance of DOMLSSerializer (the "LS" stands for load-save).
	//pImplement  = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("LS"));
	pImplement  = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("LS"));
	pSerializer = ((DOMImplementationLS*)pImplement)->createLSSerializer();
	pTarget     = new StdOutFormatTarget();

	// set user specified end of line sequence and output encoding
	pSerializer->setNewLine(XMLString::transcode("\n"));
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTSplitCdataSections, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTDiscardDefaultContent, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTBOM, false);
	
	//Creating document.
	pDoctype = pImplement->createDocumentType(XMLString::transcode("ncx"), XMLString::transcode("-//NISO//DTD ncx 2005-1//EN"), XMLString::transcode("http://www.daisy.org/z3986/2005/ncx-2005-1.dtd"));
	pDoc     = pImplement->createDocument(XMLString::transcode(myStrDaisy3NcxXmlNs.data()), XMLString::transcode("ncx"), pDoctype);

	if (pDoc)
	{
	
		
		//Creating XML element and its attributes.
		//pDoc			-> setXmlEncoding(XMLString::transcode(chrEnCoding));
		pDoc			-> setXmlStandalone(true);							//Fixed	
		pDoc			-> setXmlVersion(XMLString::transcode("1.0"));				//Fixed
		
		//Creating NCX element and its attributes.
		DOMElement		   *pRoot;	
		DOMAttr			   *domAttNcx;
		pRoot			=  pDoc->getDocumentElement();
		domAttNcx		=  pDoc->createAttribute(XMLString::transcode("version"));
		domAttNcx		-> setValue(XMLString::transcode(myStrDaisy3NcxVersion.data()));
		pRoot			-> setAttributeNode(domAttNcx);
		domAttNcx		=  pDoc->createAttribute(XMLString::transcode("xml:lang"));
		domAttNcx		-> setValue(XMLString::transcode(myStrDaisy3NcxXmlLanguage.data()));
		pRoot			-> setAttributeNode(domAttNcx);

		//Creating head element and its attributes.
		DOMElement		   *domEleHead;
		domEleHead		=  pDoc->createElement(XMLString::transcode("head"));
		pRoot			-> appendChild(domEleHead);

		//Declaration Variable.
		DOMElement		   *myDomElement;
		DOMAttr			   *myDomAttribute;
		DOMText			   *myDomText;

		//Creating smilCustomTest #1 element and its attributes.  (loop from vector)
		int j = myVecDaisy3NcxCustomTestId.size();
		for (int i=0; i<j; i++)
		{
			myDomElement	=  pDoc->createElement(XMLString::transcode("smilCustomTest"));
			domEleHead      -> appendChild(myDomElement);
			myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("id"));
			myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3NcxCustomTestId[i].data()));
			myDomElement    -> setAttributeNode(myDomAttribute);
			myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("defaultState"));
			myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3NcxCustomTestDefaultState[i].data()));
			myDomElement    -> setAttributeNode(myDomAttribute);
			myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("override"));
			myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3NcxCustomTestOverride[i].data()));
			myDomElement    -> setAttributeNode(myDomAttribute);
			myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("bookStruct"));
			myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3NcxCustomTestBookStruct[i].data()));
			myDomElement    -> setAttributeNode(myDomAttribute);
		}

		//Creating meta element and its attributes. (loop)
		j = myVecDaisy3NcxMetaName.size();
		for (int i=0; i < j; i++)
		{
			myDomElement	=  pDoc->createElement(XMLString::transcode("meta"));
			domEleHead		-> appendChild(myDomElement);
			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("name"));
			myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxMetaName[i].data()));
			myDomElement	-> setAttributeNode(myDomAttribute);
			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("content"));
			myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxMetaContent[i].data()));
			myDomElement	-> setAttributeNode(myDomAttribute);
			if (!myVecDaisy3NcxMetaScheme[i].empty())
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("scheme"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxMetaScheme[i].data()));
				myDomElement	-> setAttributeNode(myDomAttribute);
			}
		}

		//ตรวจสอบว่ามีค่า text ของ docTitle หรือไม่ (ถ้าไม่มี text ก็ถือว่าไม่มีการระบุ docTitle) 
		if(!myStrDaisy3NcxDocTitleText.empty() && myStrDaisy3NcxDocTitleText.compare("EmPtY"))
		{
			//สร้าง text ของ docTitle
			DOMElement		   *domEleDocTitle;
			domEleDocTitle	=  pDoc->createElement(XMLString::transcode("docTitle"));
			pRoot			-> appendChild(domEleDocTitle);
			myDomElement	=  pDoc->createElement(XMLString::transcode("text"));
			domEleDocTitle	-> appendChild(myDomElement);
			myDomText		=  pDoc->createTextNode(XMLString::transcode(myStrDaisy3NcxDocTitleText.data()));
			myDomElement	-> appendChild(myDomText);
		
			//ตรวจสอบว่ามีค่า Audio ของ Doctitle หรือไม่
			if(!myStrDaisy3NcxDocTitleAudioSrc.empty() && myStrDaisy3NcxDocTitleAudioSrc.compare("EmPtY"))
			{
				//สร้าง Audio ของ docTitle
				myDomElement	=  pDoc->createElement(XMLString::transcode("audio"));
				domEleDocTitle	-> appendChild(myDomElement);
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
				myDomAttribute	-> setValue(XMLString::transcode(myStrDaisy3NcxDocTitleAudioSrc.data()));
				myDomElement	-> setAttributeNode(myDomAttribute);
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
				myDomAttribute	-> setValue(XMLString::transcode(myStrDaisy3NcxDocTitleAudioBegin.data()));
				myDomElement	-> setAttributeNode(myDomAttribute);
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
				myDomAttribute	-> setValue(XMLString::transcode(myStrDaisy3NcxDocTitleAudioEnd.data()));
				myDomElement	-> setAttributeNode(myDomAttribute);
			}
			//ตรวจสอบว่ามีค่า Image ของ DocTitle หรือไม่ 
			if (!myStrDaisy3NcxDocTitleImageSrc.empty() && myStrDaisy3NcxDocTitleImageSrc.compare("EmPtY"))
			{
				//สร้าง Image ของ docTitle
				myDomElement	=  pDoc->createElement(XMLString::transcode("img"));
				domEleDocTitle	-> appendChild(myDomElement);
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
				myDomAttribute	-> setValue(XMLString::transcode(myStrDaisy3NcxDocTitleImageSrc.data()));
				myDomElement	-> setAttributeNode(myDomAttribute);
			}
		}

		//ตรวจสอบว่ามีค่า text ของ docAuthor หรือไม่ (ถ้าไม่มี text ก็ถือว่าไม่มีการระบุ docAuthor)
		if(!myStrDaisy3NcxDocAuthorText.empty() && myStrDaisy3NcxDocAuthorText.compare("EmPtY"))
		{
			//สร้าง text ของ docAuthor
			DOMElement		   *domEleDocAuthor;
			domEleDocAuthor	=  pDoc->createElement(XMLString::transcode("docAuthor"));
			pRoot			-> appendChild(domEleDocAuthor);
			myDomElement	=  pDoc->createElement(XMLString::transcode("text"));
			domEleDocAuthor	-> appendChild(myDomElement);
			myDomText		=  pDoc->createTextNode(XMLString::transcode(myStrDaisy3NcxDocAuthorText.data()));
			myDomElement	-> appendChild(myDomText);
			
			//ตรวจสอบว่ามีค่า Audio ของ DocAuthor หรือไม่
			if(!myStrDaisy3NcxDocAuthorAudioSrc.empty() && myStrDaisy3NcxDocAuthorAudioSrc.compare("EmPtY"))
			{
				//สร้าง Audio ของ docAuthor
				myDomElement	=  pDoc->createElement(XMLString::transcode("audio"));
				domEleDocAuthor	-> appendChild(myDomElement);
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
				myDomAttribute	-> setValue(XMLString::transcode(myStrDaisy3NcxDocAuthorAudioSrc.data()));
				myDomElement	-> setAttributeNode(myDomAttribute);
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
				myDomAttribute	-> setValue(XMLString::transcode(myStrDaisy3NcxDocAuthorAudioBegin.data()));
				myDomElement	-> setAttributeNode(myDomAttribute);
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
				myDomAttribute	-> setValue(XMLString::transcode(myStrDaisy3NcxDocAuthorAudioEnd.data()));
				myDomElement	-> setAttributeNode(myDomAttribute);
			}

			//ตรวจสอบว่ามีค่า Image ของ DocAuthor หรือไม่ 
			if (!myStrDaisy3NcxDocAuthorImageSrc.empty() && myStrDaisy3NcxDocAuthorImageSrc.compare("EmPtY"))
			{
				//สร้าง Image ของ docAuthor
				myDomElement	=  pDoc->createElement(XMLString::transcode("img"));
				domEleDocAuthor	-> appendChild(myDomElement);
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
				myDomAttribute	-> setValue(XMLString::transcode(myStrDaisy3NcxDocAuthorImageSrc.data()));
				myDomElement	-> setAttributeNode(myDomAttribute);
			}
		}
		
		//Creating navMap element and its attributes. (loop) 
		DOMElement		*domElePart;
		DOMElement		*domEleNavPoint1;
		DOMElement		*domEleNavPoint2;
		DOMElement		*domEleNavPoint3;
		DOMElement		*domEleNavPoint4;
		DOMElement		*domEleNavPoint5;
		DOMElement		*domEleNavLabel;
		DOMElement		*domEleNavText;
		DOMElement		*domEleNavAudio;
		DOMElement		*domEleContent;

		string tempForInsert;
		char b[5];
		int k, l;
		l = myVecDaisy3NcxPartKind.size();
		//loop for all part
		for (k=0; k<l; k++)
		{
			//Setup Heading for all part.
			domElePart	=	pDoc->createElement(XMLString::transcode(myVecDaisy3NcxPartKind[k].data()));
			pRoot		->	appendChild(domElePart);	

			if (myVecDaisy3NcxPartId[k].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxPartId[k].data()));
				domElePart		-> setAttributeNode(myDomAttribute);
			}

			if (myVecDaisy3NcxPartClass[k].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("class"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxPartClass[k].data()));
				domElePart		-> setAttributeNode(myDomAttribute);
			}

			if (myVecDaisy3NcxPartNavInfoText[k].compare("EmPtY"))
			{
				//Create navLabel
				domEleNavLabel	=  pDoc->createElement(XMLString::transcode("navInfo"));
				domElePart		-> appendChild(domEleNavLabel);

				//Creating text in navLabel
				myDomElement	=  pDoc->createElement(XMLString::transcode("text"));
				domEleNavLabel	-> appendChild(myDomElement);
				myDomText		=  pDoc->createTextNode(XMLString::transcode(myVecDaisy3NcxPartNavInfoText[k].data()));
				myDomElement	-> appendChild(myDomText);				
			
				//Check & Creating AudioSrc AudioClipBegin AudiClipEnd
				if (myVecDaisy3NcxPartNavInfoAudioSrc[k].compare("EmPtY"))
				{
					myDomElement	=  pDoc->createElement(XMLString::transcode("audio"));
					domEleNavLabel	-> appendChild(myDomElement);
					myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
					myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxPartNavInfoAudioSrc[k].data()));
					myDomElement	-> setAttributeNode(myDomAttribute);
					myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
					myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxPartNavInfoAudioBegin[k].data()));
					myDomElement	-> setAttributeNode(myDomAttribute);
					myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
					myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxPartNavInfoAudioEnd[k].data()));
					myDomElement	-> setAttributeNode(myDomAttribute);
				}		
			}

			if (myVecDaisy3NcxPartNavLabelText[k].compare("EmPtY"))
			{
				//Create navLabel
				domEleNavLabel	=  pDoc->createElement(XMLString::transcode("navLabel"));
				domElePart		-> appendChild(domEleNavLabel);

				//Creating text in navLabel
				myDomElement	=  pDoc->createElement(XMLString::transcode("text"));
				domEleNavLabel	-> appendChild(myDomElement);
				myDomText		=  pDoc->createTextNode(XMLString::transcode(myVecDaisy3NcxPartNavLabelText[k].data()));
				myDomElement	-> appendChild(myDomText);	
			
				//Check & Creating AudioSrc AudioClipBegin AudiClipEnd
				if (myVecDaisy3NcxPartNavLabelAudioSrc[k].compare("EmPtY"))
				{
					myDomElement	=  pDoc->createElement(XMLString::transcode("audio"));
					domEleNavLabel	-> appendChild(myDomElement);
					myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
					myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxPartNavLabelAudioSrc[k].data()));
					myDomElement	-> setAttributeNode(myDomAttribute);
					myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
					myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxPartNavLabelAudioBegin[k].data()));
					myDomElement	-> setAttributeNode(myDomAttribute);
					myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
					myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxPartNavLabelAudioEnd[k].data()));
					myDomElement	-> setAttributeNode(myDomAttribute);
				}			
			}

			//detect type of kind [navMap, not navMap]
			if (!myVecDaisy3NcxPartKind[k].compare("navMap"))
			{
				j = myVecDaisy3NcxBodyType.size();
				for (int i=0; i<j; i++)
				{	
					itoa(i+1, b, 10);
					if (!myVecDaisy3NcxBodyType[i].compare("h1")       || !myVecDaisy3NcxBodyType[i].compare("H1") ||
					   (!myVecDaisy3NcxBodyType[i].compare("navPoint") && !myVecDaisy3NcxBodyType[i].compare("navPoint"))) //DAISY3 text Only ของ www.bookshare.org
					{
						//Creating navPoint in navMap
						domEleNavPoint1	=  pDoc->createElement(XMLString::transcode("navPoint"));
						domElePart		-> appendChild(domEleNavPoint1);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("class"));
						myDomAttribute	-> setValue(XMLString::transcode("chapter"));
						domEleNavPoint1	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyId[i].data()));
						domEleNavPoint1	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("playOrder"));
						myDomAttribute	-> setValue(XMLString::transcode(b));
						domEleNavPoint1	-> setAttributeNode(myDomAttribute);

						//Creating navLabel in navPoint
						domEleNavLabel	=  pDoc->createElement(XMLString::transcode("navLabel"));
						domEleNavPoint1	-> appendChild(domEleNavLabel);

						//Creating text in navLabel
						domEleNavText	=  pDoc->createElement(XMLString::transcode("text"));
						domEleNavLabel	-> appendChild(domEleNavText);
						myDomText		=  pDoc->createTextNode(XMLString::transcode(myVecDaisy3NcxBodyName[i].data()));
						domEleNavText	-> appendChild(myDomText);

						//Creating audio in navLabel 
						domEleNavAudio	=  pDoc->createElement(XMLString::transcode("audio"));
						domEleNavLabel	-> appendChild(domEleNavAudio);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioSrc[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioBegin[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioEnd[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);

						//Creating content in navPoint
						tempForInsert = myVecDaisy3NcxBodyLinkFile[i].data();
						tempForInsert.append("#");
						tempForInsert.append(myVecDaisy3NcxBodyLinkId[i].data());
						domEleContent	=  pDoc->createElement(XMLString::transcode("content"));
						domEleNavPoint1	-> appendChild(domEleContent);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(tempForInsert.data()));
						domEleContent	-> setAttributeNode(myDomAttribute);
					}

					if (!myVecDaisy3NcxBodyType[i].compare("h2") || !myVecDaisy3NcxBodyType[i].compare("H2"))
					{
						domEleNavPoint2	=  pDoc->createElement(XMLString::transcode("navPoint"));
						domEleNavPoint1	-> appendChild(domEleNavPoint2);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("class"));
						myDomAttribute	-> setValue(XMLString::transcode("section"));
						domEleNavPoint2	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyId[i].data()));
						domEleNavPoint2	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("playOrder"));
						myDomAttribute	-> setValue(XMLString::transcode(b));
						domEleNavPoint2	-> setAttributeNode(myDomAttribute);

						//Creating navLabel in navPoint
						domEleNavLabel	=  pDoc->createElement(XMLString::transcode("navLabel"));
						domEleNavPoint2	-> appendChild(domEleNavLabel);

						//Creating text in navLabel
						domEleNavText	=  pDoc->createElement(XMLString::transcode("text"));
						domEleNavLabel	-> appendChild(domEleNavText);
						myDomText		=  pDoc->createTextNode(XMLString::transcode(myVecDaisy3NcxBodyName[i].data()));
						domEleNavText	-> appendChild(myDomText);

						//Creating audio in navLabel 
						domEleNavAudio	=  pDoc->createElement(XMLString::transcode("audio"));
						domEleNavLabel	-> appendChild(domEleNavAudio);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioSrc[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioBegin[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioEnd[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);

						//Creating content in navPoint
						tempForInsert = myVecDaisy3NcxBodyLinkFile[i].data();
						tempForInsert.append("#");
						tempForInsert.append(myVecDaisy3NcxBodyLinkId[i].data());

						domEleContent	=  pDoc->createElement(XMLString::transcode("content"));
						domEleNavPoint2	-> appendChild(domEleContent);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(tempForInsert.data()));
						domEleContent	-> setAttributeNode(myDomAttribute);
					}

					if (!myVecDaisy3NcxBodyType[i].compare("h3") || !myVecDaisy3NcxBodyType[i].compare("H3"))
					{
						domEleNavPoint3	=  pDoc->createElement(XMLString::transcode("navPoint"));
						domEleNavPoint2	-> appendChild(domEleNavPoint3);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("class"));
						myDomAttribute	-> setValue(XMLString::transcode("subsection"));
						domEleNavPoint3	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyId[i].data()));
						domEleNavPoint3	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("playOrder"));
						myDomAttribute	-> setValue(XMLString::transcode(b));
						domEleNavPoint3	-> setAttributeNode(myDomAttribute);

						//Creating navLabel in navPoint
						domEleNavLabel	=  pDoc->createElement(XMLString::transcode("navLabel"));
						domEleNavPoint3	-> appendChild(domEleNavLabel);

						//Creating text in navLabel
						domEleNavText	=  pDoc->createElement(XMLString::transcode("text"));
						domEleNavLabel	-> appendChild(domEleNavText);
						myDomText		=  pDoc->createTextNode(XMLString::transcode(myVecDaisy3NcxBodyName[i].data()));
						domEleNavText	-> appendChild(myDomText);

						//Creating audio in navLabel 
						domEleNavAudio	=  pDoc->createElement(XMLString::transcode("audio"));
						domEleNavLabel	-> appendChild(domEleNavAudio);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioSrc[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioBegin[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioEnd[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);

						//Creating content in navPoint
						tempForInsert = myVecDaisy3NcxBodyLinkFile[i].data();
						tempForInsert.append("#");
						tempForInsert.append(myVecDaisy3NcxBodyLinkId[i].data());
						domEleContent	=  pDoc->createElement(XMLString::transcode("content"));
						domEleNavPoint3	-> appendChild(domEleContent);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(tempForInsert.data()));
						domEleContent	-> setAttributeNode(myDomAttribute);			
					}

					if (!myVecDaisy3NcxBodyType[i].compare("h4") || !myVecDaisy3NcxBodyType[i].compare("H4"))
					{
						domEleNavPoint4	=  pDoc->createElement(XMLString::transcode("navPoint"));
						domEleNavPoint3	-> appendChild(domEleNavPoint4);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("class"));
						myDomAttribute	-> setValue(XMLString::transcode("sub-subsection"));
						domEleNavPoint4	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyId[i].data()));
						domEleNavPoint4	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("playOrder"));
						myDomAttribute	-> setValue(XMLString::transcode(b));
						domEleNavPoint4	-> setAttributeNode(myDomAttribute);

						//Creating navLabel in navPoint
						domEleNavLabel	=  pDoc->createElement(XMLString::transcode("navLabel"));
						domEleNavPoint4	-> appendChild(domEleNavLabel);

						//Creating text in navLabel
						domEleNavText	=  pDoc->createElement(XMLString::transcode("text"));
						domEleNavLabel	-> appendChild(domEleNavText);

						myDomText		=  pDoc->createTextNode(XMLString::transcode(myVecDaisy3NcxBodyName[i].data()));
						domEleNavText	-> appendChild(myDomText);

						//Creating audio in navLabel 
						domEleNavAudio	=  pDoc->createElement(XMLString::transcode("audio"));
						domEleNavLabel	-> appendChild(domEleNavAudio);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioSrc[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioBegin[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioEnd[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
					
						//Creating content in navPoint
						tempForInsert = myVecDaisy3NcxBodyLinkFile[i].data();
						tempForInsert.append("#");
						tempForInsert.append(myVecDaisy3NcxBodyLinkId[i].data());

						domEleContent	=  pDoc->createElement(XMLString::transcode("content"));
						domEleNavPoint4	-> appendChild(domEleContent);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(tempForInsert.data()));
						domEleContent	-> setAttributeNode(myDomAttribute);			
					}

					if (!myVecDaisy3NcxBodyType[i].compare("h5") || !myVecDaisy3NcxBodyType[i].compare("H5"))
					{
						domEleNavPoint5	=  pDoc->createElement(XMLString::transcode("navPoint"));
						domEleNavPoint4	-> appendChild(domEleNavPoint5);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("class"));
						myDomAttribute	-> setValue(XMLString::transcode("supersub-section"));
						domEleNavPoint5	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyId[i].data()));
						domEleNavPoint5	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("playOrder"));
						myDomAttribute	-> setValue(XMLString::transcode(b));
						domEleNavPoint5	-> setAttributeNode(myDomAttribute);

						//Creating navLabel in navPoint
						domEleNavLabel	=  pDoc->createElement(XMLString::transcode("navLabel"));
						domEleNavPoint5	-> appendChild(domEleNavLabel);

						//Creating text in navLabel
						domEleNavText	=  pDoc->createElement(XMLString::transcode("text"));
						domEleNavLabel	-> appendChild(domEleNavText);
						myDomText		=  pDoc->createTextNode(XMLString::transcode(myVecDaisy3NcxBodyName[i].data()));
						domEleNavText	-> appendChild(myDomText);

						//Creating audio in navLabel 
						domEleNavAudio	=  pDoc->createElement(XMLString::transcode("audio"));
						domEleNavLabel	-> appendChild(domEleNavAudio);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioSrc[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioBegin[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioEnd[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);

						//Creating content in navPoint
						tempForInsert = myVecDaisy3NcxBodyLinkFile[i].data();
						tempForInsert.append("#");
						tempForInsert.append(myVecDaisy3NcxBodyLinkId[i].data());

						domEleContent	=  pDoc->createElement(XMLString::transcode("content"));
						domEleNavPoint5	-> appendChild(domEleContent);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(tempForInsert.data()));
						domEleContent	-> setAttributeNode(myDomAttribute);
					}
				}
			}
			else if (!myVecDaisy3NcxPartKind[k].compare("pageList") || !myVecDaisy3NcxPartKind[k].compare("navList"))
			{
				DOMElement *domElePageTarget;
				j = myVecDaisy3NcxBodyType.size();
				for (int i=0; i<j; i++)
				{
					itoa(i+1, b, 10);
					//Detect SPAN & page-normal from loading DAISY2
					//Detect pageTarget & navTarget from loading DAISY3
					if  ((( !myVecDaisy3NcxBodyType[i].compare("SPAN")					//DAISY2
						 || !myVecDaisy3NcxBodyType[i].compare("span")					//DAISY2
						 || !myVecDaisy3NcxBodyType[i].compare("Span"))					//DAISY2
						 &&(!myVecDaisy3NcxBodyClass[i].compare("page-normal")))		//DAISY2
						 || !myVecDaisy3NcxBodyType[i].compare("pageTarget")			//DAISY3
						 || !myVecDaisy3NcxBodyType[i].compare("navTarget"))			//DAISY3
					{
						//Select between pageList and navList
						//Detect (SPAN & page-normal from loading DAISY2) or (pageList from DAISY3) => pageList(create child pageTarget)
						//Detect only (pageTarget from DAISY3) => navList (create child pageTarget)
						if ((( !myVecDaisy3NcxBodyType[i].compare("SPAN")				//DAISY2
							|| !myVecDaisy3NcxBodyType[i].compare("span")				//DAISY2
							|| !myVecDaisy3NcxBodyType[i].compare("Span"))				//DAISY2
							&&(!myVecDaisy3NcxBodyClass[i].compare("page-normal")))		//DAISY2
							||(!myVecDaisy3NcxBodyType[i].compare("pageTarget")))		//DAISY3
						{
							//Creating pageTarget in pageList
							domElePageTarget	=  pDoc->createElement(XMLString::transcode("pageTarget"));
							domElePart			-> appendChild(domElePageTarget);
						}

						if (!myVecDaisy3NcxBodyType[i].compare("navTarget"))			//DAISY3
						{
							//Creating navTarget in navList
							domElePageTarget	=  pDoc->createElement(XMLString::transcode("navTarget"));
							domElePart			-> appendChild(domElePageTarget);
						}

						myDomAttribute		=  pDoc->createAttribute(XMLString::transcode("class"));
						myDomAttribute		-> setValue(XMLString::transcode("pagenum"));
						domElePageTarget	-> setAttributeNode(myDomAttribute);

						myDomAttribute		=  pDoc->createAttribute(XMLString::transcode("type"));
						myDomAttribute		-> setValue(XMLString::transcode("normal"));
						domElePageTarget	-> setAttributeNode(myDomAttribute);

						myDomAttribute		=  pDoc->createAttribute(XMLString::transcode("id"));
						myDomAttribute		-> setValue(XMLString::transcode(myVecDaisy3NcxBodyId[i].data()));
						domElePageTarget	-> setAttributeNode(myDomAttribute);
			
						myDomAttribute		=  pDoc->createAttribute(XMLString::transcode("value"));
						myDomAttribute		-> setValue(XMLString::transcode(myVecDaisy3NcxBodyName[i].data()));
						domElePageTarget	-> setAttributeNode(myDomAttribute);

						myDomAttribute		=  pDoc->createAttribute(XMLString::transcode("playOrder"));
						myDomAttribute		-> setValue(XMLString::transcode(b));
						domElePageTarget	-> setAttributeNode(myDomAttribute);

						//Creating navLabel in pageTarget
						domEleNavLabel		=  pDoc->createElement(XMLString::transcode("navLabel"));
						domElePageTarget	-> appendChild(domEleNavLabel);

						//Creating text in navLabel
						domEleNavText		=  pDoc->createElement(XMLString::transcode("text"));
						domEleNavLabel		-> appendChild(domEleNavText);
						myDomText			=  pDoc->createTextNode(XMLString::transcode(myVecDaisy3NcxBodyName[i].data()));
						domEleNavText		-> appendChild(myDomText);

						//Creating audio in navLabel (empty)
						domEleNavAudio	=  pDoc->createElement(XMLString::transcode("audio"));
						domEleNavLabel	-> appendChild(domEleNavAudio);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioSrc[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipBegin"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioBegin[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);
						myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("clipEnd"));
						myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyAudioEnd[i].data()));
						domEleNavAudio	-> setAttributeNode(myDomAttribute);

						//Creating content in navTarget
						tempForInsert = myVecDaisy3NcxBodyLinkFile[i].data();
						tempForInsert.append("#");
						tempForInsert.append(myVecDaisy3NcxBodyLinkId[i].data());

						domEleContent		=  pDoc->createElement(XMLString::transcode("content"));
						domElePageTarget	-> appendChild(domEleContent);
						myDomAttribute		=  pDoc->createAttribute(XMLString::transcode("src"));
						myDomAttribute		-> setValue(XMLString::transcode(tempForInsert.data()));
						domEleContent		-> setAttributeNode(myDomAttribute);
					}
				}			
			}
		}
		
		//show output @ screen - no need.
		//fflush(stdout);
		//pSerializer->writeNode(pTarget, *pDoc);

		// construct the LocalFileFormatTarget
		XMLFormatTarget *myFormatTarget = new LocalFileFormatTarget(chrOutputFileName);

		pOutput = ((DOMImplementationLS*)pImplement)->createLSOutput();
        pOutput->setByteStream(myFormatTarget);

		// serialize a DOMNode to the "string strOutputFileName"
		pSerializer->write(pDoc, pOutput);

		// optionally, you can flush the buffer to ensure all contents are written
		myFormatTarget->flush();
		delete myFormatTarget; 
	}
	delete pTarget;
	delete pSerializer;
	delete pDoc;
	delete pDoctype;

	// terminate the XML library
	XMLPlatformUtils::Terminate();
	return true;

}

bool Converter::fnWriteSmil2(char* chrEnCoding, const char* chrOutputFileName, string strAudioType) //fix output as wav first! (aware next line too, because I am fixed it.)
{
	xercesc_3_1::DOMDocumentType   *pDoctype	= NULL;
	xercesc_3_1::DOMDocument	   *pDoc		= NULL;
	xercesc_3_1::DOMNode		   *pNode		= NULL;
	xercesc_3_1::DOMImplementation *pImplement  = NULL;
	xercesc_3_1::DOMLSSerializer   *pSerializer = NULL;
	xercesc_3_1::XMLFormatTarget   *pTarget	    = NULL;
	xercesc_3_1::DOMLSOutput	   *pOutput		= NULL;

	try
	{
		// initialize the XML library
		XMLPlatformUtils::Initialize("th_TH");
	}
	catch(...)
	{
		cout << "Error to initialize the XML library for writing XML file." << endl;
	}

	// get a serializer, an instance of DOMLSSerializer (the "LS" stands for load-save).
	pImplement  = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("LS"));
	pSerializer = ((DOMImplementationLS*)pImplement)->createLSSerializer();
	pTarget     = new StdOutFormatTarget();

	// set user specified end of line sequence and output encoding
	pSerializer->setNewLine(XMLString::transcode("\n"));
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTSplitCdataSections, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTDiscardDefaultContent, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTBOM, false);
	
	//Creating document.
	pDoctype = pImplement->createDocumentType(XMLString::transcode("smil"), XMLString::transcode("-//NISO//DTD dtbsmil 2005-1//EN"), XMLString::transcode("http://www.daisy.org/z3986/2005/dtbsmil-2005-1.dtd"));
	pDoc     = pImplement->createDocument(XMLString::transcode(myStrDaisy3Smil2HeadXmlNs.data()), XMLString::transcode("smil"), pDoctype);

	if (pDoc)
	{
		//Creating XML element and its attributes.
		//pDoc			-> setEncoding(XMLString::transcode(chrEnCoding));
		pDoc			-> setXmlStandalone(true);
		pDoc			-> setXmlVersion(XMLString::transcode("1.0"));
		
		//Creating root element.
		DOMElement		   *pRoot;	
		pRoot			=  pDoc->getDocumentElement();
		
		//Creating DOM Variable for Temporary using.
		//DOMElement	   *myDomElement;
		DOMAttr			   *myDomAttribute;
		//DOMText		   *myDomText;			//no need for smil

		//Creating head element and its attributes.
		DOMElement		   *domEleHead;
		domEleHead		=  pDoc->createElement(XMLString::transcode("head"));
		pRoot			-> appendChild(domEleHead);

		  ////////////////////////////////////////////////////
		 //Creating meta element and its attributes. (loop)//
		////////////////////////////////////////////////////
		DOMElement	   *domEleMeta;
		int j = myVecDaisy3Smil2HeadMetaName.size();
		for (int i=0;i<j;i++)
		{
			domEleMeta		=  pDoc->createElement(XMLString::transcode("meta"));
			domEleHead		-> appendChild(domEleMeta);
			//Meta Name
			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("name"));
			myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadMetaName[i].data()));
			domEleMeta		-> setAttributeNode(myDomAttribute);
			//Meta Content (&Scheme)
			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("content"));
			myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadMetaContent[i].data()));
			domEleMeta		-> setAttributeNode(myDomAttribute);
		}

		  ////////////////////////////
		 //Creating layout element.//
		////////////////////////////
		DOMElement		   *domEleLayout;
		domEleLayout	=  pDoc->createElement(XMLString::transcode("layout"));
		domEleHead		-> appendChild(domEleLayout);

		j = myVecDaisy3Smil2HeadRegionId.size();
		for (int i=0;i<j;i++)
		{
			//Creating region element. 
			DOMElement		   *domEleRegion;
			domEleRegion	=  pDoc->createElement(XMLString::transcode("region"));
			domEleLayout	-> appendChild(domEleRegion);

			//Create attribute for id ****FIX****
			myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("id"));						//Requried
			myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionId[i].data()));	//Requried
			domEleRegion	-> setAttributeNode(myDomAttribute);								//Requried

			//Create attribute for top
			if (myVecDaisy3Smil2HeadRegionTop[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("top"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionTop[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for left
			if (myVecDaisy3Smil2HeadRegionLeft[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("left"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionLeft[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for right
			if (myVecDaisy3Smil2HeadRegionRight[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("right"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionRight[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for bottom
			if (myVecDaisy3Smil2HeadRegionBottom[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("bottom"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionBottom[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for height
			if (myVecDaisy3Smil2HeadRegionHeight[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("height"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionHeight[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for width
			if (myVecDaisy3Smil2HeadRegionWidth[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("width"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionWidth[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for fit
			if (myVecDaisy3Smil2HeadRegionFit[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("fit"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionFit[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for backgroundColor
			if (myVecDaisy3Smil2HeadRegionBackgroundColor[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("backgroundColor"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionBackgroundColor[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for showBackground
			if (myVecDaisy3Smil2HeadRegionShowBackground[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("showBackground"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionShowBackground[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for z-index
			if (myVecDaisy3Smil2HeadRegionZIndex[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("z-index"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionZIndex[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for xml:lang
			if (myVecDaisy3Smil2HeadRegionXmlLang[i].compare("EmPtY"))
			{
				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("xml:lang"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadRegionXmlLang[i].data()));
				domEleRegion	-> setAttributeNode(myDomAttribute);
			}
		}
		
		  //////////////////////////////////////
		 //Creating customAttributes element.//
		//////////////////////////////////////
		DOMElement		   *domEleCustomA;              //domEleCustomAttributes
		domEleCustomA	=  pDoc->createElement(XMLString::transcode("customAttributes"));
		domEleHead		-> appendChild(domEleCustomA);

		j = myVecDaisy3Smil2HeadCustomTestId.size();
		for (int i=0;i<j;i++)
		{
			//Creating customTest element.
			DOMElement		   *domEleCustomTest;
			domEleCustomTest	=   pDoc->createElement(XMLString::transcode("customTest"));
			domEleCustomA		-> appendChild(domEleCustomTest);				

			//Create attribute for id.
			myDomAttribute		=  pDoc->createAttribute(XMLString::transcode("id"));							//Requested.
			myDomAttribute		-> setValue(XMLString::transcode(myVecDaisy3Smil2HeadCustomTestId[i].data()));	//Requested.
			domEleCustomTest	-> setAttributeNode(myDomAttribute);									//Requested.

			//Create attribute for class
			if (myVecDaisy3Smil2HeadCustomTestClass[i].compare("EmPtY"))
			{
				myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("class"));
				myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3Smil2HeadCustomTestClass[i].data()));
				domEleCustomTest-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for title
			if (myVecDaisy3Smil2HeadCustomTestTitle[i].compare("EmPtY"))
			{
				myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("title"));
				myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3Smil2HeadCustomTestTitle[i].data()));
				domEleCustomTest-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for xml:lang
			if (myVecDaisy3Smil2HeadCustomTestXmlLang[i].compare("EmPtY"))
			{
				myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("xml:lang"));
				myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3Smil2HeadCustomTestXmlLang[i].data()));
				domEleCustomTest-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for defaultState
			if (myVecDaisy3Smil2HeadCustomTestDefaultState[i].compare("EmPtY"))
			{
				myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("defaultState"));
				myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3Smil2HeadCustomTestDefaultState[i].data()));
				domEleCustomTest-> setAttributeNode(myDomAttribute);
			}

			//Create attribute for override
			if (myVecDaisy3Smil2HeadCustomTestOverride[i].compare("EmPtY"))
			{
				myDomAttribute  =  pDoc->createAttribute(XMLString::transcode("override"));
				myDomAttribute  -> setValue(XMLString::transcode(myVecDaisy3Smil2HeadCustomTestOverride[i].data()));
				domEleCustomTest-> setAttributeNode(myDomAttribute);
			}
		}

		///////////////////////////////
		//Start writing BODY section.//
		///////////////////////////////
		//Creating par and seq element and its attributes. 
		DOMElement	*domEleBody;
		DOMElement	*domEleSeq1;
		DOMElement	*domElePar;
		DOMElement	*domEleText;
		DOMElement	*domEleAudio;
		DOMElement	*domEleImg;
		string		tempForInsert;

		//////////////////////////
		//Creating body element.//
		//////////////////////////
		domEleBody	=	pDoc->createElement(XMLString::transcode("body"));
		pRoot		->	appendChild(domEleBody);

		/////////////////////////////////////////////////
		//create seq and its attributes. (7 Attributes)//
		/////////////////////////////////////////////////
		domEleSeq1	=	pDoc->createElement(XMLString::transcode("seq"));
		domEleBody	->	appendChild(domEleSeq1);

		////Create attribute for id
		if (myVecDaisy3Smil2BodySeqId[0].compare("EmPtY"))
		{
			myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("id"));
			myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodySeqId[0].data()));
			domEleSeq1		->	setAttributeNode(myDomAttribute);	
		}

		//Create attribute for class
		if (myVecDaisy3Smil2BodySeqClass[0].compare("EmPtY"))
		{		
			myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("class"));
			myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodySeqClass[0].data()));
			domEleSeq1		->	setAttributeNode(myDomAttribute);	
		}

		//Create attribute for customTest
		if (myVecDaisy3Smil2BodySeqCustomTest[0].compare("EmPtY"))
		{
			myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("customTest"));
			myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodySeqCustomTest[0].data()));
			domEleSeq1		->	setAttributeNode(myDomAttribute);	
		}

		//Create attribute for dur
		if (myVecDaisy3Smil2BodySeqDur[0].compare("EmPtY"))
		{
			myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("dur"));
			myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodySeqDur[0].data()));
			domEleSeq1		->	setAttributeNode(myDomAttribute);	
		}

		//Create attribute for xml:lang
		if (myVecDaisy3Smil2BodySeqXmlLang[0].compare("EmPtY"))
		{
			myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("xml:lang"));
			myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodySeqXmlLang[0].data()));
			domEleSeq1		->	setAttributeNode(myDomAttribute);	
		}

		//Create attribute for end
		if (myVecDaisy3Smil2BodySeqEnd[0].compare("EmPtY"))
		{
			myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("end"));
			myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodySeqEnd[0].data()));
			domEleSeq1		->	setAttributeNode(myDomAttribute);	
		}

		//Create attribute for fill
		if (myVecDaisy3Smil2BodySeqFill[0].compare("EmPtY"))
		{
			myDomAttribute  =	pDoc->createAttribute(XMLString::transcode("fill"));
			myDomAttribute  ->	setValue(XMLString::transcode(myVecDaisy3Smil2BodySeqFill[0].data()));
			domEleSeq1		->	setAttributeNode(myDomAttribute);	
		}

		///////////////////////////////////////////////////////////////////////
		//Creating par, text, image, audio element and its attributes. (loop)//
		///////////////////////////////////////////////////////////////////////
		j = myVecDaisy3Smil2BodySeqId.size();
		for (int i=0; i<j; i++)
		{ 
			/////////////////////////////////////////////////
			//create par and its attributes. (4 Attributes)//
			/////////////////////////////////////////////////
			domElePar	=  pDoc->createElement(XMLString::transcode("par"));
			domEleSeq1	-> appendChild(domElePar);

			//Create attribute for id
			if (myVecDaisy3Smil2BodyParId[i].compare("EmPtY"))
			{
				myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("id"));
				myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyParId[i].data()));
				domElePar		->	setAttributeNode(myDomAttribute);	
			}

			//Create attribute for class
			if (myVecDaisy3Smil2BodyParClass[i].compare("EmPtY"))
			{
				myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("class"));
				myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyParClass[i].data()));
				domElePar		->	setAttributeNode(myDomAttribute);	
			}

			//Create attribute for customTest
			if (myVecDaisy3Smil2BodyParCustomTest[i].compare("EmPtY"))
			{
				myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("customTest"));
				myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyParCustomTest[i].data()));
				domElePar		->	setAttributeNode(myDomAttribute);	
			}

			//Create attribute for xml:lang
			if (myVecDaisy3Smil2BodyParXmlLang[i].compare("EmPtY"))
			{
				myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("xml:lang"));
				myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyParXmlLang[i].data()));
				domElePar		->	setAttributeNode(myDomAttribute);	
			}

			  //////////////////////////////////////////////////////////
			 //Detect available of text. and create it (5 Attributes)//
			//////////////////////////////////////////////////////////
			if (myVecDaisy3Smil2BodyTextSrcFile[i].compare("EmPtY"))
			{
				//Creating text element
				domEleText		=  pDoc->createElement(XMLString::transcode("text"));
				domElePar		-> appendChild(domEleText);
				//Create attribute for src !!! Don't check because this function just checked it !!!
				tempForInsert = "dtb.xml#";   //Sum up src for text and fix dtb.xml as same file name.
				tempForInsert.append(myVecDaisy3Smil2BodyTextSrcId[i].data());

				myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("src"));
				myDomAttribute	->	setValue(XMLString::transcode(tempForInsert.data()));
				domEleText		->	setAttributeNode(myDomAttribute);
				
				//Create attribute for id 
				if (myVecDaisy3Smil2BodyTextId[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("id"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyTextId[i].data()));
					domEleText		->	setAttributeNode(myDomAttribute);
				}
				else
				{
					//ชดเชย สำหรับ daisy text only ที่ไม่มี id สำหรับ text
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("id"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyTextSrcId[i].data()));
					domEleText		->	setAttributeNode(myDomAttribute);
				}

				//Create attribute for type
				if (myVecDaisy3Smil2BodyTextType[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("type"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyTextType[i].data()));
					domEleText		->	setAttributeNode(myDomAttribute);
				}

				//Alway create attribute "region"
				myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("region"));
				if (myVecDaisy3Smil2BodyTextRegion[i].compare("EmPtY"))
				{
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyTextRegion[i].data()));
					domEleText		->	setAttributeNode(myDomAttribute);
				}
				else
				{
					myDomAttribute	->	setValue(XMLString::transcode("text"));
					domEleText		->	setAttributeNode(myDomAttribute);
				}
				
				//Create attribute for xml:lang
				if (myVecDaisy3Smil2BodyTextXmlLang[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("xml:lang"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyTextXmlLang[i].data()));
					domEleText		->	setAttributeNode(myDomAttribute);
				}
			}
			
			///////////////////////////////////////////////////////////
			//Detect available of image. and create it (5 Attributes)//
			///////////////////////////////////////////////////////////
			if (myVecDaisy3Smil2BodyImgSrc[i].compare("EmPtY"))
			{
				//Creating img element
				domEleImg		=  pDoc->createElement(XMLString::transcode("img"));
				domElePar		-> appendChild(domEleImg);
				//Create attribute for src	!!! Don't check because this function just checked it !!!
				myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("src"));
				myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyImgSrc[i].data()));
				domEleImg		->	setAttributeNode(myDomAttribute);
				
				//Create attribute for id
				if (myVecDaisy3Smil2BodyImgId[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("id"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyImgId[i].data()));
					domEleImg		->	setAttributeNode(myDomAttribute);
				}

				//Create attribute for type
				if (myVecDaisy3Smil2BodyImgType[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("type"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyImgType[i].data()));
					domEleImg		->	setAttributeNode(myDomAttribute);
				}

				//Create attribute for region
				if (myVecDaisy3Smil2BodyTextRegion[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("region"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyTextRegion[i].data()));
					domEleImg		->	setAttributeNode(myDomAttribute);
				}
	
				//Create attribute for xml:lang
				if (myVecDaisy3Smil2BodyTextXmlLang[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("xml:lang"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyTextXmlLang[i].data()));
					domEleImg		->	setAttributeNode(myDomAttribute);
				}
			}

			  ///////////////////////////////////////////////////////////
			 //Detect available of audio. and create it (7 Attributes)//
			///////////////////////////////////////////////////////////
			if (myVecDaisy3Smil2BodyAudioSrc[i].compare("EmPtY"))
			{
				//Creating img element
				domEleAudio		=  pDoc->createElement(XMLString::transcode("audio"));
				domElePar		-> appendChild(domEleAudio);
				//Create attribute for src	!!! Don't check because this function just checked it !!!
				myVecDaisy3Smil2BodyAudioSrc[i] = myVecDaisy3Smil2BodyAudioSrc[i].substr(0,myVecDaisy3Smil2BodyAudioSrc[i].find_last_of("."));
				myVecDaisy3Smil2BodyAudioSrc[i].append(".");
				myVecDaisy3Smil2BodyAudioSrc[i].append(strAudioType);
				myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("src"));
				myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyAudioSrc[i].data()));
				domEleAudio		->	setAttributeNode(myDomAttribute);
				
				//Create attribute for id 
				if (myVecDaisy3Smil2BodyAudioId[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("id"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyAudioId[i].data()));
					domEleAudio		->	setAttributeNode(myDomAttribute);
				}

				//Create attribute for  type
				if (myVecDaisy3Smil2BodyAudioType[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("type"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyAudioType[i].data()));
					domEleAudio		->	setAttributeNode(myDomAttribute);
				}

				//Create attribute for  clipBegin
				if (myVecDaisy3Smil2BodyAudioClipBegin[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("clipBegin"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyAudioClipBegin[i].data()));
					domEleAudio		->	setAttributeNode(myDomAttribute);
				}

				//Create attribute for clipEnd
				if (myVecDaisy3Smil2BodyAudioClipEnd[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("clipEnd"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyAudioClipEnd[i].data()));
					domEleAudio		->	setAttributeNode(myDomAttribute);
				}

				//Create attribute for region
				if (myVecDaisy3Smil2BodyAudioRegion[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("region"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyAudioRegion[i].data()));
					domEleAudio		->	setAttributeNode(myDomAttribute);
				}
	
				//Create attribute for xml:lang
				if (myVecDaisy3Smil2BodyAudioXmlLang[i].compare("EmPtY"))
				{
					myDomAttribute	=	pDoc->createAttribute(XMLString::transcode("xml:lang"));
					myDomAttribute	->	setValue(XMLString::transcode(myVecDaisy3Smil2BodyAudioXmlLang[i].data()));
					domEleAudio		->	setAttributeNode(myDomAttribute);
				}
			}
		}
		
		// construct the LocalFileFormatTarget
		XMLFormatTarget *myFormatTarget = new LocalFileFormatTarget(chrOutputFileName);

		pOutput = ((DOMImplementationLS*)pImplement)->createLSOutput();
        pOutput->setByteStream(myFormatTarget);

		// serialize a DOMNode to the "string strOutputFileName"
		pSerializer->write(pDoc, pOutput);

		// optionally, you can flush the buffer to ensure all contents are written
		myFormatTarget->flush();
		delete myFormatTarget; 
	}
	delete pTarget;
	delete pSerializer;
	delete pDoc;
	delete pDoctype;

	// terminate the XML library
	XMLPlatformUtils::Terminate();
	return true;
}

bool Converter::fnWriteOpf(char* chrEnCoding, const char* chrOutputFileName)
{
	xercesc_3_1::DOMDocumentType   *pDoctype	= NULL;
	xercesc_3_1::DOMDocument	   *pDoc		= NULL;
	xercesc_3_1::DOMNode		   *pNode		= NULL;
	xercesc_3_1::DOMImplementation *pImplement  = NULL;
	xercesc_3_1::DOMLSSerializer		   *pSerializer = NULL;
	xercesc_3_1::XMLFormatTarget   *pTarget	    = NULL;
	xercesc_3_1::DOMLSOutput	   *pOutput		= NULL;

	try
	{
		// initialize the XML library
		XMLPlatformUtils::Initialize("th_TH");
	}
	catch(...)
	{
		cout << "Error to initialize the XML library for writing XML file." << endl;
	}

	// get a serializer, an instance of DOMLSSerializer (the "LS" stands for load-save).
	pImplement  = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("LS"));
	pSerializer = ((DOMImplementationLS*)pImplement)->createLSSerializer();
	pTarget     = new StdOutFormatTarget();

	// set user specified end of line sequence and output encoding
	pSerializer->setNewLine(XMLString::transcode("\n"));
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTSplitCdataSections, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTDiscardDefaultContent, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTBOM, false);
	
	//Creating document.
	pDoctype = pImplement->createDocumentType(XMLString::transcode("package"), XMLString::transcode("-//NISO//DTD dtbook 2005-1//EN"), XMLString::transcode("http://www.daisy.org/z3986/2005/dtbook-2005-1.dtd"));
	pDoc     = pImplement->createDocument(XMLString::transcode("http://openebook.org/namespaces/oeb-package/1.0/") , XMLString::transcode("package"), pDoctype);

	if (pDoc)
	{
		//Creating XML element and its attributes.
		//pDoc			-> setEncoding(XMLString::transcode(chrEnCoding));
		pDoc			-> setXmlStandalone(true);
		pDoc			-> setXmlVersion(XMLString::transcode("1.0"));
		
		//Creating root element and its attributes.
		DOMElement		   *pRoot;	
		DOMAttr			   *domAttOpf;
		pRoot			=  pDoc->getDocumentElement();
		domAttOpf		=  pDoc->createAttribute(XMLString::transcode("unique-identifier"));
		domAttOpf		-> setValue(XMLString::transcode("uid"));
		pRoot			-> setAttributeNode(domAttOpf);

		//Creating DOM Variable for Temporary using.
		//DOMElement	   *myDomElement;
		DOMAttr			   *myDomAttribute;
		DOMText		       *myDomText;

		//Creating metadata element and its attributes.
		DOMElement		   *domEleMetaData;
		domEleMetaData	=  pDoc->createElement(XMLString::transcode("metadata"));
		pRoot			-> appendChild(domEleMetaData);

		//Creating dc-metadata element and its attributes.
		DOMElement		   *domEleDcMetaData;
		domEleDcMetaData=  pDoc->createElement(XMLString::transcode("dc-metadata"));
		domEleMetaData	-> appendChild(domEleDcMetaData);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("xmlns:dc"));
		myDomAttribute	-> setValue(XMLString::transcode("http://purl.org/dc/elements/1.1/"));
		domEleDcMetaData-> setAttributeNode(myDomAttribute);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("xmlns:oebpackage"));
		myDomAttribute	-> setValue(XMLString::transcode("http://openebook.org/namespaces/oeb-package/1.0/"));
		domEleDcMetaData-> setAttributeNode(myDomAttribute);

		//Creating dc:title element and its attributes.
		DOMElement		   *domEleDcTitle;
		domEleDcTitle	=  pDoc->createElement(XMLString::transcode("dc:title"));
		domEleDcMetaData-> appendChild(domEleDcTitle);
		myDomText		=  pDoc->createTextNode(XMLString::transcode(myStrDaisy3NcxDocTitleText.data()));
		domEleDcTitle	-> appendChild(myDomText);

		//Creating dc:title element and its attributes.
		DOMElement		   *domEleDcFormat;
		domEleDcFormat	=  pDoc->createElement(XMLString::transcode("dc:Format"));
		domEleDcMetaData-> appendChild(domEleDcFormat);
		myDomText		=  pDoc->createTextNode(XMLString::transcode("ANSI/NISO Z39.86-2005"));
		domEleDcFormat	-> appendChild(myDomText);

		//Creating dc:Publisher element and its attributes.
		DOMElement		   *domEleDcPublisher;
		domEleDcPublisher=  pDoc->createElement(XMLString::transcode("dc:Publisher"));
		domEleDcMetaData -> appendChild(domEleDcPublisher);
		myDomText		 =  pDoc->createTextNode(XMLString::transcode("Thailand Association of the Blind"));
		domEleDcPublisher-> appendChild(myDomText);

		//Creating dc:Language element and its attributes.
		DOMElement		   *domEleDcLanguage;
		domEleDcLanguage=  pDoc->createElement(XMLString::transcode("dc:Language"));
		domEleDcMetaData-> appendChild(domEleDcPublisher);
		myDomText		=  pDoc->createTextNode(XMLString::transcode("th-TH"));
		domEleDcLanguage-> appendChild(myDomText);

		//Creating manifest element.
		DOMElement		   *domEleManifest;
		domEleManifest	=  pDoc->createElement(XMLString::transcode("manifest"));
		pRoot			-> appendChild(domEleManifest);
	  
		//Creating opf item element and its attributes.
		DOMElement		   *domEleItem;
		domEleItem		=  pDoc->createElement(XMLString::transcode("item"));
		domEleManifest	-> appendChild(domEleItem);

		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
		myDomAttribute	-> setValue(XMLString::transcode("opf"));
		domEleItem	-> setAttributeNode(myDomAttribute);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("href"));
		myDomAttribute	-> setValue(XMLString::transcode("dtb.opf"));
		domEleItem	-> setAttributeNode(myDomAttribute);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("media-type"));
		myDomAttribute	-> setValue(XMLString::transcode("text/xml"));
		domEleItem	-> setAttributeNode(myDomAttribute);

		//Creating xml(text) item element and its attributes.
		domEleItem		=  pDoc->createElement(XMLString::transcode("item"));
		domEleManifest	-> appendChild(domEleItem);

		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
		myDomAttribute	-> setValue(XMLString::transcode("text"));
		domEleItem		-> setAttributeNode(myDomAttribute);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("href"));
		myDomAttribute	-> setValue(XMLString::transcode("dtb.xml"));
		domEleItem		-> setAttributeNode(myDomAttribute);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("media-type"));
		myDomAttribute	-> setValue(XMLString::transcode("text/x-dtbncx+xml"));
		domEleItem		-> setAttributeNode(myDomAttribute);

		//Creating css item element and its attributes.
		domEleItem		=  pDoc->createElement(XMLString::transcode("item"));
		domEleManifest	-> appendChild(domEleItem);

		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
		myDomAttribute	-> setValue(XMLString::transcode("text_style"));
		domEleItem		-> setAttributeNode(myDomAttribute);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("href"));
		myDomAttribute	-> setValue(XMLString::transcode("dtb.css"));
		domEleItem		-> setAttributeNode(myDomAttribute);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("media-type"));
		myDomAttribute	-> setValue(XMLString::transcode("text/css"));
		domEleItem		-> setAttributeNode(myDomAttribute);

		//Creating ncx item element and its attributes.
		domEleItem		=  pDoc->createElement(XMLString::transcode("item"));
		domEleManifest	-> appendChild(domEleItem);

		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
		myDomAttribute	-> setValue(XMLString::transcode("ncx"));
		domEleItem		-> setAttributeNode(myDomAttribute);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("href"));
		myDomAttribute	-> setValue(XMLString::transcode("dtb.ncx"));
		domEleItem		-> setAttributeNode(myDomAttribute);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("media-type"));
		myDomAttribute	-> setValue(XMLString::transcode("application/x-dtbncx+xml"));
		domEleItem		-> setAttributeNode(myDomAttribute);


		//Creating audio item element and its attributes.
		int		intLoopOpfStoreAudio, intOpfStoreAudioSize;
		string	tmpForInsert;
		intOpfStoreAudioSize = myVecOpfStoreAudio.size();
		//Loop for finds Smil file in Ncc file.
		for (intLoopOpfStoreAudio=0; intLoopOpfStoreAudio < intOpfStoreAudioSize; intLoopOpfStoreAudio++)
		{
			domEleItem		=  pDoc->createElement(XMLString::transcode("item"));
			domEleManifest	-> appendChild(domEleItem);

			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
			myDomAttribute	-> setValue(XMLString::transcode("standards"));
			domEleItem		-> setAttributeNode(myDomAttribute);
			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("href"));
			myDomAttribute	-> setValue(XMLString::transcode(myVecOpfStoreAudio[intLoopOpfStoreAudio].data()));
			domEleItem		-> setAttributeNode(myDomAttribute);
			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("media-type"));
			myDomAttribute	-> setValue(XMLString::transcode("audio/vnd.wave;codec=10"));
			domEleItem		-> setAttributeNode(myDomAttribute);
		}

		//Creating smil item element and its attributes.
		int		intLoopNcc, intNccSize;
		tmpForInsert.clear();
		char	a[5];
		intNccSize = myVecDaisy3NcxBodyType.size();
		//Loop for finds Smil file in Ncc file.
		for (intLoopNcc=0; intLoopNcc < intNccSize; intLoopNcc++)
		{
			tmpForInsert = "SMIL_";	
			itoa(intLoopNcc+1, a, 10);
			tmpForInsert.append(a);

			domEleItem		=  pDoc->createElement(XMLString::transcode("item"));
			domEleManifest	-> appendChild(domEleItem);

			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
			myDomAttribute	-> setValue(XMLString::transcode(tmpForInsert.data()));
			domEleItem		-> setAttributeNode(myDomAttribute);
			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("href"));
			myDomAttribute	-> setValue(XMLString::transcode(myVecDaisy3NcxBodyLinkFile[intLoopNcc].data()));
			domEleItem		-> setAttributeNode(myDomAttribute);
			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("media-type"));
			myDomAttribute	-> setValue(XMLString::transcode("application/smil"));
			domEleItem		-> setAttributeNode(myDomAttribute);
		}

		//Creating spine element.
		DOMElement		   *domEleSpine;
		domEleSpine		=  pDoc->createElement(XMLString::transcode("spine"));
		pRoot			-> appendChild(domEleSpine);

		for (intLoopNcc=0; intLoopNcc < intNccSize; intLoopNcc++)
		{
			tmpForInsert = "SMIL_";	
			itoa(intLoopNcc+1, a, 10);
			tmpForInsert.append(a);

			domEleItem		=  pDoc->createElement(XMLString::transcode("itemref"));
			domEleSpine		-> appendChild(domEleItem);

			myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("idref"));
			myDomAttribute	-> setValue(XMLString::transcode(tmpForInsert.data()));
			domEleItem		-> setAttributeNode(myDomAttribute);
		}

		//show output @ screen - no need.
		//fflush(stdout);
		//pSerializer->writeNode(pTarget, *pDoc);

		// construct the LocalFileFormatTarget
		XMLFormatTarget *myFormatTarget = new LocalFileFormatTarget(chrOutputFileName);

		pOutput = ((DOMImplementationLS*)pImplement)->createLSOutput();
        pOutput->setByteStream(myFormatTarget);

		// serialize a DOMNode to the "string strOutputFileName"
		pSerializer->write(pDoc, pOutput);

		// optionally, you can flush the buffer to ensure all contents are written
		myFormatTarget->flush();
		delete myFormatTarget; 
	}
	delete pTarget;
	delete pSerializer;
	delete pDoc;
	delete pDoctype;

	// terminate the XML library
	XMLPlatformUtils::Terminate();
	return true;
}


bool Converter::fnWriteXml(char* chrEnCoding, const char* chrOutputFileName)
{
	xercesc_3_1::DOMDocumentType	*pDoctype	= NULL;
	xercesc_3_1::DOMDocument		*pDoc		= NULL;
	xercesc_3_1::DOMNode			*pNode		= NULL;
	xercesc_3_1::DOMImplementation	*pImplement  = NULL;
	xercesc_3_1::DOMLSSerializer	*pSerializer = NULL;
	xercesc_3_1::XMLFormatTarget	*pTarget     = NULL;
	xercesc_3_1::DOMLSOutput		*pOutput	 = NULL;

	try
	{
		// initialize the XML library
		XMLPlatformUtils::Initialize("th_TH");
	}
	catch(...)
	{
		cout << "Error to initialize the XML library for writing XML file." << endl;
	}

	// get a serializer, an instance of DOMLSSerializer (the "LS" stands for load-save).
	pImplement  = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("LS"));
	pSerializer = ((DOMImplementationLS*)pImplement)->createLSSerializer();
	pTarget     = new StdOutFormatTarget();

	// set user specified end of line sequence and output encoding
	pSerializer->setNewLine(XMLString::transcode("\n"));
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTSplitCdataSections, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTDiscardDefaultContent, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
	pSerializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTBOM, false);
	
	//Creating document.
	pDoctype = pImplement->createDocumentType(XMLString::transcode("package"), XMLString::transcode("-//NISO//DTD dtbook 2005-1//EN"), XMLString::transcode("http://www.daisy.org/z3986/2005/dtbook-2005-1.dtd"));
	pDoc     = pImplement->createDocument(NULL , XMLString::transcode("dtbook3"), pDoctype);
	
	if (pDoc)
	{	
		//Creating XML element and its attributes.		
		pDoc			-> insertBefore(pDoc-> createProcessingInstruction(XMLString::transcode("xml-stylesheet"),XMLString::transcode("href=\"dtb.css\" type=\"text/css\"")),pDoctype);
		//pDoc			-> setEncoding(XMLString::transcode(chrEnCoding));
		pDoc			-> setXmlStandalone(true);
		pDoc			-> setXmlVersion(XMLString::transcode("1.0"));

		//Creating DOM Variable for Temporary using.
		//DOMElement	   *myDomElement;
		DOMAttr			   *myDomAttribute;
		DOMText		       *myDomText;

		//Creating root element.
		DOMElement		   *pRoot;
		pRoot			=  pDoc->getDocumentElement();

		//Creating head element.
		DOMElement		   *domEleHead;
		domEleHead		=  pDoc->createElement(XMLString::transcode("head"));
		pRoot			-> appendChild(domEleHead);

		//Creating title element and its attributes.
		DOMElement		   *domEleTitle;
		domEleTitle		=  pDoc->createElement(XMLString::transcode("title"));
		domEleHead		-> appendChild(domEleTitle);
		myDomText		=  pDoc->createTextNode(XMLString::transcode(myStrHtmlTitle.data()));
		domEleTitle		-> appendChild(myDomText);

		//Creating title element and its attributes.
		DOMElement		   *domEleAuthor;
		domEleAuthor	=  pDoc->createElement(XMLString::transcode("author"));
		domEleHead		-> appendChild(domEleAuthor);
		myDomText		=  pDoc->createTextNode(XMLString::transcode("Thailand Association of the Blind, Thailand."));
		domEleAuthor	-> appendChild(myDomText);

		//Creating head element.
		DOMElement		   *domEleBook;
		domEleBook		=  pDoc->createElement(XMLString::transcode("book"));
		pRoot			-> appendChild(domEleBook);
		myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("lang"));
		myDomAttribute	-> setValue(XMLString::transcode("th"));
		domEleBook		-> setAttributeNode(myDomAttribute);

		//Creating front-matter element and its attributes.
		DOMElement		     *domEleFrontMatter;
		DOMElement		     *domEleDocTitle;
		DOMElement		     *domEleLevel1;
		domEleFrontMatter =  pDoc->createElement(XMLString::transcode("frontmatter"));
		domEleBook		  -> appendChild(domEleFrontMatter);

		//Creating Doc Title element and its attributes.
		domEleDocTitle	  =  pDoc->createElement(XMLString::transcode("doctitle"));
		domEleFrontMatter -> appendChild(domEleDocTitle);
		myDomText		  =  pDoc->createTextNode(XMLString::transcode(myStrHtmlTitle.data()));
		domEleDocTitle	  -> appendChild(myDomText);

		//Creating Level-1 in Front matter element and its attributes.
		domEleLevel1      =  pDoc->createElement(XMLString::transcode("level1"));
		domEleFrontMatter -> appendChild(domEleLevel1);
		myDomAttribute	  =  pDoc->createAttribute(XMLString::transcode("class"));
		myDomAttribute	  -> setValue(XMLString::transcode("intro"));
		domEleLevel1 	  -> setAttributeNode(myDomAttribute);
		myDomText		  =  pDoc->createTextNode(XMLString::transcode("Converted from all legacy DAISY specification to NISO Z39.86-2005 for use in IVR-Project only."));
		domEleLevel1	  -> appendChild(myDomText);

		//Creating body-matter element and its attributes.
		DOMElement		    *domEleBodyMatter;
		DOMElement		    *domEleH1;
		domEleBodyMatter =  pDoc->createElement(XMLString::transcode("bodymatter"));
		domEleBook		 -> appendChild(domEleBodyMatter);

		//Creating Level-1 in body matter element and its attributes.
		domEleLevel1     =  pDoc->createElement(XMLString::transcode("level1"));
		domEleBodyMatter -> appendChild(domEleLevel1);
		myDomAttribute	 =  pDoc->createAttribute(XMLString::transcode("class"));
		myDomAttribute	 -> setValue(XMLString::transcode("part"));
		domEleLevel1 	 -> setAttributeNode(myDomAttribute);
		myDomAttribute	 =  pDoc->createAttribute(XMLString::transcode("id"));
		myDomAttribute	 -> setValue(XMLString::transcode("start"));
		domEleLevel1 	 -> setAttributeNode(myDomAttribute);

		//Creating H1 in Level 1 in body matter element and its attributes.
		domEleH1		=  pDoc->createElement(XMLString::transcode("h1"));
		domEleLevel1	-> appendChild(domEleH1);
		myDomText		=  pDoc->createTextNode(XMLString::transcode(myStrHtmlTitle.data()));
		domEleH1		-> appendChild(myDomText);

		//Creating p item element and its attributes.
		int				intLoopHtml, intHtmlSize;
		DOMElement		*domEleP;
		intHtmlSize		= myVecHtmlParagraphID.size();
		//Loop for writes id and content to xml file.
		for (intLoopHtml=0; intLoopHtml < intHtmlSize; intLoopHtml++)
		{
			if 	(myVecHtmlContent[intLoopHtml].compare("WaItInG"))
			{
				if (!myVecHtmlPageNumberDetect[intLoopHtml])
				{			
					domEleP			=  pDoc->createElement(XMLString::transcode("p"));
					domEleLevel1	-> appendChild(domEleP);
				}
				else
				{
					domEleP			=  pDoc->createElement(XMLString::transcode("pagenum"));
					domEleLevel1	-> appendChild(domEleP);
					myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("page"));
					myDomAttribute	-> setValue(XMLString::transcode("normal"));
					domEleP			-> setAttributeNode(myDomAttribute);
				}	

				myDomAttribute	=  pDoc->createAttribute(XMLString::transcode("id"));
				myDomAttribute	-> setValue(XMLString::transcode(myVecHtmlParagraphID[intLoopHtml].data()));
				domEleP			-> setAttributeNode(myDomAttribute);
				
				myDomText		=  pDoc->createTextNode(XMLString::transcode(myVecHtmlContent[intLoopHtml].data()));
				domEleP			-> appendChild(myDomText);
			}
		}

		//Creating Rear-matter element and its attributes.
		DOMElement		    *domEleRearMatter;
		domEleRearMatter =  pDoc->createElement(XMLString::transcode("rearmatter"));
		domEleBook		 -> appendChild(domEleRearMatter);
		myDomText		 =  pDoc->createTextNode(XMLString::transcode(""));
		domEleRearMatter -> appendChild(myDomText);

		//show output @ screen - no need.
		//fflush(stdout);
		//pSerializer->writeNode(pTarget, *pDoc);

		// construct the LocalFileFormatTarget
		XMLFormatTarget *myFormatTarget = new LocalFileFormatTarget(chrOutputFileName);

		pOutput = ((DOMImplementationLS*)pImplement)->createLSOutput();
        pOutput->setByteStream(myFormatTarget);

		// serialize a DOMNode to the "string strOutputFileName"
		pSerializer->write(pDoc, pOutput);

		// optionally, you can flush the buffer to ensure all contents are written
		myFormatTarget->flush();
		delete myFormatTarget; 
	}

	delete pTarget;
	delete pSerializer;
	delete pDoc;
	delete pDoctype;

	// terminate the XML library
	XMLPlatformUtils::Terminate();
	return true;
}

bool Converter::fnWriteCss (string strFileName)
{
	//Write CSS data to file.
	FILE* stmFileWrite;
	if ((stmFileWrite = fopen( strFileName.c_str(), "w+" )) != NULL )
	{
		fputs("/* DTBbase.CSS Created 10-13-1999 by M. Moodie from M. Hakkinen's template Modified 03-16-2000 by M. Brown*/\n", stmFileWrite);
		fputs("head, frontmatter, title, base, meta, link, style { display: none }\n", stmFileWrite);
		fputs("head object { display: none}\n", stmFileWrite);
		fputs("head script { display: none}\n", stmFileWrite);
		fputs("bodymatter, book, br, dtbook3, noscript, rearmatter, { display: block}\n", stmFileWrite);
		fputs("address, div, level, level1, level2, level3, level4, level5, level6, { display: block; margin-top: 0.5em}\n", stmFileWrite);
		fputs("doctitle { display: block; font-family: Arial, sans-serif; font-weight: bold; font-size: 1.5em; text-align: center; margin-top: 0.7em; margin-bottom: 0.7em}\n", stmFileWrite);
		fputs("h6 { display: block; font-family: Arial, sans-serif; font-size: 1.0em; font-weight: bold; margin-top: 1.0em}\n", stmFileWrite);
		fputs("level level level level level level levelhd { display: block; font-family: Arial, sans-serif; font-size: 1.0em; font-weight: bold; margin-top: 1.0em}\n", stmFileWrite);
		fputs("h5 { display: block; font-family: Arial, sans-serif; font-size: 1.2em; font-weight: bold; margin-top: 1.2em}\n", stmFileWrite);
		fputs("level level level level level levelhd { display: block; font-family: Arial, sans-serif; font-size: 1.2em; font-weight: bold}\n", stmFileWrite);
		fputs("h4 { display: block; font-family: Arial, sans-serif; font-size: 1.3em; font-weight: bold; margin-top: 1.0em}\n", stmFileWrite);
		fputs("level level level level levelhd { display: block; font-family: Arial, sans-serif; font-size: 1.3em; font-weight: bold; margin-top: 1.0em}\n", stmFileWrite);
		fputs("h3 { display: block; font-family: Arial, sans-serif; font-size: 1.4em; font-weight: bold; margin-top: 1.0em}\n", stmFileWrite);
		fputs("level level level levelhd { display: block; font-family: Arial, sans-serif; font-size: 1.4em; font-weight: bold; margin-top: 1.0em}\n", stmFileWrite);
		fputs("h2 { display: block; font-family: Arial, sans-serif; font-size: 1.5em; font-weight: bold; margin-top: 1.2em}\n", stmFileWrite);
		fputs("level level levelhd { display: block; font-family: Arial, sans-serif; font-size: 1.5em; font-weight: bold; margin-top: 1.2em}\n", stmFileWrite);
		fputs("h1 { display: block; font-family: Arial, sans-serif; font-size: 1.7em; font-weight: bold; margin-top: 1.7em}\n", stmFileWrite);
		fputs("level levelhd { display: block; font-family: Arial, sans-serif; font-size: 1.7em; font-weight: bold; margin-top: 1.7em}\n", stmFileWrite);
		fputs("ol, ul, dl { display: block; margin-left: +1.5em; margin-top: 0.3em; margin-bottom: 0.3em}\n", stmFileWrite);
		fputs("li { display: block; margin-top: 0.2em}\n", stmFileWrite);
		fputs("dt { display: block; font-weight: bold; margin-top: 0.4em}\n", stmFileWrite);
		fputs("dd { display: block; margin-left: 2em}\n", stmFileWrite);
		fputs("poem { display: block; margin-top: 1.0em}\n", stmFileWrite);
		fputs("linegroup { display: block; margin-top: 0.5em}\n", stmFileWrite);
		fputs("linenum:after { content: " "}\n", stmFileWrite);
		fputs("linenum { display: inline}\n", stmFileWrite);
		fputs("lin { display: block}\n", stmFileWrite);
		fputs("hd { display: block; font-size: 1.2em; font-weight: bold}\n", stmFileWrite);
		fputs("author:before { content: \"by \"}\n", stmFileWrite);
		fputs("author { display: block; margin-top: 0.5em}\n", stmFileWrite);
		fputs("drama, scene { display: block; margin-top: 1.0em}\n", stmFileWrite);
		fputs("act { display: block}\n", stmFileWrite);
		fputs("stage { display: block; margin-top: 0.5em; font-style: italic}\n", stmFileWrite);
		fputs("speaker { display: block; font-variant: small-caps; font-weight: bold; margin-top: 0.5em}\n", stmFileWrite);
		fputs("speech { display: block; margin-left: 2em}\n", stmFileWrite);
		fputs("a { display: inline; text-decoration: underline}\n", stmFileWrite);
		fputs("abbr { display: inline}\n", stmFileWrite);
		fputs("acronym { display: inline}\n", stmFileWrite);
		fputs("bdo { display: inline}\n", stmFileWrite);
		fputs("citation.inline { display: inline}\n", stmFileWrite);
		fputs("code.inline { display: inline; font-family: Courier; font-size: 0.9em}\n", stmFileWrite);
		fputs("dfn { display: inline}\n", stmFileWrite);
		fputs("em { display: inline; font-style: italic}\n", stmFileWrite);
		fputs("img.inline { display: inline}\n", stmFileWrite);
		fputs("kbd.inline { display: inline; font-family: Courier; font-size: 0.9em}\n", stmFileWrite);
		fputs("noteref { display: inline; font-size: 0.7em; vertical-align: super}\n", stmFileWrite);
		fputs("object { display: inline}\n", stmFileWrite);
		fputs("pagenum.inline { display: inline; font-family: Arial, sans-serif; color: white; background-color: blue}\n", stmFileWrite);
		fputs("prodnote.inline { display: inline}\n", stmFileWrite);
		fputs("q { display: inline}\n", stmFileWrite);
		fputs("samp.inline { display: inline}\n", stmFileWrite);
		fputs("script.inline { display: none}\n", stmFileWrite);
		fputs("sent { display: inline}\n", stmFileWrite);
		fputs("span { display: inline}\n", stmFileWrite);
		fputs("strong { font-weight: bold; display: inline}\n", stmFileWrite);
		fputs("sub { display: inline; font-size: 0.7em; vertical-align: sub}\n", stmFileWrite);
		fputs("sup { display: inline; font-size: 0.7em; vertical-align: super}\n", stmFileWrite);
		fputs("var.inline { display: inline; font-style: italic}\n", stmFileWrite);
		fputs("w { display: inline}\n", stmFileWrite);
		fputs("a.block { display: block; text-decoration: underline; margin-top: 0.5em}\n", stmFileWrite);
		fputs("blockquote { display: block; margin-top: 0.5em; margin-left: 1em; margin-right: 4em}\n", stmFileWrite);
		fputs("citation { display: block; margin-top: 0.5em}\n", stmFileWrite);
		fputs("code { display: block; font-family: Courier; font-size: 0.9em; margin-top: 0.5em}\n", stmFileWrite);
		fputs("hr { display: block; text-decoration: underline; margin-top: 0.5em; margin-bottom: 0.5em; padding-top: 0.5em; padding-bottom: 0.5em; border: 1pt solid; border-color: black; background-position: 200pt 6pt; background-color: #000000; border-bottom: thick solid}\n", stmFileWrite);
		fputs("img { display: block}\n", stmFileWrite);
		fputs("kbd { display: block; font-family: Courier; font-size: 0.9em; margin-top: 0.5em}\n", stmFileWrite);
		fputs("note { display: block; margin-top: 1.2em; margin-left: 1em; margin-right: 1em; margin-bottom: 1.2em; padding-top: 0.5em; padding-bottom: 0.5em; padding-left: 1em; padding-right: 1em; border-top: 1pt solid; border-bottom: 1pt solid; border-top-color: black; border-bottom-color: black; border-left-color: transparent; border-right-color: transparent}\n", stmFileWrite);
		fputs("notice { display: block; padding-top: 0.5em; padding-right: 0.5em; padding-left: 0.5em; padding-bottom: 0.5em; margin-top: 0.5em; margin-right: 4.5em; margin-left: 4.5em; margin-bottom: 0.5em; border-top: thin solid; border-right: thin solid; border-bottom: thin solid; border-left: thin solid; background-color: #FFCACA; border-color: #FF0000}\n", stmFileWrite);
		fputs("p.center { display: block; text-align: center; margin-top: 0.7em}\n", stmFileWrite);
		fputs("p { display: block; margin-top: 0.7em}\n", stmFileWrite);
		fputs("linenum:after { content: " "}\n", stmFileWrite);
		fputs("pagenum { display: block; page-break-before: always; font-family: Arial, sans-serif; text-align: center; color: white; border: 2px solid blue; background-color: blue; margin-top: 0.5em; margin-bottom: 0.5em}\n", stmFileWrite);
		fputs("prodnote { display: block; padding-top: 0.2em; padding-right: 0.2em; padding-left: 0.2em; padding-bottom: 0.2em; margin-top: 0.3em; margin-right: 0.3em; margin-left: 0.3em; margin-bottom: 0.3em; border-top: 1pt solid; border-right: 1pt solid; border-bottom: 1pt solid; border-left: 1pt solid; border-color: #000000}\n", stmFileWrite);
		fputs("samp { display: block}\n", stmFileWrite);
		fputs("script { display: none}\n", stmFileWrite);
		fputs("sidebar { float: left; padding-top: 0.5em; padding-right: 0.5em; padding-left: 0.5em; padding-bottom: 0.5em; width: 18pc; clear: left; margin-top: 0.5em; margin-right: 0.5em; margin-left: 0.5em; margin-bottom: 0.5em; border-top: thin solid; border-right: thin solid; border-bottom: thin solid; border-left: thin solid; background-color: #BEEDFC; border-color: #0000FF}\n", stmFileWrite);
		fputs("var { display: block; font-style: italic}\n", stmFileWrite);
		fputs("TABLE { display: table }\n", stmFileWrite);
		fputs("TR { display: table-row }\n", stmFileWrite);
		fputs("THEAD { display: table-header-group }\n", stmFileWrite);
		fputs("TBODY { display: table-row-group }\n", stmFileWrite);
		fputs("TFOOT { display: table-footer-group }\n", stmFileWrite);
		fputs("COL { display: table-column }\n", stmFileWrite);
		fputs("COLGROUP { display: table-column-group }\n", stmFileWrite);
		fputs("TD, TH { display: table-cell }\n", stmFileWrite);
		fputs("CAPTION { display: table-caption }", stmFileWrite);
	}
	else
	{
		return false;
	}
	fclose(stmFileWrite);
	return true;
}

bool Converter::fnCopyBinaryFile(const char* chrSourceFile, const char* chrDestinationFile)
{
    char buf[BUFSIZ];
    FILE *inf, *outf;

    if ((inf = fopen(chrSourceFile,"rb")) == NULL)
        return false;

    if ((outf = fopen(chrDestinationFile,"wb")) == NULL)
        return false;

    while (!feof(inf))
    {
        int nitems = fread(buf,1,BUFSIZ,inf);
        if (fwrite(buf,1,nitems,outf) != nitems)
            return false;
    }

    fclose(inf);
    fclose(outf);
    return true;
}


bool Converter::fnConvertWave2Wave8K(string strInputFileName, string strOutputFileName)
{
	SNDFILE		*infile, *outfile;
	SF_INFO		sfinfo;
	sf_count_t	count;
	double		src_ratio		= -1.0;
	double		gain			=  1.0;
	int			new_sample_rate =  8000;
	int			converter		=  SRC_SINC_FASTEST;
	int			max_speed		=  SF_TRUE;

	if (! (infile = sf_open (strInputFileName.c_str(), SFM_READ, &sfinfo)))
	{	
		cout << "Error : Not able to open input file " << strInputFileName << endl;
		return false;
	}

	src_ratio = (1.0 * new_sample_rate) / sfinfo.samplerate ;
	sfinfo.samplerate = new_sample_rate ;

	if ((outfile = sf_open (strOutputFileName.c_str(), SFM_WRITE, &sfinfo)) == NULL)
	{	
		cout << "Error : Not able to open output file " << strOutputFileName << endl;
		sf_close (infile) ;
		return false;
	}

	if (max_speed)
	{	
		/* This is mainly for the comparison program tests/src-evaluate.c */
		sf_command (outfile, SFC_SET_ADD_PEAK_CHUNK, NULL, SF_FALSE) ;
	}
	else
	{	
		/* Update the file header after every write. */
		sf_command (outfile, SFC_SET_UPDATE_HEADER_AUTO, NULL, SF_TRUE) ;
	} ;

	sf_command (outfile, SFC_SET_CLIPPING, NULL, SF_TRUE) ;

	do
		count = sample_rate_convert (infile, outfile, converter, src_ratio, sfinfo.channels, &gain) ;
	while (count < 0) ;

	sf_close (infile) ;
	sf_close (outfile) ;
	return true ;	
}

//static 
sf_count_t Converter::sample_rate_convert (SNDFILE *infile, SNDFILE *outfile, int converter, double src_ratio, int channels, double * gain)
{	static float input [BUFFER_LEN] ;
	static float output [BUFFER_LEN] ;

	SRC_STATE	*src_state ;
	SRC_DATA	src_data ;
	int			error ;
	double		max = 0.0 ;
	sf_count_t	output_count = 0 ;

	sf_seek (infile, 0, SEEK_SET) ;
	sf_seek (outfile, 0, SEEK_SET) ;

	/* Initialize the sample rate converter. */
	if ((src_state = src_new (converter, channels, &error)) == NULL)
	{	printf ("\n\nError : src_new() failed : %s.\n\n", src_strerror (error)) ;
		exit (1) ;
		} ;

	src_data.end_of_input = 0 ; /* Set this later. */

	/* Start with zero to force load in while loop. */
	src_data.input_frames = 0 ;
	src_data.data_in = input ;

	src_data.src_ratio = src_ratio ;

	src_data.data_out = output ;
	src_data.output_frames = BUFFER_LEN /channels ;

	while (1)
	{
		/* If the input buffer is empty, refill it. */
		if (src_data.input_frames == 0)
		{	src_data.input_frames = sf_readf_float (infile, input, BUFFER_LEN / channels) ;
			src_data.data_in = input ;

			/* The last read will not be a full buffer, so snd_of_input. */
			if (src_data.input_frames < BUFFER_LEN / channels)src_data.end_of_input = SF_TRUE ;
			} ;

		if ((error = src_process (src_state, &src_data)))
		{	printf ("\nError : %s\n", src_strerror (error)) ;
			exit (1) ;
			} ;

		/* Terminate if done. */
		if (src_data.end_of_input && src_data.output_frames_gen == 0)
			break ;

		max = apply_gain (src_data.data_out, src_data.output_frames_gen, channels, max, *gain) ;

		/* Write output. */
		sf_writef_float (outfile, output, src_data.output_frames_gen) ;
		output_count += src_data.output_frames_gen ;

		src_data.data_in += src_data.input_frames_used * channels ;
		src_data.input_frames -= src_data.input_frames_used ;
		} ;

	src_state = src_delete (src_state) ;

	if (max > 1.0)
	{	*gain = 1.0 / max ;
		printf ("\nOutput has clipped. Restarting conversion to prevent clipping.\n\n") ;
		output_count = 0 ;
		sf_command (outfile, SFC_FILE_TRUNCATE, &output_count, sizeof (output_count)) ;
		return -1 ;
		} ;

	return output_count ;
} /* sample_rate_convert */

//static 
double Converter::apply_gain (float * data, long frames, int channels, double max, double gain)
{
	long k ;

	for (k = 0 ; k < frames * channels ; k++)
	{	data [k] *= gain ;

		if (fabs (data [k]) > max)
			max = fabs (data [k]) ;
		} ;

	return max ;
} /* apply_gain */

bool Converter::fnConvertWave2Vox(string strInputFileName, string strOutputFileName)
{
	SNDFILE	 	*infile = NULL, *outfile = NULL ;
	SF_INFO	 	sfinfo ;
	static int	data [1024] ;  // 1024 means buffer size.
	int			frames, readcount ;

	//Open the input file.
	if ((infile = sf_open (strInputFileName.c_str(), SFM_READ, &sfinfo)) == NULL)
	{	
		cout << "Not able to open input file - " << strInputFileName << endl;
		return false;
	} 
	
	//Setting the output format
	sfinfo.format = SF_FORMAT_RAW |SF_FORMAT_VOX_ADPCM;

	//Open the output file. 
	if ((outfile = sf_open (strOutputFileName.c_str(), SFM_WRITE, &sfinfo)) == NULL)
	{	
		cout << "Not able to open output file : " << strOutputFileName << endl;
		return false;
	} 
	
	frames = 1024 / sfinfo.channels ; //1024 = buffer size
	readcount = frames ;
	sfinfo.frames = frames;

	while (readcount > 0)
	{	
		readcount = sf_readf_int (infile, data, frames) ;
		sf_writef_int (outfile, data, readcount) ;
	} 
	sf_close (infile) ;
	sf_close (outfile) ;

/*  <<<<<<< ตรง comment นี้ย้ายไปสร้างเป็น function แล้ว >>>>>>>
	//update length(duration) of vox file.
	static	char	strbuffer [BUFFER_LEN] ;
	SNDFILE	 		*infile2 ;
	SF_INFO	 		sfinfo2 ;

	sfinfo2.format = 0 ;
	infile2 = sf_open (strOutputFileName.c_str(), SFM_READ, &sfinfo2) ;
	//show information (disable for DLL version)
	//sf_command (infile2, SFC_GET_LOG_INFO, strbuffer, BUFFER_LEN) ;
	//puts (strbuffer) ;
	if (!infile2)
	{
		strLastDurationFile = "npt=0.000s";
	}
	else
	{
		if (sfinfo2.frames > 0x7FFFFFFF)
		{
			strLastDurationFile = "npt=0.000s";
		}
		else
		{
			strLastDurationFile = generate_duration_str (&sfinfo2);
		}
	}
	sf_close (infile2) ;
*/
	return true ;
}

string Converter::fnGetDuration(string strInputFileName)
{
	static	char	strbuffer [BUFFER_LEN] ;
	SNDFILE	 		*infile2 ;
	SF_INFO	 		sfinfo2 ;
	string			strDurationResult;

	sfinfo2.format = 0 ;
	infile2 = sf_open (strInputFileName.c_str(), SFM_READ, &sfinfo2) ;
	//show information (disable for DLL version)
	//sf_command (infile2, SFC_GET_LOG_INFO, strbuffer, BUFFER_LEN) ;
	//puts (strbuffer) ;
	if (!infile2)
	{
		strDurationResult = "npt=0.000s";
	}
	else
	{
		if (sfinfo2.frames > 0x7FFFFFFF)
		{
			strDurationResult = "npt=0.000s";
			
		}
		else
		{
			strDurationResult = generate_duration_str (&sfinfo2);
		}
	}
	sf_close (infile2) ;
	return strDurationResult;
}

//static 
const char* Converter::generate_duration_str (SF_INFO *sfinfo)
{	
	static char chrReturn[128];
	static char str [128] ;
	int seconds ;

	memset (str, 0, sizeof (str)) ;
	if (sfinfo->samplerate < 1)
		return NULL ;
	if (sfinfo->frames / sfinfo->samplerate > 0x7FFFFFFF)
		return "unknown" ;
	seconds = sfinfo->frames / sfinfo->samplerate ;
	//_snprintf (str, sizeof (str) - 1, "%02d:", seconds / 60 / 60) ;
	//seconds = seconds % (60 * 60) ;
	//_snprintf (str + strlen (str), sizeof (str) - strlen (str) - 1, "%02d:", seconds / 60) ;
	//seconds = seconds % 60 ;
	_snprintf (str + strlen (str), sizeof (str) - strlen (str) - 1, "%d.", seconds) ;
	seconds = ((1000 * sfinfo->frames) / sfinfo->samplerate) % 1000 ;
	_snprintf (str + strlen (str), sizeof (str) - strlen (str) - 1, "%03d", seconds) ;
	
	strcpy( chrReturn, "npt=" );
	strcat( chrReturn, str );
	strcat( chrReturn, "s" );

	return chrReturn ;
}

bool Converter::fnConvertText2Wave(const char* chrData, const char* chrFileName, int intOrderText2Speech, int intTryingNumber)
{
	CA2W szData(chrData);
	LPWSTR Data = szData.m_psz;

	cout << "chrData to convert to audio :: " << Data << endl;

	HRESULT hr	= E_FAIL;
    if (SUCCEEDED(hr = ::CoInitializeEx(NULL,COINIT_MULTITHREADED)))
    {
        CComPtr<ISpVoice>				cpVoice;
		CComPtr<ISpStream>				cpStream;
		CComPtr<IEnumSpObjectTokens>	cpEnum;
		CComPtr<ISpObjectToken>			cpVoiceToken;
		CSpStreamFormat					cAudioFmt;
		cpVoiceToken.Release();

		if(SUCCEEDED(hr))				//Create a SAPI Voice.
			hr = cpVoice.CoCreateInstance( CLSID_SpVoice );
		if(SUCCEEDED(hr))				//Create a Enum Tokens.
			hr = SpEnumTokens(SPCAT_VOICES, NULL, NULL, &cpEnum);
		if(SUCCEEDED(hr))				//Set #3 in order to select PPA Tatip.
			hr = cpEnum->Item(intOrderText2Speech, &cpVoiceToken);
		if(SUCCEEDED(hr))				//Make a selection.
			hr = cpVoice->SetVoice(cpVoiceToken);
		if(SUCCEEDED(hr))				//Set the audio format.
			hr = cAudioFmt.AssignFormat(SPSF_8kHz8BitMono);
		if(SUCCEEDED(hr))				//Call SPBindToFile, a SAPI helper method, to bind the audio stream to the file.
			hr = SPBindToFile(CA2W(chrFileName), SPFM_CREATE_ALWAYS,&cpStream, &cAudioFmt.FormatId(),cAudioFmt.WaveFormatExPtr());
		if(SUCCEEDED(hr))				//set the output to cpStream so that the output audio data will be stored in cpStream.
			hr = cpVoice->SetOutput(cpStream, TRUE );
		if(SUCCEEDED(hr))				//Speak the text in cStrInput to file.
			hr = cpVoice->Speak(CA2W(chrData), SPF_DEFAULT, NULL);
			//hr = cpVoice->Speak(CT2W(chrData), SPF_DEFAULT, NULL);
		if(SUCCEEDED(hr))				//close the stream.
			hr = cpStream->Close();

		cpEnum.Release();				//Release the Enum object
		cpVoiceToken.Release();			//Release the VoiceToken object
		cpStream.Release();				//Release the stream object
		cpVoice.Release();				//Release the voice object
	}
		
	//Check the length of the output if it is "npt=0.000s" so try to convert again
	if ((strlen(chrData) > 5) && (intTryingNumber < 20))
	{
		if (strcmp(fnGetDuration(chrFileName).c_str(), "npt=0.000s") == 0)
		{
			cout << "Convert Text to WAV again because output has no data" << endl;
			fnConvertText2Wave(chrData, chrFileName, intOrderText2Speech, intTryingNumber+1);
		}
	}


    return true;
}

bool Converter::fnTidyClean (string strSourceFileName, string strOutputFileName)
{
	TidyBuffer errbuf = {0};
	int rc = 1;
 
	TidyDoc tdoc = tidyCreate();
	if (rc>=0)
		rc = tidyOptSetBool		(tdoc, TidyXhtmlOut		, no);
	if (rc>=0)
		rc = tidySetErrorBuffer	(tdoc, &errbuf );    
	if (rc>=0)
 		rc = tidyOptSetBool		(tdoc, TidyXmlTags		, yes);	
	if (rc>=0)
		rc = tidyOptSetBool		(tdoc, TidyXmlOut		, yes);
	if (rc>=0)
		rc = tidyOptSetValue	(tdoc, TidyCharEncoding	, "raw");
	if (rc>=0)
		rc = tidyOptSetBool		(tdoc, TidyShowWarnings	, no);
	if (rc>=0)
		rc = tidyOptSetBool		(tdoc, TidyNumEntities	, yes);
	if (rc>=0)
		rc = tidyOptSetInt		(tdoc, TidyWrapLen		, 0);
	if (rc>=0)
		rc = tidyOptSetInt		(tdoc, TidyIndentSpaces	, 2);
	if (rc>=0)
		rc = tidyOptSetInt		(tdoc, TidyXmlDecl		, yes);
	if (rc>=0)                                   
		rc = tidyOptSetBool		(tdoc, TidyForceOutput	, yes);
	if (rc>=0)
		rc = tidyParseFile(tdoc, strSourceFileName.c_str());
	if (rc>=0)
		rc = tidyCleanAndRepair(tdoc);
	if (rc>=0)
		rc = tidySaveFile (tdoc, strOutputFileName.c_str());    
	//if (rc>=0)
	//{
	//	if ( rc > 0 )
	//	{
	//		printf("\nDiagnostics:\n\n%s", errbuf.bp);
	//	}
	//}
	//else
	//{
	//	printf("A severe error (%d) occurred.\n", rc);
	//}

	tidyRelease(tdoc);
	tidyBufFree(&errbuf);
	return true;
}

bool Converter::fnCleanSmilVariable(void)
{
	myStrDaisy3Smil2HeadXmlNs.clear();
	myVecDaisy3Smil2HeadMetaName.clear();
	myVecDaisy3Smil2HeadMetaContent.clear();
	myVecDaisy3Smil2HeadRegionId.clear();
	myVecDaisy3Smil2HeadRegionTop.clear();
	myVecDaisy3Smil2HeadRegionLeft.clear();
	myVecDaisy3Smil2HeadRegionRight.clear();
	myVecDaisy3Smil2HeadRegionBottom.clear();
	myVecDaisy3Smil2HeadRegionHeight.clear();
	myVecDaisy3Smil2HeadRegionWidth.clear();
	myVecDaisy3Smil2HeadRegionFit.clear();
	myVecDaisy3Smil2HeadRegionBackgroundColor.clear();
	myVecDaisy3Smil2HeadRegionShowBackground.clear();
	myVecDaisy3Smil2HeadRegionZIndex.clear();
	myVecDaisy3Smil2HeadRegionXmlLang.clear();
	myVecDaisy3Smil2HeadCustomTestId.clear();
	myVecDaisy3Smil2HeadCustomTestDefaultState.clear();
	myVecDaisy3Smil2HeadCustomTestOverride.clear();
	myVecDaisy3Smil2HeadCustomTestClass.clear();
	myVecDaisy3Smil2HeadCustomTestTitle.clear();
	myVecDaisy3Smil2HeadCustomTestXmlLang.clear();
	myVecDaisy3Smil2BodySeqId.clear();
	myVecDaisy3Smil2BodySeqClass.clear();	
	myVecDaisy3Smil2BodySeqCustomTest.clear();
	myVecDaisy3Smil2BodySeqDur.clear();
	myVecDaisy3Smil2BodySeqXmlLang.clear();
	myVecDaisy3Smil2BodySeqEnd.clear();
	myVecDaisy3Smil2BodySeqFill.clear();
	myVecDaisy3Smil2BodyParId.clear();
	myVecDaisy3Smil2BodyParClass.clear();
	myVecDaisy3Smil2BodyParCustomTest.clear();
	myVecDaisy3Smil2BodyParXmlLang.clear();
	myVecDaisy3Smil2BodyAnchorId.clear();
	myVecDaisy3Smil2BodyAnchorClass.clear();
	myVecDaisy3Smil2BodyAnchorTitle.clear();
	myVecDaisy3Smil2BodyAnchorXmlLang.clear();
	myVecDaisy3Smil2BodyAnchorHref.clear();
	myVecDaisy3Smil2BodyAnchorExternal.clear();
	myVecDaisy3Smil2BodyImgId.clear();
	myVecDaisy3Smil2BodyImgRegion.clear();
	myVecDaisy3Smil2BodyImgSrc.clear();
	myVecDaisy3Smil2BodyImgType.clear();
	myVecDaisy3Smil2BodyImgXmlLang.clear();
	myVecDaisy3Smil2BodyTextId.clear();
	myVecDaisy3Smil2BodyTextSrcFile.clear();
	myVecDaisy3Smil2BodyTextSrcId.clear();
	myVecDaisy3Smil2BodyTextContent.clear();
	myVecDaisy3Smil2BodyTextType.clear();
	myVecDaisy3Smil2BodyTextRegion.clear();
	myVecDaisy3Smil2BodyTextXmlLang.clear();
	myVecDaisy3Smil2BodyAudioId.clear();
	myVecDaisy3Smil2BodyAudioSrc.clear();
	myVecDaisy3Smil2BodyAudioType.clear();
	myVecDaisy3Smil2BodyAudioClipBegin.clear();
	myVecDaisy3Smil2BodyAudioClipEnd.clear();
	myVecDaisy3Smil2BodyAudioRegion.clear();
	myVecDaisy3Smil2BodyAudioXmlLang.clear();
	myVecDaisy2Smil1HeadMetaScheme.clear();

	return true;
}

bool Converter::fnCompareString(char* chrFirstString, char* chrSecondString, bool boolCaseInsensitive)
{	
	const char* pdest;
	if (boolCaseInsensitive)
		pdest = stristr(chrFirstString, chrSecondString);
	else
		pdest = strstr(chrFirstString, chrSecondString);

	if( pdest != NULL )
		return true;
	else
		return false;
}

