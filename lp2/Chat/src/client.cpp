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

using namespace std;



int main(int argc, char **argv)
{
	int port = atoi(argv[2]);
	string user_name = string(argv[3]);
	char *host = argv[1];

	/* Construção do cliente */
	int client_fd = socket(AF_INET, SOCK_STREAM, 0);

	char send_msg[100];
	char recv_msg[100];

	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	inet_aton(host, &server_addr.sin_addr);

	cout << "Conectand-se ao servidor " << string(host) << " na porta " << port << endl;

	connect(client_fd, (struct sockaddr*) &server_addr, sizeof(server_addr));

	while(1)
	{
		bzero(send_msg, 100);
		bzero(recv_msg, 100);

		cout << "Digite sua msg: ";
		fgets(send_msg, 100, stdin);

		write(client_fd, send_msg, strlen(send_msg) + 1);
		read(client_fd, recv_msg, 100);

		cout << "Recebi do server: " << string(recv_msg) << flush;
	}
	


	return 0;
}
