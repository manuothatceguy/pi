#include <stdio.h>
#include <stdlib.h>

typedef struct vectorCDT * vectorADT;

typedef char * elemType;

typedef int (*compare)(elemType, elemType);

vectorADT newVector(compare cmp);

void freeVector(vectorADT v);

int put(vectorADT v, elemType *elems, size_t dim, size_t index);

int getIdx(vectorADT v, elemType elem);

int elementCount(vectorADT v);

void deleteElement(vectorADT v, size_t index);

int getIdx(vectorADT v, elemType elem);