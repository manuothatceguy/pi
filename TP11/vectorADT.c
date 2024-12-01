#include "vectorADT.h"
#include <stdlib.h>

typedef struct Tvec {
    elemType elem;
    char occupied; // indica si está ocupado o no (1: ocupado)
} Tvec;

struct vectorCDT {
    size_t dim; // cantidad de elementos
    size_t size; // cantidad de espacio reservado
    Tvec * vec; // el vector con los elementos. vector de struct, no vector de punteros!
    compare cmp; // función de comparación
};

// Opciones para ver si hay algo:
    /**
     * Vector de 0 y 1 para marcas de si están ocupados o no.
     * Struct que tenga un elemtype y una marca on off ! ELEGIMOS ESA !
     * Vector de punteros a elemtype y sino null
    */

vectorADT newVector(compare cmp){
    vectorADT aux = calloc(1,sizeof(struct vectorCDT));
    aux->cmp = cmp;
    return aux;
}

void freeVector(vectorADT v){
    free(v->vec);
    free(v);
}



int put(vectorADT v, elemType * elems, size_t dim, size_t index){
    size_t end = index+dim;
    if(end >= v->size){ // mayor o igual pq no accedo al index size, voy de 0 a size-1
        // Debemos agrandar el vector
        v->vec = realloc(v->vec,end*sizeof(Tvec));
        // Debemos marcar las nuevas posiciones como no ocupadas
        for(int i = v->size; i < end; i++){
            v->vec[i].occupied = 0; // va . porque es vector de estructuras y no vector de PUNTEROS A ESTRUCTURAS
        }
        v->size = end;
    }
    // Ahora debemos recorrer elems e ir guardando los elemtnso a partir de index
    // en las posiciones que estaban libres, hay que retornar la cantidad de elementos q guardamos
    int cant = 0;
    for(int j = index, i = 0; j < end; j++, i++){
        if(v->vec[j].occupied == 0){
            v->vec[j].occupied = 1;
            v->vec[j].elem = elems[i];
            cant++;
        }
    }
    v->dim += cant; // lo hago al final pq no se cuantos estoy agregando
    return cant;
}

void deleteElement(vectorADT v, size_t index){
    // si en index no hay un elemento, no hace nada
    if(index < v->size && v->vec[index].occupied == 1){
        v->vec[index].occupied = 0;
        v->dim--;
    }
}

// "strchr genérico"
int getIdx(vectorADT v, elemType elem){
    for(int i = 0; i < v->size; i++){
        if(v->vec[i].occupied == 1 && v->cmp(v->vec[i].elem,elem) == 0){
            return i;
        }
    }
    return -1;
}