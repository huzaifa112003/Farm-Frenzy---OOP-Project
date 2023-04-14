#include "farmfrenzy.hpp"
#include<iostream>
void FarmFrenzy::drawObjects(){

    for (Grass* g: ghaans) {
        g->draw();
    }
    // for(iteratorr=bullets.begin();iteratorr!=bullets.end();iteratorr++){ //syntax seen from the internet
    // //loop runs from first bullet to last and increments iteratorr.
    //     if((**iteratorr).flag==true){ //using the flag variable that tells that the is frams>7
    //                                 // no more animation we have to delete bullet now.
    //         delete *iteratorr; //delete the pointer iteratorr using delete operator.
    //         bullets.erase(iteratorr); //use erase function to delete pointers from bullets list.
    //     }
    //     else{
    //         (*iteratorr)->draw(); //if the flag is false then it show continue drawing.
    //     }
    // }
}

void FarmFrenzy::createObject(int x, int y) {
    
    SDL_Rect grassRectangle = {x, y, 150, 70}; // let's make a rectangle on x, y of the size 150, 70
    Grass *grass=new Grass(gRenderer, assets, grassRectangle); //creating a tank pointer using new operator (will be made on runtime).
    ghaans.push_back(grass); //adding it to the list of tanks
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

FarmFrenzy::FarmFrenzy(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){

}




FarmFrenzy::~FarmFrenzy(){ //destructor
}
