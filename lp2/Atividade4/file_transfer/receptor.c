#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char** argv)
{

	int server_fd, port, recv_bytes = -1; //file descriptor do socket, porta e bytes recebidos
	char buffer;					 // buffer que armazenara mensagem recebida
	struct sockaddr_in server_addr;  //estrutura que armazena informacoes do socket

	// port = 9000;
	port = atoi(argv[1]);

	server_fd = socket(AF_INET, SOCK_DGRAM, 0); //crio o socket UDP

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr.s_addr = INADDR_ANY; //Defino a recepcao de pacotes de qualquer origem

	bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)); //associo estrutura ao socket

	FILE *fp = fopen("arquivo_recebido.txt", "wb");

	while(recv_bytes != 0)
	{
		// printf("Aguardando por mensagens UDP na porta %d...\n", port);
		recv_bytes = recvfrom(server_fd, &buffer, 1, MSG_WAITALL,
							  NULL, NULL); //funcao recvfrom bloqueante, recebe mensagens UDP e armazena em buffer
		// printf("Recebi: %d bytes\n", recv_bytes);
		// printf("Mensagem: %c\n", buffer); //Exibe buffer

		fwrite(&buffer, sizeof(char), 1, fp);
	} 

	fclose(fp);

	return 0;
}
