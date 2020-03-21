#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PQ_SIZE 512

typedef struct PriorityQueue
{
    void **data;
    int size, end;
} PriorityQueue;

PriorityQueue * PriorityQueueInitialize();
void PriorityQueueInsert(PriorityQueue *pq, void *x, int (*f)(void *a, void *b));
void *PriorityQueuePop(PriorityQueue *pq, int (*f)(void *a, void *b));
void FreePriorityQueue(PriorityQueue *pq);

int NumComparePq(void*a, void*b);



#endif