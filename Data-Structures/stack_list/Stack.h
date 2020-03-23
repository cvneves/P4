#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define MAX_STACK_SIZE 10000

typedef struct stack
{
    int top;
    void *data;
    size_t element_size;
} Stack;

void StackInitialize(Stack *s, size_t element_size);
void StackDestroy(Stack *s);
void StackPush(Stack *s, void *T);
void *StackTop(Stack *s);
void *StackPop(Stack *s);

#endif
