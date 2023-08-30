#define DELTA 0.0001
#define INC 0.001
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double function(double x);

int main()
{
    double num = -4, hasta = 4;
    int signoActual;
    int signoAnterior = ((function(num))>=0) ? 1 : -1;
    for (; num <= hasta; num+=INC)
    {
        signoActual = ((function(num))>=0) ? 1 : -1;

        if (signoActual != signoAnterior)
            printf("%g es raíz\n",num);
        else if (fabs(function(num)) < DELTA)
            printf("%g es raíz\n",num);
        
        signoAnterior = signoActual;
    }
    return 0;
}

double function(double x){


    return sin(x);
    //return cos(x);
    //return ((pow(2,x))*(pow(x,3)));
    //return (sin(x) + log(x));
    //return (sqrt(x) + exp(x));
}