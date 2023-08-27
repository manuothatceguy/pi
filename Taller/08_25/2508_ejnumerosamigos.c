#include <stdio.h>
#include <assert.h>

int sumaDiv(int num){
    int suma = 0;
    for(int contador = 1; contador < num; contador++){
        if ( (num % contador) == 0 ){
            suma += contador;
        }
    }
    return suma;
}

int numerosAmigos(int a, int b){
    return ((sumaDiv(a) == b) && (sumaDiv(b) == a));
}

int main(){
    int a, b;

    a = 220;
    b = 284;
    printf("Los números %d y %d %s amigos\n", a, b, numerosAmigos(a,b) ? "son" : "no son");

    a = 10;
    b = 12;
    printf("Los números %d y %d %s amigos\n", a, b, numerosAmigos(a,b) ? "son" : "no son");

    return 0;
}
