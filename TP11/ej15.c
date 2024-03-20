#include "ej15.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Para este test completar el .h con:
/*
typedef struct {
    int code;
    char name[20];
} elemType;  	
*/

typedef struct node{
    elemType head;
    struct node * tail;
} node;

typedef struct moveToFrontCDT{
    node * list;
    size_t size;
    node * next;
    compare cmp;

} moveToFrontCDT;

moveToFrontADT newMoveToFront(compare cmp){
    moveToFrontADT new = calloc(1,sizeof(moveToFrontCDT));
    new->cmp = cmp;
    return new;
}

static node *  addAlFinal(node * list, elemType elem, compare cmp, int * flag){
    if(list == NULL){
        node * new = malloc(sizeof(node));
        new->head = elem;
        new->tail = NULL;
        *flag = 1;
        return new;
    }
    if(cmp(list->head,elem) != 0){
        list->tail = addAlFinal(list->tail,elem,cmp,flag);
    }
    return list;
}

unsigned int add(moveToFrontADT moveToFront, elemType elem){
    int added = 0;
    moveToFront->list = addAlFinal(moveToFront->list,elem,moveToFront->cmp,&added);
    if(!added){
        return 0;
    }
    moveToFront->list = addAlFinal(moveToFront->list,elem,moveToFront->cmp,&added);
    moveToFront->size += 1;
    return added;
}

unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->size;
}

void toBegin(moveToFrontADT moveToFront){
    moveToFront->next = moveToFront->list;
}

int hasNext(moveToFrontADT moveToFront){
    return moveToFront->next != NULL;
}

elemType next(moveToFrontADT moveToFront){
    if(!hasNext(moveToFront)){
        fprintf(stderr, "No había next");
        exit(1);
    }

    if (moveToFront->next == NULL) {
        fprintf(stderr, "Error: moveToFront->next is NULL");
        exit(1);
    }

    elemType ans = moveToFront->next->head;
    moveToFront->next = moveToFront->next->tail;
    return ans;
}


static node * searchAndDisconnectIter(node * list ,elemType elem, compare cmp){
    // Miramos el siguiente elemento de la lista, por eso aux->tail != NULL
    // Podemos desreferenciar aux porque sabemos que hay al menos un nodo
    for(node * aux = list ; aux->tail != NULL ; aux = aux->tail)
    {   
        if(cmp(aux->tail->head,elem)==0)
        {
            node * found = aux->tail;
            aux->tail = aux->tail->tail; // "salteamos" el elemento si lo encotramos
            return found;
        }
    }
    // Si no estaba, devolvemos NULL
    return NULL;
}

elemType * get(moveToFrontADT moveToFront, elemType elem){
    // Si no estaba, devolvemos NULL
    if(moveToFront->list == NULL)
        return NULL;

    node* found = moveToFront->list;
    
    // Si es el primero, no hay que moverlo
    if(moveToFront->cmp(found->head,elem) !=0 ){
        if( ( found = searchAndDisconnectIter(moveToFront->list,elem, moveToFront->cmp) ) == NULL)
            return NULL;
        found->tail = moveToFront->list;
        moveToFront->list = found;
    }

    // Hacemos una copia del elemento encontrado para devolverlo
    elemType * e = malloc(sizeof(elemType));
    *e = found->head;
    return e;
}

void freeList(node * list){
    if(list == NULL){
        return;
    }
    freeList(list->tail);
    free(list);
}

void freeMoveToFront(moveToFrontADT moveToFront){
    freeList(moveToFront->list);
    free(moveToFront);
}

static int compareStruct (elemType e1, elemType e2) {
   	return e1.code - e2.code;
}


int 
main(void) {
   	moveToFrontADT p = newMoveToFront(compareStruct);
    
    elemType aux = {1, "uno"};
    assert(add(p, aux)==1);
    strcpy(aux.name, "dos");
    assert(add(p, aux)==0);
    aux.code = 2;
    assert(add(p, aux)==1);
    aux.code = 3;
    strcpy(aux.name, "tres");
    assert(add(p, aux)==1);
    aux.code = 4;
    strcpy(aux.name, "cuatro");
    assert(add(p, aux)==1);
    toBegin(p);
    
    while (hasNext(p)) {
       aux = next(p);
       printf("%d %s ", aux.code, aux.name);
    }
    putchar('\n'); 
    
    aux.code = 5;
    elemType * q = get(p, aux);	
    assert(q==NULL);
    
    aux.code = 3;
    q = get(p, aux);
    printf("%d %s\n", q->code, q->name);    
    assert(q->code==3);
    assert(strcmp(q->name, "tres")==0);
    free(q);
    
    // Volvemos a pedir el 3, que ahora debe estar al principio
    aux.code = 3;
    q = get(p, aux);
    printf("%d %s\n", q->code, q->name);    
    assert(q->code==3);
    assert(strcmp(q->name, "tres")==0);
    free(q);
    
    toBegin(p);
    printf("Debe imprimir 3 tres 1 uno 2 dos 4 cuatro\n");
    int vec[] = {3, 1, 2, 4};
    int i=0;
    while (hasNext(p)) {
       aux = next(p);
       printf("%d %s ", aux.code, aux.name);
       assert(aux.code == vec[i++]);
    }
    putchar('\n');

    aux.code = 5;
    strcpy(aux.name, "cinco");
    assert(add(p, aux)==1);
    q = get(p, aux);
    assert(q->code==5);
    assert(strcmp(q->name, "cinco")==0);
    free(q);
    toBegin(p);
    assert(next(p).code == 5);
    assert(next(p).code == 3);
    
    
    freeMoveToFront(p);
    puts("OK!"); 
	return 0;
}