/*! 
 *  Case Insensitive strstr function as C++ templates
 *		This function will make a case insensitive search for a string into another string.
 *      Concept are makes internal copies, converts to lower case and uses strstr.
 *
 *  Write by : Petko Popov from www.codeguru.com
 *  Apply by : Tanakom Talawat
 *  Last Access : 22 March 2004 (in Delhi face to face meeting).
 */

#include <string.h>
#include <malloc.h>
#include <tchar.h>
#include <stdio.h>

template <typename CHAR_TYPE>
CHAR_TYPE *stristr
(
   CHAR_TYPE         *  szStringToBeSearched, 
   const CHAR_TYPE   *  szSubstringToSearchFor
)
{
   CHAR_TYPE * pPos = NULL;
   CHAR_TYPE * szCopy1 = NULL;
   CHAR_TYPE * szCopy2 = NULL;

   // verify parameters
   if ( szStringToBeSearched == NULL || 
        szSubstringToSearchFor == NULL ) 
   {
      return szStringToBeSearched;
   }

   // empty substring - return input (consistent with strstr)
   if ( _tcslen(szSubstringToSearchFor) == 0 ) {
      return szStringToBeSearched;
   }

   szCopy1 = _tcslwr(_tcsdup(szStringToBeSearched));
   szCopy2 = _tcslwr(_tcsdup(szSubstringToSearchFor));

   if ( szCopy1 == NULL || szCopy2 == NULL  ) {
      // another option is to raise an exception here
      free((void*)szCopy1);
      free((void*)szCopy2);
      return NULL;
   }

   pPos = strstr(szCopy1, szCopy2);

   if ( pPos != NULL ) {
      // map to the original string
      pPos = szStringToBeSearched + (pPos - szCopy1);
   }

   free((void*)szCopy1);
   free((void*)szCopy2);

   return pPos;
}