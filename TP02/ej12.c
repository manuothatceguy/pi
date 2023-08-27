#include <stdio.h>

int main(){
    
    int letra, eval;
    letra = getchar();
    eval = ((letra>='A')&&(letra<='z')) ? 1:0;

    printf("%d\n", eval);

    return 0;
}
