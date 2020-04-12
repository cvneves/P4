#ifndef SOCKETINFO_H
#define SOCKETINFO_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "List.h"

typedef struct SocketInfo
{
	int socket_fd;
	struct sockaddr_in socket_addr;
} SocketInfo;

#endif