#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"

typedef int TipoLinea[5];
typedef TipoLinea TipoCarton[3];

#define CANT_FILS 3
#define CANT_COLS 5
#define CANT_CASILLAS CANT_FILS*CANT_COLS
#define CANT_BOLILLAS 90
#define N 2

void generarCarton(TipoCarton player);
void imprimirCarton(TipoCarton carton);
int *jugar(int bolillero[], TipoCarton cartones[]);
int sacarBolilla(int bolillero[], int * cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
char buscarBolilla(TipoCarton carton, int bolilla);
char controlarLineas(TipoLinea linea);

int main(){

    // Seteo cartones
    TipoCarton cartones[N];
    randomize();
    
    printf("---BINGO---\n\n");
    
    for(int i = 0; i < N; i++){
        printf("Cartón del jugador %d:\n",i+1);
        generarCarton(cartones[i]);
        imprimirCarton(cartones[i]);
    }

    int bolillero[CANT_BOLILLAS + 1] = {0};

    puts("Comienza el juego...\n");
    int * win = jugar(bolillero,cartones);
    
    for(int i = 0; i < N; i++){
        if(win[i]){
            printf("Ganó el jugador %d\n",i+1);
        }
    }

    free(win);
    return 0;
}

void generarCarton(TipoCarton player){
    char numeros[CANT_BOLILLAS + 1] = {0};
    int num;
    for(int i = 0; i < CANT_FILS; i++){
        for(int j = 0; j < CANT_COLS; j++){
            do
            {
                num = randInt(1,CANT_BOLILLAS);
            } while (numeros[num] != 0);
            numeros[num] = 1;
            player[i][j] = num;
        }
    }
    return;
}

void imprimirCarton(TipoCarton carton){
    puts("\n--------------");
    for(int i = 0; i < CANT_FILS; i++){
        for(int j = 0; j < CANT_COLS; j++){
            printf("%.2d ",carton[i][j]);
        }
        puts("|");
    }
    puts("--------------\n");
    return;
}

int * jugar(int bolillero[], TipoCarton cartones[]){
    int bingo = 0, cantidadBolillas = CANT_BOLILLAS, bolilla, *winnersArray = calloc(N,sizeof(int));
    int lineasJug[N];
    while(!bingo){
        bolilla = sacarBolilla(bolillero,&cantidadBolillas);
        
        for(int i = 0; i < N; i++){
            lineasJug[i] = controlarCarton(cartones[i],bolilla);
            printf("Cartón del jugador: %d\n",i+1);
            imprimirCarton(cartones[i]);
        }
        
        for(int i = 0; i < N; i++){
            if(lineasJug[i] == CANT_FILS){
                winnersArray[i] = 1;
                bingo = 1;
            }
        }
    }
    return winnersArray;
}

int sacarBolilla(int bolillero[], int * cantBolillas){
    int bolilla;
    do
    {
        bolilla = randInt(1,CANT_BOLILLAS);
    } while (bolillero[bolilla]);
    bolillero[bolilla] = 1;
    (*cantBolillas)--;
    printf("Salió el número %d\n\n",bolilla);
    return bolilla;
}

int controlarCarton(TipoCarton carton, int bolilla){
    int lineas = 0;
    if(buscarBolilla(carton,bolilla)){
        for(int i = 0; i < CANT_FILS; i++){
            lineas += controlarLineas(carton[i]);
        }
    }
    return lineas;
}

char buscarBolilla(TipoCarton carton, int bolilla){
    for(int i = 0; i < CANT_FILS; i++){
        for(int j = 0; j < CANT_COLS; j++){
            if(carton[i][j] == bolilla){
                carton[i][j] = 0;
                return 1;
            }
        }
    }
    return 0;
}


char controlarLineas(TipoLinea linea){
    for(int i = 0; i < CANT_COLS; i++){
        if(linea[i] != 0){
            return 0;
        }
    }
    return 1;
}