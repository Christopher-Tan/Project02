#include "networking.h"

int server_setup() {
	struct addrinfo *hints, *results;
	hints = calloc(1, sizeof(struct addrinfo));
	hints -> ai_family = AF_INET;
	hints -> ai_socktype = SOCK_STREAM;
	hints -> ai_flags = AI_PASSIVE;
	getaddrinfo(NULL, PORT, hints, &results);
	
	int sd = socket(results -> ai_family, results -> ai_socktype, results -> ai_protocol);
	bind(sd, results -> ai_addr, results -> ai_addrlen);
	
	listen(sd, 256);
	
	free(hints);
	freeaddrinfo(results);
	return sd;
}

int server_accept(int sd) {
	int client_socket;
	socklen_t sock_size;
	struct sockaddr_storage client_address;
	
	sock_size = sizeof(client_address);
	client_socket = accept(sd, (struct sockaddr *) &client_address, &sock_size);
	return client_socket;
}
