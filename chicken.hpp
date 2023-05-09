#include<SDL.h>
#include "animal.hpp"
#include "egg.hpp"


class chicken: public Animal{ //chicken class is inherited from the animal class
SDL_Rect srcRect, moverRect; // private members: it's source rect where the initial position of the Chicken is generated in the constructor.

public:
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function for chicken
    void move(); //move function
    bool flag = true; //flag helps in making condition for chicken
    int animation = 0; // controls animation
    chicken(SDL_Renderer*, SDL_Texture*, int, int); //constructor for chicken with 4 parameters.
    food* createProduct(SDL_Renderer* rend, SDL_Texture* texture); //a create product for chicken that will return a food pointer
};
