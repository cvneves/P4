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

    if (data->nBytes >= 2)
    {
        while (1)
        {
            if (pq->end >= 1)
            {
                NodeInfo *na = ((NodeInfo *)PriorityQueuePop(pq, NodeInfoCompare));
                NodeInfo *nb = ((NodeInfo *)PriorityQueuePop(pq, NodeInfoCompare));

                if (nb->node->value == -1)
                {
                    NodeInfo *temp = na;
                    na = nb;
                    nb = temp;
                }

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
            else if (pq->end == 0)
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

    // printf("%d\n", node->value);

    FreeHuffmanTree(node->right);

    free(node);
}

void PrintHuffmanCodes(Node *node, int num)
{
    if (!node)
        return;

    PrintHuffmanCodes(node->right, (num << 1) | 1);

    PrintHuffmanCodes(node->left, num << 1);

    if (node->value != -1)
    {
        printf("Symbol %d, Code %d\n", node->value, num);
    }
}