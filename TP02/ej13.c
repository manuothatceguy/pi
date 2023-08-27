#include <stdio.h>
#include "../getnum/getnum.h"

int main(){
    
    int num1, num2, res;

    num1 = getint("Ingrese un número: ");
    num2 = getint("Ingrese un número: ");

    res = (num1%num2)==0;
    printf("%d\n",res);

    return 0;
}
