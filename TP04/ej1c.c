#define CUBO(x)  x * x * x
#include <stdio.h>
// a+1 * a+1 * a+1
	
int cubo (int num);


int
main(void)
{
	int a=4, b, c;


	b = CUBO(a+1); //el macro anda mal porque faltan paréntesis en la definición
	c = cubo(a+1); //la función cubo se ejecuta bien porque se aplica el a+1 antes de mandarlo a la función

    printf("b=%d,c=%d",b,c);
	return 0;
}
	
int 
cubo ( int num )
{
	return num * num * num;
}
