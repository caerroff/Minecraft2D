/*
    Version 0.0.1
*/

#define VERSION "0.0.1"
#include <iostream>
#include "GUI.hpp"

typedef struct{
    int r;
    int g;
    int b;
}Colour;


Colour initColours(void);
void drawColour(App app, Colour clr);


int main(){
    std::cout << "MC2D Version :" << VERSION << std::endl;
    App app = init();
    int running;
    running = 1;
    Colour purple = initColours();
    while(running == 1){
        SDL_Event *event = pollEvents(app, &running);
        switch(event->type){
            case 1024:
                drawColour(app, purple);
                break;
            
            case 1025:
                std::cout << "AAAHHH" << std::endl;
                break;

            default:
                drawSky(app);
                break;
        }
    }


    return 0;
}

Colour initColours(void){
    Colour purple;
    
    purple.r = 255;
    
    purple.g = 0;
    
    purple.b = 255;

    return purple;
}


void drawColour(App app, Colour clr){
    SDL_SetRenderDrawColor(app.render, clr.r, clr.g, clr.b, 255);
    SDL_RenderClear(app.render);
    SDL_RenderPresent(app.render);
}