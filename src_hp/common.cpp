/*
 * common.cpp
 *
 *  Created on: 2016年4月8日
 *      Author: root
 */


#include"common.h"
/*
 * author cyzheng
 */
char * read_file(char *path)
{
	char *buf;
	FILE *Fp;
	int size;
	Fp=fopen(path,"r+");
	if(Fp==NULL) return NULL;
    fseek(Fp,0L,SEEK_END);
    size=ftell(Fp);
    buf=(char *)malloc(size);
    fseek(Fp,0L,SEEK_SET);
    if(fread(buf,size,1,Fp)<=0) return NULL;
    return buf;
}


