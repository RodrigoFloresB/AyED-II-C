#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int length;
    int i = 0;
    
    while (s[i] != '\0')
    {
        i++;
    }
    
    length = i;

    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool cadenaIgual = true;

    if (fstring_length(s1) == fstring_length(s2))
    {
        for (unsigned int i = 0; (i < fstring_length(s1)) && (cadenaIgual == true); i++)
        {
            if (s1[i] != s2[i])
            {
                cadenaIgual = false;
            }
        }
    } else {
        cadenaIgual = false;
    }

    return cadenaIgual;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool ordenAbc = false;

    if (fstring_length(s1) <= fstring_length(s2))
    {
        unsigned int i = 0;

        while (i < fstring_length(s1) && (ordenAbc == false))
        {
            if (s1[i] == s2[i])
            {
                i++;
            }

            if (s1[i] < s2[i])
            {
                ordenAbc = true;
            }

            if (s1[i] > s2[i])
            {
                i = fstring_length(s1);
            }
        }
    } else {
        
        unsigned int i = 0;

        while (i < fstring_length(s1) && (ordenAbc == false))
        {
            if (s1[i] == s2[i])
            {
                i++;
            }

            if (s1[i] < s2[i])
            {
                ordenAbc = true;
            }

            if (s1[i] > s2[i])
            {
                i = fstring_length(s1);
            }
        }      
    }

    return ordenAbc;
}

