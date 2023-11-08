#include "stackADT.h"
#include <stdio.h>
#include <assert.h>

#define BLOCK 10

struct stackCDT{
    elemType * vec;
    size_t dim; // Cantidad de elementos 
    size_t size; // Cantidad de posiciones reservadas. Con esto no tengo que "achicar" nunca.
    int (*cmp)(elemType, elemType);
};

stackADT newStack(compare cmp) {
    stackADT aux = calloc(1, sizeof(struct stackCDT));
    aux->cmp = cmp;
    return aux;
}

int isEmpty(stackADT stack){
    return (stack->dim) == 0;
}

size_t stackSize(stackADT stack){ // Esta función podría no estar.
    return stack->dim;
}

void push(stackADT stack, elemType elem){
    if(stack->dim == stack->size){ // No hago % BLOCK porque controlo con dim y size.
        stack->size += BLOCK;
        stack->vec = realloc(stack->vec,(stack->size)*sizeof(stack->vec[0]));
    }
    stack->vec[stack->dim++] = elem;
}

elemType pop(stackADT stack){
    // assert(!isEmpty(stack));
    if(isEmpty(stack))
        fprintf(stderr, "stack vacio al hacer pop");
        exit(1);
    
    return stack->vec[--stack->dim];
}

void freeStack(stackADT stack){
    free(stack->vec);
    free(stack);
}

int belongs(stackADT stack, elemType elem){
    for(size_t i = 0; i < stack->dim; i++){
        if(stack->cmp(elem,stack->vec[i]))
            return 1; 
    }
    return 0;
}