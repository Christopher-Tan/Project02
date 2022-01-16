#include "client.h"

int main() {
	int server = client_setup();
	while (1) {
		char move[2];
		read(server, move, sizeof(move));
		if (!move[0] && !move[1]) {
			return 0;
		}
		printf("%d %d\n", move[0], move[1]);
	}
	return 0;
}
