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

int main()
{
    int v[] = {1, 55, 3, 6, 4, 5};

    printf("%d\n", greatestNum(v, 5));
    printf("%d\n", recursivePower(3, 4));
}