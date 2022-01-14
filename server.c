#include "server.h"
#include <sys/select.h>

int main() {
	int counter = 0;
	int server = server_setup();
	
	fd_set read_fds;
	fd_set clients;
	
	FD_ZERO(&clients);
	FD_SET(server, &clients);
	int maxfd = listen_socket;
	
	while (1) {
		read_fds = clients;
		select(maxfd + 1, &read_fds, NULL, NULL, NULL);
		
	}
}
