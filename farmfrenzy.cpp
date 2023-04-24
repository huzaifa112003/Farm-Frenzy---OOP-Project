#include "farmfrenzy.hpp"
#include<iostream>
#include<vector>

void FarmFrenzy::drawObjects(){

    for (Grass* g: ghaans) {
        g->draw();
    }
    Animal** animals;
    p1.draw(gRenderer, assets);
    p1.fly();
    
    // for pigeons
    for (int i = 0; i < 5; i++) {
        sheeps[i] -> draw(gRenderer, assets);
        sheeps[i] -> fly();
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
    
    // SDL_Rect grassRectangle = {x, y, 150, 70}; // let's make a rectangle on x, y of the size 150, 70
    // Grass *grass=new Grass(gRenderer, assets, grassRectangle); //creating a tank pointer using new operator (will be made on runtime).
    // ghaans.push_back(grass); //adding it to the list of tanks
    // std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;

    
    int random; bool flag=false;
    if((x>=0 && x<=46) && (y>=0 && y<=52)){
        random = 0; // generates a number between 1-3 randomly
        
        if (random == 0){
            int xx= 152+ rand()%800;
            x=xx;
            int yy= 124+ rand()%392;
            y=yy;
            Sheep *p1 = new Sheep(x,y); // pigeon is drawn. Thus pigeon vector assigned to the structure object.
            sheeps.push_back(p1); // pushed back into vector 
        }


}
}





FarmFrenzy::FarmFrenzy(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){

}




FarmFrenzy::~FarmFrenzy(){ //destructor
}
