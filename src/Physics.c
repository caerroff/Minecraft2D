#include <stdio.h>
#include "Physics.h"

int ceciEstUnTest(void){
    printf("Le test fonctionne\n");
    return 1;
}


void gravity(int *y){
    if(*y<520){
        printf("%d\n",*y);
        *y = *y+1;
    }
    
}


void jump(int *y){
        *y = *y -1;

}