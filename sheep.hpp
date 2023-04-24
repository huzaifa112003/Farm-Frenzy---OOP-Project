#include<SDL.h>

class Sheep{
SDL_Rect srcRect, moverRect;

public:
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function of pigeon
    void fly(); //fly function
    bool flag = true; //flag helps in making condition for pigeon
    int animation = 0; // controls animation
    Sheep(); //default constructor
    Sheep(int, int); // may add other overloaded constructors here... 
};

