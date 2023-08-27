#include <stdio.h>
#include "../getnum/getnum.h"

int main(){
    
    int num;
    num = getint("Ingrese un entero: ");
    num <<= 1; //1 deecalaje a la izquierda es como multiplicar por 2
    printf("%d\n", num);

    return 0;
}
