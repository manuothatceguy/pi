#include <stdlib.h>
#include <stdio.h>

int eliminaRepetidos(const int v[], int dim, int resp[])
{
    int j = 0,m;
    for (int i = 0; i < dim;)
    {   
        resp[j++] = v[i];
        m = i;
        while(v[m] == v[i])
            i++;
    }
    j = j - 1; //Para cortar, porque el j++ de arriba es como para seguir iterando, y tengo uno de más porque espera que siga el vector
    return j;
}

int main()
{
    int vec[] = {1,1,1,1,1,1,2,3,3,4,5,6,7,7,7,8,8};
    int dest[18] = {0};
    int dim = eliminaRepetidos(vec,18,dest);
    for (int i = 0; i < dim; i++)
    {
        printf("dest[%d] = %d\n",i,dest[i]);
    }
    
    return 0;
}
