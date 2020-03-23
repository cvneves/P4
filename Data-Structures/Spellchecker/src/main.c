#include <stdlib.h>
#include <stdio.h>
#include "List.h"

int main()
{
	printf("Hello world!\n");
	List *list = ListInitialize();

	int *x = malloc(sizeof(int));
	*x = 7;
	
	ListInsert(list, x);

	x = malloc(sizeof(int));
	*x = 3;

	ListInsert(list, x);

	x = malloc(sizeof(int));
	*x = 4;

	ListInsert(list, x);

	Node *node = list->head;

	while(node != NULL)
	{
		printf("%d\n", *((char*)(node->data)));
		node = node->next;
	}

	ListDestroy(list);
}

