/*Escribir un programa que ofrezca las siguientes opciones 
para accionar sobre un carácter leído desde la entrada estándar. 
Utilizar distintas funciones (con no más de 4 líneas) 
para cada una de las opciones y una función para el menú de opciones:

Convertir de mayúscula a minúscula. 
Convertir de minúscula a mayúscula. 
Imprimir el carácter siguiente. 
Imprimir la siguiente letra en forma circular (si la letra es 'z', debe imprimir 'a')
*/
#include <stdio.h>
#include <stdlib.h>
#include "../getnum/getnum.h"

int mayusAMin(int letra);
int minAMayus(int letra);
int charSig(int c);
int letraSig(int letra);
int menu();

int main()
{
    int c, opt,resp;
    do{
        puts("Ingrese un caracter distinto de EOF");
        c = getchar();
        
        if(c!=EOF){
            
            opt = menu();
            
            switch(opt){
                case 1: resp = mayusAMin(c); break;
                case 2: resp = minAMayus(c); break;
                case 3: resp = charSig(c); break;
                case 4: resp = letraSig(c); break;
                default:
                    puts("Opción inválida\n");
                    resp=0;
            }

            if(resp){
            printf("Rta: %c %3d\n",c,c);
            }   
        }
        
    }
    while(c != EOF);
    return 0;
}
