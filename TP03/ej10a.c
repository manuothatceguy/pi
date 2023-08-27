#include <stdio.h>
int main()
{
    double x = 1/3;
    printf("%f",x);
    while (x != 0.52 ) {
        x += .01;
        printf("%f", x);
    }
    return 0;
}
