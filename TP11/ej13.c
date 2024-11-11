#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "ej13.h"

#define BLOCK 10

typedef struct rankingCDT{
    elemType * vector;
    size_t dim;
    compare cmp;
} rankingCDT;

static void swap(elemType * vector, size_t idxA, size_t idxB){
    elemType aux = vector[idxA];
    vector[idxA] = vector[idxB];
    vector[idxB] = aux;
    return;
}

rankingADT newRanking(elemType elems[], size_t dim, compare cmp){
    rankingADT new = malloc(sizeof(rankingCDT));
    
    
    
    new->dim = dim;
    if(dim > 0){
        new->vector = malloc(sizeof(elemType)*dim);
        for(int i = 0; i < dim; i++){
            new->vector[i] = elems[i];
        }
    } else{
        new->vector = NULL;
    }
    new->cmp = cmp;
    return new;
}

static size_t getIdx(rankingADT r, elemType e){
    for(int i = 0; i < r->dim; i++){
        if(r->cmp(r->vector[i],e) == 0){
            return i;
        }
    }
    return -1;
}

int contains(rankingADT ranking, elemType elem){
    int n = getIdx(ranking,elem);
    if(n < 0){
        return 0;
    }
    else{
        swap(ranking->vector,n,n-1);
        return 1;
    }
}

void addRanking(rankingADT ranking, elemType elem){
    int n = getIdx(ranking,elem);
    if(n == 0){
        return;
    }
    else if(n > 0){
        swap(ranking->vector,n,n-1);
    }
    else{
        ranking->dim++;
        ranking->vector = realloc(ranking->vector, ranking->dim * sizeof(elemType));
        ranking->vector[ranking->dim - 1] = elem;
        return;
    }
}

size_t size(const rankingADT ranking){
    return ranking->dim;
}

void downByRanking(rankingADT ranking, size_t n){
    if(n == ranking->dim){
        return;
    }
    swap(ranking->vector,n,n-1);
}

int getByRanking(rankingADT ranking, size_t n, elemType * elem){
    if(n <= 0 || n > size(ranking)){
        return 0;
    }
    *elem = ranking->vector[n-1];
    if(n > 1){
        swap(ranking->vector,n-1,n-2);
    }
    return 1;
}

elemType * getTopRanking(const rankingADT ranking, size_t * top){
    size_t cantidad = size(ranking);

    if(cantidad == 0){
        *top = 0;
        return NULL;
    }

    if(cantidad < *top){
        *top = cantidad;
    }

    elemType * retVec = malloc(*top * sizeof(elemType));
    for(int i = 0; i < *top; i++){
        retVec[i] = ranking->vector[i];
    }
    return retVec;
}

void freeRanking(rankingADT r){
    free(r->vector);
    free(r);
    return;
}

// Utilizamos char * como elemType strcmp como compare
int main(void) {
  rankingADT r = newRanking(NULL, 0, strcmp);
  addRanking(r, "Footloose");
  addRanking(r, "Yesterday");
  addRanking(r, "La bamba");
  addRanking(r, "Sucio y desprolijo");
  addRanking(r, "Ride of the Valkyries");
  addRanking(r, "Yesterday");
  addRanking(r, "Ride of the Valkyries");

  const char * aux = "default";
  int n;
  n = getByRanking(r, 6, &aux);
  assert( n == 0 && !strcmp(aux, "default") );

  n = getByRanking(r, 1, &aux); 
  assert( n == 1 && !strcmp(aux, "Yesterday") );

  n = getByRanking(r, 0, &aux); 
  assert( n == 0 && !strcmp(aux, "Yesterday") );

  n = getByRanking(r, 2, &aux); 
  assert( n == 1 && !strcmp(aux, "Footloose") );

  n = getByRanking(r, 1, &aux); 
  assert( n == 1 && !strcmp(aux, "Footloose") );
 
  assert( contains(r, "Ride of the Valkyries") ); 
  assert( contains(r, "Sucio y desprolijo") ); 
  assert( contains(r, "Desarma y sangra") == 0 );

  size_t dimTop = 10;
  const char ** top = getTopRanking(r, &dimTop);
  assert(dimTop == 5 && !strcmp(top[0], "Footloose") && !strcmp(top[1], "Yesterday"));
  assert(!strcmp(top[2], "Ride of the Valkyries") && !strcmp(top[3], "Sucio y desprolijo"));
  assert(strcmp(top[4], "La bamba") == 0);
  free(top);

  downByRanking(r, 1);
  dimTop = 2;
  top = getTopRanking(r, &dimTop);
  assert( dimTop == 2 && !strcmp(top[0], "Yesterday") && !strcmp(top[1], "Footloose") );

  free(top);
  freeRanking(r);
  puts("rankingADT: OK!");
  return 0;
}