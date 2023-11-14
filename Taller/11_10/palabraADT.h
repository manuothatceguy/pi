#include <stdio.h>
#include <stdlib.h>
#ifndef PALABRAADT_H_INCLUDED
#define PALABRAADT_H_INCLUDED
typedef struct palabraCDT * palabraADT;


/**
 * Retorna una palabra nueva, vacía (longitud 0).
*/
palabraADT crearVacia();

/**
 * Retorna una palabra nueva, a partir de un string.
*/
palabraADT crearDesde(char *s);

/**
 * Agrega una letra al final de una palabra existente.
*/
palabraADT agregarLetra(palabraADT pal, char letra);

/**
 * Muestra la palabra en salida estándar.
*/
void mostrarPalabra(palabraADT pal);

/**
 * Liberar recursos
*/
void destruirPalabra(palabraADT pal);

#endif 