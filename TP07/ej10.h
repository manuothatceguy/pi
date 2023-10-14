#include <stdlib.h>
#include <stdio.h>
#include "random.h"
#include <string.h>
#include <ctype.h>

#define CANT_PALABRAS 22
#define ABC 'Z' - 'A' + 1
#define BLOQUE 10
#define INTENTOS 5

#define BORRA_BUFFER while (getchar() != '\n')
#define INTRO_JUEGO printf("********\nAHORCADO\n********\n\nLongitud de la palabra a adivinar: %d\n\n",dim-1)
#define INTENTOS_RESTANTES_REPORTE(update) printf("\n%s\n\nIntentos restantes: %d\n\n",palabraParcial,update?intentosRestantes:--intentosRestantes)

/*Función que desarrolla el juego de ahorcado*/
int jugar(char * palabraSecreta, int dim, char * palabraParcial, char letrasReps[]);

/*Función que arma un string con '_' en cada posición y deja marca final*/
char * setParcial(int dim);

/*Función que elige aleatoriamente de un vector de strings una palabra y retorna un puntero en su nombre*/
char * elegirPalabra(char * opcionesPalabras[], int * dim);

/*Función que recibe como parámetro las letras incorrectas ya ingresadas y devuelve una letra ingresada por el usuario que no esté en la palabra.*/
int ingresarLetra(char * letrasIngresadas);

/*Función que retorna 0 si no encontró la letra, 1 si la encontró y además modifica el vector de apariciones y la palabra parcial*/
int actualizarPalabra(char * palabraParcial, int len, int letra, char * letrasIngresadas, char * palabraSec);