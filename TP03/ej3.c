#include <stdio.h>
#include "../getnum/getnum.h"

#define BASE 300

int main()
{
    double venta;
    venta = getfloat("Ingrese un valor de venta: ");
    while (venta < 0)
    {
        venta = getfloat("Ingrese un valor de venta: ");
    }
    if (venta < 1000)
    {
        printf("Cobra %d\n", BASE);
    }
    else if ( venta <= 2000 )
    {
        printf("Cobra %.2f\n", (BASE+(venta*0.05)));
    }
    else if ( venta <= 4000 )
    {
        printf("Cobra %.2f\n", (BASE+(venta*0.07)));
    }
    else
    {
        printf("Cobra %.2f\n", (BASE+(venta*0.09)));
    }
    return 0;
}
