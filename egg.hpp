#include<SDL.h>
#include "food.hpp"

#ifndef UNIT
#define UNIT

class egg: public food{
SDL_Rect srcRect, moverRect;

public:
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function of egg
    egg(SDL_Renderer*, SDL_Texture*, int, int); //constructor
    int getX() const; // //getter function for x coordinate of egg.
    int getY() const; //getter function for y coordinate of egg.
    int getWidth() const; //getter function for width of egg.
    int getHeight() const; //getter function for height of egg.
    char type();
    };
#endif