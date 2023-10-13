#include <stdlib.h>
#include <stdio.h>
#define BLOQUE 10

char * generarSuperVector(){
    char * arr = NULL;
    int dim = 0;
    char c;
    int corte = 0;
    puts("Ingrese caracteres: ");
    do{
        if(dim % BLOQUE == 0){
            arr = realloc(arr, (dim+BLOQUE));
        }
        c = getchar();
        if(c == EOF){
            corte = 1;
        }
        else{
            arr[dim++] = c;
        }
    }while(!corte);
    arr[dim++] = 0;
    puts("");
    
    arr = realloc(arr,dim);
    return arr;
}

int main()
{
    char * superVector = generarSuperVector();
    puts(superVector);
    free(superVector);
    return 0;
}
