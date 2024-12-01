#include <stdio.h>
#include <assert.h>

// Función que recibe 2 int y devuelve un int.
typedef int (*fn) (int, int);
int operatoria(int v[], size_t dim, int base, fn f);

// Función auxiliar para pasar como parámetro
int producto(int x, int y) {
    return x * y;
}

// Función auxiliar para pasar como parámetro
int suma(int x, int y) {
    return x + y;
}

int
main(void) {
    int v1[] = {2,3,4,5};
    assert(operatoria(v1, 4, 1, producto) == 120);
    assert(operatoria(v1, 4, 0, suma) == 14);
 
    printf("OK!\n");
    return 0;
}

int operatoria(int v[], size_t dim, int base, fn f){
    if(dim == 0)
        return base;
    return operatoria(v+1,dim-1,f(base,*v),f); // Sería recursión de pila. Pensar para la próxima como cola.
}