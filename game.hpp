#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


class Game{
    // Screen dimension constants
    const int SCREEN_WIDTH = 939;
    const int SCREEN_HEIGHT = 626;

    // The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    // Current displayed texture
    SDL_Texture *gTexture = NULL;

    // The music that will be played
    Mix_Music *gMusic = NULL;

    Game();
    ~Game();

    static Game* ptr;

    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

    public:
    bool init();
    bool loadMedia();
    
    void close();
    
    SDL_Texture *loadTexture(std::string path);
    
    void run();
    
    bool StartScreen();
    bool GameScreen();
    
    static Game* getPointer();
    
    void show_time(int);
};
