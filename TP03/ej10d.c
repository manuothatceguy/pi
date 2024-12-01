#include <stdio.h>

int main()
{
    int c, mayor;
    mayor = 0;
    while ( c = getchar() != EOF )
	{
		if ( c > mayor )
			mayor = c;
            break;
    }
    printf ("El mayor es %c\n",mayor);

    return 0;
}
