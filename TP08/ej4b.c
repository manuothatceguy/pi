#include <stdio.h>
#include <stdlib.h>
#include "random.h"

#define CANT_PALOS 4
#define CANT_NUM 13
#define CANT_CARTAS CANT_NUM*CANT_PALOS
#define TOPE_CHECK 5
#define PAR 2
#define PIERNA 3
#define POKER 4

typedef struct{
    int palo, num;
} naipe;

void setMazo(naipe mazo[]){
    int c = 0;
    for(int i = 0; i < CANT_PALOS && c < CANT_CARTAS; i++){
        for(int j = 1; j <= CANT_NUM && c < CANT_CARTAS; j++){
            mazo[c].palo = i;
            mazo[c].num = j;
            c++;
        }
    }
}

void mezcMazo(naipe mazo[]){
    naipe aux;
    int pos;
    for(int i = 0; i < CANT_CARTAS; i++){
        aux = mazo[i];
        pos = randInt(0,CANT_CARTAS-1);
        mazo[i] = mazo[pos];
        mazo[pos] = aux;
    }
    return;
}

int checkJugada(naipe mazo[], int start, int * num) {
    int contador[CANT_NUM] = {0}; // Inicializar un contador para cada número de carta
    
    // Contar las apariciones de cada número en la jugada actual desde el índice 'start'
    for (int i = start; i < TOPE_CHECK + start; i++) {
        contador[mazo[i].num - 1]++; // Incrementar el contador para el número de la carta actual
    }

    int resultado = 0;

    // Verificar si hay un POKER, PIERNA o PAR en la jugada actual
    for (int i = 0; i < CANT_NUM; i++) {
        if(contador[i] > resultado){
            *num = mazo[i].num;
            resultado = contador[i];
        }
    }
    return resultado;
}

void printMano(int idxStart, naipe mazo[]){
    char * palos[] = {"PICA", "CORAZONES", "TREBOL", "DIAMANTE"};
    for(int i = idxStart; i < idxStart+TOPE_CHECK; i++){
        printf("Carta: %d de %s\n",mazo[i].num,palos[mazo[i].palo]);
    }
    puts("");
}

int revisarDesempate(int numPlayer, int numMaquina){
    if(numPlayer > numMaquina)
        return 2;
    else if(numPlayer < numMaquina)
        return 1;
    return 0;
}

int main(){
    naipe maz[CANT_CARTAS];
    randomize();
    setMazo(maz);
    mezcMazo(maz);
    char * config[] = {"NADA","PAR","PIERNA","POKER"};
    
    
    int puntajePlayer = 0;
    int puntajeMaquina = 0;
    int manoPlayer, manoMaquina, desempate;
    int numManoPlayer = 0, numManoMaquina = 0;

    puts("-------\n|POKER|\n-------\n");

    for(int i = 0, j = CANT_CARTAS/2; i < CANT_CARTAS/2 - TOPE_CHECK && j < CANT_CARTAS - TOPE_CHECK; i += 5, j += 5){
        
        //Mano jugador
        puts("Mano del player:\n");
        printMano(i,maz);
        //Mano maquina
        puts("Mano de la máquina:\n");
        printMano(j,maz);
        
        manoPlayer = checkJugada(maz,i,&numManoPlayer);
        printf("El jugador obtuvo la siguiente jugada: %s\n",config[manoPlayer-1]);


        manoMaquina = checkJugada(maz,j,&numManoMaquina);
        printf("La máquina obtuvo la siguiente jugada: %s\n",config[manoMaquina-1]);

        puts("");

        if(manoPlayer > manoMaquina){
            puntajePlayer++;
            puts("El jugador suma puntos!\n");
        } else if(manoMaquina > manoPlayer){
            puntajeMaquina++;
            puts("La máquina suma puntos!\n");
        } else if(manoMaquina <= 1 && manoPlayer <= 1){
            puts("Ningún jugador suma puntos en esta ronda.\n");
        } else{
            desempate = revisarDesempate(numManoPlayer,numManoMaquina);
            printf("Desempate.\nSuma punto %s\n\n",desempate==1?"la máquina.":"el player.");
            if(desempate == 2)
                puntajePlayer++;
            if(desempate == 1)
                puntajeMaquina++;
        }

        printf("Puntajes:\nPlayer: %d\tMáquina: %d\n\n",puntajePlayer,puntajeMaquina);
    }
    printf("---\nFIN\n---\n\nPUNTAJES FINALES\nplayer: %d\tmáquina: %d\n\n",puntajePlayer,puntajeMaquina);
    if(puntajeMaquina > puntajePlayer){
            puts("Ganó la máquina");
        } else if(puntajePlayer > puntajeMaquina){
            puts("Ganó el player");
        } else{
            puts("Empate!");
        }
    return 0;
}