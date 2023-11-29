#include "setADT.h"

typedef struct node{
    elemType elem;
    struct node * tail;
} TNode;

typedef struct node * TList;

typedef int(*cmpFun)(elemType,elemType);

typedef struct setCDT{

    elemType max;
    elemType last;

    size_t size;

    TList first;
    cmpFun cmp;

} setCDT;

setADT newSet(cmpFun cmpFun){
    setADT new = calloc(1,sizeof(setCDT));
    new->cmp = cmpFun;
    return new;
}

static TList searchAndAdd(TList list, elemType elem, cmpFun cmp, int * flag){
    int c;
    if(list == NULL || (c = cmp(list->elem,elem)) > 0){
        TList newNode = malloc(sizeof(TNode));
        newNode->elem = elem;
        newNode->tail = list;
        *flag = 1;
        return newNode;
    }
    else if(c < 0){
        list->tail = searchAndAdd(list->tail,elem,cmp,flag);
    }
    return list;
}

int add (setADT set, elemType elem){
    int flag = 0;
    set->first = searchAndAdd(set->first,elem,set->cmp,&flag);
    if(set->size == 0){
        set->max = elem;
        set->last = elem;
        set->size++;
    }
    else if(flag){
        if(set->cmp(set->max,elem) < 0){
            set->max = elem;
        }
        set->last = elem;
        set->size++;
    }
    return set->size;
}

int size (const setADT set){
    return set->size;
}

elemType * max (const setADT set){
    if(set->size == 0)
        return NULL;
    elemType * ans = malloc(sizeof(elemType));
    *ans = set->max;
    return ans;
}

elemType * min (const setADT set){
    if(set->size == 0)
        return NULL;
    elemType * ans = malloc(sizeof(elemType));
    *ans = set->first->elem;
    return ans;
}

elemType * last (const setADT set){
    if(set->size == 0)
        return NULL;    
    elemType * ans = malloc(sizeof(elemType));
    *ans = set->last;
    return ans;
}

elemType * setToArray (const setADT set){
    elemType * array = malloc(sizeof(elemType)*set->size);
    TList aux = set->first;
    for(int i = 0; i < set->size; i++){
        array[i] = aux->elem;
        aux = aux->tail;
    }
    return array;
}