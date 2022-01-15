#include "server.h"
#include <sys/select.h>


int main() {
	int server = server_setup();
	
	fd_set read_fds;
	fd_set clients;
	
	FD_ZERO(&clients);
	FD_SET(server, &clients);
	int maxfd = server;
	
	while (1) {
		read_fds = clients;
		select(maxfd + 1, &read_fds, NULL, NULL, NULL);
		int fd = 0;
		for (; fd <= maxfd; fd++) {
			if (FD_ISSET(fd, &read_fds)) {
				if (fd == server) {
					int client = server_accept(server);
					FD_SET(client, &clients);
					if (client > maxfd) {
						maxfd = client;
					}
					//in case of second player, make a match and note down the pair
				} else {
					char move[2];
					if (read(fd, move, sizeof(move))) {
						//transfer move to other player (as determined by pairing, maybe add another check that the same client did not send two moves).
					} else {
						FD_CLR(fd, &clients);
						close(fd);
						//remove the other connected client as well.
					}
				}
			}
		}
	}
	close(server);
	return 0;
}
