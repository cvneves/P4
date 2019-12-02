#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void *WriteNumbers(void *n);

int n_random;

int main(int argc, char *argv[])
{
    int n_threads = atoi(argv[1]);
    n_random = atoi(argv[2]);

    pthread_t TID[n_threads];

    for(int i = 0; i < n_threads; i++)
    {
        pthread_create(&TID[i], NULL, WriteNumbers, (void *) i);
    }

    for(int i = 0; i < n_threads; i++)
    {
        pthread_join(TID[i], NULL);
    }
}

void *WriteNumbers(void *n)
{
    int tid = (int) n;
    char file_name[100];
    sprintf(file_name, "arquivos/arquivo_%d", tid);
    FILE *f = fopen(file_name, "w");
    for(int i = 0; i < n_random; i++)
    {
        // printf("%d\n", i);   
        fprintf(f, "%d\n", rand()%100);
    }

    // printf("\n\n");
    fclose(f);
    pthread_exit(NULL);
}