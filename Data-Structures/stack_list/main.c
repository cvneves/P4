#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Stack.h"
#include "Exercise.h"
#include "List.h"
#include "Deque.h"
#include "NinjaList.h"

int main()
{
    // NNode *head = (NNode *)malloc(sizeof(NNode));
    // head->value = 5;
    // head->np = NULL;

    // NNode *p1 = NULL, *p2 = head;
    // for (int i = 1; i <= 100; i++)
    // {
    //     NNode *temp = p2;
    //     p2 = NinjaListInsertAfter(p1, p2, i * 10);
    //     p1 = temp;
    // }

    // p1 = NULL;
    // p2 = head;
    // while (p2)
    // {
    //     printf("%d ", p2->value);
    //     NNode *temp = p2;
    //     p2 = (NNode *)((__intptr_t)p1 ^ (__intptr_t)p2->np);
    //     p1 = temp;
    // }

    Deque *deque = (Deque *)malloc(sizeof(Deque));
    DequeInitialize(deque);

    for (int i = 0; i < 26; i++)
    {
        DequePushRight(deque, 'A' + i);
    }

    // printf("%d\n", deque->max_size);

    while (deque->size)
    {
        printf("%c\n", DequePopRight(deque));
    }

    // // List *list = (List *)malloc(sizeof(List));
    // // ListInitialize(list);

    // // for (int i = 0; i < 10; i++)
    // // {
    // //     int *x = malloc(sizeof(int));
    // //     *x = 10 * i;
    // //     ListAppend(list, x);
    // // }

    // // for (int i = 0; i < 10; i++)
    // // {
    // //     int *x = malloc(sizeof(int));
    // //     *x = -10 * i;
    // //     ListPrepend(list, (void *)x);
    // // }

    // // int *a = (int*)malloc(sizeof(int));
    // // *a = 1000;
    // // // ListInsertAfter(list, list->tail->prev, (void *) a);
    // // ListRemove(list, list->tail);

    // // {
    // //     Node *p = list->head;

    // //     do
    // //     {
    // //         printf("%d ", *((int *)p->data));
    // //     } while (p = p->next);

    // //     printf("\n");
    // // }

    // // ListDestroy(list);
}