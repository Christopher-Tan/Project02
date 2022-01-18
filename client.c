#include "client.h"

int main() {
	int server = client_setup();
	char move[2];
	read(server, move, sizeof(move));
	int turn = move[1] % 2;
	while (1) {
		if (turn) {
			//move is taken from interface and written to other client
			write(server, move, sizeof(move));
		} else {
			read(server, move, sizeof(move));
			if (!move[0] && !move[1]) {
				return 0;
			}
			//display move
		}
		turn = !turn;
	}
	return 0;
}
