#include <stdio.h>
#include <stdlib.h>
#include "../../getnum/getnum.h"
#include <string.h>
  
#define TOTAL_ITEMS 2
#define MAX_LONG 10

#define BORRA_BUFFER while (getchar() != '\n')
 
typedef struct {
    int codigo;
    char desc[MAX_LONG];
    float precio;
} tItem;
 
typedef tItem tFactura[TOTAL_ITEMS]; // tFactura es un arreglo de tItem con TOTAL_ITEMS elementos.
 
void cargar(tFactura fact, int cant);
float importe(tFactura fact, int cant);
tItem leerItem();
 
int
main(void) {
    tFactura f;
    puts("INICIO\n");
    cargar(f, TOTAL_ITEMS);
    printf("%.2f\n", importe(f, TOTAL_ITEMS));
    return 0;
}

tItem leerItem(){
    tItem item; //Variable para retornar!¡
    do
    {
        item.codigo = getint("Ingrese el codigo del producto: ");
    } while (item.codigo < 0);
    do
    {
        printf("Descripción: ");
    } while (fgets(item.desc, MAX_LONG, stdin) == NULL || item.desc[0] == '\n');
    do
    {
        item.precio = getfloat("Ingrese el precio del producto: ");
    } while (item.precio <= 0);
    
    
    puts("");

    return item;
}

void cargar(tFactura fact, int cant){

    for(int i = 0; i < cant; i++){
        printf("--- NUEVO ITEM ---\n");
        fact[i] = leerItem();
    }
}

float importe(tFactura fact, int cant){
    float suma = 0;
    for(int i = 0; i < cant; i++){
        suma += fact[i].precio; 
    }
    return suma;
}