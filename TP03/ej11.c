#include <stdio.h>

int main(void)
{
    int n;
    printf("%s\t%s\t%s\t%s\n","N","10*N","100*N","1000*N");
    for(n=1;n<=20;n++){
        printf("%d\t%d\t%d\t%d\n",n,10*n,100*n,1000*n);
    }
    

    
}
