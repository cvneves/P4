all: server client

server: src/server.cpp
	g++ -o server src/server.cpp -pthread

client: src/client.cpp
	g++ -o client src/client.cpp -pthread
