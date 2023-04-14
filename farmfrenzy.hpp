#include<SDL.h>
#include<list>
#include "Grass.hpp"
using namespace std;
class FarmFrenzy{
    list<Grass*> ghaans;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    
    public:
    FarmFrenzy(SDL_Renderer *, SDL_Texture *);
    void drawObjects(); 
    void createObject(int, int);
    ~FarmFrenzy();
};