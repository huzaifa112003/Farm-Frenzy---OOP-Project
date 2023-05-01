#include<SDL.h>
#include "animal.hpp"

class sheep: public Animal{
SDL_Rect srcRect, moverRect;

public:
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function of sheep
    void move(); //move function
    bool flag = true; //flag helps in making condition for sheep
    int animation = 0; // controls animation
    //sheep(); //default constructor
    sheep(SDL_Renderer*, SDL_Texture*, int, int); // may add other overloaded constructors here... 
};

