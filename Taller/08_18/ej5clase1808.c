#include <stdio.h>
#include "../getnum/getnum.h"
#include <math.h>

int esPrimo(int n);
int main()
{
    int n = getint("Ingrese tope: "); // no es lo que pedían. convertirla en "cantidad de primos"
    if (n < 0){
        n = -n;
    }
    for (int contador = 0; contador <= n; contador++){
        if(esPrimo(contador)){
            printf("%d ",contador);
        }
    }
    printf("\n");
        return 0;
}
