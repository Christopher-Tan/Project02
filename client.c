#include "client.h"

int main() {
	int server = client_setup();
	char move[2];
	read(server, move, sizeof(move));
	int turn = move[1] % 2;
	while (1) {
		if (turn) {
			//move is taken from interface and written to other client
			//check win
			write(server, move, sizeof(move));
		} else {
			read(server, move, sizeof(move));
			//check win
			if (!move[0] && !move[1]) {
				return 0;
			}
			//display move
		}
		//display win, if applicable
		turn = !turn;
	}
	return 0;
}
//x = 1; o = 2;
int victory(char board[9][9]) {
	int i, j;
	for (i = 0; i < 9; i++) {
		//rows
		for (j = 0; j < 3; j++) {
			if (board[i][3*j+0] == board[i][3*j+1] && board[i][3*j+1] == board[i][3*j+2] && board[i][3*j] != 0) {
				return board[i][3*j];
			}
		}
		//column
		for (j = 0; j < 3; j++) {
		}
	}
	return 0;
}
