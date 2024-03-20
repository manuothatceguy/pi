#include "setADT.h"
#include <stdio.h>
#include <assert.h>

static int compare (elemType e1, elemType e2){
    return e1-e2;
}

int main (void){
    setADT mySet=newSet(compare);

    int v[]={1,2,3,4,5,6,7,8,9,10};

    assert(size(mySet)==0);

    for (size_t i = 0; i < 10 ; i++){
        assert(add( mySet ,v[i] )== (i+1));
    }
    int * auxMax, * auxMin, * auxLast;
    auxMax = max(mySet);
    auxLast = last(mySet);
    auxMin = min(mySet);
    
    assert(*auxMax==10 && *auxLast==10);
    assert(*auxMin==1);
    assert(size(mySet)==10);
    free(auxMax);
    free(auxMin);
    free(auxLast);

    for (size_t i = 0; i < 10 ; i++){
        assert(add( mySet ,v[i]) == (10));
    }

    add(mySet, 25);
    auxMax = max(mySet);
    assert(*auxMax==25);
    free(auxMax);

    int *w=setToArray(mySet);
    size_t i;

    for ( i = 0; i < 10 ; i++)    {
        assert(v[i]==w[i]);
    }
    assert( 25==w[i]);

    puts("Legendary!!!");

    return 0;
}