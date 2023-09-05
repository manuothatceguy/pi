#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../random/random.h"
#define FILAS 5
#define COLUMNAS 5

void swap(int fil, int col, int m[fil][col], int fromFil, int toFil, int fromCol, int toCol){
    int aux;
    aux = m[fromFil][fromCol];
    m[fromFil][fromCol] = m[toFil][toCol];
    m[toFil][toCol] = aux;
}

void shift_fila(int fil, int col, int m[fil][col], int filDest, int filOrig)
{
    for (int i = 0; i < fil; i++){
        swap(fil,col,m,filOrig,filDest,i,i);
    }
}

void sorting(int fil, int col, int m[fil][col], int colRef){
    --colRef;
    int idx_min;
    for (int i = 0; i < fil-1; i++)
    {
        idx_min = i;
        for (int j = i+1; j < fil; j++)
        {
            if (m[j][colRef] < m[idx_min][colRef])
                idx_min = j;
        }
        if (idx_min != i)
            shift_fila(fil,col,m,idx_min,i);
    }
    
    
}

int main()
{
    int matriz[5][5] = { {8, 1, 3 ,4 ,5}, {2,3,5,7,8}, {3,4,3,5,6}, {0,5,4,2,4}, {6,4,3,5,6} };
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");

    }
    printf("\n");

    sorting(5,5,matriz,1);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");

    }
    printf("\n");
    
    
    return 0;
}
