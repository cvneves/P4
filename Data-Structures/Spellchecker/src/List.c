#include "List.h"

List * ListInitialize()
{
	List *list = malloc(sizeof(List));
	list->tail = list->head = NULL;
	return list;
}

void * ListInsert(List *list, void *x)
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
