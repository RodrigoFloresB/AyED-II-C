/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"


void swap(player_t *a, unsigned int i, unsigned int j){
    player_t temp;
    
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

unsigned int partition(player_t *a, unsigned int izq, unsigned int der) {

    unsigned int piv = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;
    
    while(i <= j){
        if(goes_before(a[i], a[piv])){
            i= i+1;
        }else if(goes_before(a[piv], a[j])){
            j=j-1;
        }else if(!goes_before(a[i], a[piv]) && !goes_before(a[piv], a[j])){
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, piv, j);
    piv = j;
    
    return piv;
}

void quick_sort_rec(player_t *a, unsigned int izq, unsigned int der) {

    unsigned int piv = 0u;
    if (izq < der){
        piv = partition(a, izq, der);
        quick_sort_rec(a, izq, (piv == 0u) ? piv : piv-1);
        quick_sort_rec(a, piv+1, der);
    }
}

bool goes_before(player_t x, player_t y){
    bool is_before = (*x).rank <= (*y).rank;
    return is_before;
}

bool array_is_sorted(player_t *atp, unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

