#include <stdio.h>
#include <stdlib.h>
#include "../../random/random.h"

#define MIN -5
#define MAX 5
#define BLOQUE 10

typedef struct{
    int x;
    int y;
} tPunto2D;

typedef tPunto2D * tPos;

int main(){
    randomize();
    
    tPunto2D pos = {randInt(MIN,MAX),randInt(MIN,MAX)};
    tPos posiciones = NULL;

    int dim = 0;

    while(pos.x != 0 && pos.y != 0){
        
        if(dim % BLOQUE == 0){
            posiciones = realloc(posiciones,(dim+BLOQUE)*sizeof(tPunto2D));
        }
        
        posiciones[dim].x = pos.x;
        posiciones[dim].y = pos.y;
        
        dim++;

        pos.x = pos.x + randInt(MIN,MAX);
        pos.y = pos.y + randInt(MIN,MAX);
    }

    posiciones = realloc(posiciones,dim*sizeof(tPunto2D));

    puts("posicion inicial: (0,0)");

    for(int i = 0; i < dim; i++){
        printf("posicion numero %d: (%d,%d)\n",i+1,posiciones[i].x,posiciones[i].y);
    }
    puts("posicion final: (0,0)");
    free(posiciones);
    return 0;
}