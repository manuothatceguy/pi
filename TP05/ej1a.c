#include <stdio.h>

void local ( void );

int
main ( void )
{
    int a,b;
    a = 2; b = 3;
    local();
 	printf(" a vale : %d\tb vale %d\n",  a, b );
    return 0;
}

void 
local ( void )
{	
    int a,b;
    a =  -5;
    b = 10; 
 	return ;
}

//no tiene sentidooooooooooooooooooo
