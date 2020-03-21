#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include "Data.h"
#include "ByteInfo.h"
#include "PriorityQueue.h"

typedef struct Node
{
    int value;
    struct Node *left, *right;
} Node;

typedef struct NodeInfo
{
    int freq;
    Node *node;
} NodeInfo;

Node *BuildHuffmanTree(Data *data);
void FreeHuffmanTree(Node *node);
int NodeInfoCompare(void *a, void *b);

void DFS(Node *node);

#endif