/*
#include "AllHandle.h"

string leftTrim( const string &str, const string &whitespace = "\t ")
{

   int idx = str.find_first_not_of(whitespace);
   if( idx != string::npos )
   {      
	  return str.substr(idx);
   }
   return "";
}

string rightTrim( const string &str, const string &whitespace = "\t ")
{

   int idx = str.find_last_not_of(whitespace);
   if( idx != string::npos )
       return str.substr(0,idx+1);

   return str;
}

string allTrim( const string &str, const string &whitespace = "\t ")
{
    return rightTrim(leftTrim(str));
}

*/