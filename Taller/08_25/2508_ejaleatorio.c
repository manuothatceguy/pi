#include <stdio.h>
#include "../../random/random.h"
#define DELTA ('a' - 'A')

int cuentaLetra(int letra, int num){
    int contLetra = 0,l;
    for(int cont = 0; (cont < num)&&(l != EOF); cont++){
        l = getchar();
        if ((l == letra) || (l == letra + DELTA)){
            contLetra++;
        }
    }
    return contLetra;
}

int main()
{
    randomize();
    int letra = randInt('A','Z');
    int num = randInt(1,256);
    printf("\nEl valor de N es: %d\nEl valor de la letra es: %c\n%d\n",num,letra,cuentaLetra(letra, num)); 
    return 0;
}
