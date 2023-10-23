#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int belongs(const List list, int elem){
    return list == NULL;
}

size_t size(const List list){
    if(isEmpty(list)) // o if( list == NULL )
        return 0;
    return 1 + size(list->tail); // voy pasando de elemento a elemento con la tail, que es un puntero a la "sub-lista"
}

size_t sizeIter(List list){
    size_t cant = 0;
    while(list != NULL){
        cant++;
        list = list->tail;
    }
    return cant;
}

int belongs(const List list, int elem){
    if(isEmpty(list) || list->head > elem)
        return 0;
    if(list->head == elem)
        return 1;
    
    return belongs(list->tail,elem);
}

int main(){

    List myList = NULL;
    assert(size(myList) == 0);
    assert(belongs(myList, 10)==0);





    return 0;
}