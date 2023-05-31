#include"animal.hpp"
#include<iostream>
using namespace std; 

Animal::Animal(SDL_Renderer* rend, SDL_Texture* ast): gRenderer(rend), assets(ast){}
// constructor for animal.

Animal::~Animal(){
    cout << "Destroying animals"<<endl;
}