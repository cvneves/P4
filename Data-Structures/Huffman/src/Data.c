#include "Data.h"

void ReadData(Data *data, char *fileName)
{
    for (int i = 0; i < MAX_BYTES; i++)
    {
        data->byteFrequency[i] = 0;
    }

    FILE *fp = fopen(fileName, "rb");
    unsigned char c;

    data->nBytes = 0;

    while (fread(&c, sizeof(char), 1, fp) == 1)
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
    double average = 0.0;
    double sumFreq = 0;
    double p[data->nBytes];
    double entropy = 0;

    for (int i = 0; i < data->nBytes; i++)
    {
        sumFreq += data->byteTable[i]->frequency;
        // printf("Byte: %d, Frequência: %d\n",(unsigned char) data->byteTable[i]->byte, data->byteTable[i]->frequency);
    }
    for (int i = 0; i < data->nBytes; i++)
    {
        p[i] = (double)data->byteTable[i]->frequency / sumFreq;
        entropy -= p[i] * (log10(p[i]) / log10(data->nBytes));

        // printf("p[%d] = %lf\n", i, p[i]);
    }

    printf("Entropy: %lf\n", entropy);
}
