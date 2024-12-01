#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../getnum/getnum.h"

int dcm(int x, int y){
    int divcm = 1;
    for (int i = 2; i <= (x>y?y:x); i++){
        if((x%i == 0)&&(y%i == 0))
            divcm *= i;}
    return divcm;   
}
void simpFrac(int num, int den){
    int divcm = dcm(num,den);
    if(divcm != 1){
        num /= divcm;
        den /= divcm;}
    printf("%d/%d",num,den);
    return;
}
void sumFrac(int num1, int den1, int num2, int den2){
    int newDen, newNum;
    newDen = den1*den2;
    newNum = (((num1)*(newDen/den1)) + (num2)*(newDen/den2));
    printf("%d/%d + %d/%d = ",num1,den1,num2,den2);
    simpFrac(newNum,newDen);
    puts("\n");
    return;

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
    int opt = menu(), num1,num2,den1 = 0,den2 = 0;
    switch (opt)
    {
    case 1:
        num1 = getint("Ingrese un valor para el numerador: ");
        den1 = getint("Ingrese un valor para el denominador: ");
        while(den1 == 0){
            printf("El denominador no puede ser cero\n");
            den1 = getint("Ingrese un valor para el denominador: ");}
        simpFrac(num1,den1);
        break;
    
    case 2:
        printf("Para la primera fracción: \n");
        num1 = getint("Ingrese un valor para el numerador: ");
        den1 = getint("Ingrese un valor para el denominador: ");
        while(den1 == 0){
            printf("El denominador no puede ser cero");
            den1 = getint("Ingrese un valor para el denominador: ");}
        printf("Para la segunda fracción: \n");
        num2 = getint("Ingrese un valor para el numerador: ");
        den2 = getint("Ingrese un valor para el denominador: ");
        while(den2 == 0){
            printf("El denominador no puede ser cero\n");
            den2 = getint("Ingrese un valor para el denominador: ");}
        sumFrac(num1,den1,num2,den2);
        break;
    case 3:

        break;
    default:
        puts("Opción inválida");
        break;
    }

    return 0;
}
