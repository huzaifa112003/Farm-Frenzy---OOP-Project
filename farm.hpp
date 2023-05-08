#include<SDL.h>
#include "sheep.hpp"
#include"pig.hpp"
// #include "animal.hpp"
// #include "food.hpp"
#include "egg.hpp"
#include<vector>
#include<list>
using namespace std;
#include <chrono>
#include <thread>


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
    std::vector<food*> eggs;
    vector<Animal*> animals;
    vector<food*> products;
    std::chrono::time_point<std::chrono::system_clock> last_product_time;
    public:
    farmfrenzy(SDL_Renderer *, SDL_Texture *, int, int);
    void drawObjects(); 
    void createObject(int, int);
    void drawProducts();
    void removeEgg(int x, int y);

};