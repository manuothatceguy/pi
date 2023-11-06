#ifndef __STACKADT_H
#define __STACKADT_H

#include <stdlib.h>

typedef struct stackCDT* stackADT;

// Con un typedef definimos el tipo de dato a usar, el usuario debe cambiar este typedef y recompilar
// Teóricamente es genérica
// Solo puedo tener un stack de una sola cosa!! No se pueden tener dos stacks por separado de cosas distintas.

typedef int elemType;

typedef int(*compare)(elemType e1, elemType e2);

/**
 * Función para crear un stack inicializado en cero.
*/
stackADT newStack();

/**
 * Función para ver si un stack está vacío
*/
int isEmpty(stackADT stack);

/**
 * @param stack
 * @return cantidad de elementos en el stack
 * 
*/
size_t stackSize(stackADT stack);

/**
 * @param stack
 * @param elem elemento de tipo elemType para meter al tope del stack.
*/
void push(stackADT stack, elemType elem);

/**
 * @param stack
 * @return el elemento del tope. Aborta si la pila estaba vacía
*/
elemType pop(stackADT stack);

/**
 * @param stack 
 * @brief liberar la memoria alocada por el stack
*/
void freeStack(stackADT stack);

/**
 * @param stack
 * @param elem elemento a verificar si está en el stack
 * @return 1 si elem está en el stack, 0 si no lo está.
*/
int belongs(stackADT stack, elemType elem);

#endif