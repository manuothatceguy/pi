#include "ej14.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node{
    elemType head;
    struct node * tail
}TNode;

typedef struct node * TList;

typedef struct listCDT{
    TList listAsc;
    TList listInsert;

    TList nextAscendente;
    TList nextOrdenInsert;

    TList lastInsert;

    int (*compare)(elemType,elemType);
    int dim;
}listCDT;

listADT newList(int (*compare) (elemType e1, elemType e2)){
    listADT new = calloc(1,sizeof(listCDT));
    new->compare = compare;
    return new;
}

static TNode * addRec(TNode * first, elemType elem, int *ok, int (*compare) (elemType e1, elemType e2)) {
  int c;
  if ( first == NULL ||  ( c =  compare(elem, first->head)) < 0) {
    TNode * aux = malloc(sizeof(struct node));
    aux->head = elem;
    aux->tail = first;
    *ok = 1;
    return aux;
  }
  if ( c > 0 )
    first->tail = addRec(first->tail,  elem, ok, compare);
  return first;
}

void add(listADT list, elemType elem) {
  // primero insertarmos en orden, y que nos diga si estaba o no
  int added = 0;
  list->listAsc = addRec(list->listAsc, elem, &added, list->compare);
  if ( added ) {    // Si no estaba, entonces lo agregamos directamente al final de la otra lista
    TNode * aux = malloc(sizeof(TNode));
    aux->head = elem;
    aux->tail = NULL;
    if ( list->listInsert == NULL)
      list->listInsert = aux;
    else
      list->lastInsert->tail = aux;
    list->lastInsert = aux;
  }
}

void toBegin(listADT list){
    list->nextOrdenInsert = list->listInsert;
}

int hasNext(listADT list){
    return (list->nextOrdenInsert != NULL);
}

elemType next(listADT list){
    if(!hasNext(list)){
        fprintf(stderr,"No había next");
        exit(1);
    }
    elemType ans = list->nextOrdenInsert->head;
    list->nextOrdenInsert = list->nextOrdenInsert->tail;
    return ans;
}

void toBeginAsc(listADT list){
    list->nextAscendente = list->listAsc;
}

int hasNextAsc(listADT list){
    return list->nextAscendente != NULL;
}

elemType nextAsc(listADT list){
    if(!hasNextAsc(list)){
        fprintf(stderr,"No había next");
        exit(1);
    }
    elemType ans = list->nextAscendente->head;
    list->nextAscendente = list->nextAscendente->tail;
    return ans;
}

void freeRec(TNode * first) {
  if ( first == NULL)
    return;
  freeRec(first->tail);
  free(first);
}

void freeList(listADT list) {
  freeRec(list->listAsc);
  freeRec(list->listInsert);
  free(list);
}

static int compare (elemType e1, elemType e2) {
    return e1-e2;
}

int
main(void) {
   listADT c = newList(compare); // una lista, en este caso de int
   toBegin(c);
   assert(!hasNext(c));
   assert(!hasNextAsc(c));
   add(c, 3);   add(c, 1);   add(c, 5);   add(c, 2);
   toBegin(c);         // iterador por orden de insercià¸£à¸“n
   int n = next(c);    // n = 3
   assert(n==3);
   n = next(c);        // n = 1
   assert(n==1);
  
   toBeginAsc(c);      // iterador por orden ascendente

   assert(hasNext(c));
   assert(hasNextAsc(c));

   n = nextAsc(c);     // n = 1
   assert(n==1);

   n = next(c);        // n = 5
   assert(n==5);

   n = next(c);        // n = 2
   assert(n==2);
   assert(!hasNext(c)); 

   n = nextAsc(c);     // n = 2
   assert(n==2);

   n = nextAsc(c);     // n = 3
   assert(n==3);

   n = nextAsc(c);     // n = 5
   assert(n==5);

   assert(! hasNextAsc(c));

   freeList(c);

   puts("OK!");

   return 0;
}