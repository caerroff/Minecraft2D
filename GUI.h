#ifndef GUI
#define GUI

//#include "Libraries/include/SDL.h"
#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720
#include "Libraries/include/SDL.h"

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Event *event;
} App;

App initSDL(void);
void drawBlack(App app);
void drawColour(SDL_Renderer *renderer, int r, int g, int b);
void cleanUp(App app);
void pollEvents(App app, int *running);
int createWindow(void);


#endif