#ifndef render_h
#define render_h
#include "game.h"

void render_grid(SDL_Renderer * renderer, const SDL_Color *color);
void render_x(SDL_Renderer * renderer, int box, int row, int column, const SDL_Color * color);
void draw_circle(SDL_Renderer * renderer, int centreX, int centreY, int radius, const SDL_Color *color);
void render_o(SDL_Renderer * renderer, int box, int row, int column, const SDL_Color * color);
void render_board(SDL_Renderer * renderer, const char board[9][9], const SDL_Color *player_x_color, const SDL_Color *player_o_color);
void render_running_state(SDL_Renderer * renderer, struct game_t *game);
void render_lose(SDL_Renderer * renderer, struct game_t * game);
void render_game_over(SDL_Renderer * renderer, struct game_t * game, const SDL_Color * color);
void rendering_game(SDL_Renderer * renderer, struct game_t *game);
#endif
