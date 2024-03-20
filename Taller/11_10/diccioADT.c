#include "diccioADT.h"

#define CANT_LETRAS 'Z' - 'A' + 1

typedef struct tipoPalSig{
    char * palabra;
    char * significado;
} tipoPalSig;

typedef struct listaPalabras{
    int cant;
    tipoPalSig * lista;
} listaPalabras;

typedef struct diccioCDT{
  listaPalabras inicial[CANT_LETRAS];  
} diccioCDT;

diccioADT crearDiccionario(){
    return calloc(1,sizeof(diccioCDT));
}

void liberarDiccionario(diccioADT d){
    for(int i = 0; i < CANT_LETRAS; i++){
        for(int j = 0; j < d->inicial[i].cant; j++){
            free(d->inicial[i].lista[j].palabra);
            free(d->inicial[i].lista[j].significado);
        }
        free(d->inicial[i].lista);
    }
    free(d);
}

int agregarPalabra(diccioADT dic, char * palabra, char * significado){

    int indice, total, ubic;
    int lenPal = strlen(palabra);
    int lenSign = strlen(significado);
    if (lenPal > MAXWIDTH || lenSign > MAXSIGNIFICADO)
        return 0;
    indice = indiceLetra(palabra[0]);
    if(!repetido(palabra, dic->inicial[indice])){
        total = dic->inicial[indice].cant;
        dic->inicial[indice].lista = realloc(dic->inicial[indice].lista,sizeof(tipoPalSig)*(total+1));
        dic->inicial[indice].lista[total].palabra = malloc(lenPal + 1);
        strcpy(dic->inicial[indice].lista[total].palabra,palabra);
        dic->inicial[indice].lista[total].palabra = malloc(lenSign + 1);
        strcpy(dic->inicial[indice].lista[total].significado,significado);
        dic->inicial[indice].cant = total+1;
        return 1;
    }
    return -1; // repetido
}