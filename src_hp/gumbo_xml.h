#ifndef __GUMBO_XML__
#define __GUMBO_XML__
#include "libxml/xpath.h"
#include "gumbo_libxml.h"

int main_test(const char *file_path);

xmlXPathObjectPtr getNodeset(xmlDocPtr doc, const xmlChar *xpath);




#endif
