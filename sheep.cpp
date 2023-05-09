#include "sheep.hpp"

// sheep implementation will go here.

void sheep::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


void sheep :: move(){
    
    if (flag == true) {
        if (animation == 0) { // if first animation
            srcRect = {557, 1457, 49, 39}; // move up right
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation 
            srcRect = {685, 1456, 49, 39}; // move middle right coordinates
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect = {813, 1457, 49, 39}; // move down right 
            animation = 3; // move back to first animation
        } 

        else if (animation == 3) { // if last animation
            srcRect = {941, 1456, 49, 39}; // move down right 
            animation = 0; // move back to first animation
        }
        
        if(moverRect.x<=700){ // if sheep has not reached the right corner x plus 20
            moverRect.x += 5;
        }
       
        if (moverRect.x>=700){ // if sheep reached the right end corner flag false and exit the if condition
            flag = false;
        }
        
    }
   

    else{ // whole condition runs if the flag is false when sheep reaches right corner. it brings the sheep back to left
        if (animation == 0) { // if first animation
            srcRect = {552, 1201, 49, 39}; // reverse move up left
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation
            srcRect = {680, 1200, 49, 39}; // reverse move middle
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect = {808, 1201, 49, 39}; // reverse move down left
            animation = 3; // move back to first animation
        }
        else if (animation == 3) { // if last animation
            srcRect = {936, 1200, 49, 39}; // reverse move down left
            animation = 0; // move back to first animation
        }  
        moverRect.x -= 5; // move sheep 20 pixels etc as indicated

        if(moverRect.x>=135){ // if sheep has not reached the right corner x plus 20
            moverRect.x -= 5;
        }
        if (moverRect.x<=155){ // if sheep reached the right end corner flag false and exit the if condition
            flag = true;
        }
    }
}


const int SCREEN_HEIGHT = 600;

food* sheep::createProduct(SDL_Renderer* rend, SDL_Texture* texture){
    //anda= new egg(rend, texture ,x, y);
    
    return new wool(rend, texture,moverRect.x,moverRect.y);
}


sheep::sheep(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  Animal(rend, texture) { // overloaded constructor
    srcRect = {557, 1457, 49, 39};
    moverRect = {x, y, 50, 60}; // sheep drawn at x,y co=ordinates
    rui= new wool(rend, texture ,moverRect.x, moverRect.y);
}  






