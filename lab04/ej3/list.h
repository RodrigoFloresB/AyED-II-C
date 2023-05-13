#ifndef _LIST_H
#define _LIST_H

typedef struct _list * list;

typedef int list_elem;

struct _list {
	list_elem value;
	struct _list *next;
};



/* Constructos */

list empty(); 
// Crea una lista vacia.

void addl(list_elem e, list l);
// Agrega el elemento e al comienzo de la lista l.


/* Destroy */
void destroy(list l);
// Libera memoria en caso que sea necesario.


/* Operations */

bool is_empty(list l);
// Devuelve true si l es vacia.

list_elem head(list l);
// Devuelve el primer elemento de la lista l.
// PRE : not is_empty(l).

void tail(list l);
// Elimina el primer elemento de la lista l.
// PRE : not is_empty(l).

void addr(list l, list_elem e);
// Agrega el elemento e al final de la lista l.

unsigned int length(list l);
// Devuelve la cantidad de elementos de la lista l.

void concat(list l,list l0);
// Agrega al final de l todos los elementos de 
// l0 en el mismo orden.

list_elem index(list l, unsigned int n);
// Devuelve el n-esimo elemento de la lista l.
// PRE : length(l) > n .

void take(list l, unsigned int n);
// Deja en l solo los primeros n
// elementos, eliminando el resto.

void drop(list l, unsigned int n);
// Elimina los primeros n elementos de l.

list copy_list(list l1);
// Copia todos los elementos de l1
// en la nueva lista l2.

#endif