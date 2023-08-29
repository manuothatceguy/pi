#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../getnum/getnum.h"
#define EPSILON 0.0000001

double ex(double x){
    double factorial=1;
    double valor, anterior, potX;
    int termino=1;
    if ( x < 0 )
        return -1;
    potX = x;
    valor = 1;
    anterior = 0;
    while (valor - anterior > EPSILON)
    {
        anterior = valor;
        valor += potX / factorial;
        potX *= x;
        termino++;
        factorial *= termino;
    }
return valor;
}


int main()
{
    double x = getfloat("Ingrese un valor para aproximar e: "),eEstimado,eReal;
    if (x < 0){
        puts("Solo para positivos.");
    }
    else{
        eEstimado = ex(x);
        eReal = exp(x);
        printf("\nValor calculado: %f\n",eEstimado);
        printf("Valor real: %f\n",eReal);
    }
    return 0;
}
