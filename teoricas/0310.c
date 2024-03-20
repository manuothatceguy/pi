#include <stdlib.h>
#include <stdio.h>
#include "../getnum/getnum.h"

float * leeArreglo(int * dim){
    do{
        *dim = getint("Ingrese la cantidad de números en el vector: ");
    }
    while(*dim < 0);

    float * v = malloc(*dim * sizeof(float));
    for(int i = 0; i < *dim; i++){
        v[i] = getfloat("Ingrese un número real: ");
    }
    return v;
}

int main(void){

    int dim;
    float * vec = leeArreglo(&dim);

    for(int i = 0; i < dim; i++){
        printf("%f",vec[i]);
    }
    free(vec); // NO OLVIDARSE! PORQUE SANITIZE FALLA!
    return 0;
}