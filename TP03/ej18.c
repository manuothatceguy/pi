#include <stdio.h>
#include "../getnum/getnum.h"



int main(void)
{
    int number,factorial = 1;
    for(number = getint("Ingrese número: ");number!=0;number--){
        if(number < 0){
            printf("El valor ingresado no es válido. Ingresar solo enteros positivos.\n");
            return 1;
        }
        factorial *= number;
    }
    printf("El factorial es %d\n",factorial);
    return 0;
}

