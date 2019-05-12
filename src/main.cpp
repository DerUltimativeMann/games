#include "map.h"


int main(int argc, char **argv) {

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    Map *karte;
    bool running = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return 0;
    }

    window = SDL_CreateWindow("GameEmulator v0.0", 50, 50, 640, 480, SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    karte = new Map(renderer, "assets/tiles/tile_grass.bmp");

    while(running) {

        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            running = false;
                            break;

                        case SDLK_RIGHT:
                            karte->setPosX(karte->getPosX() + 1);
                            break;
                        case SDLK_LEFT:
                            karte->setPosX(karte->getPosX() - 1);
                            break;

                        case SDLK_DOWN:
                            karte->setPosY(karte->getPosY() + 1);
                            break;
                        case SDLK_UP:
                            karte->setPosY(karte->getPosY() - 1);
                            break;
                    }
                    break;
            }
        }

        SDL_RenderClear(renderer);

        karte->render(renderer);

        SDL_RenderPresent(renderer);
    }

    delete karte;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
