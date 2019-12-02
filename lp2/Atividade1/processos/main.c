#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int n_processos = atoi(argv[1]);
    int n_random = atoi(argv[2]);

    char file_name[100];
    FILE *f;

    int np = 0;

    for(int i = 0; i < n_processos; i++)
    {
        if(fork() == 0)
        {
            np = i;
            break;
        }
    }
    srand(time(NULL) + np);
    sprintf(file_name, "arquivos/arquivo_%d", np);
    f = fopen(file_name, "w");


    for(int i = 0; i < n_random; i++)
    {
        fprintf(f, "%d\n", rand()%100);
    }

    fclose(f);
    return 0;
}