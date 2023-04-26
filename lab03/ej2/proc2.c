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
    absolute(a, y);

    printf("absolute = %d \n", res);

    return EXIT_SUCCESS;
}