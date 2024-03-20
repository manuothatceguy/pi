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

int checkJugada(naipe mazo[]){
    int target[TOPE_CHECK] = {0};
    for(int i = 0; i < TOPE_CHECK; i++){
        for(int j = 0; j < TOPE_CHECK; j++){
            if(mazo[i].num == mazo[j].num)
                target[i]++;
        }
    }

    int retVal = 0;
    int c = 0;
    for(; c < TOPE_CHECK; c++){
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

int main(){
    naipe maz[CANT_CARTAS];
    randomize();
    setMazo(maz);
    mezcMazo(maz);
    char * config[] = {"NADA","PAR","PIERNA","POKER"};
    char * palos[] = {"PICA", "CORAZONES", "TREBOL", "DIAMANTE"};
    
    for(int i = 0; i < TOPE_CHECK; i++){
        printf("Carta numero %d: %d de %s\n",i+1,maz[i].num,palos[maz[i].palo]);
    }
    puts("");

    int ans = checkJugada(maz);

    printf("%s\n",config[ans]);

    
    return 0;
}