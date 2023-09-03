// Arreglo ordenado, mezclarlo.
#include "../random/random.h"

void mezclarArray(int arr[], int dim)
{
    int aux, pos;
    for (int i = 0; i < dim; i++)
    {
        pos = randInt(0,dim-1);
        aux = arr[i];
        arr[i] = arr[pos];
        arr[pos] = aux;
    }
}