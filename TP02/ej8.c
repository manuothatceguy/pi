#include <stdio.h>
#include "../getnum/getnum.h"

int main(){
    float velocidad;

    velocidad = getfloat("Ingrese una velocidad en m/s: ");

    //Conversión

    velocidad *= 3.6;

    printf("%fkm/h", velocidad);

    return 0;
}
