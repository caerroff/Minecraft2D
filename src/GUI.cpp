#include "GUI.hpp"
#include <iostream>
#include "../lib/SDL2/include/SDL.h"
#define WIDTH 1280
#define HEIGHT 720
#define VERSION_GUI "1.0"


typedef struct {
    int r;
    int g;
    int b;
}Colour;

App init(void){
    std::cout << "Version of the GUI "<< VERSION_GUI << std::endl;
    int rendererFlags, windowFlags;
    App app;
    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = 0;

    app.window = SDL_CreateWindow("MC2D", 100, 100, WIDTH, HEIGHT, windowFlags);

    app.render = SDL_CreateRenderer(app.window, -1, rendererFlags);
    return app;
}

SDL_Event* pollEvents(App app, int *running){

    while(SDL_PollEvent(app.event) != 0){
        switch(app.event->type){
            case SDL_QUIT:
                cleanUp(app);
                *running = 0;
                return app.event;
                break;

            case SDL_KEYDOWN:
                SDL_Event *e;
                return e;
                break;

            default:
                std::cout << app.event->type << std::endl;
                return app.event;
                break;
        }   
    }
    
    return app.event;
}


void drawSky(App app){
    SDL_SetRenderDrawColor(app.render, 105, 205, 255, 255);
    SDL_RenderClear(app.render);
    SDL_RenderPresent(app.render);
}

void cleanUp(App app){
    SDL_DestroyRenderer(app.render);
    SDL_DestroyWindow(app.window);
    SDL_Quit;
    
}

