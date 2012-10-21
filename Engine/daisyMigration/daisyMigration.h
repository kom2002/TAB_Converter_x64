#ifdef DAISYMIGRATION_EXPORTS
#define DAISYMIGRATION_API __declspec(dllexport)
#else
#define DAISYMIGRATION_API __declspec(dllimport)
#endif

#include "dhList.h"
#include "dhListText.h"
#include "dhListString.h"
using namespace std;

class DAISYMIGRATION_API CdaisyMigration {
public:
			CdaisyMigration				(void);
			~CdaisyMigration			(void);
	BSTR	CdaisyMigration::AddNcc		(BSTR strNccPath, BSTR strDestinationPath,BSTR strAudioOutputFormat);
	int		CdaisyMigration::Multiply	(int ParOne, int ParTwo);

private:
			dhListText   *MydhText;
			dhListString *MydhString;
};

extern DAISYMIGRATION_API int ndaisyMigration;

DAISYMIGRATION_API int fndaisyMigration(void);
