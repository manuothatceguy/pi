#include <stdio.h>
#include "../getnum/getnum.h"

int main()
{
    int contador, lado;
    lado = getint("Ingrese valor para el lado: ");

    for(contador=0;contador<lado*lado;contador++){
        printf("*");
        if((contador+1)%lado == 0){ //La instancia de n = múltiplo de lado va a ser donde termina una columna
            printf("\n");
        }
        
        
    }

    return 0;
}
