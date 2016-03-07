/*
 * hp_do.c
 *
 *  Created on: 2016年1月27日
 *      Author: root
 */
#include"hp.h"
#include <curl/curl.h>
#include <libxml/parser.h>
#include <libxml/xpath.h>

 /*
  * @author
  */
 static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}
 /*
  * @author
  */
int hp_init(const char *url,char *data)
{

}
/*
 * @author
 */
struct hp_node *hp_new_node(const char *str)
{
	struct hp_node *new_node;
	new_node=(struct hp_node*)malloc(sizeof(struct hp_node));

}
/*
 * @author
 */
struct hp_node_list *hp_select(struct hp_node * node,
		  enum hp_selector_type type1, const char *main_selector ,
		  enum hp_selector_type type2, const char *match_selector)
{



}
/*
 * @author
 */
void hp_free_node(struct hp_node *node)
{

}
