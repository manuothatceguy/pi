#include <stdio.h>



void primero ( void );
void segundo ( void );
                        
int
main ( void )
{   
    int a, b, c; 
    a = 1;    
 	printf("El valor de c es %d", c );
    segundo();
    printf ("El valor de a es %d, el de b es %d",a , b );
  	primero();      
    printf("El valor de a es %d, el de c es %d", a, c );
	return 0;
}


void 
primero ( void )
{ 	
    int a,c;
 	a = 3;   
 	c = 0;
}
	 
void
segundo ( void )
{	
	int a,b,c;
	c = 0;   
	a = 2;   
	b = -a;
}

