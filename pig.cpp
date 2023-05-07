#include "pig.hpp"
// Pig implementation will go here.

void Pig::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

void Pig :: move(){
    
    if (flag == true) {
        if (animation == 0) { // if first animation
            srcRect = {1068, 953, 55, 30}; // move up right
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation 
            srcRect = {1196, 952, 55, 30}; // move middle right coordinates
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect = {1324, 953, 55, 30}; // move down right 
            animation = 3; // move back to first animation
        } 

        else if (animation == 3) { // if last animation
            srcRect = {1452, 952, 55, 30}; // move down right 
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
            srcRect = {1063, 697, 55, 30}; // reverse move up left
            animation = 1; // next animation
        } 
        else if (animation == 1) { // if middle animation
            srcRect = {1191, 696, 55, 30}; // reverse move middle
            animation = 2; // next animation
        }
        else if (animation == 2) { // if last animation
            srcRect = {1319, 697, 55, 30}; // reverse move down left
            animation = 3; // move back to first animation
        }
        else if (animation == 3) { // if last animation
            srcRect = {1447, 696, 55, 30}; // reverse move down left
            animation = 0; // move back to first animation
        }  
        moverRect.x -= 5; // move Pig 20 pixels etc as indicated

        if(moverRect.x>=135){ // if sheep has not reached the right corner x plus 20
            moverRect.x -= 5;
        }
        if (moverRect.x<=155){ // if sheep reached the right end corner flag false and exit the if condition
            flag = true;
        }
    }
}


const int SCREEN_HEIGHT = 600;

// Pig::Pig(){
//     // src coorinates from assets.png file, they have been found using spritecow.com
//     srcRect = {1068, 953, 55, 30};
//     // it will display Pig on x = 30, y = 40 location, the size of Pig is 50 width, 60 height
//     moverRect = {40, SCREEN_HEIGHT - 200, 50, 60};
// }



// Pig::Pig(int x, int y) { // overloaded constructor
//     srcRect = {1068, 953, 55, 30};
//     moverRect = {x, y, 50, 60}; // Pig drawn at x,y co=ordinates
// }


void Pig::createProduct(SDL_Renderer* rend, SDL_Texture* texture){
    
    anda->draw(rend, texture);
}


Pig::Pig(SDL_Renderer* rend, SDL_Texture* texture, int x, int y):
  Animal(rend, texture) { // overloaded constructor
    srcRect = {1068, 953, 55, 30};
    moverRect = {x, y, 50, 60}; // sheep drawn at x,y co=ordinates
    anda= new egg(rend, texture ,x, y);
}






