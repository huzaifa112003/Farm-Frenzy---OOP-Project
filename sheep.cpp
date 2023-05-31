#include "sheep.hpp"

void sheep::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


void sheep :: move(){
    
    if (flag == true) {
        if (animation == 0) { // if first animation
             srcRect={558,1458,49,38};// move right
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation 
            srcRect={686,1457,49,39};
            // move middle right coordinates
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
             srcRect={814,1458,49,39};// move down right 
            animation = 3; // move back to first animation
        } 

        else if (animation == 3) { // if last animation
            srcRect={942,1457,49,39}; // move down right 
            animation = 0; // move back to first animation
        }
        
        if(moverRect.x<=700){ // if sheep has not reached the right corner x plus 20
            moverRect.x += 4;
        }
       
        if (moverRect.x>=700){ // if sheep reached the right end corner flag false and exit the if condition
            flag = false;
        }
        
    }
   

    else{ // whole condition runs if the flag is false when sheep reaches right corner. it brings the sheep back to left
        if (animation == 0) { // if first animation
            //  move left
            srcRect={937,1201,49,39};
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation
             srcRect={809,1202,49,39}; // reverse move middle
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
             srcRect={681,1201,49,39};// reverse move down left
            animation = 3; // move back to first animation
        }
        else if (animation == 3) { // if last animation
            srcRect={553,1202,49,38};// reverse move down left
            animation = 0; // move back to first animation
        }  

        if(moverRect.x>=135){ // if sheep has not reached the right corner x plus 20
            moverRect.x -= 4;
        }
        if (moverRect.x<=155){ // if sheep reached the right end corner flag false and exit the if condition
            flag = true;
        }
    }
}


const int SCREEN_HEIGHT = 600;

food* sheep::createProduct(SDL_Renderer* rend, SDL_Texture* texture){
    return  new wool(rend, texture,moverRect.x,moverRect.y);
}


sheep::sheep(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  Animal(rend, texture) { // constructor
    srcRect={558,1458,49,38}; 
    moverRect = {x, y, 50, 60}; // sheep drawn at x,y co=ordinates
    
}  






