/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2016, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
/* <DESC>
 * Download a given URL into a local file named page.out.
 * </DESC>
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include"./src_hp/hp_parse.h"
#include <curl/curl.h>
#include"./src_hp/gumbo_xml.h"
#include "gumbo_libxml.h"
#include <libxml/parser.h>
#include <libxml/xmlmemory.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

int main(int argc, char *argv[])
{
	xmlDocPtr playlistDoc;

    xmlInitParser();
	playlistDoc=xmlParseFile("/root/out.xml");
	xmlChar *xpath = BAD_CAST("/radios/radio[name='DEU-Antenne Bayern']");   //关键在这行
	xmlXPathObjectPtr app_result = getNodeset(playlistDoc, xpath);
	if (app_result == NULL)
	{
	    printf("app_result is NULL\n");
	    return 1;
	}

	int i = 0;
	xmlChar *value;
	if(app_result)
	{
	    xmlNodeSetPtr nodeset = app_result->nodesetval;
	    xmlNodePtr cur;

	    for (i=0; i < nodeset->nodeNr; i++)
	    {
	        cur = nodeset->nodeTab[i];
	        cur = cur->xmlChildrenNode;

	        while (cur != NULL)
	        {
	            if (!xmlStrcmp(cur->name, (const xmlChar *)"name"))
	                printf("%s\n", ((char*)XML_GET_CONTENT(cur->xmlChildrenNode)));
	            else if (!xmlStrcmp(cur->name, (const xmlChar *)"url"))
	                printf("%s\n", ((char*)XML_GET_CONTENT(cur->xmlChildrenNode)));
	            	cur = cur->next;
	        }
	    }

	    xmlXPathFreeObject(app_result);
}
}




