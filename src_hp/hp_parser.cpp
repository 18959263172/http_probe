/*
 * hp_parser.cpp
 *
 *  Created on: 2016年2月24日
 *      Author: root
 */
#include"cJSON.h"
#include"malloc.h"
#include"hp_parse.h"
#include<stdio.h>
#include<string.h>
#include"debug.h"
char *docdat;
/*
 *	@author
 */
int output_type_decide()
{

}
/*
 *	@author
 */
int init_output_engine(FILE *file,Presult result)
{
	int length;
	fseek(file,0L,SEEK_END);
	length=ftell(file);
	docdat=(char *)malloc(length);
	fread(docdat,1,length,file);
	result.docbuf=docdat;

}
/*
 *	@author
 */
int out_test_json(char *file_path)
{
	FILE *file;
	file=fopen(file_path,"w+");
	if(file==NULL) return -1;
	char *out ;
	cJSON *root,*fmt;
	root=cJSON_CreateObject();//创建项目
	cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack (\"Bee\") Nimble"));
	cJSON_AddItemToObject(root, "format", fmt=cJSON_CreateObject());//在项目上添加项目
	cJSON_AddStringToObject(fmt,"type", "rect");//在项目上的项目上添加字符串，这说明cJSON是可以嵌套的
	cJSON_AddNumberToObject(fmt,"width", 1920);
	cJSON_AddNumberToObject(fmt,"height", 1080);
	cJSON_AddNumberToObject(fmt,"frame rate", 24);
	out=cJSON_Print(fmt);
	printf("%s\n",out);
	fprintf(file,out,strlen(out));
	free(out);
}
/*
 *	@author
 */
int judge_type_doc(Presult result)
{

}
