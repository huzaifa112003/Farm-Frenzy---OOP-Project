#include "egg.hpp"
// Pig implementation will go here.

void egg::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


egg::egg(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  food(rend, texture) { // overloaded constructor
    srcRect = {557, 1457, 49, 39};
    //srcRect = {0, 2, 218, 212};
    moverRect = {x, y, 30, 40}; // egg drawn at x,y coordinates
}
int egg::getX() const {
    return moverRect.x;
}

int egg::getY() const {
    return moverRect.y;
}

int egg::getWidth() const {
    return moverRect.w;
}

int egg::getHeight() const {
    return moverRect.h;
}