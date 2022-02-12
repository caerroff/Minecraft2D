#include <stdio.h>
#include "GUI.h"
#include <stdlib.h>
#include "util.h"
#include "Physics.h"


int createWindow(int *x, int *y){
	int running;
	int *point;
	running = 1;
	point = &running;
	App app = initSDL();
	
	drawSky(app);
	while(running){
		gravity(y);
		SDL_Delay(1);
		switch(pollEvents(app, point)){
			case 'Z':
				while(*y>220){
					jump(y);
					drawRectangle(app, *x, *y);
					SDL_Delay(0.5);

				}
				break;
		}
		drawRectangle(app, *x, *y);
	}
	/*
    Penser a utiliser scanf comme ca:
    scanf("%d", &reference) <---- reference vers la variable
    */

    return 0;
}

void drawSky(App app){
	SDL_SetRenderDrawColor(app.renderer, 159, 233, 255, 255);

	SDL_RenderClear(app.renderer);

	SDL_RenderPresent(app.renderer);
}


int drawCharacter(App app){
	SDL_Surface* image = SDL_LoadBMP("../sprite/apple.bmp");
	if(!image)
	{
    	printf("Erreur de chargement de l'image : %s",SDL_GetError());
    	return -1;
	}
	SDL_Texture* monImage = SDL_CreateTextureFromSurface(app.renderer,image); 
	
	
	SDL_GetWindowSurface(app.window);

	return 0;
}

void drawColour(App app, int r, int g, int b){

	SDL_SetRenderDrawColor(app.renderer,r,g,b,255 );

	SDL_RenderClear(app.renderer);
	
	SDL_RenderPresent(app.renderer);
}

void drawRectangle(App app, int x, int y){
	SDL_RenderClear(app.renderer);

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = 200;
    rect.h = 200;

    SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(app.renderer, &rect);
	SDL_RenderFillRect(app.renderer, &rect);
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

    SDL_RenderPresent(app.renderer);

}

void cleanUp(App app)
{
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    SDL_Quit();
}


char pollEvents(App app, int * running)
{
	SDL_Event e;
	while(SDL_PollEvent(&e) != 0){
   		switch(e.type){
				case SDL_QUIT:
					cleanUp(app);
					*running = 0;
					break;	

			
				case SDL_KEYUP:
					break;
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym){
						case 122:
							return 'Z';
							break;
						default:
							printf("%s\n", SDL_GetKeyName(e.key.keysym.sym));
							printf("%x\n", e.key.keysym.sym);
							break;
					}
					break;
				
				case 771:
					break;

				case 1024:
					break;

				case SDL_MOUSEBUTTONUP:
					break;
				case SDL_MOUSEBUTTONDOWN:
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