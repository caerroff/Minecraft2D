/*
*   
*This is how the versioning works:
*{isReleased = 0}.{isPlayable = 0}.{ver = 3}
*	MC2D Build 0.0.3
*/


#include <stdio.h>
#include <stdlib.h>
#include "../lib/include/SDL.h"
#include "GUI.h"
#include "util.h"
#include "Physics.h"


//Version number
#define VERSION "0.0.3"

typedef struct{
    int x;
    int y;
    int xVel;
    int yVel;
}Perso;

int main(void){
    printf("Version %s\n", VERSION);
    Perso square;
    square.x = 500;
    square.y = 500;

    int x = 500;
    int y = 400;
    int running = 1;
    int *point = &running;
    App app = createWindow();
    while(running){
		gravity(square.y);
		SDL_Delay(1);
		switch(pollEvents(app, point)){
			case -1:
                cleanUp(app);
                running = 0;
                break;
            case 1:
				while(y>220){
					int *pointY = &y;
                    jump(&square.y);
					drawRectangle(app, &square.x, &square.y);
					SDL_Delay(0.5);

				}
				break;
            case 2:
                 ;
                int copyX = square.x;
                while(square.x != copyX+10){
                    x = x+1;
                    drawRectangle(app, &square.x, &square.y);
                }
                    
                
                break;
            
            case 3:
                square.x = square.x-10;
                break;
		}
		drawRectangle(app, square.x, square.y);
	}
    return 0;
}