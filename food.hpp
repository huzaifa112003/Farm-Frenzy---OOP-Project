#include<SDL.h>
#pragma once

class food{
    SDL_Renderer* gRenderer;
    SDL_Texture* assets;
public:
    food(SDL_Renderer*, SDL_Texture*);
    virtual void draw(SDL_Renderer*, SDL_Texture* assets) = 0; //pure virtual draw function and every product draws using its own draw function.
    virtual int getX() const=0; //pure virtual getter functions for x, y , width, and height for all products. we need these to delete them on collection/click.
    virtual int getY() const=0;
    virtual int getWidth() const=0;
    virtual int getHeight() const=0;
    virtual char type() =0;
};