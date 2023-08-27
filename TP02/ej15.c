#include <stdio.h>

int main(){
    
    char letra;

    letra = getchar();

    printf("\n%c\n", letra<='Z' ? letra:letra+('A'-'a'));

    return 0;
}
