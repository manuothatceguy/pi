#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int dondeEsta(const int vec[],int dim, int num, int resp[]){
    int j = 0;

    for (int i = 0; (i < dim) && (vec[i] <= num); i++)
    {
        if (vec[i] == num)
            resp[j++] = i;
    }
    return j;
}

