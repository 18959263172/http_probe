#ifndef _LIST_H
#define _LIST_H

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * Simple doubly linked list implementation.
 *
 * Some of the internal functions ("__xxx") are useful when
 * manipulating whole lists rather than single entries, as
 * sometimes we already know the next/prev entries and we can
 * generate better code by using them directly rather than
 * using the generic single-entry routines.
 */

struct list_head {
	void *self; //use to save self ptr
    struct list_head *next, *prev;
};

#define INIT_LIST_HEAD(ptr) do { \
        (ptr)->self = (void*)0; \
        (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

/*
 * Insert a newh entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
void __list_add(struct list_head *newh, struct list_head *prev, struct list_head *next);

/**
 * list_add - add a newh entry
 * @newh: newh entry to be added
 * @head: list head to add it after
 *
 * Insert a newh entry after the specified head.
 * This is good for implementing stacks.
 */
void list_add(struct list_head *newh, struct list_head *head);

/**
 * list_add_tail - add a newh entry
 * @newh: newh entry to be added
 * @head: list head to add it before
 *
 * Insert a newh entry before the specified head.
 * This is useful for implementing queues.
 */
void list_add_tail(struct list_head *newh, struct list_head *head);

/**
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty on entry does not return true after this, the entry is in an undefined state.
 */
void list_del(struct list_head *entry);

/**
 * list_del_init - deletes entry from list and reinitialize it.
 * @entry: the element to delete from the list.
 */
void list_del_init(struct list_head *entry);
/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
int list_empty(struct list_head *head);
/**
 * list_splice - join two lists
 * @list: the newh list to add.
 * @head: the place to add it in the first list.
 */
void list_splice(struct list_head *list, struct list_head *head);

/**
 * list_entry - get the struct for this entry
 * @ptr:        the &struct list_head pointer.
 * @type:       the type of the struct this is embedded in.
 * @member:     the name of the list_struct within the struct.
 */
#define list_entry(ptr, type, member) \
        ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

/**
 * list_for_each        -       iterate over a list
 * @pos:        the &struct list_head to use as a loop counter.
 * @head:       the head for your list.
 */
#define list_for_each(pos, head) \
        for (pos = (head)->next; pos != (head); \
                pos = pos->next)

/**
 * list_for_each_safe   -       iterate over a list safe against removal of list entry
 * @pos:        the &struct list_head to use as a loop counter.
 * @n:          another &struct list_head to use as temporary storage
 * @head:       the head for your list.
 */
#define list_for_each_safe(pos, n, head) \
        for (pos = (head)->next, n = pos->next; pos != (head); \
                pos = n, n = pos->next)

/**
 * list_for_each_entry  -       iterate over list of given type
 * @pos:        the type * to use as a loop counter.
 * @head:       the head for your list.
 * @member:     the name of the list_struct within the struct.
 */
#define list_for_each_entry(pos, head, member, type) \
        for (pos = list_entry((head)->next, type, member);\
             &pos->member != (head);\
             pos = list_entry(pos->member.next,type, member))

#ifdef  __cplusplus
}
#endif

#endif
