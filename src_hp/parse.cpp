/*
 * parse.cpp

 *
 *  Created on: 2016年4月7日
 *      Author: root
 */
#include"parse.h"

#include<stdio.h>
#include<malloc.h>
#include <Document.h>
#include <Selection.h>
#include <Node.h>
#include<string.h>
#include<string>
#include <curl/curl.h>
#include"gumbo_xml.h"
#include "gumbo_libxml.h"
#include <libxml/parser.h>
#include <libxml/xmlmemory.h>

using namespace std;

/*
 * author cyzheng
 */
int parse_gumbo(char *in_content,char *filter,struct output_result *out_list)
{
	int i,length;
	i=0;
	CDocument doc;
	string page(in_content);
	doc.parse(in_content);
	struct output_result *list;
	INIT_LIST_HEAD(&out_list->head);
	length=doc.find(filter).nodeNum();
	while(i<length)
	{
                CNode pNode = doc.find(filter).nodeAt(i);
                std::string content =page.substr(pNode.startPos(),pNode.startPos()-pNode.endPos());
                list=(struct output_result *)malloc(sizeof(struct output_result));
                list->node=(char *)malloc(strlen(content.c_str()));
                memcpy(list->node,content.c_str(),strlen(content.c_str()));
                list_add(&list->head,&out_list->head);
                i++;
	}
	return 1;
}

int  parse_xpath(char *in_content,char *filter,struct output_result *out_list)
{
    char *buf;
    xmlDocPtr playlistDoc;
    xmlDocPtr FirstStatePrt;
	struct output_result *list;
	int length;
	INIT_LIST_HEAD(&out_list->head);


    xmlChar *xpath = BAD_CAST(filter);   //关键在这行
    xmlXPathObjectPtr app_result = getNodeset(playlistDoc, xpath);
    xmlInitParser();
    if (app_result == NULL)
    {
    	printf("app_result is NULL\n");
        return NULL;
    }
   int i = 0;
   xmlChar *value;
   if(app_result)
  {
      xmlNodeSetPtr nodeset = app_result->nodesetval;
      xmlNodePtr cur;
      length=nodeset->nodeNr;
     for (i=0; i < nodeset->nodeNr; i++)
      {
            cur = nodeset->nodeTab[i];
            std::string content =((char*)xmlNodeGetContent(cur));
            list=(struct output_result *)malloc(sizeof(struct output_result));
            list->node=(char *)malloc(strlen(content.c_str()));
            memcpy(list->node,content.c_str(),strlen(content.c_str()));
            list_add(&list->head,&out_list->head);
      }
      xmlXPathFreeObject(app_result);
   }
}
