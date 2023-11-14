#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUEADT_H_INCLUDED
#define QUEUEADT_H_INCLUDED

typedef struct queueCDT * queueADT;
typedef int elemType;

queueADT newQueue(void);

/**
 * Agrega un elemento al final de la cola
*/
void queue(queueADT q, elemType n);

/**
 * Remueve un elemento del principio de la cola y lo deja en out
*/
void dequeue(queueADT q, elemType * out);

void toBegin(queueADT q);

int hasNext(queueADT q);

elemType next(queueADT q);

void freeQueue(queueADT q);

int isEmpty(queueADT q);

#endif