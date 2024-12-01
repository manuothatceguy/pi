#define MAXIMO2(num1, num2) ((num1)>(num2)?(num1):(num2))
#define MAXIMO3(number1, number2, number3) MAXIMO2(MAXIMO2(number1, number2), number3)
#include <stdio.h>

int main()
{
    int a,b,c;
    a = 5;
    b = 10;
    c = 7;
    int max = MAXIMO3(a, b, c);
    printf("%d", max);
    return 0;
}