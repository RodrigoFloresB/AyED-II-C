#include <stdio.h>
#include <stdlib.h>
#include "strfuncs.h"

size_t string_length(const char *str){
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	
	return length;
}

char *string_filter(const char *str, char c){
	size_t length = 0;
	size_t aux = string_length(str);

	/* Calcular la nueva longitud */

	for (size_t i = 0; i < aux; i++)
	{
		if (str[i] != c)
		{
			length++;
		}
	}

	char *res = malloc(sizeof(char) * (length++));

	size_t j = 0;

	for (size_t i = 0; i < aux; i++)
	{
		if (str[i] != c)
		{
			res[j] = str[i];
			j++;
		}
	}

	res[j] = '\0';

	return res;
}