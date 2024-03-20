#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

/* Para definir “alumnos” como matriz de caracteres */
#define MAX_ALUMNOS 6
#define MAX_NOMBRE 15
#define BLOCK 10
#define NOTA_MINIMA 4
typedef char TAlumnos[MAX_ALUMNOS][MAX_NOMBRE];

/* Para definir “alumnos” como vector de punteros a char */
/* typedef char * Talumnos[]; */

char ** aprobados(TAlumnos nombres, int notas[]){
    char ** arrRet = NULL;
    int dim = 0;
    int j = 0;
    for(int i = 0; i < MAX_ALUMNOS; i++){
        if(notas[i] >= NOTA_MINIMA){
            if(dim % BLOCK == 0){
                arrRet = realloc(arrRet,(dim+BLOCK)*sizeof(char*));
            }
            arrRet[j] = malloc(MAX_NOMBRE*sizeof(char));
            strcpy(arrRet[j++],nombres[i]);
            dim++;
        }
    }
    arrRet = realloc(arrRet,(dim+1)*sizeof(char*));
    arrRet[dim] = NULL;
    return arrRet;
}




int main(void){

    TAlumnos alumnos = {"Juan", "Pedro", "Martin", ""};
    int notas[] = {1, 4, 10, 2, 10, 11};
    
    char ** apr = aprobados(alumnos, notas);
    if(apr == NULL){
        printf("No hay suficiente memoria!\n");
        return 1;
    }
    assert(!strcmp(alumnos[1], apr[0]) && !strcmp(alumnos[2], apr[1]) && !strcmp(alumnos[3], apr[2]));

    puts("OK!");
    for(int i = 0; apr[i] != NULL ;i++){
        free(apr[i]);
    }
    
    free(apr);
    return 0;
}