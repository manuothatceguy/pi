#include <stdio.h>
#include <assert.h>
 
#define OK 1
#define ERROR !OK
 
int unDiaMas(int *, int *, int *);
 
static int bisiesto(int);
static int invalidoAnio(int);
static int invalidoMes(int);
static int invalidoDia(int, int, int);

int
main(void) {
    int dia, mes, anio;
 
    dia = 9, mes = 4, anio = 2021;
    printf("Fecha actual: %d/%d/%d\n", dia, mes, anio);
    if (unDiaMas(&dia, &mes, &anio))
        printf("Fecha con un dia mas: %d/%d/%d\n", dia, mes, anio);
    else
        printf("Error en los datos\n");
 
    dia = 1, mes = 1, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 2 && mes == 1 && anio == 2021);
 
    dia = 31, mes = 3, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 4 && anio == 2021);
 
    dia = 31, mes = 12, anio = 2020;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 1 && anio == 2021);
 
    printf("OK!\n");
    return 0;
}
 
static int
bisiesto(int anio) {
    int esb=0;
    if((anio%4 == 0 && anio%100!= 0) || anio%400 == 0)
        esb=1;
    return esb;
}

int daytab[2][12] = {{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};

int invalidoAnio(int a){ //Return 1 si hay error
    return a<0;
}

int invalidoMes(int m){
    return (m>12 || m<1);
}

int invalidoDia(int d, int m, int a){
    // Fuera del rango [1 , 31]
    if(d<0 || d>31)
        return 1;
    //Fuera del mes
    int esb = bisiesto(a);
    int diasMes = daytab[esb][m-1];
    if(d<1 || d > diasMes)
        return 1;
    return 0;
}

int unDiaMas(int *dia, int *mes, int *anio){
    if(invalidoAnio(*anio) || invalidoMes(*mes) || invalidoDia(*dia, *mes, *anio))
        return 0;  
    //Si no hay error de input, opero.

    *dia = *dia + 1; //Arranca
    if(invalidoDia(*dia,*mes,*anio)){
        (*mes)++;
        *dia = 1;
    }
    if(invalidoMes(*mes)){
        (*anio)++;
        *mes = 1;
    }
    return 1;
}