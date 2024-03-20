#include <stdio.h>
#include <stdlib.h>
#include "random.h"

typedef struct {
    int x;
    int y;
} coordenada;

int experimento(coordenada part, int radio){
    int move;
    int outOfRange = 0;
    int tiempo = 0;
    while(!outOfRange){
        move = randInt(0,3);
        switch(move){
            case 0:
                (part.x)--;
                tiempo++;
                break;
            case 1:
                (part.x)++;
                tiempo++;
                break;
            case 2:
                (part.y)--;
                tiempo++;
                break;
            case 3:
                (part.y)++;
                tiempo++;
                break;
        }
        if((part.x * part.x) + (part.y * part.y) > (radio*radio))
            outOfRange = 1;
    }
    return tiempo;
}


int main(){
    randomize();
    coordenada part = {0,0};
    int tiempo;
    puts("EXPERIMENTO\n");
    printf("Radio\tTiempo\tRelación radio/tiempo\n\n");
    for(int i = 1; i < 16; i++){
        tiempo = experimento(part,i);
        printf("%d\t|%d\t|%f\n",i,tiempo,(double)i/tiempo);
        puts("-------------------------------------");
    }
    return 0;
}