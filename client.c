#include "client.h"
#include "game.h"

int main() {
	int server = client_setup();
	char move[2];
    read(server, move, sizeof(move));
	int turn = move[1] % 2;
	//SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
      printf("Initializing SDL2 failed%s\n", SDL_GetError());
      return EXIT_FAILURE;
    }
	SDL_Window * window = SDL_CreateWindow("Hello, SDL2", 100, 100, SCREEN_WIDTH,   SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
	if (window == NULL){
        printf("Create Window error %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL){
        SDL_DestroyWindow(window);
        printf("Renderer Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    struct game_t game = {{{}}, move[1], RUNNING_STATE, -1};
    SDL_Event first;
	SDL_PollEvent(&first);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    rendering_game(renderer, &game);
    SDL_RenderPresent(renderer);
	while (1) {
		if (turn) {
			int valid = 0;
			while (!valid) {
				while (SDL_PollEvent(&first)) {
					switch (first.type) {
						case SDL_QUIT:
							valid = 1;
							game.state = QUIT_STATE;
							break;
						case SDL_MOUSEBUTTONDOWN:
							valid = on_click(&game, first.button.y / CELL_HEIGHT, first.button.x / CELL_WIDTH, move);
							break;
						default: {}
					}
					break;
				}
			}
			write(server, move, sizeof(move));
		} else {
			read(server, move, sizeof(move));
			if (!move[0] && !move[1]) {
				return 0;
			}
            edit_board(&game, move[0], move[1], (game.player) % 2 + 1);
		}
        //if not quit
		game.state = victory(game.board);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        rendering_game(renderer, &game);
        SDL_RenderPresent(renderer);
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
			if (board[i][3*j] && board[i][3*j+0] == board[i][3*j+1] && board[i][3*j+1] == board[i][3*j+2]) {
				return board[i][3*j];
			}
		}
		//columns
		for (j = 0; j < 3; j++) {
			if (board[i][j] && board[i][j+0] == board[i][j+3] && board[i][j+3] == board[i][j+6]) {
				return board[i][j];
			}
		}
		//diagonal
		if (board[i][0] && board[i][0] == board[i][4] && board[i][4] == board[i][8]) {
			return board[i][0];
		}
		if (board[i][2] && board[i][2] == board[i][4] && board[i][4] == board[i][6]) {
			return board[i][2];
		}
	}
	return 0;
}
