#include <stdio.h>
#include "../getnum/getnum.h"

int main()
{
    int num,reverso = 0,original;
    num = getint("Ingrese un número: ");
    original = num;
   while (num > 0) {
        reverso = reverso * 10 + num % 10; //voy "empujando para adelante" los dígitos.
        num /= 10;}
    printf("El reverso del número es %d\n", reverso);
    if (original == reverso){
        printf("Es capicúa.\n");
    }
    else{
        printf("No es capicúa\n");
    }
    

    return 0;
}
