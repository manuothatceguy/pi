#include <stdio.h>

static void este(void);

int main(void){	
    static int  m;
    int b;
    m = 2; 
    b = 3;
                
 	este();
    printf("\nm vale : %d\n", m );
    printf("b vale : %d\n", b );
 	return 0;

}


static void este(void){	
    
    int m = 0,b;  
 	m++; 
    b = - 3;
    printf( "Dentro de este() m vale %d y b vale %d", m, b);
    return;

}