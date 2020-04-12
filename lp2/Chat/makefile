all: server client

server: src/server.c
	gcc -o server src/server.c src/List.c -pthread

client: src/client.c
	gcc -o client src/client.c src/List.c -pthread
