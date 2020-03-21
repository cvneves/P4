#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Data.h"
#include "ByteInfo.h"
#include "Tree.h"
#include "PriorityQueue.h"
#include "Compress.h"

int main(int argc, char **argv)
{
    Data *data = malloc(sizeof(Data));

    ReadData(data, argv[1]);

    GetByteFrequency(data);

    // MergeSortByteInfo(data->byteTable, 0, data->nBytes - 1);

    PrintByteTable(data);

    Node *root = BuildHuffmanTree(data);

    CompressFile(argv[1], argv[2], root);

    FreeHuffmanTree(root);

    FreeData(data);

    // char str[] = "abbcccdddde";
    // FILE *fp = fopen("instance/teste2.bin", "w");

    // for(int i = 0; i < strlen(str); i++)
    // {
    //     fwrite(&str[i], sizeof(char), 1, fp);
    // }
    // fclose(fp);
}