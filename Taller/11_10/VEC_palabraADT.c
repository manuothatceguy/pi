#include "palabraADT.h"
#include <string.h>

typedef struct palabraCDT{
    char * p;
    int len;
} palabraCDT;

palabraADT crearVacia(){
    palabraADT aux = calloc(1,sizeof(struct palabraCDT));
    return aux;
}

palabraADT crearDesde(char * s){
    palabraADT pal = crearVacia();
    while(*s != '\0'){
        agregarLetra(pal,*s);
        s++;
    }
    return pal;
}

palabraADT agregarLetra(palabraADT pal, char letra){
    pal->p = realloc(pal->p,(pal->len + 1)*sizeof(char));
    pal->p[pal->len] = letra;
    pal->len++;
    return pal;
}

void mostrarPalabra(palabraADT pal){
    for(int i = 0; i < pal->len; i++){
        printf("%c",pal->p[i]);
    }
}

void destruirPalabra(palabraADT pal){
    free(pal->p);
    free(pal);
    return;
}