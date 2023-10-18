#include <stdio.h>
#include <stdlib.h>
#include "random.h"

#define CANT_PALOS 4
#define CANT_NUM 13
#define CANT_CARTAS CANT_NUM*CANT_PALOS
#define TOPE_CHECK 5
#define PAR 2
#define PIERNA 3
#define POKER 5


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

int checkJugada(naipe mazo[], int start){
    int target[TOPE_CHECK] = {0};
    for(int i = start; i < CANT_CARTAS && i < start + TOPE_CHECK; i++){
        for(int j = start + 1; j < CANT_CARTAS && j < start + CANT_CARTAS - start; j++){
            if(mazo[i].num == mazo[j].num)
                target[i - start]++;
        }
    }

    int retVal = 0;
    for(int c = 0; c < TOPE_CHECK; c++){
        if(target[c] > retVal)
            retVal = target[c];
    }
    
    switch(retVal){
        case POKER:
            return 3;
            break;
        case PIERNA:
            return 2;
            break;
        case PAR:
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

int revisarDesempate(naipe mazo[], int idxPlayer, int idxMaquina, int * puntajePlayer, int * puntajeMaquina, int resultado){
    int naipesPlayer[TOPE_CHECK] = {0};
    int naipesMaquina[TOPE_CHECK] = {0};
    int ret = 0;

    for(int i = idxPlayer; i < idxPlayer + TOPE_CHECK && i < CANT_CARTAS; i++){
        for (int j = idxMaquina; j < idxMaquina + TOPE_CHECK && j < CANT_CARTAS; j++){
            if(mazo[i].num == mazo[j].num){
                naipesPlayer[i - idxPlayer]++;
                naipesMaquina[j - idxMaquina]++;
            }
        }
    }

    int i = 0; int j = 0;
    for(; i < TOPE_CHECK && naipesPlayer[i] != resultado; i++);
    for(; j < TOPE_CHECK && naipesMaquina[j] != resultado; j++);

    if(i < TOPE_CHECK && j < TOPE_CHECK && mazo[idxMaquina + j].num > mazo[idxPlayer + i].num){
        (*puntajeMaquina)++;
        ret = 1;
    }
    else if(i < TOPE_CHECK && j < TOPE_CHECK && mazo[idxMaquina + j].num < mazo[idxPlayer + i].num)
    {
        (*puntajePlayer)++;
        ret = 2;
    }
    return ret;
}

void printMano(int idxStart, naipe mazo[]){
    char * palos[] = {"PICA", "CORAZONES", "TREBOL", "DIAMANTE"};
    for(int i = idxStart; i < idxStart+TOPE_CHECK; i++){
        printf("Carta: %d de %s\n",mazo[i].num,palos[mazo[i].palo]);
    }
    puts("");
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

    for(int i = 0, j = CANT_CARTAS/2; i < CANT_CARTAS/2 - TOPE_CHECK && j < CANT_CARTAS - TOPE_CHECK; i += 5, j += 5){
        
        //Mano jugador
        printMano(i,maz);
        //Mano maquina
        printMano(j,maz);
        
        manoPlayer = checkJugada(maz,i);
        printf("El jugador obtuvo la siguiente jugada: %s\n",config[manoPlayer]);


        manoMaquina = checkJugada(maz,j);
        printf("La máquina obtuvo la siguiente jugada: %s\n",config[manoMaquina]);

        puts("");

        if(manoPlayer > manoMaquina){
            puntajePlayer++;
            printf("El jugador suma puntos!\nPuntaje del player: %d\n\n",puntajePlayer);
        } else if(manoMaquina > manoPlayer){
            puntajeMaquina++;
            printf("La máquina suma puntos!\nPuntaje de la máquina: %d\n\n",puntajeMaquina);
        } else if(manoMaquina){
            desempate = revisarDesempate(maz, i, j, &puntajePlayer, &puntajeMaquina, manoMaquina);
            printf("Desempate.\nSuma punto %s.\n",desempate==1?"la máquina.":"el player");
        }
    }
    printf("PUNTAJES FINALES\nplayer: %d\tmáquina: %d\n\n",puntajePlayer,puntajeMaquina);
    if(puntajeMaquina > puntajePlayer){
            puts("Ganó la máquina");
        } else if(puntajePlayer > puntajeMaquina){
            puts("Ganó el player");
        } else{
            puts("Empate!");
        }
    return 0;
}