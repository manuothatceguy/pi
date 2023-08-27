#include <stdio.h>

int main(){
    int edad = 25;
    float longitud = 185.654;
    char letra = 'Z';

    printf("%-5.0d*\n", edad);
    printf("\t%10d*\n", edad);
    printf("%-10.2f*\n", longitud);
    printf("%8.0d*\n", letra);

    return 0;
}
