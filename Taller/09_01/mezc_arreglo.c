#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../../random/random.h"
#include <time.h>



void mezclarArreglo(int array[], unsigned int dim){
    int aux,pos;
    
    randomize();
    for (int i = 0; i < dim; i++)
    {
        pos = randInt(0,dim-1);
        aux = array[i];
        array[i] = array[pos];
        array[pos] = aux;
    }
}

int main()
{
    int dim;

    int vec[5] = {0,1,2,3,4};
    dim = sizeof(vec)/sizeof(vec[0]);
    randomize();
    mezclarArreglo(vec,dim);

    for (int i = 0; i < dim; i++)
    {
        printf("vec[%d] = %d\n",i,vec[i]);
    }

    return 0;
}
