#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = length + 1 ;
    
    for (int i = 0; (unsigned) i < length; i++)
    {
        if (value < arr[i])
        {
            res.is_upperbound = false;
        }
        if (value > arr[i])
        {
            res.is_lowerbound = false;
        }
        if (value == arr[i])
        {
            res.exists = true;
            res.where = i;
        } 
    }
    
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value;
    int elem;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
	    printf("Ingrese el elemento en la posicion %d : ", i);
	    scanf("%d", &elem);
	    a[i] = elem;
    }
    
    printf("Ingrese el valor a comparar : ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if ((result.is_upperbound == true) && (result.exists == false))
    {
        printf("Es cota superior");
    }

    if ((result.is_lowerbound == true) && (result.exists == false))
    {
        printf("Es cota inferior");
    }

    if ((result.is_upperbound == true) && (result.exists == true))
    {
        printf("Maximo en la posicion %d ", result.where);
    }

    if ((result.is_lowerbound == true) && (result.exists == true))
    {
        printf("Minimo en la posicion %d ", result.where);
    }
    
    if ((result.is_upperbound == false) && (result.is_lowerbound == false))
    {
        printf("Nada nadita");
    }
    
    return EXIT_SUCCESS;
}