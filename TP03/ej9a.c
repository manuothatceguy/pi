// contar blanks tabs newlines

#include <stdio.h>

int main()
{
    int c, cont = 0; //importante el cont = 0 porque sino me guarda basura!!! ojo
    while ((c=getchar()) != EOF)
    {
        if (c == 9 || c == 10 || c == ' ')
        {
            ++cont;
        }
        
    }
    printf("Número de blanks, tabs y newlines es: %d\n",cont);

    return 0;
}
