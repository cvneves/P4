#include "Tree.h"

Node *BuildHuffmanTree(Data *data)
{
    Node **nodeArray = malloc(data->nBytes * sizeof(Node *));
    for(int i = 0; i < data->nBytes; i++)
    {
        nodeArray[i] = malloc(sizeof(Node));
    }   
}