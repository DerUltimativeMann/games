#include "map.h"

Map::Map() {
    int x,y;
    Map::tilemap = NULL;
    Map::posX = Map::posY = 0;

    for(y=0; y < MAP_HEIGHT; y++) {
        for(x=0; x < MAP_WIDTH; x++) {
            Map::tiles[x][y].type = TYLETYPE_EMPTY;
        }
    }
}

Map::Map(SDL_Renderer *renderer, const char *path) {
    int x,y;
    SDL_Surface *surface = SDL_LoadBMP(path);
    Map::posX = Map::posY = 0;

    if(surface) {
        SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 255, 0, 255));
        Map::tilemap = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    for(y=0; y < MAP_HEIGHT; y++) {
        for(x=0; x < MAP_WIDTH; x++) {
            Map::tiles[x][y].type = TYLETYPE_GRASS;
        }
    }
}

Map::~Map() {
    SDL_DestroyTexture(tilemap);
}

void Map::render(SDL_Renderer *renderer) {
    SDL_Rect orig, dest;
    int x, y;

    orig.x = orig.y = 0;
    orig.w = 64;
    orig.h = 32;

    dest.w = 64;
    dest.h = 32;



    for(y=0; y < MAP_HEIGHT; y++) {
        for(x=0; x < MAP_WIDTH; x++)
            if(Map::tiles[x][y].type != TYLETYPE_EMPTY) {
                switch(Map::tiles[x][y].type) {
                    case TYLETYPE_GRASS:
                        orig.x = orig.y = 0;
                        break;
                }

                dest.x = dest.w/2 * x + Map::posX;
                dest.y = dest.h/2 * y + Map::posY;

                SDL_RenderCopy(renderer, tilemap, &orig, &dest);
            }
        }
    }
}

void Map::update() {
}


void Map::setPosX(int posX) {
    Map::posX = posX;
}

void Map::setPosY(int posY) {
    Map::posY = posY;
}

int Map::getPosX() const {
    return Map::posX;
}

int Map::getPosY() const {
    return Map::posY;
}
