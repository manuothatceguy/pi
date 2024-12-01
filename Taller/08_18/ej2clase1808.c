#include <stdio.h>
#include "../getnum/getnum.h"


int main()
{
    double numero,aux;
    int sumaCifras = 0;
    numero = getfloat("Ingrese un número: ");
    aux = numero > 0 ? numero : -numero;
    while(numero != 0){
        numero -= (int)numero;
        numero*=10;
        sumaCifras += (int)numero%10;
    }
    printf("La suma de las cifras decimales de %g es %d\n",aux,sumaCifras);
    return 0;
}

/**
*** La idea es que se rompa! 
*** Para que no se rompa hay que hacerlo con getchar!! que diver!
**/

    