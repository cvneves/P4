#include "PriorityQueue.h"

PriorityQueue *PriorityQueueInitialize()
{
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->end = -1;
    pq->data = NULL;
}

void PriorityQueueInsert(PriorityQueue *pq, void *x, int (*f)(void *a, void *b))
{
    if (pq->end == -1)
    {
        pq->data = malloc(sizeof(void *));
        pq->data[0] = x;
        pq->size = 1;
        pq->end++;
        return;
    }

    pq->end++;

    if (pq->end >= pq->size)
    {
        int newSize = 2 * pq->size;
        void **temp = malloc(newSize * sizeof(void *));

        for (int i = 0; i <= pq->end; i++)
        {
            temp[i] = pq->data[i];
        }

        pq->size = newSize;

        free(pq->data);
        pq->data = temp;
    }

    int index = pq->end;
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

    int parent = 0;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    while (1)
    {
        int index;

        if (left <= pq->end && right <= pq->end)
        {
            if (f(pq->data[left], pq->data[right]))
                index = left;
            else
                index = right;
        }
        else
        {
            if (left > pq->end && right > pq->end)
                break;
            if (left > pq->end)
                index = right;
            else
                index = left;
        }

        if (f(pq->data[index], pq->data[parent]))
        {

            void *temp = pq->data[parent];
            pq->data[parent] = pq->data[index];
            pq->data[index] = temp;

            parent = index;
            left = 2 * index + 1;
            right = 2 * index + 2;
        }
        else
        {
            break;
        }
    }

    // for (int i = 0; i <= pq->end; i++)
    // {
    //     printf("%d ", (int)*((char *)pq->data[i]));
    // }
    // printf("\n");

    return x;
}

void FreePriorityQueue(PriorityQueue *pq)
{
    free(pq->data);
    free(pq);
}

int NumComparePq(void *a, void *b)
{
    int x = (int)*((char *)a);
    int y = (int)*((char *)b);

    // printf("%d %d\n", x, y);

    if (x < y)
        return 1;
    return 0;
}
