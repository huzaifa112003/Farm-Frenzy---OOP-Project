#include"animal.hpp"

Animal::Animal(SDL_Renderer* rend, SDL_Texture* ast): gRenderer(rend), assets(ast){

}

void Animal::draw(SDL_Rect srcRect, SDL_Rect moverRect){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}