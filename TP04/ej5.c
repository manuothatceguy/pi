#define MAXIMO2(num1, num2) ((num1)>(num2)?(num1):(num2))
#include <stdio.h>
int main()
{
    int a,b;
    a = 5;
    b = 10;
    int max = MAXIMO2(a, b);
    printf("%d", max);
    return 0;
}
