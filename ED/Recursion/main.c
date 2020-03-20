#include <stdlib.h>
#include <stdio.h>

#include <string.h>

int maximum(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int greatestNum(int *v, int size)
{
    if (size == 1)
        return v[0];

    return maximum(v[size - 1], greatestNum(v, size - 1));
}

int recursivePower(int x, int y)
{
    if (y == 1)
        return x;
    return x * recursivePower(x, y - 1);
}

int isPalindrome(char *str)
{
    if (strlen(str) == 1)
        return 1;
}

int *binarySearch(int *v, int size, int value)
{
    if (size == 0 && v[0] == value)
        return v;

    size /= 2;

    if (v[size] < value)
        v += size;
    binarySearch(v + size + 1, size, value);
}

int main()
{
    int v[] = {1,2,3,4,5,6,7,8};

    printf("%d\n", (binarySearch(v, 7, 8) - v)/sizeof(int) );

    // printf("%d\n", greatestNum(v, 6));
    // printf("%d\n", recursivePower(3, 4));
}