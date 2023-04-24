#include<SDL.h>
#include<list>
#include "Grass.hpp"
#include "sheep.hpp"
#include "vector"
using namespace std;
class FarmFrenzy{
    list<Grass*> ghaans;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    Sheep p1;
    vector<Sheep*> sheeps;
    public:
    FarmFrenzy(SDL_Renderer *, SDL_Texture *);
    void drawObjects(); 
    void createObject(int, int);
    ~FarmFrenzy();
};