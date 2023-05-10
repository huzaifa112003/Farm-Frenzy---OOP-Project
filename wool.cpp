#include "wool.hpp"

void wool::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


wool::wool(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  food(rend, texture) { // constructor
    srcRect={350,1554,112,83};
    moverRect = {x, y, 30, 40}; // wool drawn at x,y coordinates
}

char wool::type(){
    return 'w';
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