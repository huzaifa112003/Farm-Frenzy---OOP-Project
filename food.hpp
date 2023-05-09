#include<SDL.h>
#pragma once

class food{
    SDL_Renderer* gRenderer;
    SDL_Texture* assets;
public:
    food(SDL_Renderer*, SDL_Texture*);
    virtual void draw(SDL_Renderer*, SDL_Texture* assets) = 0;
    //Animal();
    // virtual void draw(SDL_Rect* srcRect, SDL_Rect* moverRect)=0;
    //virtual void move() = 0;
    virtual int getX() const=0;
    virtual int getY() const=0;
    virtual int getWidth() const=0;
    virtual int getHeight() const=0;
};