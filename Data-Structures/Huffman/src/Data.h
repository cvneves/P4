#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "ByteInfo.h"

#define MAX_BYTES 256

typedef struct Data
{
    int nBytes;
    int byteFrequency[256];
    ByteInfo **byteTable;
    int orignal_size, final_size, tree_size;
} Data;

void ReadData(Data *data, char *fileName);
void FreeData(Data *data);

void GetByteFrequency(Data *data);
void PrintByteTable(Data *data);

#endif