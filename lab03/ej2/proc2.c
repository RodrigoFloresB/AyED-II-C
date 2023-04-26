#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    *y = x;
    if(x < 0) {
        *y = -x;
    }
}

int main(void) {
    int a = 0, res = 0;
    int *y = NULL;
    a = -10;

    y = &res; 
    /* El puntero apunto a res */
    absolute(a, y);
    /* Luego de ejecutar absolute res aloja el |a| */

    printf("absolute = %d \n", res);

    return EXIT_SUCCESS;
}