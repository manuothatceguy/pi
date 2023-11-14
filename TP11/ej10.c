#include "ej10.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <strings.h>

typedef struct node{
    elemType head;
    size_t count;
    struct node * tail;
} tNode;

typedef struct node * tList;

struct bagCDT{
    tList elems;
    size_t dim;
    compare cmp;
};

static void freeElems(tList list){
    if(list == NULL){
        return;
    }
    freeElems(list->tail);
    free(list);
}

void freeBag(bagADT bag){
    freeElems(bag->elems);
    free(bag);
}

bagADT newBag(compare cmp){
    bagADT bag = calloc(1,sizeof(struct bagCDT));
    bag->cmp = cmp;
    return bag;
}

static tList addRec(tList list, elemType e, int * count, compare cmp){
    int c;
    if(list == NULL || (c = cmp(list->head,e)) > 0){
        tList aux = malloc(sizeof( tNode ));
        aux->head = e;
        aux->count = 1;
        aux->tail = list;
        *count = 1;
        return aux;
    } else if(c < 0){
        list->tail = addRec(list->tail,e,count,cmp);
    }
    else{
        *count = ++(list->count);
    }
    return list;
}

unsigned int add(bagADT bag, elemType elem){
    int count;
    bag->elems = addRec(bag->elems, elem, &count, bag->cmp);
    if(count == 1){
        bag->dim++;
    }
    return count;
}



unsigned int count(const bagADT bag, elemType elem){
    tList aux = bag->elems;
    int c;
    while((aux != NULL) && (c = bag->cmp(aux->head,elem)) < 0 ){
        aux = aux->tail;
    }
    if(c == 0){
        return aux->count;
    }
    return 0;
}

unsigned int size(const bagADT bag){
    return bag->dim;
}

elemType mostPopular(bagADT bag){
    if(bag->dim == 0){
        fprintf(stderr,"Error no puede estar vacio");
        exit(1);
    }else {
        tList aux = bag->elems;
        int max = aux->count;
        elemType maxElem = aux->head;
        while(aux != NULL){
            if(aux->count > max){
                max = aux->count;
                maxElem = aux->head;
            }
            aux = aux->tail;
        }
        return maxElem;
    }

}

// Utilizamos char * como elemType y strcasemp como compare
// Recuerden recompilar tp11_ej10.c si cambian el elemType

int main(void) {
	bagADT bag = newBag(strcasecmp);
	assert( add(bag, "agustina") == 1 );
	assert( add(bag, "Agustina") == 2 );
	assert( add(bag, "belen") == 1 );
	assert( add(bag, "carla") == 1 );
	assert( add(bag, "CARLA") == 2 );
	assert( add(bag, "carla") == 3 );
	assert( add(bag, "daniel") == 1 );
	assert( add(bag, "emilio") == 1 );

	assert( count(bag, "carla") == 3 );
	assert( count(bag, "agustina") == 2 );
	assert( count(bag, "amelia") == 0 );
	assert( count(bag, "emilio") == 1 );
	assert( count(bag, "daniel") == 1 );
	assert( count(bag, "belen") == 1 );
	assert( size(bag) == 5 );
	assert( strcasecmp(mostPopular(bag), "carla") == 0 );

    for(int i=2; i <= 10001; i++)
        assert( add(bag, "belen") == i );
    assert(count(bag, "carla") == 3);
    assert(count(bag, "belen") ==10001);
    assert( strcasecmp(mostPopular(bag), "belen") == 0 );

    freeBag( bag );
    puts("OK!");

    bag = newBag(strcasecmp);
    puts("Al buscar el más popular de un bag vacío debe abortar");
    mostPopular(bag);
    puts("Si ud. ve esto, entonces no abortó como debería haber hecho");
    return 0;
}