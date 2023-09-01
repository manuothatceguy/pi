#include <stdio.h>
#include <stdlib.h>

int interseccion(const int vec1[], unsigned int dim1, const int vec2[], unsigned int dim2, int intersect[]){
    int m = 0;
    int encontrado = 0;
    for (int i = 0; (i < dim1); i++)
    {
        for (int j = 0; (j < dim2) && !(encontrado); j++)
        {
            if (vec1[i] == vec2[j])
            {
                intersect[m++] = vec1[i];
                encontrado = 1;
            }
        }
        encontrado = 0;
        
    }
    

   
    return m;
}