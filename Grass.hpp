#include "animal.hpp"
#include<SDL.h>

class Grass{
    SDL_Rect src, mover;
    SDL_Renderer* gRenderer;
    SDL_Texture* assets;
    public:
    Grass(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    void draw();
};