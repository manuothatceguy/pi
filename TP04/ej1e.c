#define DIVISION(x, y, z)	{int i; \
				  for(z = 0, i = x-y; i >= 0; z++, i-= y); \
					}
int
main( void )
{
    int a, b, c, m, n, p, x, y, z;


    a = 20; b=5; c=3;
    DIVISION(a, b, c);


    m=5; n=4; p=2;
    DIVISION(m++, n--, p);


    x=15; y=3; z=0;
    DIVISION(x, y, z);


    return 0;
}
