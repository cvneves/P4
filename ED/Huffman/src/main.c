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

    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "w");

    CompressFile(fi, fo, root);

    FreeHuffmanTree(root);

    FreeData(data);

    fclose(fi);
    fclose(fo);

    // char str[] = "abbcccdddde";
    // FILE *fp = fopen("instance/teste2.bin", "w");

    // for(int i = 0; i < strlen(str); i++)
    // {
    //     fwrite(&str[i], sizeof(char), 1, fp);
    // }
    // fclose(fp);
}