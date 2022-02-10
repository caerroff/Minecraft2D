#include <stdio.h>
#include "Physics.h"
#include "util.h"

int main(void){
    printf("coucou le monde\n");
    printf("%d \n",ceciEstUnTest());
    int test = renvoyer2();
    printf("%d \n", test);

    /*
    Penser a utiliser scanf comme ca:
    scanf("%d", &reference) <---- reference vers la variable
    */

    return 0;
}
