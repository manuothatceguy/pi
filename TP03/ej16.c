#include <stdio.h>
#include "../getnum/getnum.h"

void print_binary(int num) { //ChatGPT 
    if (num > 1) {
        print_binary(num / 2);
    }
    printf("%d", num % 2);
}

int main() {
    int num = getint("Ingrese un número positivo: ");

    printf("El equivalente en base binaria es: ");
    if (num == 0) {
        printf("0");
    } else {
        print_binary(num);
    }
    printf("\n");

    return 0;
}