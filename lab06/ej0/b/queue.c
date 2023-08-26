#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

struct s_queue {
    unsigned int size;
    struct s_node *last;
    struct s_node *first;
};

struct s_node {
    queue_elem elem;
    struct s_node *next;
};

static struct s_node *
create_node(queue_elem e) {
    struct s_node *new_node=malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    return new_node;
}

static struct s_node *
destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}


static bool
invrep(queue q) {
    return q != NULL;
}

queue queue_empty(void) {
    queue q=NULL;
    q = malloc(sizeof(struct s_queue));
    q->last = NULL;
    q->first = NULL;
    q->size = 0;

    assert(invrep(q) && queue_is_empty(q));
    return q;
}

queue queue_enqueue(queue q, queue_elem e) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e);
    new_node->elem = e;
    new_node->next = NULL;

    if (q->first==NULL) {
        q->first = new_node;
        q->last = new_node;
        q->size = q->size + 1;
    } else {
        (q->last)->next = new_node;
        q->last = new_node;
        q->size = q->size + 1;
    }

    assert(invrep(q) && !queue_is_empty(q));
    
    return q;
}

bool queue_is_empty(queue q) {
    assert(invrep(q));
    return q->first == NULL;
}

queue_elem queue_first(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    return q->first->elem;
}
unsigned int queue_size(queue q) {
    assert(invrep(q));
    unsigned int size=0;

    size = q->size;
    
    return size;
}

queue queue_dequeue(queue q) {
    assert(invrep(q) && !queue_is_empty(q));
    struct s_node * killme=q->first;
    q->first = q->first->next;
    killme = destroy_node(killme);
    q->size -= 1;
    assert(invrep(q));
    return q;

}

queue queue_disscard(queue q, unsigned int n) {

    assert(n < q->size && invrep(q));
    
    if (n == 0) // Eliminar el primero
    {
        q = queue_dequeue(q);
    } 
  
    else if ( n > 0 && (q->size - 1) > n) // Eliminar al medio
    {
        struct s_node *aux, *elim;
        
        aux = q->first; 
        for (size_t i = 0; i < n-1; i++)
        {
            aux = aux->next;
        }

        elim = aux->next;
        aux->next = elim->next;
        
        elim = destroy_node(elim);
        elim = NULL;

        q->size -= 1;
    }

    else if ( n == q->size - 1) // Eliminar ultimo
    {
        struct s_node *aux = q->first;

        q->last = destroy_node(q->last);
        q->last = NULL;
        q->size -= 1;

        for (size_t i = 0; i < n-1; i++)
        {
            aux = aux->next;
        }

        q->last = aux;
        q->last->next = NULL;
    }

    assert(invrep(q));

    return q;
}

void queue_dump(queue q, FILE *file) {
    file = file==NULL ? stdout: file;
    struct s_node *node=q->first;
    fprintf(file, "[ ");
    while(node!=NULL) {
        fprintf(file, "%d", node->elem);
        node = node->next;
        if (node != NULL) {
            fprintf(file, ", ");
        }
    }
    fprintf(file, "]\n");
}

queue queue_destroy(queue q) {
    assert(invrep(q));
    struct s_node *node=q->first;
    while (node != NULL) {
        struct s_node *killme=node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}

