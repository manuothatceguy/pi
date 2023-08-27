#define isdigit(x) (((x)>='0') && ((x)<='9'))?1:0
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int letra;
	letra = getchar();
	if ( isdigit(letra) )
		printf("Es un dígito\n");
    return 0;
}
