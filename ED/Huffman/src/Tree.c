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
        printf("%d\n", pq->size);
    }

    if (data->nBytes >= 2)
    {
        while (1)
        {
            if (pq->end >= 1)
            {
                NodeInfo *na = ((NodeInfo *)PriorityQueuePop(pq, NodeInfoCompare));
                printf("%d %d\n", pq->end, pq->size);
                NodeInfo *nb = ((NodeInfo *)PriorityQueuePop(pq, NodeInfoCompare));
                printf("%d %d\n", pq->end, pq->size);

                NodeInfo *nf = malloc(sizeof(NodeInfo));
                nf->node = malloc(sizeof(Node));
                nf->node->right = na->node;
                nf->node->left = nb->node;
                nf->node->value = -1;
                nf->freq = na->freq + nb->freq;

                root = nf->node;

                PriorityQueueInsert(pq, nf, NodeInfoCompare);

                free(na);
                free(nb);
            }
            else if(pq->end == 0)
            {
                NodeInfo *na = ((NodeInfo *)PriorityQueuePop(pq, NodeInfoCompare));
                root = na->node;

                free(na);
                break;
            }
            else
            {
                break;
            }
            
        }
    }

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