#include <stdio.h>
#include "Libraries/include/SDL.h"
#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720


typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

App initSDL(void);
void drawBlack(App app);

int main(void){
    printf("coucou le monde\n");
	App app = initSDL();
	drawBlack(app);
	char answer;
	scanf("%c", &answer);
	if(answer == 'e'){
		printf("GoodBye");
	}
	/*
    Penser a utiliser scanf comme ca:
    scanf("%d", &reference) <---- reference vers la variable
    */

    return 0;
}

void drawBlack(App app){
	SDL_SetRenderDrawColor(app.renderer, 135, 206, 235, 255);

	SDL_RenderClear(app.renderer);

	SDL_RenderPresent(app.renderer);
}


App initSDL(void)
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	App app;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("MC2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
	return app;
}