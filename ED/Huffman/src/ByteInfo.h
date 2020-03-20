#ifndef BYTEINFO_H
#define BYTEINFO_H

typedef struct ByteInfo
{
    char byte;
    int frequency;
} ByteInfo;

void MergeSortByteInfo(ByteInfo** arr, int l, int r);
void MergeByteInfo(ByteInfo** arr, int l, int m, int r);

#endif