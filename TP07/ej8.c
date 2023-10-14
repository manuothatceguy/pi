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

void generarCarton(TipoCarton player);
void imprimirCarton(TipoCarton carton);
int jugar(int bolillero[], TipoCarton jug1, TipoCarton jug2);
int sacarBolilla(int bolillero[], int * cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
char buscarBolilla(TipoCarton carton, int bolilla);
char controlarLineas(TipoLinea linea);

int main(){

    // Seteo cartones
    TipoCarton jug1;
    TipoCarton jug2;
    randomize();
    
    printf("---BINGO---\n\n");
    
    puts("Generando cartón del jugador 1...");
    generarCarton(jug1);

    puts("Generando cartón del jugador 2...");
    generarCarton(jug2);
    
    puts("");

    puts("Carton jugador 1 a continuación:");
    imprimirCarton(jug1);

    puts("Carton jugador 2 a continuación:");
    imprimirCarton(jug2);

    int bolillero[CANT_BOLILLAS + 1];
    for (int i = 1; i <= CANT_BOLILLAS; i++) {
        bolillero[i - 1] = i;
    }
    for (int i = CANT_BOLILLAS - 1; i > 0; i--) {
        int j = randInt(0, i);
        int temp = bolillero[i];
        bolillero[i] = bolillero[j];
        bolillero[j] = temp;
    }
    puts("Comienza el juego...\n");
    int res = jugar(bolillero,jug1,jug2);
    printf("Ganador: %s\n",(res == 3)?"ambos ganaron":((res == 1)?"jugador 1":"jugador 2"));


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

int jugar(int bolillero[], TipoCarton jug1, TipoCarton jug2){
    int bingo = 0, cantidadBolillas = CANT_BOLILLAS, bolilla, lin1, lin2, retVal = 0;
    while(!bingo){
        bolilla = sacarBolilla(bolillero,&cantidadBolillas);
        lin1 = controlarCarton(jug1,bolilla);
        imprimirCarton(jug1);
        lin2 = controlarCarton(jug2,bolilla);
        imprimirCarton(jug2);
        if(lin1 == CANT_FILS && lin2 == CANT_FILS){
            retVal |= 3;
            bingo = 3;
        }
        else if(lin2 == CANT_FILS && lin1 != CANT_FILS){
            retVal |= 2;
            bingo = 2;
        }
        else if(lin1 == CANT_FILS){
            retVal |= 1;
            bingo = 1;
        }
    }
    return bingo;
}

int
sacarBolilla (int bolillero[], int *cantBolillas)
{
	int aux;
	int bolilla;


	aux = randInt(1, *cantBolillas -1) ;
	(*cantBolillas)--;
	bolilla = bolillero[aux];
	bolillero[aux] = bolillero[*cantBolillas];
    
    printf("Salió el número %d\n",bolilla);

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