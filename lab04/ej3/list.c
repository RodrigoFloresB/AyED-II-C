#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

/* Constructos */

list empty(){
	list l = NULL;

	return l;
}

void addl(list_elem e, list l){
	list p = malloc(sizeof(struct _list));
	p->value = e;
	p->next = l;
	l = p;
	free(p);
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

void tail(list l){
	assert(!is_empty(l));

	list p = malloc(sizeof(struct _list));
	p = l;
	l = l->next;
	free(p);
}

void addr(list l, list_elem e){
	list p, q;
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
}

