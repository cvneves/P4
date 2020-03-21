#include "Compress.h"

void GenerateCodeTable(Node *node, int i, int length, ByteCode *bc)
{
    if (node == NULL)
        return;

    GenerateCodeTable(node->left, i << 1, length + 1, bc);
    GenerateCodeTable(node->right, (i << 1) | 1, length + 1, bc);

    if (node->value != -1)
    {
        bc[node->value].code = i;
        bc[node->value].length = length;
    }
    // printf("Byte: %d, Code: %d, Length; %d\n", node->value, i, length);
}

void CompressFile(char *inputFileName, char *outputFileName, Node *root)
{

    ByteCode bc[MAX_BYTES];

    for(int i = 0; i < MAX_BYTES;i++)
    {
        bc[i].code = -1;
    }

    GenerateCodeTable(root, 0, 0, bc);

    printf("##########################################\n");
    for(int i = 0; i < MAX_BYTES; i++)
    {
        if(bc[i].code != -1)
        {
            printf("Byte: %d, Code: %d, Length: %d\n", i, bc[i].code, bc[i].length);
        }
    }
    printf("##########################################\n");

    /* Compressing loop */

    char msg[] = "abbcccdddde";

    for(int i = 0; i < strlen(msg); i++)
    {
        int chunkSize = 8;
    }

}