#include "animal.hpp"
#include "milk.hpp"


class cow: public Animal{
SDL_Rect srcRect, moverRect;


public:
    void draw(SDL_Renderer*, SDL_Texture* assets); //draw function of cow
    void move(); //move function
    bool flag = true; //flag helps in making condition for sheep
    int animation = 0; // controls animation
    cow(SDL_Renderer*, SDL_Texture*, int, int); //Constructor
    food* createProduct(SDL_Renderer* rend, SDL_Texture* texture); //a create product for chicken that will return a food pointer
};
