/* 仅供参考 */

#ifndef HP_H
#define HP_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include <stddef.h>
enum hp_selector_type {
	HPSELECTORTYPE_NONE            = -1,
	HPSELECTORTYPE_XPATH           = 0,
	HPSELECTORTYPE_REGEX           = 1,
	HPSELECTORTYPE_JQUERY_SELECTOR = 2,
	HPSELECTORTYPE_JSON_POINTER    = 3
};

enum hp_savepath_type {
	HPSAVEPATHTYPE_JSON_POINTER = 0,
	HPSAVEPATHTYPE_XPATH        = 1
};

struct hp_node {
	char *raw_str;         /* 节点的内容 */
	void *cache_gumbo_doc; /* raw_str是html源码或者html片段时, 可以缓存一个gumbo的文档指针, 下次解析无需再次创建 */
	void *cache_json_doc;  /* raw_str是json字符串时, 可以缓存一个rapidjson的文档指针, 下次解析无需再次创建 */
	void *cache_xml_doc;   /* raw_str是xml字符串时, 可以缓存一个libxml的文档指针, 下次解析无需再次创建 */
	struct hp_node *prev;  /* 用于hp_node_list */
	struct hp_node *next;  /* 用于hp_node_list */
};

struct hp_node_list {
	size_t size;
	struct hp_node *head;
};

struct hp_out_docs {
	void *json_doc;
	void *xml_doc;
};
/*
 *	author
 */
int hp_init(const char *url,char *data);
/* 参数html可以是完整的html文档, html片段, JSON字符串, XML字符串, 普通字符串 */

struct hp_node *
hp_new_node(const char *str);

/* 释放节点 */
void
hp_free_node(struct hp_node *);

/* 执行选择器过滤除符合条件的所有节点
 * main_selector是必需参数, 不可为空.
 * match_selector是可选参数, 可以为空, 目的是对main_selector返回结果进行筛选,
 * 筛选方法是, 对待筛选所有节点执行match_selector, 匹配数大于0则保留, 否则不保留. */
struct hp_node_list *
hp_select(struct hp_node *,
		  enum hp_selector_type, const char *main_selector,
		  enum hp_selector_type, const char *match_selector);

/* 释放节点列表 */
void
hp_free_node_list(struct hp_node_list *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* HP_H */
