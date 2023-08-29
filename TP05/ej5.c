/*
Escribir una función potencia, que reciba en dos parámetros de entrada la base (de tipo double) 
y el exponente (entero), y devuelva el valor de dicha potencia (En no más de 10 líneas).
Por ejemplo, potencia(2,-4) debe devolver 0.0625. 
En caso de no poder calcularse el resultado debe devolver –1.
*/

#include <stdlib.h>
#include <math.h>

#define EPSILON 0.00001

double potencia(double base, int exponente){

    double pot;
    double auxBase;
    if ((fabs(base) < EPSILON && exponente <= 0 ))
        return -1.0;
    if (exponente < 0){
        auxBase = 1 / base;
        exponente *= -1;
    }
    else
    auxBase = base;
    for(pot = 1; exponente; pot *= auxBase, exponente--);
    
    return pot;
}