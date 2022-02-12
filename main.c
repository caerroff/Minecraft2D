/*
*   
*This is how the versioning works:
*{isReleased = 0}.{isPlayable = 0}.{ver = 1}
*	MC2D Build 0.0.1
*/


#include <stdio.h>
#include <stdlib.h>
#include "Libraries/include/SDL.h"
#include "GUI.h"
#include "util.h"
#include "Physics.h"


//Version number
#define VERSION "0.0.1"

int main(void){
    printf("Version %s\n", VERSION);

    createWindow();
    return 0;
}