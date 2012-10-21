#ifndef DHLISTTEXT_H
#define DHLISTTEXT_H
//project include
#include "dhList.h"

/*! -----------------------------------------------------------------------
 *  dhListText Class : Use for get list of html#/xml# from smil file.
 *  -----------------------------------------------------------------------
 */
class dhListText : public  DefaultHandler 
{
public:	
					dhListText();
					~dhListText();
	void			clearTempVector(void);
	vector<string>	getVecTextFileList(void);
	vector<string>	getVecTextIDList(void);

private:
	/*! -----------------------------------------------------------------------
     *  Handlers for the SAX ContentHandler interface
     *  -----------------------------------------------------------------------
	 */
	void startElement(const XMLCh*      const uri,
	                  const XMLCh*      const localname,
	                  const XMLCh*      const qname,
	                  const Attributes&       attrs);
	void fatalError  (const SAXParseException&);	
	
    /*! -----------------------------------------------------------------------
     * Private data members
     *
     * tempVecTextFileList
     *     This is vector that store name of text files from last parser. 
	 * tempVecTextIDList
     *     This is vector that store name of ID files from last parser.
     *  ------------------------------------------------------------------------
	 */
	vector<string> tempVecTextFileList;
	vector<string> tempVecTextIDList;
};

#endif