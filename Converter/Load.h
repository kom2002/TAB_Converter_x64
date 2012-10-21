#ifndef LOAD_H
#define LOAD_H

#include "AllHandle.h"

#include "LoadNccHandle.h"
#include "LoadSmilHandle.h"
#include "LoadHtmlHandle.h"

	//vector for Ncc
	 vector<string>	myVecNccType;
	 vector<string>	myVecNccClass;
	 vector<string>	myVecNccId;
	 vector<string>	myVecNccLinkFile;
	 vector<string>	myVecNccLinkId;
	 vector<string>	myVecNccName;
	
	//vector for Smil
	 vector<string>	myVecSmilType;
	 vector<string>	myVecSmilId;
	 vector<string>	myVecSmilLinkFile;
	 vector<string>	myVecSmilBegin;
	 vector<string>	myVecSmilEnd;

	//Handle for parser
	 LoadNccHandle   *MyLoadNccHandle;
	 LoadSmilHandle  *MyLoadSmilHandle;
	 LoadHtmlHandle  *MyLoadHtmlHandle;


#endif
