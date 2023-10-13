#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "random.h"
#include "getnum.h"

void generarNumero(char num[], int x){
    char number[10] = {0}; //Vector de apariciones
    int digit, i = 0;
    
    randomize();

    while(i < x){
        if(i == 0){
            digit = randInt(1,9); //porque sino sería 0xxxx, número de 4 digitos
        }
        else{
            digit = randInt(0,9);
        }
        
        if(number[digit] == 0){
            number[digit]++;
            num[i++] = digit + '0';
        }
    }
    return;
}

int elegirNivel(){
    int n;
    do
    {
        n = getint("Ingrese el nivel de dificultad: ");
    } while (n < 1);
    return n;
}

void leerNumero(char num[], int x){
    int n;
    do
    {
        n = getint("Ingrese un número: ");
    } while (n < pow(10,x-1) || n >= pow(10,x));
    
    sprintf(num,"%d",n); //Convierto el número en un str
    
    return;
}

int cantidadBien(char num[], char numS[], int x){
    int bien = 0;
    for(int i = 0; i < x; i++){
        if(num[i] == numS[i]){
            bien++;
        }
    }
    return bien;
}

int cantidadRegular(char num[], char numS[], int x){
    int regular = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            if(num[i] == numS[j] && i != j){
                regular++;
            }
        }
    }
    return regular;
}

int coincideNumero(char num[], char numS[], int x){
    int cantBien = cantidadBien(num, numS,x);
    int cantRegular = cantidadRegular(num, numS,x);
    printf("%d bien, %d regular\n",cantBien,cantRegular);
    if(cantBien == x){
        return 1;
    }
    return 0;
}

void resultado(int match, char numSecreto[]){
    if(match){
        puts("Ganaste!");
    }
    else{
        printf("Lo siento, el número es %s\n",numSecreto);
    }
    return;
}

int main(){
    int x;
    do
    {
        x = getint("Ingrese la cantidad de digitos del número a adivinar (de 1 a 10): ");
    } while (x < 1 || x > 10);
    
    char * numSecreto = malloc(x+1);
    char * numUsuario = malloc(x+1);
    numSecreto[x] = '\0'; //Le pongo marca de fin
    numUsuario[x] = '\0';

    generarNumero(numSecreto,x);
    int lvl = elegirNivel();
    int match = 0;
    for(int i = 0; i < lvl && !match; i++){
        leerNumero(numUsuario,x);
        match = coincideNumero(numUsuario, numSecreto,x);
    }

    resultado(match,numSecreto);
    free(numSecreto);
    free(numUsuario);
    return 0;

}