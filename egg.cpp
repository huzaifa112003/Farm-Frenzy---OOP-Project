#include "egg.hpp"

void egg::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    //drawing the egg using grenderer, asset file, adress of srcrect, and the adress of its moverrect.
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect); 
}


egg::egg(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  food(rend, texture) { // constructor that also inherits the food class constructor
    
    srcRect={22,1558,89,107};
    moverRect = {x, y, 20, 30}; // egg drawn at x,y coordinates
}
int egg::getX() const {
    return moverRect.x; //returns x coordinate of egg.
}

int egg::getY() const {
    return moverRect.y; //returns y coordinate of egg.
}

int egg::getWidth() const {
    return moverRect.w; //returns width of egg.
}

int egg::getHeight() const {
    return moverRect.h; //returns height of egg.
}