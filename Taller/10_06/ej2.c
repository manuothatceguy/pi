#include <stdlib.h>
#include "../../getnum/getnum.h"
#include <stdio.h>
#include <errno.h>

#define BLOQUE 10

int aparece(int * vec, int n, int dim){
    for(int i = 0; i < dim; i++){
        if(vec[i] == n)
            return 1;
    }
    return 0;
}

int * cargarNumeros(int * dim){
    int * v = NULL;
    int n = 1, fin = 0;
    *dim = 0;
    do
    {
        if(*dim % BLOQUE == 0){ // Asignar de a bloques de 10 * bytes de int
            v = realloc(v,(*dim + BLOQUE)*sizeof(int));
        }

        n = getint("Ingrese un numero: ");
        if(aparece(v,n,*dim)){
            fin = 1;
        }
        else{
            v[(*dim)++] = n;
        }
    } while (!fin);
    v = realloc(v,(*dim) * sizeof(int));
    return v;
}

int main(){
    int dim;
    int * arr;
    arr = cargarNumeros(&dim);
    for(int i = 0; i < dim; i++){
        printf("%d ", arr[i]);
    }
    puts("");
    free(arr);
    return 0;
}