#define DIVISOR(a,b) !((a)%(b))
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b = 10, c = 3;
    a = DIVISOR(b,c); 	/* a = 0 */
    printf("%d",a);
    a = DIVISOR(b,c-1);	/* a = 1 */
    printf("%d",a);
    return 0;
}
