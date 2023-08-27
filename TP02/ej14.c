#include <stdio.h>
#include "../getnum/getnum.h"

int main(){
    
    double a,b;
    double prom; 

    a = getint("Ingrese un número: ");
    b = getint("Ingrese un número: ");

    prom = ((a + b)/2);

    printf("El promedio es: %f\n", prom);
    printf("La suma es: %.0f\n", a+b);
    printf("El mayor es: %.0f\n", a==b ? a:(a>b?a:b));
    printf("El menor es: %.0f\n", a==b ? a:(a<b?a:b));
    printf("%s\n", a==b ? "Son iguales":"No son iguales");
    return 0;
}
