#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utillist.h"


TList listUnion  (const TList list1, const TList list2);


int main(void) {

  int v[] = {1, 4, 5, 6, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x[] = {2, 3, 9};

  TList l1 = fromArray(v, 6);
  TList l2 = fromArray(w, 9);
  TList l3 = listUnion(l1, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l1);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, NULL);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(NULL, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);
  freeList(l1);
  freeList(l2);
  
  l1 = fromArray(v, 6);
  l2 = fromArray(x, 3);
  l3 = listUnion(l1, l2);
  freeList(l1);
  freeList(l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);


  printf ("OK!\n");
  return 0;
}

TList listUnion(const TList list1, const TList list2){
    TList un = malloc(sizeof(TNode));
    un->tail = NULL;
    if(list1 == NULL && list2 == NULL){
        free(un);
        return NULL;
    }
    if(list1 == NULL){
        un->elem = list2->elem;
        un->tail = listUnion(NULL,list2->tail);
    }
    else if(list2 == NULL){
        un->elem = list1->elem;
        un->tail = listUnion(list1->tail,NULL);
    }
    else if(list1->elem < list2->elem){
        un->elem = list1->elem;
        un->tail = listUnion(list1->tail,list2);
    }
    else if(list1->elem > list2->elem){
        un->elem = list2->elem;
        un->tail = listUnion(list1,list2->tail);
    }
    else{

        un->elem = list2->elem;
        un->tail = listUnion(list1->tail,list2->tail);
    }
    return un;


}