#include <SDL2/SDL.h>

int main(int argc, char **argv) {

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Event event;
    bool running = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return 0;
    }

    window = SDL_CreateWindow("GameEmulator v0.0", 50, 50, 640, 480, SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    surface = SDL_LoadBMP("assets/tiles/sr_tiles.bmp");
    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255));
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    while(running) {
        SDL_Rect tile1, tile2, pos1, pos2;

        tile1.w = tile2.w = 64;
        tile1.h = tile2.h = 33;
        tile1.y = tile2.y = 0;
        tile1.x = 0;
        tile2.x = 64;

        pos1.x = pos1.y = 10;
        pos2.x = 10 + 32;
        pos2.y = 10 + 16;

        pos1.w = pos2.w = 64;
        pos1.h = pos2.h = 32;

        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE) {
                            running = false;
                    }
                    break;
            }
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, texture, &tile1, &pos1);
        SDL_RenderCopy(renderer, texture, &tile2, &pos2);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
