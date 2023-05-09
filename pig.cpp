#include "pig.hpp"

void Pig::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Pig :: move(){
    
    if (flag == true) {
        if (animation == 0) { // if first animation
             srcRect={1069,954,55,30};// move right
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation 
            srcRect={1197,953,55,30};// move middle right coordinates
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect={1325,954,55,30};// move down right 
            animation = 3; // move back to first animation
        } 

        else if (animation == 3) { // if last animation
             srcRect={1453,953,55,30};// move down right 
            animation = 0; // move back to first animation
        }
        
        if(moverRect.x<=950){ // if Pig has not reached the right corner x plus 20
            moverRect.x += 5;
        }

        if (moverRect.x>=800){ // if Pig reached the right end corner flag false and exit the if condition
            flag = false;
        }
    }
   

    else{ // whole condition runs if the flag is false when Pig reaches right corner. it brings the Pig back to left
        if (animation == 0) { // if first animation
            srcRect={1448,697,55,30}; //move right
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation
            srcRect={1320,698,55,30};// reverse move middle
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect={1192,697,55,30};// reverse move down left
            animation = 3; // move back to first animation
        }
        else if (animation == 3) { // if last animation
             srcRect={1064,698,55,30};// reverse move down left
            animation = 0; // move back to first animation
        }  

        if(moverRect.x>=135){ // if sheep has not reached the right corner x plus 20
            moverRect.x -= 5;
        }
        if (moverRect.x<=155){ // if sheep reached the right end corner flag false and exit the if condition
            flag = true;
        }
    }
}



food* Pig::createProduct(SDL_Renderer* rend, SDL_Texture* texture){
    
    return new meat(rend, texture, moverRect.x, moverRect.y);
}


Pig::Pig(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  Animal(rend, texture) { // constructor
    srcRect={1069,954,55,30};
    moverRect = {x, y, 50, 60}; // sheep drawn at x,y co=ordinates
    
}






