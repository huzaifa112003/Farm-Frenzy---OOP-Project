#include<SDL.h>
#include "animal.hpp"
#include "egg.hpp"
#include "food.hpp"
#include <windows.h>
// sheep implementation will go here.
#include <time.h>
class chicken: public Animal{
SDL_Rect srcRect, moverRect;


public:
    //food* anda;
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function of sheep
    void move(); //move function
    bool flag = true; //flag helps in making condition for sheep
    int animation = 0; // controls animation
    //sheep(); //default constructor
    chicken(SDL_Renderer*, SDL_Texture*, int, int); // may add other overloaded constructors here...  
    food* createProduct(SDL_Renderer* rend, SDL_Texture* texture);
};
