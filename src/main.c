/*
*   
*This is how the versioning works:
*{isReleased = 0}.{isPlayable = 0}.{ver = 2}
*	MC2D Build 0.0.2
*/


#include <stdio.h>
#include <stdlib.h>
#include "../lib/include/SDL.h"
#include "GUI.h"
#include "util.h"
#include "Physics.h"


//Version number
#define VERSION "0.0.1"

int main(void){
    printf("Version %s\n", VERSION);
    int x = 500;
    int y = 400;
    createWindow(&x, &y);
    return 0;
}