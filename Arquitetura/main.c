#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int n = pow(2, 3);
    for (int m = 1; m < n; m++)
    {
        printf("%d to %d\n", (m & (m - 1)) % 3, ((m | (m - 1)) + 1) % 3);
    }
}