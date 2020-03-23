#include "Stack.h"

void StackInitialize(Stack *s, size_t element_size)
{
    s->top = -1;
    s->element_size = element_size;
    s->data = (void *)malloc(MAX_STACK_SIZE * s->element_size);
}

void StackDestroy(Stack *s)
{
    free(s->data);
    free(s);
}

void StackPush(Stack *s, void *T)
{
    void *pos = (char *)(s->data + ++s->top * s->element_size);
    memcpy(pos, T, s->element_size);
}

void *StackTop(Stack *s)
{
    if (s->top == -1)
        exit(0);

    return (char *)s->data + s->top * s->element_size;
}

void *StackPop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        exit(0);
    }

    return (char *)s->data + s->top-- * s->element_size;
}