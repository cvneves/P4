#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Data.h"
#include "ByteInfo.h"
#include "Tree.h"
#include "PriorityQueue.h"

int main(int argc, char **argv)
{
    Data *data = malloc(sizeof(Data));

    ReadData(data, argv[1]);

    GetByteFrequency(data);

    // MergeSortByteInfo(data->byteTable, 0, data->nBytes - 1);

    PrintByteTable(data);

    Node *root = BuildHuffmanTree(data);

    FreeHuffmanTree(root);

    FreeData(data);

    // PriorityQueue *pq = PriorityQueueInitialize();

    // srand(time(NULL));

    // int arrSize = 10;
    // // int arr[arrSize];
    // int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // for (int i = 0; i < arrSize; i++)
    // {
    //     arr[i] = rand() % 10;
    // }

    // for (int i = 0; i < arrSize; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    // for (int i = 0; i < arrSize; i++)
    // {
    //     PriorityQueueInsert(pq, &arr[i], BytePQCompare);
    // }

    // for (int i = 0; i <= pq->end; i++)
    // {
    //     printf("%d ", (int)*((char *)pq->data[i]));
    // }
    // printf("\n");

    // for (int i = 0; i < arrSize; i++)
    // {
    //     printf("%d\n", (int)*((char *)PriorityQueuePop(pq, BytePQCompare)));
    //     // PriorityQueuePop(pq, BytePQCompare);
    // }

    // FreePriorityQueue(pq);
}