#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;
sem_t dormir;
int indice_string = 0;
char caracter;

void *threadProdutor(void *arg)
{
	char str[] = "ABRACADABRA SIMSALABIM";

	for (int i = 0; i <= strlen(str); i++)
	{
		sem_wait(&mutex);
		caracter = str[i];
		printf("Enviando o caracter %c\n", caracter);
		sem_post(&mutex);
		sleep(1);
	}
}

void *threadConsumidor(void *arg)
{
	char str[100] = {0};

	int i = 0;
	while (1)
	{
		sem_wait(&mutex);

		printf("Recebendo o caracter %c\n", caracter);
		str[i++] = caracter;
		if (!caracter)
		{
			break;
		}
		sem_post(&mutex);
		sleep(1);
	}

	printf("%s\n", str);
	sem_post(&mutex);
	sem_post(&dormir);
	sleep(1);
}

int main()
{
	sem_init(&mutex, 0, 1);
	sem_init(&dormir, 0, 0);
	pthread_t tp, tc;
	pthread_create(&tp, NULL, threadProdutor, NULL);
	pthread_create(&tc, NULL, threadConsumidor, NULL);
	
	// while (1)
		// ;
	sem_wait(&dormir);

	return 0;
}
