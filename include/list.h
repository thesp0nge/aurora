#ifndef _LIST_H
#define _LIST_H

typedef struct node_s {
	void *data;
  int  counter; // has the number of linked items on the first item. 0 on others
	struct node_s *next;	
} NODE;

#define TAINTED   127
#define UNTAINTED 255

NODE *list_create(void *data);
NODE *list_insert_after(NODE *node, void *data);
NODE *list_insert_beginning(NODE *list, void *data);
int list_remove(NODE *list, NODE *node);
int list_foreach(NODE *node, int(*func)(void*));
NODE *list_find(NODE *node, int(*func)(void*,void*), void *data);
#endif
