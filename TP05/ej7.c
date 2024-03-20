#include <stdio.h>
#define EPSILON 0.0000001
#include <math.h>
#include "../getnum/getnum.h"

double ex(int x){
    if (x<0){
        return -1;
    }
    
    double factorial = 1;
	double valor, anterior, potX;
	int termino = 1;

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
    double eAprox, eReal;
    int x = getint("Ingrese un valor para calcular e a esa potencia: ");
    if (x >= 0)
    {
        eAprox = ex(x);
        eReal = exp(x);
        printf("Valor real %f\tValor estimado %f\n",eReal,eAprox);
    
    }
    else
    {
        printf("El valor debe ser positivo!");
    }
    
    return 0;
}
