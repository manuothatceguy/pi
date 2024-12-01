#include <stdio.h>
#include "../getnum/getnum.h"

int main(){
    int num1, num2, num3, numMax;
    num1 = getint("Ingrese un número: ");
    num2 = getint("Ingrese un número: ");
    num3 = getint("Ingrese un número: ");

    numMax = num1>num2 ? (num1>num3 ? num1:num3):(num2>num3 ? num2:num3);
    printf("El número más grande es %d\n", numMax);
    return 0;
}
