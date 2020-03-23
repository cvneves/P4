#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	void *data;
	struct Node * next , *prev;
}Node;

typedef struct List
{
	Node *head, *tail;
	size_t size;
} List;

List * ListInitialize();
void * ListDestroy(List * list);
void * ListInsert(List * list, void * x);

#endif
