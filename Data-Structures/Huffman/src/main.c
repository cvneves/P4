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
    char *mode = argv[1];

    if (strcmp(mode, "-c") == 0)
    {
        Data *data = malloc(sizeof(Data));

        ReadData(data, argv[2]);

        GetByteFrequency(data);

        PrintByteTable(data);

        Node *root = BuildHuffmanTree(data);

        FILE *fi = fopen(argv[2], "rb");
        FILE *fo = fopen(argv[3], "wb");

        int compressed_size = 0;
        int original_size = 0;
        CompressFile(fi, fo, root, &original_size, &compressed_size);

        FreeHuffmanTree(root);

        FreeData(data);

        fclose(fi);
        fclose(fo);

        exit(0);
    }
    else if (strcmp(mode, "-x") == 0)
    {
        FILE *fi = fopen(argv[2], "rb");
        
        FILE *fo = fopen(argv[3], "wb");

        DecompressFile(fi,fo);

        fclose(fi);
        fclose(fo);
    }
    else
    {
        printf("Entrada invalida\n");
    }

    // char str[] = "abbcccdddde";
    // FILE *fp = fopen("instance/teste2.bin", "w");

    // for(int i = 0; i < strlen(str); i++)
    // {
    //     fwrite(&str[i], sizeof(char), 1, fp);
    // }
    // fclose(fp);
}