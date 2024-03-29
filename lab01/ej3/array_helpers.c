#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(
    int array[],
    unsigned int max_size,
    const char *filepath
    ){
        
    unsigned int length;
    FILE * f;
    f=fopen(filepath , "r");
    if (f == NULL)
    {
        printf("Error al leer el fichero \n");
        exit(EXIT_FAILURE);
    }
    
    fscanf(f , "%u" , &length);

    if (length > max_size)
    {
        exit(EXIT_FAILURE);
    } 
        
    for (unsigned int i = 0; i < length; i++)
    {
       fscanf(f , "%d", &array[i]);
    }
    
    fclose(f);

    return length;
}
    
void array_dump(int a[], unsigned int length) {

    printf("[");
    for (unsigned int i = 0; i < length; i++)
    {
        if (i < length - 1)
        {
            printf(" %d,", a[i]); 
        } else {
            printf(" %d", a[i]); 
        }
    }
    printf("] \n");
}