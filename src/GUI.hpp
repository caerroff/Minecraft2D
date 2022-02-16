#ifndef GUI
#define GUI
#include "../lib/SDL2/include/SDL.h"

typedef struct{
    SDL_Renderer *render;
    SDL_Window *window;
    SDL_Event *event;
}App;

App init(void);
SDL_Event * pollEvents(App app, int *running);
void cleanUp(App app);
void drawSky(App app);

#endif