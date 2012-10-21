#ifndef ALLHANDLE_H
#define ALLHANDLE_H

// turn off warning about symbols too long for debugger
//#pragma warning(disable: 4786)
//#pragma warning(disable: 4251)
//#pragma warning(disable: 4267)
#pragma once
//#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

//System include
#include <string.h>
#include <vector>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//strstr include - case insensitive comparison 
#include "stristr.cpp"

//xercesc include - general
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>

//xercesc include - sax parser&handle
#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>

//xercesc include - dom writer
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMLSSerializer.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/dom/impl/DOMLSSerializerImpl.hpp>
#include <xercesc/dom/impl/DOMDocumentImpl.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>


using namespace std;
XERCES_CPP_NAMESPACE_USE;

#endif