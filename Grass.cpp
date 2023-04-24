#include"Grass.hpp"


Grass::Grass(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov){
        src = {1, 1, 251, 194}; //self defined using assets.png
    }
void Grass::draw(){
        
    SDL_RenderCopy(gRenderer, assets, &src, &mover);
}

    