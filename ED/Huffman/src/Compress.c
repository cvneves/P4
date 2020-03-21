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

    /* Compressing loop */

    bc['a'].length = 10;
    bc['a'].code = 512;

    char msg[] = "aa";

    {
        int i = 0;
        int leftOver = 0;

        while (i < strlen(msg))
        {
            char finalByte = 0;
            int chunkSize = 8;

            while (i < strlen(msg))
            {
                int codeLength = bc[msg[i]].length;
                int code = bc[msg[i]].code;

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
                i++;
            }

            printf("%hhx\n", finalByte);
        }
    }
}