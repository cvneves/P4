#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>

typedef struct ClientInfo
{
	int client_fd;
	struct sockaddr_in client_addr;
} ClientInfo;

void *responde_cliente(void *param)
{
	ClientInfo *client_info = (ClientInfo *)param;

	char user_name[100];

	read(client_info->client_fd, user_name, 100);
	printf("%s se conectou com o IP %s\n", user_name, inet_ntoa(client_info->client_addr.sin_addr));

	char msg[100];

	while (1)
	{
		bzero(msg, 100);									  // inicializa a mensagem com 0
		read(client_info->client_fd, msg, 100);				  // le mensagem do socket cliente associado
		printf("%s enviou uma mensagem: %s", user_name, msg); // exibe o que recebeu do cliente
		write(client_info->client_fd, msg, strlen(msg) + 1);  // envia de volta a mesma mensgem
	}
}

/* Um servidor de eco. Tudo que este servidor receber de um cliente, ele enviara de volta */

int main(int argc, char **argv)
{
	char msg[100];

	int server_port = atoi(argv[1]);
	char *nome_bate_papo = argv[2];

	printf("Iniciando %s na porta %d...\n", nome_bate_papo, server_port);

	int listen_fd;
	// int client_fd; // dois file descriptors, 1 para ouvir solicitacoes, outro para o cliente

	struct sockaddr_in server_addr; // struct com informacoes para o server socket

	pthread_t threads[10]; // array que armazenara 10 threads (MAXIMO DE CLIENTES)

	int thread_count = 0; // contador de threads (de clientes)

	listen_fd = socket(AF_INET, SOCK_STREAM, 0); // listen_fd representa o socket que aguardara requisicoes

	bzero(&server_addr, sizeof(server_addr)); // Inicializa a estrutura do servidor sockaddr_in com 0

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;  // Constante sinaliza que o socket sera um servidor
	server_addr.sin_port = htons(server_port); // Porta a ser associada ao socket servidor criado

	bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)); // associa parametros definidos

	listen(listen_fd, 10); // sinaliza que aguardara conexoes na porta associada

	while (1)
	{
		// client_fd = accept(listen_fd, (struct sockaddr *)NULL, NULL); // funcao bloqueante, gera novo socket
		int c = sizeof(struct sockaddr_in);

		ClientInfo *client_info = malloc(sizeof(ClientInfo));

		bzero(&(client_info->client_addr), sizeof(client_info->client_addr));
		client_info->client_fd = accept(listen_fd, (struct sockaddr *)&(client_info->client_addr), &c); // funcao bloqueante, gera novo socket

		pthread_create(&threads[thread_count++], NULL, (void *)responde_cliente, (void *)client_info);
		// printf("Se conectou com IP %s\n", inet_ntoa(client_addr.sin_addr));
	}

	return 0;
}
