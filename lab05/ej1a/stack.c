#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
	stack_elem elem;
	stack next;
};

stack stack_empty(){
	stack empty = NULL;

	return empty;
}

stack stack_push(stack s, stack_elem e){
	stack aux = malloc(sizeof(struct _s_stack));
	
	aux->elem = e;
	aux->next = s;
	s = aux;

	return s;
}

stack stack_pop(stack s){
	assert(! stack_is_empty(s));
	
	s = s->next;

	return s;
}

unsigned int stack_size(stack s){
	unsigned int res = 0;
	stack aux = s;

	while (aux != NULL)
	{
		aux = aux->next;
		res++;
	}
	
	return res;
}

stack_elem stack_top(stack s){
	assert(!stack_is_empty(s));

	return s->elem;
}

bool stack_is_empty(stack s){
	bool res = (s == NULL);

	return res;
}

stack_elem *stack_to_array(stack s){
	stack_elem *res = calloc(stack_size(s), sizeof(stack_elem));
	stack aux = s;

	if (stack_is_empty(aux))
	{
		free(res);
		res = NULL;
	} else {
		for (unsigned int  i = stack_size(aux); i > 0; i--)
		{
			res[i-1] = stack_top(aux);
			aux = aux->next;
		}
	}

	return res;
}

stack stack_destroy(stack s){
	stack aux = s;

	while (s != NULL)
	{
		s = s->next;
		free(aux);
		aux = s;
	}

	s = NULL;

	return s;
}