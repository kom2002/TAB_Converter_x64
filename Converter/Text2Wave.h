#ifndef TEXT2WAVE_H
#define TEXT2WAVE_H

#include "./Include/SAPI5/sphelper.h"

class Text2Wave
{
	public:
		Text2Wave();
		~Text2Wave();
		bool ConvertText2Wave(const char* chrData, const char*   chrFileName);
};



#endif