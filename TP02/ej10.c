#include <stdio.h>
#include "../getnum/getnum.h"

int main(){
    
    int sec;
    sec = getint("Ingrese un tiempo en segundos: ");
    printf("%d segundo/s, %d minuto/s, %d hora/s\n", sec, sec/60, sec/3600);

    return 0;
}
