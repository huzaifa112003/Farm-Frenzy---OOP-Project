#include<SDL.h>
#pragma once

class Animal{
    SDL_Renderer* gRenderer;
    SDL_Texture* assets;
public:
    Animal(SDL_Renderer*, SDL_Texture*);
    virtual void draw(SDL_Renderer*, SDL_Texture* assets) = 0;
    //Animal();
    // virtual void draw(SDL_Rect* srcRect, SDL_Rect* moverRect)=0;
    virtual void move() = 0;
};
