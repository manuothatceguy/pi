#include <stdio.h>
#include <math.h>
#include "../getnum/getnum.h"
#include <stdlib.h>

double roundParam(double num,unsigned int cifras){
    //floor( num * 100 + .5 ) / 100
    long digits;
    for(digits = 1; cifras; cifras--){
        digits*=10;
    }
    return floor( num * digits + .5 ) / digits;
}

int main()
{
    double numero;
    numero = getfloat("Ingrese un valor de float: ");
    int decim = getint("Ingrese la cantidad de decimales a redondear: ");
    printf("El numero es %f y redondeado a %d cifras es %g\n",numero,decim,roundParam(numero,decim));

    return 0;
}

