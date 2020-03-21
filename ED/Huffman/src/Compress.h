#ifndef COMPRESS_H
#define COMPRESS_H

#include <stdlib.h>
#include <stdio.h>
#include "Data.h"
#include "ByteInfo.h"
#include "PriorityQueue.h"
#include "Tree.h"

#define MAX_STR_LEN 100

typedef struct ByteCode
{
    int code;
    int length;
} ByteCode;

void GenerateCodeTable(Node *node, int i, int length, ByteCode *bc);
void CompressFile(char *inputFileName, char *outputFileName, Node *root);

#endif