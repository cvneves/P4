#include <stdlib.h>
#include <stdio.h>
#include "Data.h"
#include "ByteInfo.h"
#include "Tree.h"

int main(int argc, char **argv)
{
    Data *data = malloc(sizeof(Data));

    ReadData(data, argv[1]);

    GetByteFrequency(data);

    MergeSortByteInfo(data->byteTable, 0, data->nBytes - 1);
    
    PrintByteTable(data);

    FreeData(data);
}