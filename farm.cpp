#include<iostream>
#include "farm.hpp"
#include <chrono>
#include <thread>

int lastProductTime = 0;

void farmfrenzy::drawObjects(){
    
    for (int i = 0; i < animals.size(); i++) {
        animals[i] -> draw(gRenderer, assets);
        animals[i] -> move();
        
        // check if it's time to create a product for this animal
        int currentTime = SDL_GetTicks() / 1000;
        int secs= 15+ rand()%40;
        if (currentTime - lastProductTime >= secs) {
            // create a product for this animal
            food* product = animals[i]->createProduct(gRenderer, assets);
            products.push_back(product);
            lastProductTime = currentTime;
        }
    }
}
void farmfrenzy::createChicken(int x, int y){
    if((x>=0 && x<=46) && (y>=0 && y<=52)){ //when the player buys a chicken
        int xx= 152+ rand()%630;
        x=xx;
        int yy= 124+ rand()%300;
        y=yy;
        if((y>125 && y<450) && (x>142 && x<812)){
            Animal *murghi = new chicken(gRenderer, assets, x, y); // chicken is drawn. Thus animal vector assigned to the structure object.
            animals.push_back(murghi); // pushed back into vector 
        }  
        std::cout<<"Chicken created at: "<<x<<" -- "<<y<<std::endl;
    }
}
void farmfrenzy::createPig(int x, int y){
    if((x>=50 && x<=94) && (y>=3 && y<=52)){ //when the player buys a pig
        int xx= 152+ rand()%630;
        x=xx;
        int yy= 124+ rand()%300;
        y=yy;
        if((y>125 && y<450) && (x>142 && x<812)){
            Animal *piggy = new Pig(gRenderer, assets, x, y); // pig is drawn. Thus animal vector assigned to the structure object.
            animals.push_back(piggy); // pushed back into vector 
        }  
        std::cout<<"Pig created at: "<<x<<" -- "<<y<<std::endl;
    }
}

void farmfrenzy::createCow(int x, int y){
    if((x>=95 && x<=141) && (y>=0 && y<=52)){ //when the player will buy a cow
        int xx= 152+ rand()%630;
        x=xx;
        int yy= 124+ rand()%300;
        y=yy;
        if((y>125 && y<450) && (x>142 && x<812)){ // condition that makes sure animals only appear in the farm area.
            Animal* gaye = new cow(gRenderer, assets, x, y); // cow is drawn. Thus animal vector assigned to the structure object.
            animals.push_back(gaye); // pushed back into vector     
        }
        std::cout<<"Cow created  at: "<<x<<" -- "<<y<<std::endl;
    }
}

void farmfrenzy::createSheep(int x, int y){
    
    if((x>=144 && x<=193) && (y>=0 && y<=52)){ //when the player will buy a sheep
        
        int xx= 152+ rand()%630;
        x=xx;
        int yy= 124+ rand()%300;
        y=yy;
        if((y>125 && y<450) && (x>142 && x<812)){ // condition that makes sure animals only appear in the farm area.
            Animal* sheepu = new sheep(gRenderer, assets, x, y); // sheep is drawn. Thus animal vector assigned to the structure object.
            animals.push_back(sheepu); // pushed back into vector     
        }
        std::cout<<"Sheep created at: "<<x<<" -- "<<y<<std::endl;

    }

}


farmfrenzy::farmfrenzy(SDL_Renderer *renderer, SDL_Texture *asset, int x, int y): 
        gRenderer(renderer),
        assets(asset){ 
            last_product_time = std::chrono::system_clock::now();
            }

void farmfrenzy::drawProducts(){
    for (int i = 0; i < products.size(); i++) {
        products[i]->draw(gRenderer, assets);
    }
}

void farmfrenzy::removeProduct(int x, int y){
    std::cout << "removeProduct called with x = " << x << " and y = " << y << std::endl;
    // iterate over all the products
    for (int i = 0; i < products.size(); i++) {
        // get the position and size of the product
        int product_x = products[i]->getX();
        int product_y = products[i]->getY();
        int product_w = products[i]->getWidth();
        int product_h = products[i]->getHeight();
        
        // check if the mouse click is inside the product
        if (x >= product_x && x <= product_x + product_w && y >= product_y && y <= product_y + product_h) {
            // remove the product from the vector and delete it from memory
            delete products[i];
            products.erase(products.begin() + i);
            break; // break out of the loop after removing the product
        }
    }//
}