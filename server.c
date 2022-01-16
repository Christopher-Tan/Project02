#include "server.h"
#include <sys/select.h>

struct node * insert_node(struct node* start, int fd1, int fd2) {
    struct node *n = malloc(sizeof(struct node));
    n -> fd1 = fd1;
    n -> fd2 = fd2;
    n -> next = start;
    return n;
}

struct node * search(struct node* start, int fd) {
    while (start) {
        if (start -> fd1 == fd || start -> fd2 == fd) {
            return start;
        }
        start = start -> next;
    }
    return NULL;
}

struct node * remove_node(struct node* start, struct node* node) {
    if (!start) {
        return NULL;
    }
    if (start == node) {
        struct node *temp = start -> next;
        free(start);
        return temp;
    }
    struct node *s = start;
    while (start -> next) {
        if (start -> next == node) {
            struct node *temp = start -> next -> next;
            free(start -> next);
            start -> next = temp;
        }
        start = start -> next;
    }
    return s;
}

int opponent(struct node* start, int fd) {
	struct node *pairing = search(start, fd);
	if (pairing -> fd1 == fd) {
		return pairing -> fd2;
	} else {
		return pairing -> fd1;
	}
}

int main() {
	int server = server_setup();
	
	struct node *matches = NULL;
	int queue[1] = {0};

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
					//in case of second player, make a match and note down the pair if not, add to queue.
					if (queue[0]) {
						char move[2] = {0,1};
						matches = insert_node(matches, queue[0], client);
						write(queue[0], move, sizeof(move));
						move[1] = 2;
						write(client, move, sizeof(move));
						printf("%d and %d paired\n", queue[0], client);
						queue[0] = 0;
					} else {
						queue[0] = client;
						printf("%d queuing\n", client);
					}
				} else {
					char move[2];
					if (read(fd, move, sizeof(move))) {
						//transfer move to other player (as determined by pairing, maybe add another check that the same client did not send two moves).
						write(opponent(matches, fd), move, sizeof(move));
					} else {
						printf("Hi\n");
						struct node *pairing = search(matches, fd);
						printf("Hi\n");
						FD_CLR(fd, &clients);
						close(fd);
						printf("Hi\n");
						if (pairing) {
							//remove the other connected client as well.
							int opp = opponent(matches, fd);
							printf("Hi\n");
							FD_CLR(opp, &clients);
							close(opp);
							printf("Hi\n");
							remove_node(matches, pairing);
							printf("Hi\n");
							printf("%d and %d disconnected\n", fd, opp);
						} else {
							queue[0] = 0;
							printf("%d left the queue\n", fd);
						}
					}
				}
			}
		}
	}
	close(server);
	return 0;
}
