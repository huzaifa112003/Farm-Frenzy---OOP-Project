#include "egg.hpp"
// Pig implementation will go here.

void egg::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


egg::egg(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  food(rend, texture) { // overloaded constructor
    srcRect = {0, 2, 218, 212};
    moverRect = {x, y, 30, 40}; // egg drawn at x,y coordinates
}