#include<SDL.h>

#include "sheep.hpp"
#include "pig.hpp"
#include "cow.hpp"
#include "chicken.hpp"
#include "egg.hpp"
#include "milk.hpp"
#include "meat.hpp"
#include "wool.hpp"
#include "countp.hpp"

#include<vector>

#include <chrono>
#include <thread>
using namespace std;


class farmfrenzy{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    vector<Animal*> animals; 
    vector<food*> products;
    std::chrono::time_point<std::chrono::system_clock> last_product_time;
    //int countproduct = 0;
    public:
    farmfrenzy(SDL_Renderer *, SDL_Texture *, int, int);
    void drawObjects();                      
    void createChicken(int, int);
    void createPig(int, int);
    void createSheep(int, int);
    void createCow(int, int);
    void drawProducts();
    void removeProduct(int x, int y);
    int collectedProducts();
    int money = 100;
    int currentMoney();
    int countProduct=0;
    friend class Game;
    ~farmfrenzy();
};