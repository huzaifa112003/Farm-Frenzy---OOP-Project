#include<SDL.h>
#pragma once
#include "food.hpp"

class Animal{
    SDL_Renderer* gRenderer;// private members SDL_Renderer and the asset file.
    SDL_Texture* assets;
public:
    Animal(SDL_Renderer*, SDL_Texture*); // Constructor with two parameters rendere and asset file.
    virtual void draw(SDL_Renderer*, SDL_Texture* assets) = 0; // A pure virtual draw function that every derived class will have of its own.
    virtual void move() = 0; // A pure virtual move function that every derived class will have of its own.
    virtual food* createProduct(SDL_Renderer* rend, SDL_Texture* texture)=0; // A pure virtual createproduct function that every derived class will have of its own.
};
