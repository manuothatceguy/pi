#include "../getnum/getnum.h"
#include <stdio.h>

int main()
{
    int num, countFive = 0, digit;
    num = getint("Ingrese un número: ");
    if (num < 0)
    {
        num *= -1;
    }
    
    for (digit = 0;num != 0;digit++)
    {
        if ((num % 5 == 0 ) && ((num + 1 )% 2 == 0))
        {
            countFive++;
            num /= 10;
        }
        else
        {
            num /= 10;
        }
    }
    printf("De %d dígito%s, %d %s a 5.\n",digit,digit>1?"s":"",countFive, countFive>1?"son iguales":"es igual");

    return 0;
}
