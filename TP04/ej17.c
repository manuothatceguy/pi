#define ELAPSED(h1,m1,h2,m2) ((((h2)-(h1))*60 + ((m2)-(m1)))<0)?(((h2)-(h1))*60 + ((m2)-(m1)))*-1:(((h2)-(h1))*60 + ((m2)-(m1)))
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int minutos, h1, h2, m1, m2;
    h1 = 2; m1 = 10; h2 = 3; m2 = 15;
    minutos = ELAPSED(h1, m1, h2, m2);		/* minutos = 65 */
    printf("%d\n",minutos);
    minutos = ELAPSED(3, 15, 2, 10);		/* minutos = 65 */
    printf("%d\n",minutos);
    minutos = ELAPSED(h1, m1, h1 + 1, m1);	/* minutos = 60 */
    printf("%d\n",minutos);
    return 0;
}
