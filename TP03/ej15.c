#include <stdio.h>
#include "../getnum/getnum.h"

int main()
{
    int binary = getint("Ingrese un número binario: ");
    for (int temp = binary; temp > 0; temp /= 10) {
        if (temp % 10 != 0 && temp % 10 != 1) {
            printf("El número ingresado no es binario.\n");
            return 1;
        }
    }
    int decimal = 0, base = 1; //planteo exponente como 1 * 2 eterno
    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    printf("El equivalente decimal es: %d\n", decimal);
    return 0;


    


    return 0;
}
