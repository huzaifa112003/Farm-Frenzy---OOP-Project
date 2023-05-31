#include "milk.hpp"

void milk::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


milk::milk(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  food(rend, texture) { // overloaded constructor
    // srcRect = {557, 1457, 49, 39};
    srcRect={277,1556,52,107};
    //srcRect = {0, 2, 218, 212};
    moverRect = {x, y, 30, 40}; // milk drawn at x,y coordinates
}
char milk::type(){
    return 'm';
}
int milk::getX() const {
    return moverRect.x;
}

int milk::getY() const {
    return moverRect.y;
}

int milk::getWidth() const {
    return moverRect.w;
}

int milk::getHeight() const {
    return moverRect.h;
}