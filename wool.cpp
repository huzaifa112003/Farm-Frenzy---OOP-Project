#include "wool.hpp"
// Pig implementation will go here.

void wool::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


wool::wool(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  food(rend, texture) { // overloaded constructor
    //srcRect = {557, 1457, 49, 39};
    srcRect={22,1558,89,107};
    //srcRect = {0, 2, 218, 212};
    moverRect = {x, y, 30, 40}; // wool drawn at x,y coordinates
}
int wool::getX() const {
    return moverRect.x;
}

int wool::getY() const {
    return moverRect.y;
}

int wool::getWidth() const {
    return moverRect.w;
}

int wool::getHeight() const {
    return moverRect.h;
}