#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        printf("Error, debe de ingresar un archivo.in \n");
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int data_from_file(
    const char *path,
    unsigned int indexes[],
    char letters[],
    unsigned int max_size
    ){
    
    FILE *file;
    file = fopen(path, "r");

    if (file == NULL)
    {
        printf("Error al leer el archivo \n");
        exit(EXIT_FAILURE);
    }
    
    unsigned int i = 0;
    
    while ((!feof(file)) && i < max_size)
    {
        int ctrl = fscanf(file,"%u -> *%c*\n", &indexes[i], &letters[i]);

        if (ctrl != 2)
        {
            printf("Error de argumentos \n");
            exit(EXIT_FAILURE);
        }
        
        if (indexes[i] > max_size)
        {
            printf("Error, supero el limite del arreglo. \n");
            exit(EXIT_FAILURE);
        }
        
        i++;
    }

    return i;
}

void sort(
    unsigned int length,
    unsigned int indexes[],
    char letters[],
    char sorted[]
    ){
    

    for (unsigned int i = 0; i < length; i++)
    {
        int n = indexes[i];
        sorted[n] = letters[i];
    }
}

int main(int argc, char *argv[]) {
    char *file = NULL;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0;

    file = parse_filepath(argc, argv);
    
    length = data_from_file(file,indexes,letters,MAX_SIZE);

    sort(length,indexes,letters,sorted);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

