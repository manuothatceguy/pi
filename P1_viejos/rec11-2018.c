#include <stdio.h>
void imprimeFila(int mat[3][4], unsigned int fila) {
    for(int i=0; i < 4 ; i++)
    printf("%d ", mat[fila][i]);
    putchar('\n');
}
//hola 
int
main(void) {
int m[][3] ={ {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12},
    {13,14,15}, {16}, {17}, {18,19} };
    imprimeFila(m, 0);
    imprimeFila(m, 2);
    imprimeFila(m, 4);
    return 0;
}