#include "Exercise.h"

int Exercise1()
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

    if (s->top == -1)
    {
        printf("Expression is valid\n");
    }
    else
    {
        printf("Invalid expression\n");
    }

    StackDestroy(s);
}

int Exercise2()
{
    char str[100];
    printf("String: ");
    fgets(str, 100, stdin);

    Stack *s = (Stack *)malloc(sizeof(Stack));
    StackInitialize(s, sizeof(char));

    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];
        StackPush(s, &c);
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = *((char *)StackPop(s));
    }

    printf("%s\n", str);

    StackDestroy(s);
}

int Exercise4()
{
    char str[100];
    printf("Expression: ");
    // fgets(str, 100, stdin);
    scanf("%s", str);

    Stack *s = (Stack *)malloc(sizeof(Stack));
    StackInitialize(s, sizeof(int));

    for (int i = 0; i < strlen(str); i++)
    {
        int x = 0;
        if (str[i] - 48 >= 0 && str[i] - 48 <= 9)
        {
            x = str[i] - 48;
            StackPush(s, &x);
        }
        else
        {
            int a = *((int *)StackPop(s));
            int b = *((int *)StackPop(s));
            int c = 0;
            switch (str[i])
            {
            case '+':
                c = a + b;
                break;
            case '-':
                c = b - a;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                c = b / a;
                break;
            }
            StackPush(s, &c);
        }
    }

    printf("%d\n", *((int *)StackTop(s)));

    StackDestroy(s);

    return 0;
}