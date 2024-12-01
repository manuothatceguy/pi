#include <stdio.h>
#ifndef __LIST__H // hacer esto en todos los .h para no tener problemas al compilar
#define __LIST__h

// Biblioteca de lista de enteros ordenados sin repetir

struct node{
    int head;
    struct node * tail;
};

typedef struct node * List; // List es un alias a puntero a nodo (struct node * List)

// Ver si una lista es vacía. Retorna 1 si es vacía, 0 en caso contrario.
int isEmpty(const List list); // o int isEmpty(const struct node * list);

// Ver si un elemento pertenece a una lista. Retorna 1 si está, 0 en caso contrario.
int belongs(const List list, int elem);

// Devuelve la cantidad de "nodos" en una lista.
size_t size(const List list);

// Función size pero con un ciclo while.
size_t sizeIter(List list);

// Agrega un elemento al final de una lista.
List add(List list, int elem);

// Elimina un elemento de una lista.
List delete(List list, int elem);

// Libera los elementos de una lista.
void freeList(List list);



#endif