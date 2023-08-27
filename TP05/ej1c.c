#include <stdio.h>

int
main( void )
{	
    char letra; 
    void segundo ( void );
    printf( "Ingrese un carácter : ");
    letra = getchar();
    segundo();
    printf( " letra es : %c\n", letra );
    return 0;
}

void 
segundo( void )
{	
    char letra; 
 	letra = 'X';
 	return;
}