#include "Deque.h"

void DequeInitialize(Deque *deque)
{
    deque->left = 1;
    deque->right = 0;
    deque->size = 0;
    deque->max_size = MAX_DEQUE_SIZE;
    deque->data = (char *)malloc(MAX_DEQUE_SIZE * sizeof(char));
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

    if (deque->size > deque->max_size)
    {

        char *temp = (char *)malloc(2 * deque->max_size * sizeof(char));

        {
            int i = 0;
            int a = deque->left;
            while (i < deque->size)
            {
                temp[i++] = deque->data[a];
                a = (a + 1) % deque->max_size;
            }
            deque->right = deque->size - 2;
            deque->left = 0;
        }

        free(deque->data);
        deque->data = temp;

        deque->max_size *= 2;
    }

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