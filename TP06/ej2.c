/* Ejercicio 10
 	Escribir un programa que ofrezca un menú con las siguientes opciones:
Simplificar una fracción
Sumar dos fracciones
Terminar la ejecución

	   Si se elige la primera opción se le solicitará numerador y denominador de la fracción y se imprimirá la fracción simplificada (algunos de ellos podrían ser negativos). Si se opta por la segunda, se le solicitará dos fracciones y se imprimirá la suma de las mismas, también simplificada. Obviamente con la tercera opción finaliza la ejecución del mismo. Escribir una función para cada item del menú. (No más de 20 líneas para main y no más de 10 líneas para las funciones del menú).
	Pista: Escribir y usar la función DivisorComunMaximo.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../getnum/getnum.h"


int dcm(int x, int y){
    int divcm = 1;
    for (int i = 2; i <= (x>y?y:x); i++){
        if((x%i == 0)&&(y%i == 0))
            divcm *= i;}
    return divcm;   
}
void simpFrac(int frac[]){
    int divcm = dcm(frac[0],frac[1]);
    frac[0] /= divcm;
    frac[1] /= divcm;
}

void sumaFracciones(int frac[]){
    int newDen = (frac[1])*(frac[3]);
    int newNum = (frac[0]*frac[3]) + (frac[2]*frac[1]);
    frac [2] = 0; frac[3] = 0;
    frac[0] = newNum;
    frac[1] = newDen;
    simpFrac(frac);
}
void printFrac(int num, int den){
    printf("%d/%d",num,den);
}
int menu(){
    int opt = 0;
    puts("Menu");
    printf("\n(1) - Simplificar una fracción");
    printf("\n(2) - Sumar fracciones");
    printf("\n(3) - Terminar con el programa\n");
    while ((opt < 1) || (opt > 3)){
        opt = getint("Elija una opción: ");
    }
    return opt;
}

int main()
{
    int n1 = 0,d1 = 0,n2 = 0,d2 = 0;
    int frac[4];
    int opt = menu();
    switch (opt)
    {
    case 1:
        n1 = getint("Ingrese un numerador: ");
        d1 = getint("Ingrese un denominador: ");
        frac[0] = n1;
        frac[1] = d1;
        simpFrac(frac);
        printf("La fracción %d/%d simplificada es ",n1,d1);
        printFrac(frac[0],frac[1]);
        puts("\n");
        break;
    
    case 2:
        n1 = getint("Ingrese un numerador: ");
        d1 = getint("Ingrese un denominador: ");
        n2 = getint("Ingrese un numerador: ");
        d2 = getint("Ingrese un denominador: ");
        frac[0] = n1;
        frac[1] = d1;
        frac[2] = n2;
        frac[3] = d2;
        sumaFracciones(frac);
        printf("%d/%d + %d/%d = ",n1,d1,n2,d2);
        printFrac(frac[0],frac[1]);
        puts("\n");
    case 3:
        printf("Programa terminado");
        
        break;
    default: printf("Opción incorrecta");
        break;
    }

    return 0;
}
