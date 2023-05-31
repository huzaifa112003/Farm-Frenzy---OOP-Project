#include "chicken.hpp"

void chicken::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect); //drawing the chicken using grenderer, asset file, adress of srcrect, and the adress of its moverrect.
}


void chicken :: move(){
    
    if (flag == true) {
        if (animation == 0) { // if first animation
            srcRect = {133, 102, 30, 25}; // move right
            animation++; // next animation
        } 
        else if (animation == 1) { // if middle animation 
            srcRect = {165, 103, 30, 25}; //(shows leg movement of chicken)
            animation++; // next animation
        }
        else if (animation == 2) { // if second last animation
            srcRect = {197, 102,30,25}; // move right 
            animation++; //increment animation
        } 

        else if (animation == 3) { // if last animation
            srcRect = {229, 103, 30, 25}; // move right 
            animation = 0; // move back to first animation
        }
        
        if(moverRect.x<=700){ // if sheep has not reached the right corner x plus 5
            moverRect.x += 5;
        }
       
        if (moverRect.x>=700){ // if sheep reached the right end corner flag false and exit the if condition
                                // and go to the else where the same thing happens for left
            flag = false;
        }
        
    }
   

    else{ // whole condition runs if the flag is false when chicken reaches right most corner. it brings the chicken back to left
        if (animation == 0) { // if first animation
            srcRect={228,39,31,25}; // reverse move left
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation
            srcRect={197,38,30,26}; // reverse move left
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect={164,39,31,24}; // reverse move left
            animation = 3; // move back to first animation
        }
        else if (animation == 3) { // if last animation
            srcRect={133,38,30,25}; // reverse move left
            animation = 0; // move back to first animation
        }  

        if(moverRect.x>=135){ // if chicken has not reached the right corner x plus 20
            moverRect.x -= 5;
        }
        if (moverRect.x<=155){ // if chicken reached the right end corner flag false and exit the else condition
            flag = true;
        }
    }
}


const int SCREEN_HEIGHT = 600;

food* chicken::createProduct(SDL_Renderer* rend, SDL_Texture* texture){
    //create product function of a chicken returns a pointer to a dynamically created egg.
    return new egg(rend, texture,moverRect.x,moverRect.y);
}


chicken::chicken(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  Animal(rend, texture) { //constructor for chicken which also inherits the animal constructor.
    srcRect = {133, 102, 36, 25};
    moverRect = {x, y, 50, 60}; // sheep drawn at x,y co=ordinates with 50 width and 60 height of the rectangle.
}  






