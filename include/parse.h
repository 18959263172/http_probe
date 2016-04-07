/*
 *
 */
#include<stdio.h>
#include"list.h"

struct output_result
{
	char *node;
	struct list_head head;
};
/*
 *
 */
int init_parse(char *name);
/*
 *
 */
int parse_gumbo(char *in_content,char *filter,struct output_result *out_list);
