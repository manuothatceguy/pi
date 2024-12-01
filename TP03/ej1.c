/*
* Leer un caracter desde la entrada estándar e imprimir por salida estándar si el caracter es una letra o no y, en caso de ser una letra, 
*indicar si es letra mayúscula o minúscula, sin tener en cuenta el caracter ‘ñ’. (En no más de 15 líneas).
*
*/

#include <stdio.h>

int main()
{
    int letra;
    letra = getchar();
    if (letra>='A' && letra<='Z')
    {
        printf(" es una letra mayúscula.\n");
    }
    else if (letra>='a' && letra<='z')
    {
        printf(" es una letra minúscula.\n");
    }
    else
    {
        printf(" no es una letra.\n");
    }
    return 0;
}
