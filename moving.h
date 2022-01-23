#ifndef moving_h
#define moving_h
#include "game.h"
#include <stdio.h>

int on_click(struct game_t *game, int row, int column, char move[2]);
int edit_board(struct game_t *game, int outerbox, int innerbox, int player);
#endif
