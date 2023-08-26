#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include <assert.h>
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y){
    pair_t res;
    res.fst = x;
    res.snd = y;

    // POS: {p --> (x, y)}
    assert(res.fst == x && res.snd == y);

    return res;
}

int pair_first(pair_t p){

    // PRE: {p --> (x, y)}

    int x = p.fst;

    // POS: {fst == x}
    assert(p.fst == x);
    
    return x;
}


int pair_second(pair_t p){
    // PRE: {p --> (x, y)}

    int y = p.snd;

    // POS: {snd == y}
    assert(p.snd == y);

    return y;
}

pair_t pair_swapped(pair_t p){
    // PRE: {p --> (x, y)}

    pair_t res;
    res.fst = pair_second(p);
    res.snd = pair_first(p);

    // POS: {pair_first(q) == pair_second(p) 
    //   && pair_second(q) == pair_first(p)}
    assert(res.fst == p.snd && res.snd == p.fst);

    return res;
}

pair_t pair_destroy(pair_t p){
    p.fst = 0;
    p.snd = 0;

    return p;
}
