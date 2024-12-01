#include "multiSetADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int count;
    elemType head;
    struct node * tail;
} TNode;

typedef TNode * TList;

typedef struct multiSetCDT{
    TList set;
    size_t cantDif;
} multiSetCDT;

/**
** Retorna 0 si los elementos son iguales, negativo si e1 es "menor" que e2 y positivo
** si e1 es "mayor" que e2
*/
static int compare ( elemType e1 , elemType e2 ){
    return e1-e2;
}

multiSetADT newMultiSet(){
    return calloc(1,sizeof(multiSetCDT));
}

static TList searchAndAdd(TList list, elemType elem, int * howMany, int howMuch){
    int c;
    if(list == NULL || (c = compare(list->head,elem)) > 0){
        TList new = malloc(sizeof(TNode));
        *howMany = new->count = 1;
        new->head = elem;
        new->tail = list;
        return new;
    }
    else if(c == 0){
        list->count+=howMuch;
        *howMany = list->count;
        if(list->count == 0){
            *howMany = -1;
        }
    }
    else{
        list->tail = searchAndAdd(list->tail,elem,howMany,howMuch);
    }
    return list;
}

unsigned int add(multiSetADT multiSet, elemType elem){
    int newAdded = 0;
    multiSet->set = searchAndAdd(multiSet->set,elem,&newAdded,1);
    if(newAdded == 1){
        multiSet->cantDif++;
    }
    return newAdded;
}

unsigned int count(const multiSetADT multiSet, elemType elem){
    TList aux = multiSet->set;
    for(int i = 0; i < multiSet->cantDif; i++, aux = aux->tail){
        if(compare(aux->head,elem) == 0){
            return aux->count;
        }
    }
    return 0;
}

unsigned int size(const multiSetADT multiSet){
    return multiSet->cantDif;
}

static TList searchAndDestroy(TList list, elemType elem, int *howMany) {
    if (list == NULL)
        return list;

    int c = compare(elem, list->head);

    if (c == 0) {
        list->count -= 1;
        *howMany = list->count;

        if (list->count == 0) {
            *howMany = -1;
            TList aux = list->tail;
            free(list);
            return aux;
        }
    } else {
        list->tail = searchAndDestroy(list->tail, elem, howMany);
    }

    return list;
}

int removeOne(multiSetADT multiSet, elemType elem) {
    int ret = 0;
    if (count(multiSet, elem) == 1) {
        multiSet->cantDif--;
    }

    multiSet->set = searchAndDestroy(multiSet->set, elem, &ret);

    if (ret == -1) {
        ret = 0;
    }
    return ret;
}


static TList bombaAtomica(TList list, elemType elem, int * deleted){
    if(list == NULL){
        return list;
    }
    if(compare(list->head,elem) == 0){
        TList aux = list->tail;
        *deleted = 1;
        aux->tail = list->tail->tail;
        free(list);
        return aux;
    }
    list->tail = bombaAtomica(list->tail,elem,deleted);
    return list;
}

void removeAll(multiSetADT multiSet, elemType elem){
    int loBorre = 0;
    multiSet->set = bombaAtomica(multiSet->set,elem,&loBorre);
    if(loBorre){
        multiSet->cantDif--;
    }
    return;
}



elemType * minElements(const multiSetADT multiSet, int * dim){
    int min = multiSet->set->count;
    int cantElems = 0;
    TList aux = multiSet->set;

    for(int i = 0; aux != NULL; i++, aux = aux->tail){
        if(aux->count == min){
            cantElems++;
        }
            
        else if(aux->count < min){
            cantElems = 1;
            min = aux->count;
        }
    }
    *dim = cantElems;
    elemType * retArr = malloc(cantElems*sizeof(elemType));
    aux = multiSet->set;
    int idx = 0;
    while(aux!=NULL){
        if(aux->count == min){
            retArr[idx++] = aux->head;
        }
        aux = aux->tail;
    }
    return retArr;
}

static void freeList(TList list){
    if(list == NULL)
        return;
    freeList(list->tail);
    free(list);
}

void freeMultiSet(multiSetADT multiSet){
    freeList(multiSet->set);
    free(multiSet);
}




