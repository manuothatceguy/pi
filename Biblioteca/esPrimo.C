#include <math.h>
#include <stdio.h>
#include "../getnum/getnum.h"

// Función "esPrimo"

int esPrimo(int num){
    int esPrimo = 1;
    if(num < 0){
        num = -num;
    }

    if (num < 2){
        esPrimo = 0;
    }
    
    for (int contador = 2; contador <= sqrt(num) && esPrimo; contador++){
        if(num%contador == 0){
            esPrimo = 0;
        }
        else{
            esPrimo = 1;
        }
    }
    return esPrimo;
}