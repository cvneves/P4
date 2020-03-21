#include "Tree.h"

Node *BuildHuffmanTree(Data *data)
{
    Node *root;
    PriorityQueue *pq = PriorityQueueInitialize();

    for (int i = 0; i < data->nBytes; i++)
    {
        NodeInfo *nf = malloc(sizeof(NodeInfo));
        nf->node = malloc(sizeof(Node));
        nf->node->left = nf->node->right = NULL;
        nf->node->value = data->byteTable[i]->byte;
        nf->freq = data->byteTable[i]->frequency;
        PriorityQueueInsert(pq, nf, NodeInfoCompare);
    }

    for(int i = 0; i < data->nBytes;i++)
    {
        free(pq->data[i]);
    }

    // if (data->nBytes >= 2)
    // {
    //     while (pq->end > 0)
    //     {
    //         NodeInfo *na = ((NodeInfo *)PriorityQueuePop(pq, NodeInfoCompare));
    //         NodeInfo *nb = ((NodeInfo *)PriorityQueuePop(pq, NodeInfoCompare));

    //         NodeInfo *nf = malloc(sizeof(NodeInfo));
    //         nf->node = malloc(sizeof(Node));
    //         nf->node->right = na->node;
    //         nf->node->left = nb->node;
    //         nf->node->value = -1;
    //         nf->freq = na->freq + nb->freq;

    //         PriorityQueueInsert(pq, nf, NodeInfoCompare);

    //         free(na);
    //         free(nb);
    //     }

    //     NodeInfo *na = ((NodeInfo *)PriorityQueuePop(pq, NodeInfoCompare));
    //     root = na->node;

    //     free(na);
    // }

    FreePriorityQueue(pq);

    return root;
}

int NodeInfoCompare(void *a, void *b)
{

    if (((NodeInfo *)a)->freq < ((NodeInfo *)b)->freq)
        return 1;
    return 0;
}

void DFS(Node *node)
{
    if (node == NULL)
        return;

    DFS(node->left);
    DFS(node->right);

    free(node);
}

void FreeHuffmanTree(Node *node)
{
    if (node == NULL)
        return;
    
    FreeHuffmanTree(node->left);
    FreeHuffmanTree(node->right);

    free(node);
}