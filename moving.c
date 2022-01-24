#include "moving.h"

int on_click(struct game_t *game, int row, int column, char move[2]) {
    int outerbox = (column / 3) + 3 * (row / 3);
    row = row % 3;
    column = column % 3;
    int innerbox = row * 3 + column;
    move[0] = outerbox;
    move[1] = innerbox;
    return edit_board(game, outerbox, innerbox, game -> player);
}

int edit_board(struct game_t *game, int outerbox, int innerbox, int player) {
    if (game -> board[outerbox][innerbox] || !(outerbox == game -> lastbox || game -> lastbox == -1)) {
        return 0;
    } else {
        game -> board[outerbox][innerbox] = player;
        game -> lastbox = innerbox;
        int i;
        for (i = 0; i < 9; i++) {
            if (!(game -> board[innerbox][i])) {
                return 1;
            }
        }
        game -> lastbox = -1;
        return 1;
    }
}
