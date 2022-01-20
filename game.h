//
//  game.h
//  SDL PLS WORK
//
//  Created by Theodore Fahey on 1/17/22.
//
#include <SDL2/SDL.h>
#ifndef game_h
#define game_h
#include <stdlib.h>
#include <stdio.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define C 3
#define RUNNING_STATE 0
#define X_PLAYER_WON 1
#define O_PLAYER_WON 2
#define TIE 3
#define QUIT_STATE 4
#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2
#define CELL_HEIGHT (SCREEN_HEIGHT / 9)
#define CELL_WIDTH (SCREEN_WIDTH / 9)

struct game_t {
    int board[9][9];
    int player;
    int state;
    int lastbox; 
};

#endif /* game_h */
