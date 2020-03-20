#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include "Data.h"
#include "ByteInfo.h"

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *BuildHuffmanTree(Data *data);

#endif