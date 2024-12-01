#include "stackADT.h"
#include <stdio.h>

typedef struct node{
    int head;
    struct node * tail;
} node;

typedef node * TList;

struct stackCDT{
    size_t dim; //Cantidad de elementos
    TList first;
    compare cmp;
};

stackADT newStack(compare cmp){
    stackADT aux = calloc(1,sizeof(elemType));
    aux->cmp = cmp;
    return aux;
}

int isEmpty(stackADT stack){
    return (stack->dim) == 0;
}

size_t stackSize(stackADT stack){
    return stack->dim;
}

static void freeList(TList list){ // También puede ser iterativo.
    if(list == NULL){
        return;
    }
    freeList(list->tail);
    free(list);
}

void freeStack(stackADT stack){
    freeList(stack->first);
    free(stack);
}

void push(stackADT stack, int elem) {
    TList aux = malloc(sizeof(node));
    aux->head = elem; //Para entender esta función ver dibujito de los cuadrados y las flechas
    aux->tail = stack->first;
    stack->first = aux;
    stack->dim++; // No olvidarse!
}

elemType pop(stackADT stack){
    // assert(!isEmpty(stack));
    if(isEmpty(stack))
        fprintf(stderr, "stack vacio al hacer pop");
        exit(1);
    
    elemType aux = stack->first->head;
    TList secondNode = stack->first->tail;
    free(stack->first);
    stack->first = secondNode;
    stack->dim--;
    return aux;
}

int belongsRec(TList list, elemType elem, compare cmp){
    if(list == NULL){
        return 0;
    }
    if(cmp(list->head, elem)){
        return 1;
    }
    return belongsRec(list->tail,elem,cmp);
}

// Función wrapper
int belongs(stackADT stack, elemType elem){
    return belongsRec(stack->first, elem, stack->cmp);
}

int belongsIter(const stackADT stack, elemType elem){
    TList aux = stack->first;
    while(aux != NULL){
        if(stack->cmp(aux->head,elem)){
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}