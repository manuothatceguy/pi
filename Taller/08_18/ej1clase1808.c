#include <stdio.h>
#include "../getnum/getnum.h"

int main()
{
    int numero,sumaCifras = 0,aux; //aux me guarda el valor original para no perderlo
    numero = getint("Ingrese un número: ");
    aux = numero > 0 ? numero : -numero;
    while(numero != 0){
        sumaCifras += numero%10;
        numero /= 10;
    }
    printf("La suma de los dígitos de %d es %d\n",aux,sumaCifras);
    return 0;
}