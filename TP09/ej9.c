#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EPSILON 0.01

float raizNR(float valorAnterior, int iter, float x) {
    if (fabs(valorAnterior * valorAnterior - x) < EPSILON) {
        return valorAnterior;
    }
    if (iter == 0) {
        return valorAnterior;
    }
    float valorAprox = 0.5 * (valorAnterior + x / valorAnterior);
    return raizNR(valorAprox, iter - 1, x);
}

int main(void){

    assert(fabs(raizNR(4, 3, 8)-2.833) <= EPSILON);
    assert(raizNR(0, 0, 0) <= EPSILON);
    assert(raizNR(0, 0, 4) <= EPSILON);
    
    printf("OK!\n");
}