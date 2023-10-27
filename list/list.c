#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int isEmpty(const List list){
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

List add(List list, int elem){
    //Vacia
    if(list == NULL || list->head > elem){ //o if(isEmpty(list)). si es igual cambio > por >=
        List aux = malloc(sizeof(struct node)); // struct node * aux
        aux->head = elem;
        aux->tail = list;
        return aux; // aux es un puntero, lo devuelvo y se lo asigno a mi lista
    }
    
    // Ya sabemos que list NO es NULL y elem es mayor o igual al primero

    if(elem == list->head){
        return list;
    }

    // elem es mayor que el primero, hay que insertarlo en la sublist

    list->tail = add(list->tail,elem); //paso recursivo, ir de tail en tail.
    return list;
}

List delete(List list, int elem){
    if(isEmpty(list) || elem < list->head){
        return list;
    }
    if(list->head == elem){ // Libero y desp retorno, entonces uso aux
        List aux = list->tail;
        free(list);
        return aux;
    }
    // El elemento puede estar en la sublista.
    list->tail = delete(list->tail,elem);
    return list;

    /*
    Si yo hago:
        return delete(list->tail,elem)

        Borro a partir de elem.
    */

}

void freeList(List list){
    if (list == NULL){
        return;
    }
    // Recursividad de pila. Libero sublista y desp nodo.
    freeList(list->tail);
    free(list);
}


/*Devuelve el primer elemento, aborta si la lista está vacía*/
int head(List list){
    if( list == NULL ){
        fprintf(stderr, "List no puede ser null\n");
        exit(1);
    }
    return list->head;
}

/*Devuelve la sublista*/
List tail(List list){
    return list->tail;
}

int get(List list, size_t idx){
    if(list == NULL){
        exit(0);
    }
    
    if(idx == 0){
        return list->head;
    }
    return get(list->tail,idx-1);
}

int main(){

    List myList = NULL;
    assert(size(myList) == 0);
    assert(belongs(myList, 10)==0);

    // Iterar por los elementos

    List aux = myList;
    while(! isEmpty(myList)){
        printf("%d",myList->head);
        aux = myList->tail;
    }
    printf("%d",head(NULL));
    free(myList);

    return 0;
}