#include<SDL.h>
#include "food.hpp"

#ifndef UNIT
#define UNIT

class egg: public food{
SDL_Rect srcRect, moverRect;

public:
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function of pigeon
    egg(SDL_Renderer*, SDL_Texture*, int, int);
    // void move(); //move function
    // bool flag = true; //flag helps in making condition for pigeon
    // int animation = 0; // controls animation
    // Pig(); //default constructor
    // Pig(int, int); // may add other overloaded constructors here... 
    };
#endif