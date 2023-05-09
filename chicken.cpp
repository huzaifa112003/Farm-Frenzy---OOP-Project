#include "chicken.hpp"

// sheep implementation will go here.

void chicken::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


void chicken :: move(){
    
    if (flag == true) {
        if (animation == 0) { // if first animation
            srcRect = {133, 102, 36, 25}; // move up right
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation 
            srcRect = {165, 103, 31, 24}; // move middle right coordinates
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect = {197, 102,30,26}; // move down right 
            animation = 3; // move back to first animation
        } 

        else if (animation == 3) { // if last animation
            srcRect = {229, 103, 31, 25}; // move down right 
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
            srcRect={228,39,31,25}; // reverse move up left
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation
            srcRect={197,38,30,26}; // reverse move middle
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect={164,39,31,24}; // reverse move down left
            animation = 3; // move back to first animation
        }
        else if (animation == 3) { // if last animation
            srcRect={133,38,30,25}; // reverse move down left
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

food* chicken::createProduct(SDL_Renderer* rend, SDL_Texture* texture){
    //anda= new egg(rend, texture ,x, y);
    
    return new egg(rend, texture,moverRect.x,moverRect.y);
}


chicken::chicken(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  Animal(rend, texture) { // overloaded constructor
    srcRect = {133, 102, 36, 25};
    moverRect = {x, y, 50, 60}; // sheep drawn at x,y co=ordinates
    //anda= new egg(rend, texture ,moverRect.x, moverRect.y);
}  






