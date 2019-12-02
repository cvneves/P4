#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Stack.h"

int main()
{
    char str[100];

    printf("Digite a expressao\n");
    scanf("%s", str);

    Stack *s = (Stack *)malloc(sizeof(Stack));

    StackInitialize(s, sizeof(char));

    int i = 0;
    char c;
    while ((c = str[i]) != '\0')
    {
        if (c == '(')
        {
            StackPush(s, &c);
        }
        else
        {
            if (s->top < 0)
            {
                printf("Invalid expression\n");
                return 0;
            }
            StackPop(s);
        }
        i++;
    }

    if(s->top == -1)
    {
        printf("Expression is valid\n");
    }
    else
    {
        printf("Invalid expression\n");
    }

    StackDestroy(s);
}