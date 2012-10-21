#include "Converter.h"
// local function


//Check Duplicate Smil file in Ncc vector.
extern bool fnCheckDupSmil(void)
{
	unsigned int intCheckDupSmil1;
	unsigned int intCheckDupSmil2;
	int intNumberOfDupSmil = 0;
	for (intCheckDupSmil1=0; intCheckDupSmil1 < myVecNccType.size(); intCheckDupSmil1++)
	{
		//select only heading
		if (!myVecNccType[intCheckDupSmil1].compare(0,1,"H") || !myVecNccType[intCheckDupSmil1].compare(0,1,"h"))
		{
			for (intCheckDupSmil2=0; intCheckDupSmil2 < myVecNccType.size(); intCheckDupSmil2++)
			{
				//select only heading
				if (!myVecNccType[intCheckDupSmil2].compare(0,1,"H") || !myVecNccType[intCheckDupSmil2].compare(0,1,"h"))
				{
					if (myVecNccLinkFile[intCheckDupSmil1] == myVecNccLinkFile[intCheckDupSmil2])
					{
						intNumberOfDupSmil++;
					}
				}
			}
						
			if (intNumberOfDupSmil != 1)
			{
				//Error
				cout << "Ncc Error : Duplicate Smil" << endl;
				return false;
			}
			intNumberOfDupSmil = 0;
		}
	}
	return true;
}
