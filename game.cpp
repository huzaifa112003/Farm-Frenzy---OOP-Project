#include "game.hpp"
#include "farm.hpp"
#include <vector>
#include <time.h>
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <ctime>
#include<string>
#include<SDL_ttf.h>

using namespace std;
using namespace std::chrono;

// Game *Game::ptr = NULL;

// SDL_Renderer *Drawing::gRenderer = NULL;
// SDL_Renderer *Drawing::hRenderer = NULL;
// SDL_Texture *Drawing::assets = NULL;


void Game::show_time(int t){
	TTF_Init(); //Initializes SDL_TTF for displaying text in 
    TTF_Font* font = TTF_OpenFont("arial.ttf", 24); //Opens a font style that can be downloaded as a .ttf file and sets a font size
    SDL_Color color = {0, 0, 0}; //This is the texts color that can be changed using RGB values from 0 to 255.
    string tmp = to_string(t); //converts score to string that can later be displayed using the font file - hence why we needed font.
    SDL_Surface *surfacemessage = TTF_RenderText_Solid(font, tmp.c_str(), color); //A surface is created using functions from SDL library that displays the score on the screen.
    SDL_Texture *Message = SDL_CreateTextureFromSurface(gRenderer, surfacemessage); //Converts into texture that can be displayed
    SDL_Rect Message_rect = {800, 30, 90, 30}; //create a rect for it
    SDL_RenderCopy(gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfacemessage);
    // SDL_DestroyTexture(Message);
    // TTF_CloseFont(font);
    // TTF_Quit();
}

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Farm Frenzy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	assets = loadTexture("assets.png");
	//assets_for_egg =loadTexture("egg.png");
    gTexture = loadTexture("startscreen.png");
	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	// gMusic = Mix_LoadMUS("bgm.mp3");
	// if (gMusic == NULL)
	// {
	// 	printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	// 	success = false;
	// }

	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run( )
{
	bool quit = false;;
	SDL_Event e;

	farmfrenzy farmfrenzyy(gRenderer, assets, 100, 100);
	auto start = high_resolution_clock::now();

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}

			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				if((xMouse>=298 && xMouse<=700) && (yMouse>=396 && yMouse<=490)){
					gTexture = loadTexture("start.png");
						

				// if((xMouse>=15 && xMouse<=80) && (yMouse>=30 && yMouse<=91)){
				// 	gTexture = loadTexture("instruction.png");
				// }
				SDL_GetMouseState(&xMouse,&yMouse);
				farmfrenzyy.createObject(xMouse, yMouse);
			}
		}


		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		farmfrenzyy.drawObjects();
		farmfrenzyy.drawProducts();
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<seconds>(stop - start);
		// time_left = time_left - duration.count();
		cout << "time: " << duration.count() << endl;
		int t = 185 - duration.count();
		cout << "You have " << t << " seconds left\n";
		show_time(t);
				// }
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState(&x, &y);
			std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
			farmfrenzyy.removeEgg(x, y);
		}
		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
	
	}
			}
