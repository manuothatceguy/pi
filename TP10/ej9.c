#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "utillist.h"

typedef struct nodeBrief * TListBrief; 

typedef struct nodeBrief {
		int elem;
		size_t count;
		struct nodeBrief * tail;
} TNodeBrief;

TListBrief comprimeList(const TList list);

// Auxiliar para que pase el test con sanitizer
void freeListBrief(TListBrief lb) {
   if ( lb == NULL)
     return;
   freeListBrief(lb->tail);
   free(lb);
}

int main(void) {

  int v[] = {1,1,2,3,3,3,3,3,10,100,100,998};
  TList list = fromArray(v, sizeof(v)/sizeof(v[0]));
  TListBrief bf = comprimeList(list);

  TListBrief aux = bf;
  assert(aux->elem ==1 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==2 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==3 && aux->count == 5);

  aux = aux->tail;
  assert(aux->elem ==10 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==100 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==998 && aux->count == 1);

  aux = aux->tail;
  assert(aux == NULL);

  freeList(list);
  freeListBrief(bf);
  
  printf ("OK!\n");
  return 0;
}
/**
 * Escribir la función recursiva comprimeList que reciba una lista ordenada donde cada elemento es menor o igual al siguiente (puede tener repetidos), y retorne una nueva lista de tipo TListBrief ordenada donde en cada nodo se indica la cantidad de veces que aparece el elemento.
*/
TListBrief comprimeList(const TList list){
    if(list == NULL)
        return NULL;

    TListBrief bl = comprimeList(list->tail);

    if(bl == NULL || list->elem < bl->elem){
        TListBrief aux = malloc(sizeof(TListBrief)); // Agrego uno atrás
        aux->elem = list->elem;
        aux->count = 1;
        aux->tail = bl;
        return aux;
    }
    bl->count++; // Si no es menor, es igual entonces sumo 1.
    return bl;
}