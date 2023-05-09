#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

void set_name(name_t new_name, data_t *d) {

    int i = 0;

    while (new_name[i] != '\0')
    {
        d->name[i] = new_name[i];

        i++;
    }

    d->name[i] = '\0';
    
}

int main(void) {
    data_t *p = NULL;

    printf("before  \n");

    data_t messi = {"Leo Messi", 35, 169};
    print_data(messi);
    name_t messi_full_name = "Lionel Messi";

    p = &messi;

    printf("after \n");
    set_name(messi_full_name, p);
    print_data(messi);

    return EXIT_SUCCESS;
}

