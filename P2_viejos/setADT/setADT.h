#ifndef setADT_h
#define setADT_h
#include <stdlib.h>
#include <stdio.h>


typedef struct setCDT * setADT;

typedef int elemType;

//Retorna un nuveo conjunto de elementos genericos. Al principio estÃ¡ vacio
setADT newSet(int(*)(elemType,elemType));

//Inserta una copia superficial de elem siempre y cunado el elemento no estÃ© en el conjunto. Retorna la cantidad total de elementos luego de agregar el elemento nuevo
int add (setADT set, elemType elem);

//Retorna cuantos elementos hay en el conjunto
int size (const setADT set);

//Retorna una copia del mayor elemento del conjunto, NULL si no hay elementos
elemType * max (const setADT set);

//Retorna una copia del menor elemento del conjunto, NULL si no hay elementos
elemType * min (const setADT set);

//Retorna una copia del ultimo elemento agregado en el conjunto, NULL si estÃ¡ vacio
elemType * last (const setADT set);

//Retorna un vector con todos los elementos del conjunto, ordenados en forma ascendente
elemType * setToArray (const setADT set);

#endif /* setADT_h */