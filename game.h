#include <SDL2/SDL.h>
#ifndef game_h
#define game_h
#include <stdlib.h>
#include <stdio.h>
#include "render.h"
#include "moving.h"
#define SCREEN_WIDTH 801
#define SCREEN_HEIGHT 603
#define C 3
#define RUNNING_STATE 0
#define WON 1
#define LOST 2
#define TIE 3
#define QUIT_STATE 4
#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2
#define CELL_HEIGHT (SCREEN_HEIGHT / 9)
#define CELL_WIDTH (SCREEN_WIDTH / 9)

struct game_t {
    char board[9][9];
    int player;
    int state;
    int lastbox; 
};

#endif
