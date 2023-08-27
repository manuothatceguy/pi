#include <stdio.h>

int main()
{
    int digito,sumoAscii = 0, suma = 0;
    while((digito = getchar()) != '\n'){
        if ((digito < '0' || digito > '9' ) && digito != '.'){
            printf("Error\n");
            return 1;
        }
        if(sumoAscii && (digito != '.')){
            suma += (digito - '0');
        }
        if(digito == '.'){
            sumoAscii = 1;
        }
    }
    printf("La suma de la parte decimal es %d\n",suma);

    return 0;
}
