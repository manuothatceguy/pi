#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

#define DIM 9

int verifFila(char fila[]);
int sudokuSolver(char m[][DIM]);

int main(void) {
  // Una matriz vacía no es solución
  char sudoku[DIM][DIM] = {{0}};

  assert(sudokuSolver(sudoku)==0);

  char sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku2)==1);
  
  char sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2}, 
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku3)==0);
  
  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  char sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}
  };

  assert(sudokuSolver(sudoku4)==0);

  char sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku5)==0);
  puts("OK!");

  return 0;
}
int verifSq(char m[][DIM]){
    int dimCuad = DIM/sqrt(DIM);
    char digitos[DIM] = {0};
    int k = 0;
    for (int i = 0; i < DIM; i+=dimCuad)
    {
        for (int j = 0; j < DIM; j+=dimCuad)
        {
            k = 0;
            for (int p = i; p < dimCuad; p++)
            {
                for (int n = j; n < dimCuad; n++)
                {
                    digitos[k++] = m[p][n];
                }
            }
            if(verifFila(digitos) == 0)
                return 0;
        }
    }
    return 1;
    
}



int verifFila(char fila[]){
    char digitos[DIM] = {0};
    for (int i = 0; i < DIM; i++)
    {
        if (fila[i] < 1 || fila[i] > 9)
            return 0;
        else
            digitos[fila[i]-1]++;
    }
    for (int n = 0; n < DIM; n++)
    {
        if(digitos[n] != 1)
            return 0;
    }
    return 1;
}

int verifCol(char m[][DIM], int col){
    int digitos[DIM] = {0};
    for (int i = 0; i < DIM; i++)
    {
        digitos[i] = m[i][col];
    }
    for (int n = 0; n < DIM; n++)
    {
        if(!digitos[n])
            return 0;
    }
    return 1;
}

int sudokuSolver(char m[][DIM]){
    for (int i = 0; i < DIM; i++)
    {
        if(verifFila(m[i]) == 0 || verifCol(m,i) == 0 || verifSq(m) == 0)
            return 0;
    }
    return 1;
}