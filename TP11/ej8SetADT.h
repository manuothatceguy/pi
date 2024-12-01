#ifndef __SETADTH_

#define __SETADTH_

typedef struct setCDT * setADT;
#include "listADT.h"

/* Retorna un nuevo conjunto vacío */
setADT newSet(compare cmp);

void freeSet(setADT set);

int isEmptySet(setADT set);

int setContains(const setADT set, elemType element);

int addElement(setADT set, elemType element);

int deleteElement(setADT set, elemType element);

int sizeSet(const setADT set);

setADT unionSet(setADT set1, setADT set2);

setADT intersectionSet(setADT set1, setADT set2);

setADT diffSet(setADT set1, setADT set2);

#endif