#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "random.h"
#include "getnum.h"

#define X 5 

void generarNumero(char num[]){
    char number[10] = {0}; //Vector de apariciones
    int digit, i = 0;
    
    randomize();

    while(i < X){
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

void leerNumero(char num[]){
    int n;
    do
    {
        n = getint("Ingrese un número: ");
    } while (n < pow(10,X-1) || n >= pow(10,X));
    
    sprintf(num,"%d",n); //Convierto el número en un str
    
    return;
}

int cantidadBien(char num[], char numS[]){
    int bien = 0;
    for(int i = 0; i < X; i++){
        if(num[i] == numS[i]){
            bien++;
        }
    }
    return bien;
}

int cantidadRegular(char num[], char numS[]){
    int regular = 0;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < X; j++){
            if(num[i] == numS[j] && i != j){
                regular++;
            }
        }
    }
    return regular;
}

int coincideNumero(char num[], char numS[]){
    int cantBien = cantidadBien(num, numS);
    int cantRegular = cantidadRegular(num, numS);
    printf("%d bien, %d regular\n",cantBien,cantRegular);
    if(cantBien == X){
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
    char numSecreto[X+1];
    char numUsuario[X+1];
    numSecreto[X] = 0; //Le pongo marca de fin
    numUsuario[X] = 0;

    generarNumero(numSecreto);
    int lvl = elegirNivel();
    int match = 0;
    for(int i = 0; i < lvl && !match; i++){
        leerNumero(numUsuario);
        match = coincideNumero(numUsuario, numSecreto);
    }

    resultado(match,numSecreto);
    return 0;

}