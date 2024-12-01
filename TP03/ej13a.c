#include <stdio.h>
#include "../getnum/getnum.h"

int main(void){

    int lado, contadorLado, contadorAltura;
    lado = getint("Ingrese el valor del lado: ");
    for(contadorAltura = lado;contadorAltura!=0;contadorAltura--){
        if(lado<=0){
            printf("Error\n");
            break;
        }
        for(contadorLado=0;contadorLado<lado;contadorLado++){
        printf("*");
        }
        printf("\n");
    }

    return 0;
}
