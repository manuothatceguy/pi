#include <stdio.h>

int main()
{
    int letra;

    while((letra = getchar()) != EOF){
        if ((letra == ' '))
        {
            printf("\n");
        }
        else
        {
            putchar(letra);
        }
        
    }

    return 0;
}

