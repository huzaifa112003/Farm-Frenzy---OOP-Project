#include "meat.hpp"
// Pig implementation will go here.

void meat::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


meat::meat(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  food(rend, texture) { // overloaded constructor
    srcRect = {557, 1457, 49, 39};
    //srcRect = {0, 2, 218, 212};
    moverRect = {x, y, 30, 40}; // egg drawn at x,y coordinates
}
int meat::getX() const {
    return moverRect.x;
}

int meat::getY() const {
    return moverRect.y;
}

int meat::getWidth() const {
    return moverRect.w;
}

int meat::getHeight() const {
    return moverRect.h;
}