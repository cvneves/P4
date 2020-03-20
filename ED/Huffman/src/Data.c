#include "Data.h"

void ReadData(Data *data, char *fileName)
{
    for (int i = 0; i < MAX_BYTES; i++)
    {
        data->byteFrequency[i] = 0;
    }

    FILE *fp = fopen(fileName, "r");
    char c;

    data->nBytes = 0;

    while (fread(&c, sizeof(c), 1, fp) == 1)
    {
        if (data->byteFrequency[c]++ == 0)
        {
            data->nBytes++;
        }
    }

    fclose(fp);
}

void FreeData(Data *data)
{
    for (int i = 0; i < data->nBytes; i++)
    {
        free(data->byteTable[i]);
    }
    free(data->byteTable);
    free(data);
}

void GetByteFrequency(Data *data)
{
    data->byteTable = malloc(data->nBytes * sizeof(ByteInfo *));

    for (int i = 0, j = 0; i < MAX_BYTES; i++)
    {
        if (data->byteFrequency[i] != 0)
        {
            data->byteTable[j] = malloc(sizeof(ByteInfo));
            data->byteTable[j]->byte = i;
            data->byteTable[j]->frequency = data->byteFrequency[i];
            j++;
        }
    }
}

void PrintByteTable(Data *data)
{
    for (int i = 0; i < data->nBytes; i++)
    {
        printf("Byte: %d, Frequência: %d\n", data->byteTable[i]->byte, data->byteTable[i]->frequency);
    }
}
