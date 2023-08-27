#include "../getnum/getnum.h"
#include <stdio.h>

int main(){
    int n, rta;
    n = getint("");
    rta = n >= 0 && n<16 ? (n < 10 ? n+'0' :n-10+'A') : n;
    printf("La respuesta es: %c\n", rta);

    return 0;
}
