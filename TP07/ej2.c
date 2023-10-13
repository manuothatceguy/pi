#include <stdlib.h>
#include <stdio.h>
#include "getnum.h"
#include <math.h>

int obtenerConversion(int * bInput, int * bOutput){
    char e[5];
    printf("Ingrese conversión: ");
    scanf("%s",e);

    int tempBInput = atoi(e+1);
    int tempBOutput = atoi(e+3);

    if(tempBInput > 1 && tempBInput < 11 && tempBOutput > 1 && tempBOutput < 11){
        *bInput = tempBInput;
        *bOutput = tempBOutput;
        return 1;
    }
    *bInput = 0;
    *bOutput = 0;
    return 0;
}

int convertirBase10(int n, int b){
    int ans = 0;
    int idx = 0;
    while(n > 0){
        ans += (n%10)*pow(b,idx++);
        n /= 10;
    }
    return ans;
}

int pasaDeBase10(int entrada, int base)
{
    int digito, salida = 0;
    int potencia = 1;

    while (entrada > 0)
    {
        digito = entrada % base;
        entrada /= base;
        salida += digito * potencia;
        potencia *= 10;
    }

    return salida;
}

void cambiarBase(){
    int baseIn, baseOut;
    if(!obtenerConversion(&baseIn,&baseOut)){
        puts("Error de entrada de base.\n");
        return;
    }

    int num;

    do
    {
        num = getint("Ingrese el número a convertir: ");
    } while (num < 1);
    
    int numBase10 = convertirBase10(num, baseIn);
    int numNewBase = pasaDeBase10(numBase10, baseOut);

    printf("Número convertido: %d, en base %d\n",numNewBase,baseOut);
}

int main(){
    cambiarBase();
    return 0;
}