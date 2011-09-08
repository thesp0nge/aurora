#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

NODE *list_create(void *data)
{
  NODE *node;
  if(!(node=malloc(sizeof(NODE)))) return NULL;
  // node->data=data;
  node->data = malloc(strlen((char *)data) * sizeof (char) + 1);
  strncpy((char *)node->data, data, strlen(data));
  node->counter=0;
  node->next=NULL;
  return node;
}


NODE *list_insert_after(NODE *node, void *data)
{
  NODE *newnode;
  newnode=list_create(data);
  newnode->next = node->next;
  node->next = newnode;
  return newnode;
}

NODE *list_insert_beginning(NODE *list, void *data)
{
  NODE *newnode;
  newnode=list_create(data);
  newnode->next = list;
  return newnode;
}

int list_remove(NODE *list, NODE *node)
{
  while(list->next && list->next!=node) list=list->next;
  if(list->next) {
    list->next=node->next;
    free(node);
    return 0;		
  } else return -1;
}

int list_foreach(NODE *node, int(*func)(void*))
{
  while(node) {
    if(func(node->data)!=0) return -1;
    node=node->next;
  }
  return 0;
}
NODE *list_find(NODE *node, int(*func)(void*,void*), void *data)
{
  while(node) {
    if(func(node->data, data)>0) return node;
    node=node->next;
  }
  return NULL;
}

