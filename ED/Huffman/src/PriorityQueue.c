#include "PriorityQueue.h"

PriorityQueue *PriorityQueueInitialize()
{
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->size = MAX_PQ_SIZE;
    pq->end = -1;
    pq->data = malloc(MAX_PQ_SIZE * sizeof(void *));
}

void PriorityQueueInsert(PriorityQueue *pq, void *x, int (*f)(void *a, void *b))
{
    if (pq->end == -1)
    {
        pq->data[0] = x;
        // memcpy((char *)pq->data, x, sizeof(void *));
        pq->end++;
        return;
    }

    int index = pq->end + 1;
    pq->data[index] = x;

    void *a = pq->data[index];
    void *b = pq->data[(index - 1) / 2];

    while (index > 0 && f((void *)a, (void *)b))
    {
        void *temp = pq->data[index];
        pq->data[index] = pq->data[(index - 1) / 2];
        pq->data[(index - 1) / 2] = temp;

        index = (index - 1) / 2;

        a = pq->data[index];
        b = pq->data[(index - 1) / 2];
    }
    pq->end++;

    // for (int i = 0; i <= pq->end; i++)
    // {
    //     printf("%d ", (int)*((char *)pq->data[i]));
    // }
    // printf("\n");
}

void *PriorityQueuePop(PriorityQueue *pq, int (*f)(void *a, void *b))
{
    void *x = pq->data[0];

    pq->data[0] = pq->data[pq->end];
    pq->end--;

    int index = 0;
    void *b = pq->data[index];
    void *a = pq->data[2 * index + 1];

    while ((2 * index + 1) <= pq->end && f(a, b))
    {
        void *temp = pq->data[index];
        pq->data[index] = pq->data[2 * index + 1];
        pq->data[2 * index + 1] = temp;

        index = 2 * index + 1;

        b = pq->data[index];
        a = pq->data[2 * index + 1];
    }

    for (int i = 0; i <= pq->end; i++)
    {
        printf("%d ", (int)*((char *)pq->data[i]));
    }
    printf("\n");

    return x;
}

void DestroyHeap(PriorityQueue *pq)
{
}

int BytePQCompare(void *a, void *b)
{
    int x = (int)*((char *)a);
    int y = (int)*((char *)b);

    // printf("%d %d\n", x, y);

    if (x < y)
        return 1;
    return 0;
}