#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"
#include <math.h>

#define FUNCION(x) ((x)*(x) - 5*(x) + 6)
#define CANT_NUM 100000
#define EPSILON 0.000001
#define BLOCK 10

typedef struct {
    float numeros[CANT_NUM];
} dominio;

typedef struct {
    float ** roots;
    int dim;
} raices;

void extremos(float * min, float * max){
    puts("Dominio de la función: \n");
    do{
        *min = getfloat("Ingrese el extremo inferior del intervalo: ");
        *max = getfloat("Ingrese el extremo superior del intervalo: ");
    } while(*min > *max);
    printf("El intervalo queda de la siguiente manera:\t[%f,%f]\n\n",*min,*max);
}

dominio setearIntervalo(){
    
    float min, max;
    min = max = 0;
    extremos(&min,&max);

    dominio retDom; //Dominio auxiliar de retorno

    float incremento = (max - min)/(CANT_NUM-1);
    
    retDom.numeros[0] = min;
    for(int i = 1; i < CANT_NUM; i++){
        retDom.numeros[i] = retDom.numeros[i - 1] + incremento;
    }

    return retDom;
}

void agregarIntervalo(float raizMin, float raizMax, raices * root){
    if(root->dim % BLOCK == 0){
        root->roots = realloc(root->roots,(root->dim + BLOCK)*sizeof(float));
    }
    float * intervalo = malloc(2*sizeof(float));
    intervalo[0] = raizMin;
    intervalo[1] = raizMax;
    root->roots[root->dim] = intervalo;
    (root->dim)++;
    return;
}

void calcularCeros(float min, float max, raices * resp) {
    float numMax = FUNCION(min), intervalMin = min, intervalMax = min;
    for (float x = min + EPSILON; x <= max; x += EPSILON) {
        float num = FUNCION(x);
        if ((numMax > -EPSILON && num < EPSILON) || (numMax < EPSILON && num > -EPSILON) || fabs(num) < EPSILON) {
            intervalMax = x;
        } else {
            if (intervalMin != intervalMax) {
                agregarIntervalo(intervalMin, intervalMax, resp);
            }
            intervalMin = intervalMax = x;
        }

        numMax = num;
    }
    if (intervalMin != intervalMax) {
        agregarIntervalo(intervalMin, intervalMax, resp);
    }
}

void liberarMemoria(raices * rts){
    for(int i = 0; i < rts->dim; i++){
        free(rts->roots[i]);
    }
    free(rts->roots);
}

int main(){
    dominio dom = setearIntervalo();
    raices raiz = {NULL,0};
    calcularCeros(dom.numeros[0],dom.numeros[CANT_NUM - 1],&raiz);
    for(int i = 0; i < raiz.dim; i++){
        printf("%f %f\n",raiz.roots[i][0], raiz.roots[i][1]);
    }
    puts("");
    liberarMemoria(&raiz);
}

