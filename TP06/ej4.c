#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int eliminaCeros(const int v[], int n, int dest[]){
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != 0)
        {
            dest[j++] = v[i];
        }
        
    }
    
    return j;
}
// Version Jero (ayudante)
int estaRepetido(const int arr[], int pos, int dim){
    for (int i = pos+1; i < dim; i++)
    {
        if (arr[pos] == arr[i])
            return 1;
    }
    return 0;
    
}

int eliminaRepetidos(const int arr[], int dim, int resp[]){
    int j = 0;

    for (int i = 0; i < dim; i++)
    {
        if(!estaRepetido(arr, i, dim))
            resp[j++] = arr[i];
    }
    return j;
    
}



int main()
{
    int vec[] = {2,3,5,4,3,2,3,4,3,2,3,5,6,3,4,3,4,5,6,3,2};
    int array[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int dim = eliminaRepetidos(vec,21,array);
    for (int i = 0; i < dim; i++)
    {
        printf("array[%d] = %d\n",i,array[i]);
    }
    
    


    return 0;
}

