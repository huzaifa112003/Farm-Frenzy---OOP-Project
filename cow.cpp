#include "cow.hpp"


void cow::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect); ////drawing the cow using grenderer, asset file, adress of srcrect, and the adress of its moverrect.
}


void cow :: move(){
    
    if (flag == true) {
        if (animation == 0) { // if first animation

            srcRect={812,431,71,44}; // move right
            animation++ ; // next animation
        } 
        else if (animation == 1) { // if middle animation 
             
            srcRect={940,430,71,44}; // move  right 
            animation++ ; // next animation
        }
        else if (animation == 2) { // if last animation
              
            srcRect={1068,431,71,43}; // move down right
            animation++ ; //increment animation
        } 

        else if (animation == 3) { // if last animation
             
            srcRect={1196,430,71,43}; // move down right 
            animation = 0; // move back to first animation
        }
        
        if(moverRect.x<=700){ // if cow has not reached the right corner x plus 20
            moverRect.x += 2;
        }
       
        if (moverRect.x>=700){ // if cow reached the right end corner flag false and exit the if condition
            flag = false;
        }
        
    }
   

    else{ // whole condition runs if the flag is false when cow reaches the right most corner. it brings the cow back to left
        if (animation == 0) { // if first animation
             // reverse move left
            srcRect={1180,174,71,43};
            animation++ ; // next animation
        } 
        else if (animation == 1) { // if middle animation
             // reverse move left
            srcRect={1052,175,71,44};
            animation++ ; // next animation
        }
        else if (animation == 2) { // if last animation
             // reverse move left
            srcRect={924,174,71,44};
            animation++ ; // move back to first animation
        }
        else if (animation == 3) { // if last animation
             // reverse move left
            srcRect={796,175,71,44};
            animation = 0; // move back to first animation
        }  

        if(moverRect.x>=135){ // if cow has not reached the right corner x plus 20
            moverRect.x -= 2;
        }
        if (moverRect.x<=155){ // if cow has reached the right end corner flag false and exit the else condition
            flag = true;
        }
    }
}


food* cow::createProduct(SDL_Renderer* rend, SDL_Texture* texture){
    //create product function of a cow returns a pointer to a dynamically created milk product.
    return new milk(rend, texture,moverRect.x,moverRect.y);
}


cow::cow(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  Animal(rend, texture) { // constructor which also inherits animal constructor
    srcRect={812,431,71,44};
    moverRect = {x, y, 50, 60}; // cow drawn at x,y co=ordinates
   
}  






