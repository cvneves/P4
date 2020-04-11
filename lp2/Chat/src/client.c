#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char *host = argv[1];
	int port = atoi(argv[2]);
	char *user_name = argv[3];

	printf("Apelido: %s\n", user_name);

	int client_fd;

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

	{
		strcpy(send_msg, user_name);
		write(client_fd, send_msg, strlen(send_msg) + 1);
	}

	while (1)
	{
		bzero(send_msg, 100);
		bzero(recv_msg, 100);

		printf("Digite algo para enviar ao servidor: ");
		fgets(send_msg, 100, stdin); //le do usuario string para enviar ao servidor

		write(client_fd, send_msg, strlen(send_msg) + 1);
		read(client_fd, recv_msg, 100); // le do servidor string para exibir para o usuario

		printf("Recebi do servidor: %s\n", recv_msg); // exibe o recebido na tela
	}

	return 0;
}
