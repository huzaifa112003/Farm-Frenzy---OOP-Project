#include "cow.hpp"

// sheep implementation will go here.

void cow::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}


void cow :: move(){
    
    if (flag == true) {
        if (animation == 0) { // if first animation
            //srcRect = {557, 1457, 49, 39}; // move up right
            srcRect={812,431,71,44};
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation 
            //srcRect = {685, 1456, 49, 39}; // move middle right coordinates
            srcRect={940,430,71,44};
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            //srcRect = {813, 1457, 49, 39}; // move down right 
            srcRect={1068,431,71,43};
            animation = 3; // move back to first animation
        } 

        else if (animation == 3) { // if last animation
            //srcRect = {941, 1456, 49, 39}; // move down right 
            srcRect={1196,430,71,43};
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
             // reverse move up left
            srcRect={1180,174,71,43};
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation
             // reverse move middle
            srcRect={1052,175,71,44};
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
             // reverse move down left
            srcRect={924,174,71,44};
            animation = 3; // move back to first animation
        }
        else if (animation == 3) { // if last animation
             // reverse move down left
            srcRect={796,175,71,44};
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

food* cow::createProduct(SDL_Renderer* rend, SDL_Texture* texture){
    //anda= new egg(rend, texture ,x, y);
    
    return new milk(rend, texture,moverRect.x,moverRect.y);
}


cow::cow(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  Animal(rend, texture) { // overloaded constructor
    srcRect={812,431,71,44};
    moverRect = {x, y, 50, 60}; // sheep drawn at x,y co=ordinates
    //doodh= new milk(rend, texture ,moverRect.x, moverRect.y);
}  






