#include<SDL.h>
#include "animal.hpp"
#include "meat.hpp"
#include "food.hpp"

class Pig: public Animal{
SDL_Rect srcRect, moverRect;

public:
    //food* bacon;
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function of pigeon
    void move(); //move function
    bool flag = true; //flag helps in making condition for pigeon
    int animation = 0; // controls animation
    // Pig(); //default constructor
    // Pig(int, int); // may add other overloaded constructors here... 
    Pig(SDL_Renderer*, SDL_Texture*, int, int);
    food* createProduct(SDL_Renderer* rend, SDL_Texture* texture);
};

