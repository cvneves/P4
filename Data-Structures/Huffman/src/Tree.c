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

                // if (nb->node->value == -1)
                // {
                //     NodeInfo *temp = na;
                //     na = nb;
                //     nb = temp;
                // }

                NodeInfo *nf = malloc(sizeof(NodeInfo));
                nf->node = malloc(sizeof(Node));
                nf->node->left = na->node;
                nf->node->right = nb->node;
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

void FreeHuffmanTree(Node *node)
{
    if (node == NULL)
        return;


    // printf("%c\n", node->value);

    FreeHuffmanTree(node->left);


    FreeHuffmanTree(node->right);

    free(node);
}

void SerializeTree(Node *root, FILE *fp)
{
    int value;
    if (!root)
    {
        value = -2;
        fwrite(&value, sizeof(int), 1, fp);
        // fprintf(fp, "%d ", -2);
        return;
    }

    fwrite(&(root->value), sizeof(int), 1, fp);
    SerializeTree(root->left, fp);
    SerializeTree(root->right, fp);
}

void DeSerializeTree(Node **root, FILE *fp)
{
    int value;
    // if (!fscanf(fp, "%d ", &value) || value == -2)
    if (fread(&value, sizeof(int), 1, fp) != 1 || value == -2)
    {
        *root = NULL;
        return;
    }
    *root = malloc(sizeof(Node));
    (*root)->value = value;
    DeSerializeTree(&(*root)->left, fp);
    DeSerializeTree(&(*root)->right, fp);
}