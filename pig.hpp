#include<SDL.h>
#include "animal.hpp"

class Pig: public Animal{
SDL_Rect srcRect, moverRect;

public:
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function of pigeon
    void move(); //move function
    bool flag = true; //flag helps in making condition for pigeon
    int animation = 0; // controls animation
    // Pig(); //default constructor
    // Pig(int, int); // may add other overloaded constructors here... 
    Pig(SDL_Renderer*, SDL_Texture*, int, int);
};

