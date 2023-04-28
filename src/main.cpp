#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
int main(int argc, const char *argv[]) {
    cout << "Inside main 1" << endl;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                               SDL_WINDOWPOS_UNDEFINED,
                                               SCREEN_WIDTH, SCREEN_HEIGHT,
                                               SDL_WINDOW_SHOWN);
    if(gWindow == NULL )
    {
        cout << "Window could not be created! SDL_Error: " <<  SDL_GetError() << endl;
        return 1;
    }
    gScreenSurface = SDL_GetWindowSurface(gWindow);
    SDL_Event event;
    bool quit = false;

    while(!quit) {
       
        while (SDL_PollEvent(&event)) {
            
            if (event.type == SDL_QUIT) {
                quit = true;
            }     
            SDL_FillRect( gScreenSurface, NULL, SDL_MapRGB( gScreenSurface->format, 0xFF, 0xFF, 0xFF ) );
            SDL_UpdateWindowSurface( gWindow );
        }
    }
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    SDL_Quit();

    return 0;

}