#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 20
#define COLUMNAS 80

// Función para generar una matriz aleatoria de intensidades en el cielo
void generarMatriz(int matriz[FILAS][COLUMNAS]) {
    srand(time(NULL));
    for (int i = 1; i < FILAS - 1; i++) {
        for (int j = 1; j < COLUMNAS - 1; j++) {
            matriz[i][j] = rand() % 21; // Valores entre 0 y 20
        }
    }
}

// Función para graficar las estrellas en la matriz
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
