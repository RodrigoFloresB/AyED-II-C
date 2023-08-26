#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 35, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n",
            sizeof(messi.name), sizeof(messi.age), sizeof(messi.height),
            (sizeof(messi.name) + sizeof(messi.age) + sizeof(messi.height)));

    return EXIT_SUCCESS;
}

/* 

¿La suma de los miembros coincide con el total? Si.

¿El tamaño del campo name depende del nombre que contiene?
No, en este caso depende de NAME_MAXSIZE

*/
