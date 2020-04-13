#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <thread>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <vector>

#define MAX_CLIENTS 100

using namespace std;

class Server
{
	
};

void answer_client(int client_fd)
{
	char msg[100];

	while (1)
	{
		bzero(msg, 100);
		read(client_fd, msg, 100);
		cout << "Recebi do cliente: " << string(msg) << flush;
		write(client_fd, msg, strlen(msg) + 1);
	}
}

thread answer_thread[MAX_CLIENTS];

int main(int argc, char **argv)
{
	int server_port = atoi(argv[1]);
	string server_name = string(argv[2]);

	cout << "Iniciando bate-papo " << server_name << " na porta " << server_port << endl;

	/* Construção do servidor */
	struct sockaddr_in server_addr;
	int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(server_port);

	bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	listen(listen_fd, MAX_CLIENTS);

	int thread_count = 0;

	while (1)
	{
		struct sockaddr_in client_addr;
		int client_addr_len = sizeof(client_addr);
		int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
		cout << inet_ntoa(client_addr.sin_addr) << flush;

		answer_thread[thread_count++] = thread(answer_client, client_fd);
	}

	return 0;
}
