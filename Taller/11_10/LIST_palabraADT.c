#include <stdio.h>
#include <stdlib.h>
#include "palabraADT.h"

typedef struct palabraCDT{
    char letra;
    struct palabraCDT * sig;
} palabraCDT;


palabraADT crearVacia(){
    palabraADT aux = calloc(1,sizeof(struct palabraCDT));
    return aux;
}

palabraADT crearDesde(char *s){
    palabraADT new;
    if(*s == NULL){
        new = calloc(1,sizeof(struct palabraCDT));
        return new;
    }
    new = malloc(sizeof(struct palabraCDT));
    new->letra = *s;
    new->sig = crearDesde(s+1);
    return new;
}

palabraADT agregarLetra(palabraADT pal, char letra){
    if(pal == NULL){
        palabraADT new = malloc(sizeof(palabraCDT));
        new->letra = letra;
        new->sig = NULL;
        return new;
    }
    return agregarLetra(pal->sig,letra);
}

void mostrarPalabra(palabraADT pal){
    if(pal == NULL){
        return;
    }
    printf("%c",pal->letra);
    mostrarPalabra(pal->sig);
    return;
}

void destruirPalabra(palabraADT pal){
    if(pal == NULL){
        return;
    }
    free(pal->sig);
    free(pal);
    return;
}