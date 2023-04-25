#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    y = &x;
    if(x<0){
        x = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración1
    int *y = NULL;
    a = -10;

    absolute(a, y);
    res = *y;
    
    printf("absolute = %d \n", res);

    /* Violacion de segmento */

    return EXIT_SUCCESS;
}

