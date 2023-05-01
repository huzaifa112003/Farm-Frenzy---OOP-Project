#include<iostream>
#include "farm.hpp"

void farmfrenzy::drawObjects(){
    // call draw functions of all the objects here
    for (int i = 0; i < animals.size(); i++) {
        animals[i] -> draw(gRenderer, assets);
        animals[i] -> move();
        //products[i]->draw(gRenderer, assets);
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
            Animal *sheepu = new sheep(gRenderer, assets, x, y); // sheep is drawn. Thus sheep vector assigned to the structure object.
            animals.push_back(sheepu); // pushed back into vector 
            // food* anda= new egg(gRenderer, assets ,x, y);
            // products.push_back(anda);
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
        assets(asset){}
