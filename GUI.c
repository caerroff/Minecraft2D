#include <stdio.h>
#include "GUI.h"
#include <stdlib.h>




int createWindow(void){
	int running;
	int *point;
	running = 1;
	point = &running;
	App app = initSDL();
	
	char answer;
	while(running){
		drawBlack(app);
		pollEvents(app, point);
	}
	/*
    Penser a utiliser scanf comme ca:
    scanf("%d", &reference) <---- reference vers la variable
    */

    return 0;
}

void drawBlack(App app){
	SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

	SDL_RenderClear(app.renderer);

	SDL_RenderPresent(app.renderer);
}

void drawColour(SDL_Renderer *renderer, int r, int g, int b){
	SDL_SetRenderDrawColor(renderer,r,g,b,255 );
}

void cleanUp(App app)
{
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}


void pollEvents(App app, int * running)
{
	SDL_Event e;
	while(SDL_PollEvent(&e) != 0){
   		switch(e.type){
				case SDL_QUIT:
					cleanUp(app);
					*running = 0;
					break;	

				case SDL_WINDOWEVENT_FOCUS_LOST:
					printf("yep\n");
					SDL_MinimizeWindow(app.window);
					break;

			
				case SDL_KEYUP:
					break;
				case SDL_KEYDOWN:
					printf("%s\n", SDL_GetKeyName(e.key.keysym.sym));
					break;
				
				case 771:
					break;

				case SDL_WINDOW_MOUSE_FOCUS:
					printf("%x\n",SDL_GetMouseState);
					break;

				default:
					printf("%d \n", e.type);
					break;

		}
		
	}
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