#define CUBO(x)  ((x) * (x) * (x))
#include <stdio.h>


int cubo (int num);

int
main(void)
{
	int a=3, b, c, d, e, f;


	b = CUBO( ++a ); // b = ((4+1)*(5+1)*(6+1)) = 150

    c = CUBO( a++ ); // c = 6 * 7 * 8 = 336
    d = 3;
	e = cubo ( ++d ); // e = 64
	d = 3;
	f = cubo ( d++ ); // f = 27 d = 4
    printf("a=%d b=%d c=%d d=%d e=%d f=%d",a,b,c,d,e,f);
	return 0;
}


int 
cubo ( int num )
{
	return num * num * num;
}
