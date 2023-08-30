#include <stdio.h>
#include <math.h>
#include "../getnum/getnum.h"
#include <stdlib.h>

double roundParam(double num,unsigned int cifras){
    //floor( num * 100 + .5 ) / 100
    long digits;
    for(digits = 1; cifras; cifras--){
        digits*=10;
    }
    return
    floor( num * digits + .5 ) / digits;
}

int menu(double numero){
    puts("Menu:");
    puts("(1) Redondear al entero más cercano");
    puts("(2) Redondear al décimo más cercano");
    puts("(3) Redondear al centésimo más cercano");
    puts("(4) Redondear a la milésima más cercana");
    int opcion = getint("Ingrese la opción: ");
    switch (opcion)
    {
    case 1:
        numero = roundParam(numero,0);
        break;
    case 2:
        numero = roundParam(numero,1);
        break;
    case 3:
        numero = roundParam(numero,2);
        break;
    case 4:
        numero = roundParam(numero,3);
        break;
    default: puts("Error opción inválida.");
        break;
    }
    return numero;
}

int main()
{
    double numero;
    numero = getfloat("Ingrese un valor de float: ");
    double numeroR = menu(numero);
    printf("%f número redondeado.",numeroR);

    return 0;
}

