#include <stdio.h>
#include "../getnum/getnum.h"


int main()
{
    int num, countUnos = 0;
    num = getint("Ingrese número: ");
    while(num > 0){
        countUnos += num%2; //No hay que pensarlo como pasar el número a binario 
                            //sino en como contar la cantidad de unos solamente con resto de dividir por 2
        num /= 2;
    }
    printf("%d\n",countUnos);
    return 0;
}
