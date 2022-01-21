#include "game.h"

int main(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
      printf("Initializing sdl2 failed%s\n", SDL_GetError());
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
    int i;
    int j;
    struct game_t game;
    game.player = PLAYER_X;
    game.state = RUNNING_STATE;
    game.lastbox = -1; 
    for (i = 0; i < 9; i++ ){
        for (j = 0; j < 9; j++){
            game.board[i][j] = EMPTY;
        }
    }
    const float cell_height = SCREEN_HEIGHT / 9;
    const float cell_width = SCREEN_WIDTH / 9;
    SDL_Event first;
    while(game.state != QUIT_STATE){
        while (SDL_PollEvent(&first)){
            switch (first.type){
                case SDL_QUIT:
                    game.state = QUIT_STATE;
                case SDL_MOUSEBUTTONDOWN:
                    on_click(&game, first.button.y / cell_height, first.button.x / cell_width);
                default: {}

            }
       }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        rendering_game(renderer, &game);
        SDL_RenderPresent(renderer);
        
   }
    SDL_DestroyWindow(window);
    SDL_Quit();
    
}
