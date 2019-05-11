#include <SDL2/SDL.h>

int main(int argc, char **argv) {

    SDL_Window *window;
    SDL_Event event;
    bool running = true;

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return 0;
    }

    window = SDL_CreateWindow("GameEmulator v0.0", 50, 50, 640, 480, SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_SHOWN);

    while(running) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE) {
                            running = false;
                    }
                    break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
