#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

#include "SocketInfo.h"

pthread_mutex_t lock;

void *receive_message(void *param)
{
	int client_fd = *((int *)param);

	char recv_msg[100];

	while (1)
	{
		// pthread_mutex_lock(&lock);

		bzero(recv_msg, 100);
		read(client_fd, recv_msg, 100);
		printf("Recebi do servidor: %s", recv_msg);

		// pthread_mutex_unlock(&lock);
	}
}

int main(int argc, char **argv)
{
	char *username = argv[3];

	int client_fd;

	int port = atoi(argv[2]);

	char *host = argv[1];

	char send_msg[100];
	char recv_msg[100];

	struct sockaddr_in server_addr;

	client_fd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	inet_aton(host, &server_addr.sin_addr);

	printf("Conectando-se a porta %d do servidor %s\n", port, host);

	connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	pthread_t client_receive_thread;
	pthread_create(&client_receive_thread, NULL, (void *)receive_message, (void *)&client_fd);
	// pthread_join(client_receive_thread, NULL);

	while (1)
	{
		// pthread_mutex_lock(&lock);

		bzero(send_msg, 100);

		// printf("Digite sua mensagem: ");
		fgets(send_msg, 100, stdin);

		write(client_fd, send_msg, strlen(send_msg) + 1);

		// pthread_mutex_unlock(&lock);
	}

	return 0;
}
