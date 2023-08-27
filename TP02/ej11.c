#include <stdio.h>

int main(){
    
    int letra1, letra2, mayor;
    letra1 = getchar();
    letra2 = getchar();

    mayor = letra1>letra2 ? letra1:letra2;
    printf("%d\n", mayor);

    return 0;
}
