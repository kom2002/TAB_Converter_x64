/* charsets.h -- character set information and mappings

  (c) 1998-2003 (W3C) MIT, ERCIM, Keio University
  See tidy.h for the copyright notice.

  $Id: charsets.h,v 1.7 2005/05/23 02:08:11 phrostbyte Exp $
*/

uint GetEncodingIdFromName(ctmbstr name);
uint GetEncodingIdFromCodePage(uint cp);
uint GetEncodingCodePageFromName(ctmbstr name);
uint GetEncodingCodePageFromId(uint id);
ctmbstr GetEncodingNameFromId(uint id);
ctmbstr GetEncodingNameFromCodePage(uint cp);
