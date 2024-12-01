#include "listADT.h"
#include <stdlib.h>
#include <stdio.h>

// Estructura interna para los nodos de las listas. El usuario no sabe de esto.
typedef struct node{
    elemType head;
    struct node * tail;
}node;

typedef node* TList;

struct listCDT{
    TList first;
    size_t dim; // cantidad de elementos para hacer mas eficiente la función sizeList (tamaño)
    compare cmp;
    TList next; // apunta al siguiente de la lista. concepto de iteradores
};
/**
 * Crear una lista nueva inicializada en 0
*/

listADT newList(compare cmp){
    listADT aux = calloc(1,sizeof(struct listCDT));
    aux->cmp = cmp;
    return aux;
}

static void freeListRec(TList list){
    if(list == NULL) // Caso base
        return;
    free(list->tail); // Recursión de pila
    free(list);
    // Recursión de cola

    // TList aux = list->tail;
    // free(list);
    //free(aux);
}

void freeListADT(listADT list){
    freeListRec(list->first);
    free(list);
}

void freeListADTIter(listADT list){
    TList aux = list->first;
    while(aux != NULL){
        TList subList = aux->tail;
        free(aux);
        aux = subList;
    }
    free(list);
}

int isEmptyList(listADT list){
    return list->dim == 0; // o list->first == NULL;
}

size_t sizeList(listADT list){
    return list->dim;
}

static int belongsRec(TList list, elemType elem, compare cmp){
    int c;
    if(list == NULL || (c = cmp(list->head, elem)) > 0){ // recordar lo que devuelve cmp!, c es la nueva variable que guarda lo que retorna cmp para no repetir codigo!!!! importante!
        return 0;
    }
    if(c == 0){
        return 1;
    }
    return belongsRec(list->tail,elem,cmp);
}

int belongsList(listADT list, elemType elem){
    return belongsRec(list->first, elem, list->cmp);
}

// Trabajamos con la lista interna 
// en *flag 1 si lo agrega, cero si no lo agrega
static TList addRec(TList list, elemType elem, compare cmp, int * flag){
    int c;
    if(list == NULL || (c = cmp(list->head,elem)) > 0){
        TList aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = list;
        *flag = 1;
        return aux;
    }
    if(c > 0){
        list->tail = addRec(list->tail,elem,cmp,flag);
    }
    return list;
}

int addList(listADT list, elemType elem){
    int flag = 0; // la inicializo, así es más fácil.
    list->first = addRec(list->first, elem, list->cmp, &flag);
    list->dim += flag; // suma 1 si lo agregó, 0 si no lo agregó
    return flag;
}

static TList deleteRec(TList list, elemType elem, compare cmp, int *flag){
    int c;
    if(list == NULL || (c = cmp(list->head,elem)) > 0){
        return list;
    }
    if(c == 0){
        *flag = 1;
        TList aux = list->tail;
        free(list);
        return aux;
    }
    // elem es mayor al primero, puede estar en la sublista
    list->tail = deleteRec(list->tail,elem,cmp,flag);
    return list;
}

int deleteList(listADT list, elemType elem){
    int flag = 0;
    list->first = deleteRec(list->first, elem, list->cmp, &flag);
    list->dim -= flag;
    return flag;
}

static elemType getRec(TList list, size_t idx){
    if(idx == 0){
        return list->head;
    }
    return getRec(list->tail,--idx);
}

elemType get(listADT list, size_t idx){
    if(list->dim <= idx){
        exit(1);
    }
    return getRec(list->first, idx);

    
}

elemType getListIter(listADT list, size_t idx){
    if(list->dim <= idx){
        exit(1);
    }
    TList aux = list->first;
    
    for(int i = 0; i < idx; i++, aux=aux->tail) // hasta no llegar al idx, me voy moviendo como lista
        ;
    return aux->head;
}

void toBegin(listADT list){
    list->next = list->first;
}

int hasNext(listADT list){
    return list->next != NULL;
}

elemType next(listADT list){
    if(hasNext(list)){
        elemType aux = list->next->head;
        list->next = list->next->tail;
        return aux;
    }
    fprintf(stderr,"No next here");
    exit(1);
}

elemType * toArray(listADT list){
    elemType * toReturn = malloc(list->dim * sizeof(elemType));
    TList aux = list->first;
    for(size_t i = 0; i < list->dim; i++, aux=aux->tail){
        toReturn[i] = aux->head;
    }
    return toReturn;
}

#define BLOCK 10

elemType * select(listADT list, int (*criteria)(elemType), size_t * dim){
    elemType * toReturn = NULL;
    size_t j = 0;
    TList aux = list->first;
    for(size_t i = 0; i < list->dim; i++, aux=aux->tail){
        if(criteria(aux->head)){
            if(j % BLOCK == 0){
                toReturn = realloc(toReturn, (j+BLOCK)*sizeof(elemType));
            }
            
            toReturn[j++] = aux->head;
        }
    }
    toReturn = realloc(toReturn,j * sizeof(elemType));
    *dim = j;
    return toReturn;
}

void mapRec(TList list, elemType(*mapFunc)(elemType)){
    if(list == NULL){
        return;
    }
    mapRec(list->tail,mapFunc);
    list->head = mapFunc(list->head);
    return;
}

void map(listADT list, elemType(*mapFunc)(elemType)){
    mapRec(list->first,mapFunc);
}
