#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../random/random.h"
#define FILAS 20
#define COLUMNAS 80

void generarMatriz(int matriz[FILAS][COLUMNAS]) {
    randomize();
    for (int i = 1; i < FILAS - 1; i++) {
        for (int j = 1; j < COLUMNAS - 1; j++) {
            matriz[i][j] = randInt(0,20); // Valores entre 0 y 20
        }
    }
}

void graficarEstrellas(int matriz[FILAS][COLUMNAS]) {
    for (int i = 1; i < FILAS - 1; i++) {
        for (int j = 1; j < COLUMNAS - 1; j++) {
            int suma = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    suma += matriz[i + x][j + y];
                }
            }
            if ((matriz[i][j] + suma) / 9 > 10) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int cielo[FILAS][COLUMNAS];

    generarMatriz(cielo);
    graficarEstrellas(cielo);

    return 0;
}