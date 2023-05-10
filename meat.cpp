#include "meat.hpp"

void meat::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    //drawing the meat using grenderer, asset file, adress of srcrect, and the adress of its moverrect.
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


meat::meat(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  food(rend, texture) { //constructor which also inherits parent class food constructor
    srcRect={131,1545,128,75};
    moverRect = {x, y, 30, 40}; // egg drawn at x,y coordinates
}
char meat::type(){
    return 'g';
}
int meat::getX() const {
    return moverRect.x; //returns meat's x position.
}

int meat::getY() const {
    return moverRect.y; //returns meat's y position.
}

int meat::getWidth() const {

    return moverRect.w; //returns meat's width.
}

int meat::getHeight() const {
    return moverRect.h; //returns meat's height.
}