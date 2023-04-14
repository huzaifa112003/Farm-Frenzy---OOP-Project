#include"Grass.hpp"


Grass::Grass(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Animal(rend, ast), mover(mov){
        src = {1, 1, 251, 194}; //self defined using assets.png
    }
void Grass::draw(){
        Animal::draw(src, mover); 

    }