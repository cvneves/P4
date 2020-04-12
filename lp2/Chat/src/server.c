#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

#include "SocketInfo.h"
#include "List.h"

List *client_list;

void *responde_cliente(void *param)
{

	int client_fd = *((int *)param);

	char msg[100];

	while (1)
	{
		bzero(msg, 100);
		read(client_fd, msg, 100);

		Node *node = client_list->head;

		printf("Recebi do cliente: %s", msg);

		while (node != NULL)
		{
			int c_fd = *((int *)node->data);
			if (c_fd == client_fd)
			{
				node = node->next;
				continue;
			}
			write(c_fd, msg, strlen(msg) + 1);
			node = node->next;
		}
	}
}

int main(int argc, char **argv)
{
	client_list = ListInitialize();

	char msg[100];

	int server_port = atoi(argv[1]);
	char *servername = argv[2];

	int listen_fd;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	pthread_t threads[10];

	int thread_count = 0;

	printf("Loading...\n");

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&server_addr, sizeof(server_addr));
	bzero(&client_addr, sizeof(client_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(server_port);

	bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	listen(listen_fd, 10);

	printf("Aguardando conexoes na porta %d\n", server_port);

	while (1)
	{
		int *client_fd = malloc(sizeof(int));
		*client_fd = accept(listen_fd, (struct sockaddr *)NULL, NULL);
		pthread_create(&threads[thread_count++], NULL, (void *)responde_cliente, (void *)client_fd);
		ListAppend(client_list, client_fd);
	}

	return 0;
}
