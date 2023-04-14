#include "animal.hpp"
#include<SDL.h>

class Grass: public Animal{
    SDL_Rect src, mover;
    public:
    Grass(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov);

    void draw();
};