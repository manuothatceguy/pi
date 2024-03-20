#include <stdio.h>
#include <stdlib.h>

#ifndef _DICCIOADT__H
#define _DICCIOADT__H
#define MAXWIDTH 25
#define MAXSIGNIFICADO 255

typedef struct diccioCDT * diccioADT;

diccioADT crearDiccionario();

void liberarDiccionario(diccioADT d);

int agregarPalabra(diccioADT dic, char * palabra, char * significado);


#endif