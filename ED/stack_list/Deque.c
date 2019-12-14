#include "Deque.h"

void DequeInitialize(Deque *deque)
{
    deque->left = MAX_DEQUE_SIZE/2+1;
    deque->right = MAX_DEQUE_SIZE/2;
    deque->size = 0;
    deque->max_size = MAX_DEQUE_SIZE;
}

void DequePushLeft(Deque *deque, char c)
{
    deque->size++;
    deque->left = ((deque->left - 1) % deque->max_size + deque->max_size) % deque->max_size;
    deque->data[deque->left] = c;
}
void DequePushRight(Deque *deque, char c)
{
    deque->size++;
    deque->right = (deque->right + 1) % deque->max_size;
    deque->data[deque->right] = c;
}
char DequePopLeft(Deque *deque)
{
    char c = deque->data[deque->left];
    deque->size--;
    deque->left = (deque->left + 1) % deque->max_size;
    return c;
}
char DequePopRight(Deque *deque)
{
    char c = deque->data[deque->right];
    deque->size--;
    deque->right = ((deque->right - 1) % deque->max_size + deque->max_size) % deque->max_size;
    return c;
}