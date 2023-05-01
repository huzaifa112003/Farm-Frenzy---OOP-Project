#include<SDL.h>
#include "sheep.hpp"
#include"pig.hpp"
// #include "animal.hpp"
// #include "food.hpp"
#include "egg.hpp"
#include<vector>
#include<list>
using namespace std;


class farmfrenzy{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    //SDL_Texture* assets_for_egg;

   //all required objects created    
    //sheep sheep1; not needed because list
    //Pig pig1; not needed because list

    // In the solution you have to create vectors of sheeps, eggs, and nests   
    // vector<sheep*> sheeps;
    // vector<Pig*> pigs;
    vector<Animal*> animals;
    vector<food*> products;

    public:
    farmfrenzy(SDL_Renderer *, SDL_Texture *, int, int);
    void drawObjects(); 
    void createObject(int, int);
};