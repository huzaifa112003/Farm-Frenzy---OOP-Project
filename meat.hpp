#include<SDL.h>
#include "food.hpp"

#ifndef UNIT
#define UNIT

class meat: public food{ //inherited from food class
SDL_Rect srcRect, moverRect;

public:
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function of meat
    meat(SDL_Renderer*, SDL_Texture*, int, int); //constructor
    int getX() const; //constant getter functions for x, y, width, and height of the meat product.
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    char type();
    };
#endif