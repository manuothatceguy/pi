#ifndef __LISTADT_H
#define __LISTADT_H
#include <stdlib.h>

/**
 * ADT para listas genéricas, ordenadas y sin repetidos.
*/

typedef struct listCDT* listADT;
 
// El tipo de datos a insertar, definido por el usuario
typedef int elemType;

/**
 * Puntero a función de comparación
 * @return 0 si son iguales,
 * @return <0 si el primero es "menor" que el segundo,
 * @return >0 si el primero es "mayor" que el segundo
*/
typedef int(*compare)(elemType, elemType);

/**
 * 
 * @return una lista vacía
*/
listADT newList(compare cmp);

void freeListADT(listADT list);

int isEmptyList(listADT list);

size_t sizeList(listADT list);

int belongsList(listADT list, elemType elem);


/**
 * Agrega -si no estaba- un elemento a la lista
 * @param list
 * @param elem
 * @return 1 si lo agrega, 0 si no
*/
int addList(listADT list, elemType elem);

int deleteList(listADT list, elemType elem);

void tobegin(listADT list);

int hasNext(listADT list);

elemType next(listADT list);


/**
 * @param list
 * @return un vector con TODOS los elementos de la lista
*/
elemType * toArray(listADT list);

/**
 * @param list
 * @param criteria
 * @param dim cuántos elementos cumplen con el criterio
 * @return un VECTOR con los elementos que cumplen con el criterio
*/
elemType * select(listADT list, int (*criteria)(elemType), size_t * dim);



#endif