#include <stdio.h>
#include <stdlib.h>
#include "../getnum/getnum.h"

int mayusAMin(int letra){
    if((letra >= 'A') && (letra <= 'Z')){
        letra += ('A'-'a');
        }
    return letra;
}
int minAMayus(int letra){
    if((letra >= 'a') && (letra <= 'z')){
        letra -= ('A'-'a');
        }
    return letra;
}
int charSig(int c){
    return c + 1;
}
int letraSig(int letra){

    if ( ! ((letra>='A' && letra<='Z') || (letra>='a' && letra <= 'z')))
        return letra;
    return ( letra == 'z' || letra == 'Z') ? letra - ( 'Z' - 'A'): charSig(letra);
}

int menu(){
    printf("MENU\nSELECCIONE QUE HACER CON SU CARACTER\n(1) Convertir de mayúscula a minúscula\n(2) Convertir de minúscula a mayúscula\n(3) Imprimir el caracter siguiente\n(4) Imprimir la siguiente letra en forma circular (si la letra es 'z', debe imprimir 'a')");
    int opt;
    opt = getint("\nIngrese número: ");
    return opt;
}