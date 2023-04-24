#include "sheep.hpp"
// pigeon implementation will go here.

void Sheep::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Sheep :: fly(){
    
    if (flag == true) {
        if (animation == 0) { // if first animation
            srcRect = {557, 1457, 49, 39}; // fly up right
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation 
            srcRect = {685, 1456, 49, 39}; // fly middle right coordinates
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect = {813, 1457, 49, 39}; // fly down right 
            animation = 3; // move back to first animation
        } 

        else if (animation == 3) { // if last animation
            srcRect = {941, 1456, 49, 39}; // fly down right 
            animation = 0; // move back to first animation
        }
        
        if(moverRect.x<=900){ // if pigeon has not reached the right corner x plus 20
            moverRect.x += 5;
        }

        if (moverRect.x>=800){ // if pigeon reached the right end corner flag false and exit the if condition
            flag = false;
        }
    }
   

    else{ // whole condition runs if the flag is false when pigeon reaches right corner. it brings the pigeon back to left
        if (animation == 0) { // if first animation
            srcRect = {552, 1201, 49, 39}; // reverse fly up left
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation
            srcRect = {680, 1200, 49, 39}; // reverse fly middle
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect = {808, 1201, 49, 39}; // reverse fly down left
            animation = 3; // move back to first animation
        }
        else if (animation == 3) { // if last animation
            srcRect = {936, 1200, 49, 39}; // reverse fly down left
            animation = 0; // move back to first animation
        }  
        moverRect.x -= 5; // move pigeon 20 pixels etc as indicated
    }
}


const int SCREEN_HEIGHT = 600;

Sheep::Sheep(){
    // // src coorinates from assets.png file, they have been found using spritecow.com
    // srcRect = {557, 1457, 49, 39};
    // // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    // moverRect = {40, SCREEN_HEIGHT - 150, 50, 60};
}



Sheep::Sheep(int x, int y) { // overloaded constructor
    srcRect = {557, 1457, 49, 39};
    moverRect = {x, y, 50, 60}; // pigeon drawn at x,y co=ordinates
}






