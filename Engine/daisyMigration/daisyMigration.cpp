//Project include
#include "stdafx.h"
#include "daisyMigration.h"
#include "dhList.h"
#include "dhListString.h"
#include "dhListText.h"
//Xercesc include
#include <xercesc\sax2\SAX2XMLReader.hpp>
#include <xercesc\sax2\XMLReaderFactory.hpp>

using namespace std;

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
			::MessageBox(NULL,"Initializing the DLL.","C++ DLL",0);
			break;
	case DLL_THREAD_ATTACH:
			::MessageBox(NULL,"Initializing thread of the DLL.","C++ DLL",0);
			break;
	case DLL_THREAD_DETACH:
			::MessageBox(NULL,"Closing down therad of the DLL.","C++ DLL",0);
			break;
	case DLL_PROCESS_DETACH:
			::MessageBox(NULL,"Closing down the DLL.","C++ DLL",0);
			break;
	}
    return TRUE;
}

//Constructor
CdaisyMigration::CdaisyMigration()
{ 
	::MessageBox(NULL,"Constructing Class","C++ DLL",0);
	MydhText   = new dhListText();
	MydhString = new dhListString();
	return; 
}

//Deconstructor
CdaisyMigration::~CdaisyMigration()
{ 
	::MessageBox(NULL,"Deconstructing Class","C++ DLL",0);
	MydhText   = new dhListText();
	MydhString = new dhListString();
	return; 
}

//Add Ncc path to system and start migration to Daisy3.
BSTR CdaisyMigration::AddNcc(BSTR strNccPath, BSTR strDestinationPath,BSTR strAudioOutputFormat)
{
	LPSTR buffer;
	buffer = (LPSTR)strNccPath;
	::MessageBox(NULL,buffer,"in C++",0);
	buffer = _strrev(buffer);
	return(SysAllocString(strNccPath));
}



//Function for Testing
DAISYMIGRATION_API int ndaisyMigration=0;

DAISYMIGRATION_API int fndaisyMigration(void)
{
	return 42;
}

int CdaisyMigration::Multiply(int ParOne, int ParTwo)
{
	return ParOne*ParTwo;
}



