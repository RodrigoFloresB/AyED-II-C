#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main(){
	
	stack list = stack_empty();
	list = stack_push(list, 10000);
	list = stack_pop(list);

	for (int i = 0; i < 10; i++)
	{
		list = stack_push(list, i);
	}
	
	unsigned int ss = stack_size(list); 
	bool sie = stack_is_empty(list);
	stack_elem st = stack_top(list);
	
	printf("length = %u , vacio = %d , tope = %d \n", ss, sie, st);

	stack_elem *array = stack_to_array(list);
	stack_elem aux = array[3];

	printf("array[3] = %d \n", aux);

	free(array);
	list = stack_destroy(list);

	return 0;
}