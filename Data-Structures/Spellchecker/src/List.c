#include "List.h"

List * ListInitialize()
{
	List *list = malloc(sizeof(List));
	list->tail = list->head = NULL;
	return list;
}

void * ListAppend(List *list, void *x)
{
	Node *temp = malloc(sizeof(Node));
	temp->data = x;

	if(list->head == NULL)
	{
		temp->prev = temp->next = NULL;
		list->head = list->tail = temp;
	}
	else
	{
		list->tail->next = temp;
		temp->prev = list->tail;
		temp->next = NULL;
		list->tail = temp;
	}
}

void * ListRemove(List * list, Node *node)
{
	if(node == list->tail)
	{
		Node *temp = list->tail->prev;
		free(list->tail);
		free(list->tail->data);
		temp->next = NULL;
		list->tail = temp;
	}
	else if(node == list->head)
	{
		Node *temp = list->head->next;
		free(list->head);
		free(list->head->data);
		temp->prev = NULL;
		list->head = temp;
	}
	else
	{
		Node *prev = node->prev;
		Node *next = node->next;
		prev->next = next;
		next->prev = prev;
		free(node->data);
		free(node);
	}
}

void * ListDestroy(List *list)
{
	Node *node = list->head;
	while(node != NULL)
	{
		Node *temp = node->next;
		free(node->data);
		free(node);
		node = temp;
	}
	free(list);
}
