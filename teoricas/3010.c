#include <stdio.h>
#include <stdlib.h>
#define BLOCK 10


// La función subset recibe un puntero a función con el criterio para agregar!
// Lo molesto de esto es tener que escribir cada uno de los criterios.

// Ejemplo de comentarios con tags para una función. Hacerlo en el .h !!!

/*
*   @brief Función que recibe vector de ingreso y su dimensión, retorna en su nombre un vector que cumple con el criterio recibido como función, además de modificar el parámetro de e/s de la dimensión.
*   @param v vector de enteros 
*   @param dim dimensión del vector v
*   @param n nueva dimension del vector de retorno
*   @param criteria función a evaluar
*   @return vector de int con el subconjunto deseado
*/
int * subSet(const int * v, size_t dim, size_t * n, int (*criteria)(int)){
    int * ans = NULL;
    *n = 0;
    for(size_t i = 0; i < dim; i++){
        if(criteria(v[i])){ // No hace falta usar el * !!! ojo!!! solo en funcptr !!!
            if(*n % BLOCK == 0){
                ans = realloc(ans,(*n+BLOCK)*sizeof(ans[0]));
            }
            ans[*n++] = v[i];
        }
    }
    ans = realloc(ans,*n * sizeof(int));

    return ans;
}