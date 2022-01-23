#include "moving.h"
void switch_player(struct game_t *game){
    if (game -> player == PLAYER_X){
        game -> player = PLAYER_O;
    }
    else if (game -> player == PLAYER_O){
        game -> player = PLAYER_X;
    }
}
void player_turn(struct game_t *game, int box, int secondbox){
    if (game->board[box][secondbox] == EMPTY){
        if (box == game -> lastbox || game -> lastbox == -1){
            
        
            game->board[box][secondbox] = game -> player;
            game -> lastbox = secondbox;
            switch_player(game);
        }
    }
}
void on_click(struct game_t *game, int row, int column){
    if (game -> state == RUNNING_STATE){
        int box = (column / 3) + 3 * (row / 3);
        row = row % 3;
        column = column % 3;
        int secondbox = row * 3 + column;
        
        player_turn(game, box, secondbox);
    }
}
void reset_game(struct game_t * game){
    int i, j;
    for (i = 0; i < 9; i++ ){
        for (j = 0; j < 9; j++){
            game -> board[i][j] = EMPTY;
        }
    }
    game -> player = PLAYER_X;
    game -> state = RUNNING_STATE;
    
}
