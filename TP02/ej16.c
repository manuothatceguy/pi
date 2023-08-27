#include <stdio.h>

int main(){

    int a,b;

    a = getchar();
    b = getchar();

    if (a == b)
    {
        printf("El caracter '%c' es igual al caracter '%c'\n",a,b);
    }
    else if (a<b)
    {
        printf("El caracter '%c' es menor al caracter '%c'\n",a,b);
    }
    else
    {
        printf("El caracter '%c' es mayor al caracter '%c'\n",a,b);
    }
    
    return 0;
}
