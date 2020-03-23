#include "ByteInfo.h"

void MergeSortByteInfo(ByteInfo **arr, int l, int r)
{
    if (l < r)
    {
        int m = (l+r)/2;

        
        MergeSortByteInfo(arr, l, m);
        MergeSortByteInfo(arr, m + 1, r);


        MergeByteInfo(arr, l, m, r);
    }
}

void MergeByteInfo(ByteInfo **arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    ByteInfo *L[n1], *R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i]->frequency <= R[j]->frequency)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}