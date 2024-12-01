#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void transpose(int dim, int matrix[][3]);
void swap_matrix(int fil, int col, int m[fil][col], int fromFil, int toFil, int fromCol, int toCol);

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int dim = 9;
    transpose(dim, matrix);
    for (int i = 0; i < 3; i++) //Print matrix
    {
        for (int j = 0; j < 3; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    
    return 0;
}

void swap_matrix(int fil, int col, int m[fil][col], int fromFil, int toFil, int fromCol, int toCol){
    int aux;
    aux = m[fromFil][fromCol];
    m[fromFil][fromCol] = m[toFil][toCol];
    m[toFil][toCol] = aux;
}

void transpose(int dim, int matrix[][3]){
    int fil, col; 
    fil = col = (3);
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; (j < col)&&(i!=j); j++){
            int aux;
            aux = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = aux;
        }
    }
}