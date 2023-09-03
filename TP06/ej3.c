#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int mayorDiferencia(const int vec[]){
    int max = 0;
    for (int i = 0; vec[i+1] != 0; i++)
        max = (max > (vec[i] - vec[i+1])?max:(vec[i] - vec[i+1]));
    return max;
}