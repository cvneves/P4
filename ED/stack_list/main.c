#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Exercise.h"
#include "List.h"
#include "Deque.h"

int main()
{
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    DequeInitialize(deque);

    DequePushRight(deque, 'A');
    DequePushRight(deque, 'B');
    DequePushRight(deque, 'C');

    printf("%d\n\n", deque->left);

    printf("%c\n", DequePopRight(deque));
    printf("%c\n", DequePopRight(deque));
    printf("%c\n", DequePopRight(deque));

    // List *list = (List *)malloc(sizeof(List));
    // ListInitialize(list);

    // for (int i = 0; i < 10; i++)
    // {
    //     int *x = malloc(sizeof(int));
    //     *x = 10 * i;
    //     ListAppend(list, x);
    // }

    // for (int i = 0; i < 10; i++)
    // {
    //     int *x = malloc(sizeof(int));
    //     *x = -10 * i;
    //     ListPrepend(list, (void *)x);
    // }

    // int *a = (int*)malloc(sizeof(int));
    // *a = 1000;
    // // ListInsertAfter(list, list->tail->prev, (void *) a);
    // ListRemove(list, list->tail);

    // {
    //     Node *p = list->head;

    //     do
    //     {
    //         printf("%d ", *((int *)p->data));
    //     } while (p = p->next);

    //     printf("\n");
    // }

    // ListDestroy(list);
}