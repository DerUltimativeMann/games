#ifndef _MAP_H
#define _MAP_H

#include <SDL2/SDL.h>

/* Tile Types */
#define TYLETYPE_EMPTY  0
#define TYLETYPE_GRASS  1

#define MAP_WIDTH   100
#define MAP_HEIGHT  50

typedef struct {
    char type;
}Tile;

class Map {
    private:
        Tile tiles[MAP_WIDTH][MAP_HEIGHT];
        SDL_Texture *tilemap;

        int posX;
        int posY;

    public:
        Map();
        Map(SDL_Renderer *renderer, const char *path);
        ~Map();

        void render(SDL_Renderer *renderer);
        void update();

        void setPosX(int posX);
        void setPosY(int posY);

        int getPosX() const;
        int getPosY() const;
};

#endif
