#include <stdio.h>
#include "../getnum/getnum.h"

float f1 (float x);
float f2 (float x);

int
main (void)
{
	float x, y, z;
	x = getfloat("Ingrese un número real: ");
	putchar('\n');

	y = f1(x);
	z = f2(x);

	printf("El doble de %g es %g\n",x, y);
	printf("El triple de %g es %g\n",x , z);
	return 0;
}

