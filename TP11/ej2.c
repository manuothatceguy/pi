#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include "../getnum/getnum.h"

#define CANT_INTERVALOS 100000
#define CANT_FUNC 5
#define EPSILON 0.000001
#define BLOCK 10

typedef double(*TFunc)(double x);

typedef struct inverval{
    float min, max;
    TFunc f;
} interval;

typedef struct TRaices{
    interval * intervalos;
    size_t dim;
} TRaices;

/**
 * Función de front para poner las opciones
*/
static void opciones(){
    printf("\n------------------------------------------------------\n");
    printf("-----CÁLCULO DE RAÍCES DE FUNCIONES MATEMÁTICAS-----\n");
    printf("Elija la función matemática que desea calcularle las raíces:\n\n");
    printf("1)\tsen(x)\n");
    printf("2)\tcos(x)\n");
    printf("3)\ttan(x)\n");
    printf("4)\tln(x)\n");
    printf("5)\tlog(x)\n");
    printf("\n------------------------------------------------------\n");
}

interval menu(){
    opciones();
    int opt;
    do
    {
        opt = getint("Ingrese su opción: ");
    } while (opt <= 0 || opt > CANT_FUNC);
    
    TFunc func[] = {sin,cos,tan,log,log10};

    // VALIDAR DOMINIO, HACER FUNCION AUXILIAR !

    int validDomain = 1;
    float min, max;
    do
    {
        if(!validDomain){
            puts("Error de dominio, ingrese los valores nuevamente\n");
        }
        min = getfloat("Ingrese el mínimo del dominio: ");
        max = getfloat("Ingrese el máximo del dominio: ");
        
        func[opt - 1](min);
        func[opt - 1](max);

        validDomain = (errno != EDOM);
        errno = 0;

    } while (!validDomain);
    
    interval ret;
    ret.f = func[opt - 1];
    ret.min = min;
    ret.max = max;
    puts("Dominio OK");
    return ret;
}




// repensar esta función


/*static void agregarIntervalo(float raizMin, float raizMax, TRaices * root){
    if(root->dim % BLOCK == 0){
        root->intervalos = realloc(root->roots,(root->dim + BLOCK)*sizeof(float));
    }
    float * intervalo = malloc(2*sizeof(float));
    intervalo[0] = raizMin;
    intervalo[1] = raizMax;
    root->roots[root->dim] = intervalo;
    (root->dim)++;
    return;
}*/

static void agregarRaices(float rMin, float rMax, TRaices * raizAlmacen){
    size_t dim = raizAlmacen->dim;
    raizAlmacen->intervalos = realloc(raizAlmacen->intervalos,sizeof(interval)*(raizAlmacen->dim + 1));
    raizAlmacen->intervalos[dim].min = rMin;
    raizAlmacen->intervalos[dim].max = rMax;
    raizAlmacen->dim++;
    return;
}

TRaices calculoDeRaices(interval funcion){
    float min = funcion.min;
    float max = funcion.max;
    float numMax = min;
    float incremento = (max - min)/CANT_INTERVALOS;
    float minInterval = min, maxInterval = min, num;
    
    TRaices roots;
    
    roots.intervalos = NULL;
    roots.dim = 0;

    for(float x = min; x <= max; x += incremento){
        num = funcion.f(x);
        if ((numMax > -EPSILON && num < EPSILON) || (numMax < EPSILON && num > -EPSILON) || fabs(num) < EPSILON) {
            maxInterval = x;
        } else {
            if (minInterval != maxInterval) {
                agregarRaices(minInterval, maxInterval, &roots);
            }
            minInterval = maxInterval = x;
        }

        numMax = num;
    }
    return roots;
}


int main(){

    interval funcion = menu();
    TRaices ceros = calculoDeRaices(funcion);
    for(int i = 0; i < ceros.dim; i++){
        printf("[%f,%f]\n",ceros.intervalos[i].min,ceros.intervalos[i].max);
    }
    free(ceros.intervalos);
    return 0;
}