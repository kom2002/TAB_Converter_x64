#ifndef DHLISTSTRING_H
#define DHLISTSTRING_H

#include "dhList.h"

class dhListString : public DefaultHandler 
{
public:	
		   dhListString();
		   ~dhListString();
	void   putIdForGetString(string _IdForGetString); 
	string getTempResult(void);

private:
	/*! -----------------------------------------------------------------------
     *  Handlers for the SAX ContentHandler interface
     *  -----------------------------------------------------------------------
	 */
	void characters  (const XMLCh*      const chars,
					  const unsigned    int   length);
	void startElement(const XMLCh*      const uri,
	                  const XMLCh*      const localname,
	                  const XMLCh*      const qname,
	                  const Attributes&       attrs);
	void fatalError  (const SAXParseException&);

    /*! -----------------------------------------------------------------------
     * Private data members
     *
     * fWaitTagA
     *     This is variable of enable mode for get string from Tag A. 
	 * fWaitTagP
     *     This is variable of enable mode for get string from Tag P.
     * fFoundString
     *     This is variable show when ready for get string.
	 * fIdForGetString
	 *     This is string for compare. It get value from putIdForGetString function.
	 * tempResult
	 *     This is result for return to calling function.
     *  -----------------------------------------------------------------------
	 */
	bool    fWaitTagA;
	bool    fWaitTagP;
	bool    fFoundString;
	string 	fIdForGetString;
	string  tempResult;
};
#endif