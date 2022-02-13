#include <stdio.h>
#include "util.h"
#include <time.h>
#include <stdlib.h>



int rd(int max){
    srand(time(NULL));
    return (rand() % (max + 1));
}

