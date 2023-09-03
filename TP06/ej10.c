#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../random/random.h"
#define FIL 20
#define COL 80

void generar_matriz_num(int mat[][COL], int fil, int col) { //fil y col son TODAS
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            mat[i][j] = randInt(0,20);
        }
    }
}

int suma_div_9(int mat[][COL], int fil, int col){ // fil y col hacen ref a la pos del candidato a estrella
    int suma = 0;
    for (int i = -1; (i <= 1) && (fil+i < FIL); i++)
    {
        for(int j = -1; (j <= 1) && (col+j < COL); j++){
            suma+= mat[fil-i][col+j];
        }
    }
    return (suma/9);
    

}
int pone_estrella_eval(int mat[][COL], int fil, int col){
    for (int i = 1; i < fil; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if( suma_div_9(mat,i,j) > 10 )
                return 1;
        }
    }
    return 0;
    

}

void estrella(int mat[][COL], int fil, int col){
    for(int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
            if(pone_estrella_eval(mat,i,j))
                mat[i][j] = '*';
            else
                mat[i][j] = '~';
        }
    }
}

void matriz_estrellas(int mat[][COL],int fil,int col) {
    generar_matriz_num(mat,fil,col);
    for (int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
            estrella(mat,i,j);
        }
    }
}

int main() {
    int matriz[FIL][COL];
    randomize();

    matriz_estrellas(matriz, FIL, COL); //puede ser fil y col numeros menores o iguales a los que dice la consigna

    
    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}


