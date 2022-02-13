#ifndef GUI
#define GUI

//#include "Libraries/include/SDL.h"
#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720
#include "../lib/include/SDL.h"

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Event *event;
} App;

//Creating window
App initSDL(void);

//Drawing white to the App Renderer
void drawSky(App app);

//Drawing a colour with the r g and b values
void drawColour(App app, int r, int g, int b);

//Draws the character
int drawCharacter(App app);

//Draws a rectangle
void drawRectangle(App app, int x, int y);

//cleans up when closed
void cleanUp(App app);

char pollEvents(App app, int *running);

App createWindow(int *x, int *y);


#endif