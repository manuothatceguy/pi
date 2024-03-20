#include <stdio.h>
#include <stdlib.h>
#include "ej11.h"
#include <assert.h>

struct vectorCDT{
    elemType * vec;
    int (*compare)(elemType source, elemType target);
    size_t dim;
    size_t size;
    char * isEmpty;
};

vectorADT newVector(int (*compare)(elemType source, elemType target)){
    vectorADT v = calloc(1,sizeof(struct vectorCDT));
    v->compare = compare;
    return v;
}

void freeVector(vectorADT v){
    if(v != NULL){
        free(v->vec);
        free(v->isEmpty);
    }
    free(v);
}

size_t put(vectorADT v, elemType * elems, size_t dim, size_t index){
    if(elems==NULL)
        return 0;
    if(dim+index > v->size){
        v->vec=realloc(v->vec, sizeof(elemType)*(dim + index));

        v->isEmpty=realloc(v->isEmpty, sizeof(char)*(dim + index));

        for(size_t i=v->size; i < dim + index; i++)
            v->isEmpty[i] = 1;
        v->size = dim + index;
    }
    size_t count=0;
    for(size_t i=index, j=0; i < index+dim; i++, j++){
        if(v->isEmpty[i]){
            v->vec[i]=elems[j];
            v->isEmpty[i]=0;
            count++;
            v->dim++;
        }
    }
    return count;
}


int getIdx(vectorADT v, elemType elem){
    for(size_t i = 0; i < v->size; i++){
        if(! v->isEmpty[i] && v->compare(v->vec[i],elem) == 0){
            return i;
        }
    }
    return -1;
}

void deleteElement(vectorADT v, size_t index){
    if(index>=v->size){
        return;
    }
    if( ! v->isEmpty[index]){
        v->isEmpty[index] = 1;
        v->dim--;
    }
    return;
}

int elementCount(vectorADT v){
    return v->dim;
}


int compInt (elemType source, elemType target) {
    return source - target;
}

int main(void) {
    
    vectorADT v = newVector(compInt);
    elemType elems[] = {1, 2, 10, 20, 100, -2, 4};
    elemType elems2[]= {1, 3, 4, 10, 22, 33};

    assert( getIdx(v, elems[2]) == -1);
    
    assert( put(v, elems, 7, 3) == 7);    // v queda {vacio, vacio, vacio, 1, 2, 10, 20, 100, -2, 4}
    assert(elementCount(v)==7);
    assert( getIdx(v, 1) == 3);
    assert( getIdx(v, 2) == 4);
    assert( getIdx(v, 10) == 5);
    assert( getIdx(v, 22) == -1);
    assert( put(v, elems2, 6, 0) == 3);   // v queda {1, 3, 4, 1, 2, 10, 20, 100, -2, 4}
    assert( getIdx(v, 22) == -1);
    assert( getIdx(v, 1) == 0);
    assert( getIdx(v, 3) == 1);
    assert(elementCount(v)==10);
    assert( put(v, elems2, 6, 0) == 0);   // v queda igual
    assert( getIdx(v, 1) == 0);
    assert(elementCount(v)==10);
    deleteElement(v, 100);
    assert(elementCount(v)==10);
    deleteElement(v, 0);
    assert( getIdx(v, 1) == 3);
    assert(elementCount(v)==9);
    // Volvemos a borrar el 0, no deberia decrementar la cantidad
    deleteElement(v, 0);
    assert(elementCount(v)==9);
    assert( getIdx(v, 1) == 3);
    
    assert( put(v, elems2 + 5, 1, 12) == 1);   // v queda {vacio, 3, 4, 1, 2, 10, 20, 100, -2, 4. vacio, vacio, 33}
    assert(elementCount(v)==10);
    assert( getIdx(v, 33) == 12);
    assert( getIdx(v, 0) == -1);

    freeVector(v);
    
    puts("OK!");

    return 0;
}