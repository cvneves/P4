#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node
{
    void *data;
    struct Node *next, *prev;
} Node;

typedef struct List
{
    int size;
    size_t element_size;
    Node *head, *tail;
} List;

void ListInitialize(List *list);
void ListAppend(List *list, void * data);
void ListPrepend(List *list, void * data);
void ListInsertAfter(List *list, Node *node, void *data);
void ListRemove(List *list, Node *node);
void ListDestroy(List *list);

#endif