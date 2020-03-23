#include "List.h"

void ListInitialize(List *list)
{
    list->size = 0;
    list->head = list->tail = NULL;
    // list->element_size = element_size;
}

void ListAppend(List *list, void *data)
{
    if (!list->size++)
    {
        list->head = list->tail = (Node *)malloc(sizeof(Node));
        list->tail->data = data;

        list->head->next = NULL;
        list->head->prev = NULL;
        list->tail->next = NULL;
        list->tail->prev = NULL;

        return;
    }

    list->tail->next = (Node *)malloc(sizeof(Node));
    list->tail->next->data = data;
    list->tail->next->prev = list->tail;
    list->tail = list->tail->next;
}

void ListPrepend(List *list, void *data)
{
    if (!list->size++)
    {
        list->head = list->tail = (Node *)malloc(sizeof(Node));
        list->tail->data = data;

        list->head->next = list->tail;
        list->head->prev = NULL;
        list->tail->next = NULL;
        list->tail->prev = list->head;

        return;
    }

    list->head->prev = (Node *)malloc(sizeof(Node));
    list->head->prev->data = data;
    list->head->prev->next = list->head;
    list->head = list->head->prev;
}

void ListInsertAfter(List *list, Node *node, void *data)
{
    list->size++;
    if (!node->next)
    {
        ListAppend(list, data);
        return;
    }
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = node->next;
    n->prev = node;
    node->next->prev = n;
    node->next = n;
    n->data = data;
}

void ListRemove(List *list, Node *node)
{
    if (node == list->head && list->size > 1)
    {
        list->head = list->head->next;
        list->head->prev = NULL;
        free(node->data);
        free(node);
        list->size--;
        return;
    }
    if (node == list->tail && list->size > 1)
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(node->data);
        free(node);
        list->size--;
        return;
    }
    if (list->size == 1)
    {
        ListDestroy(list);
        ListInitialize(list);
        return;
    }

    list->size--;
    node->next->prev = node->prev;
    node->prev->next = node->next;
    free(node->data);
    free(node);
}

void ListDestroy(List *list)
{
    Node *p = list->head;
    do
    {
        free(p->data);
        free(p);
    } while (p = p->next);

    free(list);
}