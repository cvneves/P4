#ifndef DEQUE_H
#define DEQUE_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_DEQUE_SIZE 10

typedef struct Deque
{
    char data[MAX_DEQUE_SIZE];
    int left, right;
    int size;
    int max_size;
} Deque;

void DequeInitialize(Deque *deque);
void DequePushLeft(Deque *deque, char c);
void DequePushRight(Deque *deque, char c);
char DequePopLeft(Deque *deque);
char DequePopRight(Deque *deque);

#endif