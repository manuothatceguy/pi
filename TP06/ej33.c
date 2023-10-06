#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include "../random/random.h"

#define MAX 100
#define CANT_LETRAS ('Z' - 'A' + 1)

void mezclarArreglo(char * array, unsigned int dim){
    int aux,j;
    randomize();
    for (int i = 0; i < dim; i++)
    {
        j = randInt(0,dim);
        aux = array[i];
        array[i] = array[j];
        array[j] = aux;
    }
}

void crearAlfabeto(char * alph){
    for (int i = 0; i < CANT_LETRAS; i++)
    {
        alph[i] = 'A' + i;
    }
    mezclarArreglo(alph, CANT_LETRAS);
}

void codificar(char * mensaje, char * alph, char * target){
    int i = 0, j = 0;
    for (; mensaje[i]; i++)
    {
        if(isalpha(mensaje[i]))
            target[j++] = alph[toupper(mensaje[i]) - 'A'];
        else
            target[j++] = mensaje[i];
    }
    target[i] = 0;
    return;
}

int buscoIndex(char c, char * alph){
    for (int i = 0; i < CANT_LETRAS; i++)
    {
        if(alph[i] == c)
            return i + 'A';
    }
    return 0;
}

void decodificar(char * msjEncriptado, char * alph, char * target){
    int j = 0;
    for (int i = 0; msjEncriptado[i]; i++)
    {
        if(isalpha(msjEncriptado[i]))
            target[j++] = buscoIndex(msjEncriptado[i], alph);
        else
            target[j++] = msjEncriptado[i];
    }
}

int main(void) {
  char msg[MAX];
  char dest[MAX];
  // Debemos probar con mayusculas, porque siempre decodifica a mayuscuas
  char *s = "MENSAJE A CODIFICAR";
  char *s2 = "Mensaje a codificar";
  char alpha[CANT_LETRAS];
  crearAlfabeto(alpha);
  codificar(s, alpha, msg);
  assert(strlen(s)==strlen(msg));
  assert(strcmp(s, msg) != 0);
  decodificar(msg, alpha, dest);
  assert(strcmp(dest, s) == 0);

  codificar(s2, alpha, msg);
  assert(strlen(s2)==strlen(msg));
  assert(strcmp(s2, msg) != 0);
  decodificar(msg, alpha, dest);
  assert(strcmp(dest, s) == 0);
  
  puts("OK");
  return 0;
}

