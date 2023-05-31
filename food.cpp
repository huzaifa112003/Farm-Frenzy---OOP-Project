#include"food.hpp"
#include<iostream>
using namespace std;

food::food(SDL_Renderer* rend, SDL_Texture* ast): gRenderer(rend), assets(ast){ //constructor

}

food::~food(){ //destructor for food which will be called when farmfrenzy destructor is called
    cout << "Destroying food"<<endl;
}