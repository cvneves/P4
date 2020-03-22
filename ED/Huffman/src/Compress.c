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

void CompressFile(FILE *fi, FILE *fo, Node *root)
{

    ByteCode bc[MAX_BYTES];

    for (int i = 0; i < MAX_BYTES; i++)
    {
        bc[i].code = -1;
    }

    GenerateCodeTable(root, 0, 0, bc);

    printf("##########################################\n");
    for (int i = 0; i < MAX_BYTES; i++)
    {
        if (bc[i].code != -1)
        {
            printf("Byte: %d, Code: %d, Length: %d\n", i, bc[i].code, bc[i].length);
        }
    }
    printf("##########################################\n");

    SerializeTree(root, fo);

    /* Compressing loop */

    {
        int i = 0;
        int leftOver = 0;

        char msg;
        int endOfFile;
        endOfFile = fread(&msg, sizeof(char), 1, fi) != 1;

        while (!endOfFile)
        {
            char finalByte = 0;
            int chunkSize = 8;

            while (!endOfFile)
            {
                int codeLength = bc[msg].length;
                int code = bc[msg].code;

                int leftShiftLength = chunkSize - codeLength + leftOver;

                if (leftShiftLength < 0)
                {
                    leftShiftLength *= -1;
                    code = code >> leftShiftLength;
                    finalByte = finalByte | code;
                    leftOver = codeLength - leftShiftLength;
                    break;
                }

                code = code << leftShiftLength;

                // printf("%d\n", code);

                finalByte = finalByte | code;

                chunkSize -= codeLength;

                endOfFile = fread(&msg, sizeof(char), 1, fi) != 1;
                i++;
            }

            // printf("%hhx\n", finalByte);
            fwrite(&finalByte, sizeof(char), 1, fo);
        }
    }
}

void DecompressFile(FILE *fi, FILE *fo)
{
    Node *root;
    DeSerializeTree(&root, fi);

    unsigned char chunk;

    Node *node = root;

    int bitStream[] = {1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    // int i = 0;

    // while (i < 24)
    while (fread(&chunk, sizeof(char), 1, fi) == 1)
    {

        int i = 0;
        // printf("\n\n%d\n\n", chunk);

        while (i < 8)
        {
            // printf("%d\n",   i);
            if (node->left == NULL && node->right == NULL)
            {
                printf("%c\n", node->value);
                node = root;
                // printf("vem\n");

                continue;
            }
            if (chunk >= 128)
            {
                node = node->right;
                 chunk = chunk << 1;
            i++;
            }
            else
            {
                node = node->left;
                 chunk = chunk << 1;
            i++;
            }

           
        }

        if (node->left == NULL && node->right == NULL)
        {
            printf("%c\n", node->value);
            node = root;
            // printf("vem\n");

            // continue;
        }
    }

    FreeHuffmanTree(root);
}