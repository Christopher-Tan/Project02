#include "render.h"
const SDL_Color GRID_COLOR = {.r = 255, .g = 255 , .b = 255};
const SDL_Color X_COLOR = { .r = 255, .g = 0, .b = 0};
const SDL_Color O_COLOR = { .r = 50 , .g = 100, .b = 255};
const SDL_Color TIE_COLOR = { .r = 100, .g = 100, .b = 100};
void render_grid(SDL_Renderer * renderer, const SDL_Color *color){
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 255);
    
    int i;
    for (i = 1; i < 9; i++){
        SDL_RenderDrawLine(renderer, CELL_WIDTH * i, 0, i * CELL_WIDTH, SCREEN_HEIGHT);
    }
    for (i = 1; i < 9; i++){
        SDL_RenderDrawLine(renderer, 0, CELL_HEIGHT * i, SCREEN_WIDTH, i * CELL_HEIGHT);
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    for (i = 1; i < 3; i++){
        SDL_RenderDrawLine(renderer, 3 * CELL_WIDTH * i, 0, 3 * CELL_WIDTH * i, SCREEN_HEIGHT);
    }
    for (i = 1; i < 3; i++){
        SDL_RenderDrawLine(renderer,0, 3 * CELL_HEIGHT * i, SCREEN_WIDTH, 3 * CELL_HEIGHT * i);
    }
}
void render_x(SDL_Renderer * renderer, int box, int row, int column, const SDL_Color * color){
    float half_box_side = fmin(CELL_WIDTH, CELL_HEIGHT) * 0.25;
    float center_x = CELL_WIDTH * 0.5 + 3 * (box % 3) * CELL_WIDTH + column * CELL_WIDTH;
    float center_y = CELL_HEIGHT * 0.5 + 3 * (box / 3 ) * CELL_HEIGHT + row* CELL_HEIGHT;
    SDL_SetRenderDrawColor(renderer, color -> r, color -> g, color -> b, 255);
    SDL_RenderDrawLine(renderer, center_x - half_box_side, center_y - half_box_side, center_x + half_box_side, center_y + half_box_side);
    SDL_RenderDrawLine(renderer, center_x + half_box_side, center_y - half_box_side, center_x - half_box_side, center_y + half_box_side);
}
void draw_circle(SDL_Renderer * renderer, int centreX, int centreY, int radius, const SDL_Color *color)
{
   const int diameter = (radius * 2);

   int x = (radius - 1);
   int y = 0;
   int tx = 1;
   int ty = 1;
   int error = (tx - diameter);
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 255);
   while (x >= y)
   {
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}
void render_o(SDL_Renderer * renderer, int box, int row, int column, const SDL_Color * color){
    float half_box_side = fmin(CELL_WIDTH, CELL_HEIGHT) * 0.35;
    float center_x = CELL_WIDTH * 0.5 + 3 * (box % 3) * CELL_WIDTH + column * CELL_WIDTH;
    float center_y = CELL_HEIGHT * 0.5 + 3 * (box / 3 ) * CELL_HEIGHT + row* CELL_HEIGHT;
    draw_circle(renderer, center_x, center_y, half_box_side, color);
    
}
void render_board(SDL_Renderer * renderer, const int board[9][9], const SDL_Color *player_x_color, const SDL_Color *player_o_color){
    int i;
    int j;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            switch (board[i][j]){
                case PLAYER_X:
                    render_x(renderer, i, j / 3, j % 3,player_x_color);
                    break;
                case PLAYER_O:
                    render_o(renderer, i, j / 3, j % 3,player_o_color);
            }
        }
    }
    
    
    
}
void render_running_state(SDL_Renderer * renderer, const struct game_t *game){
    render_grid(renderer, &GRID_COLOR);
    render_board(renderer, game-> board, &X_COLOR, &O_COLOR);
    
}

void render_game_over(SDL_Renderer * renderer, const struct game_t * game, const SDL_Color * color){
    render_grid(renderer, color);
    render_board(renderer, game -> board, color, color );
    
}
void rendering_game(SDL_Renderer * renderer, const struct game_t *game){
    switch (game->state){
        case RUNNING_STATE:
            render_running_state(renderer,game);
            break;
        case X_PLAYER_WON:
            render_game_over(renderer, game, &X_COLOR);
            break;
        case O_PLAYER_WON:
            render_game_over(renderer, game, &O_COLOR);
            break;
        case TIE:
            render_game_over(renderer, game, &TIE_COLOR);
            break;
            
            
    }
}
