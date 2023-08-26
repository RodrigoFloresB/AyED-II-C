#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

/* Constructos */

list empty(){
	list l = NULL;

	return l;
}

list addl(list_elem e, list l){
	list p = malloc(sizeof(struct _list));
	p->value = e;
	p->next = l;
	l = p;
	free(p);

	return l;
}

/* Destroy */

void destroy(list l){
	free(l);
}

/* Operations */

bool is_empty(list l){
	bool res = false;
	
	if (l == NULL)
	{
		res = true;
	}
	
	return res;
}

list_elem head(list l){
	assert(!is_empty(l));
	
	list_elem res = l->value;

	return res;
}

list tail(list l){
	assert(!is_empty(l));

	list p = malloc(sizeof(struct _list));
	p = l;
	l = l->next;
	free(p);

	return l;
}

list addr(list l, list_elem e){
	list p = empty();
	list q = empty();
	p = malloc(sizeof(struct _list));
	q->value = e;
	q->next = NULL;

	if (!is_empty(l))
	{
		p = l;

		while (p->next != NULL)
		{
			p = p->next;
		}

		p->next = q;
	} else {
		l = q;
	}

	return l;
}

unsigned int length(list l){
	list p = empty();
	unsigned int count = 0;
	p = l; 
	
	while (p != NULL)
	{
		++count;
		p = p->next;
	}

	return count;
}

list concat(list l0, list l1){
    list aux, copy;
    aux = l0;
    copy = l1;
	
    if(aux != NULL){

        while (aux->next != NULL ){
            aux = aux->next;
        }

        aux->next = copy;

    } else {
        l0 = copy;
    }

    return l0;
}

list_elem index(list l, unsigned int n){
	assert(length(l) > n);

	list copy = l;

	for (unsigned int i = 0; i < n; i++)
	{
		copy = copy->next;
	}

	l = copy;

	free(copy);

	return l->value;
}

list take(list l, unsigned int n){
	list copy = l;

	if (n == 0)
	{
		copy = NULL;
	} else {
		for (unsigned int i = 0; copy->next != NULL && i < n; i++)
		{
			copy = copy->next;
		}

		l = copy;
	}

	free(copy);

	return l;
}

list drop(list l, unsigned int n){

	while (n > 0)
	{
		l = l->next;
		--n;
	}
	
    return l;
}

list copy_list(list l1){
	list copy = l1;

	return copy;
}