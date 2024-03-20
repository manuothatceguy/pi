#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_ALUMNOS 40
#define MAX_LARGO 25

typedef char TAlumnos[MAX_ALUMNOS][MAX_LARGO];   
typedef char TCurso[MAX_LARGO];

void separaCursos(TAlumnos nombre, TCurso curso, TAlumnos cursoG, TAlumnos cursoH){
    int j = 0, k = 0;
    for(int i = 0; curso[i]; i++){
        printf("Comparé curso[%d] con 0 y entré al for\n",i);
        if(curso[i] == 'G'){
            printf("como curso[%d] = %c entonces copio en curso G el nombre: %s\n",i,curso[i],nombre[i]);
            strcpy(cursoG[j++] , nombre[i]);
            puts("Pude copiarlo");
        } else if(curso[i] == 'H'){
            printf("como curso[%d] = %c entonces copio en curso H el nombre: %s\n",i,curso[i],nombre[i]);
            strcpy(cursoH[k++], nombre[i]);
            puts("Pude copiarlo");
        }
    }
    cursoG[j][0] = 0;
    cursoH[k][0] = 0;
    puts("Fin del programa.");
}

// Cambiar de acuerdo al tipo elegido 
// Si usan "matriz" de chars debe quedar


int main(void){

    TAlumnos alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    TCurso curso={'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con "" 

    alumnos[0][0]=0; curso[0]=0;
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}