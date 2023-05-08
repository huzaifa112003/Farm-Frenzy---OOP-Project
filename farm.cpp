#include<iostream>
#include "farm.hpp"
#include <chrono>
#include <thread>

int lastEggTime = 0;

void farmfrenzy::drawObjects(){
    
    // call draw functions of all the objects here
    for (int i = 0; i < animals.size(); i++) {
        animals[i] -> draw(gRenderer, assets);
        animals[i] -> move();
        
        // check if it's time to create an egg for this sheep
        int currentTime = SDL_GetTicks() / 1000;
        int secs= 7+ rand()%35;
        if (currentTime - lastEggTime >= secs) {
            // create an egg for this sheep
            //animals[i]->createProduct(gRenderer, assets);
            food* egg = animals[i]->createProduct(gRenderer, assets);
            eggs.push_back(egg);
            lastEggTime = currentTime;
        }
    }
}

void farmfrenzy::createObject(int x, int y){
    

    int random;
    if((x>=0 && x<=46) && (y>=0 && y<=52)){ //when the player will buy a sheep
        
        
        int xx= 152+ rand()%800;
        x=xx;
        int yy= 124+ rand()%392;
        y=yy;
        if((y>125 && y<370) && (x>142 && x<812)){ // condition that makes sure animals only appear in the farm area.
            Animal* sheepu = new sheep(gRenderer, assets, x, y); // sheep is drawn. Thus sheep vector assigned to the structure object.
            //sheepu->createProduct(gRenderer, assets);
            animals.push_back(sheepu); // pushed back into vector     
        }
        std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
    }

    else if((x>=50 && x<=94) && (y>=3 && y<=52)){ //when the player buys a pig
        //do {
        int xx= 152+ rand()%800;
        x=xx;
        int yy= 124+ rand()%392;
        y=yy;//}while(!(y>115 && y<350) && !(x>142 && x<812));
        if((y>125 && y<350) && (x>142 && x<812)){
            Animal *piggy = new Pig(gRenderer, assets, x, y); // sheep is drawn. Thus animal vector assigned to the structure object.
            animals.push_back(piggy); // pushed back into vector 
        }  
        std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
    }
}


farmfrenzy::farmfrenzy(SDL_Renderer *renderer, SDL_Texture *asset, int x, int y): 
        gRenderer(renderer),
        assets(asset){ 
            last_product_time = std::chrono::system_clock::now();
            }

void farmfrenzy::drawProducts(){
    for (int i = 0; i < eggs.size(); i++) {
        eggs[i]->draw(gRenderer, assets);
    }
}

void farmfrenzy::removeEgg(int x, int y){
    std::cout << "removeEgg called with x = " << x << " and y = " << y << std::endl;
    // iterate over all the eggs
    for (int i = 0; i < eggs.size(); i++) {
        // get the position and size of the egg
        int egg_x = eggs[i]->getX();
        int egg_y = eggs[i]->getY();
        int egg_w = eggs[i]->getWidth();
        int egg_h = eggs[i]->getHeight();
        
        // check if the mouse click is inside the egg
        if (x >= egg_x && x <= egg_x + egg_w && y >= egg_y && y <= egg_y + egg_h) {
            // remove the egg from the vector and delete it from memory
            delete eggs[i];
            eggs.erase(eggs.begin() + i);
            break; // break out of the loop after removing the egg
        }
    }
}