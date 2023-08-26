#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
	stack empty = malloc(sizeof(stack));
    empty->elems = malloc(sizeof(stack_elem));
    empty->capacity = 1;
    empty->size = 0;

	return empty;
}

stack stack_push(stack s, stack_elem e){

	if (s->size == s->capacity)
	{
		unsigned int AuxCap = s->size == 0 ? 1: (2*s->size);

		s->elems = realloc(s->elems, AuxCap * sizeof(stack_elem));
		s->capacity = AuxCap;
	}

	s->elems[s->size] = e;
	s->size = s->size + 1;
	
	return s;
}

stack stack_pop(stack s){
	assert(!stack_is_empty(s));
	
	s->size = s->size - 1;

	return s;
}

unsigned int stack_size(stack s){
	unsigned int res = s == NULL ? 0 : s->size;

	return res;
}

stack_elem stack_top(stack s){
	assert(!stack_is_empty(s));
	stack_elem res = s->elems[s->size - 1];	
	
	return res;
}

bool stack_is_empty(stack s){
	bool res = s == NULL;

	return res;
}


stack_elem *stack_to_array(stack s){
	stack_elem *res = calloc(stack_size(s), sizeof(stack_elem));
	stack aux = s;

	if (stack_is_empty(aux))
	{
		res = NULL;
	} else {
		for (unsigned int  i = stack_size(aux); i > 0; i--)
		{
			res[i-1] = s->elems[i-1];
		}
	}

	return res;
}

stack stack_destroy(stack s){
	free(s->elems);
	free(s);

	return s;
}