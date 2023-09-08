#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

int contiene(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2);

int main(void) {

  int v1[] = {1,6,5,3,2};
  int v2[] = {1,2};
  assert(contiene(v1, 5, v2, 2)==2);
  assert(contiene(v2, 2, v1, 5)==1);
  assert(contiene(v1, 1, v2, 2)==1);
  assert(contiene(v1, 0, v2, 2)==1);
  assert(contiene(v1, 5, v2, 0)==2);
  
  int v3[] = {1,2,3,4,5,6};
  assert(contiene(v1, 5, v3, 6)==1);

  int cnt = contiene(v1, 0, v3, 0);
  assert(cnt ==1 || cnt==2);

  int v4[] = { 10, 20, 30, 1, 2};
  assert(contiene(v2, 2, v4, 4)==0);
  assert(contiene(v2, 2, v4, 5)==1);
  assert(contiene(v4, 5, v2, 2)==2);

  int v5[] = {1,1,1,1,1,2,1,2};
  int v6[] = {1,2,3};
  assert(contiene(v5, 8, v6, 3)==1);
  assert(contiene(v6, 3, v5, 8 )==2);

  printf("OK!\n");
  return 0;
}

int contiene(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2){
    if(!dim1)
        return 1;
    else if(!dim2)
        return 2;
    // Si ninguno es vacío
    int iguales = 0;
    if(dim1 > dim2)
    {
        for (int i = 0; i < dim1; i++)
        {
            for (int j = 0; j < dim2; j++)
            {
                if(v1[i] == v2[j])
                    iguales++;
            }
        }
        if(iguales==dim2)
            return 2;

        for (int i = 0; i < dim2; i++)
        {
            for (int j = 0; j < dim1; j++)
            {
                if(v2[i] == v1[j])
                    iguales++;
            }
        }
        // REPLANTEAR ESTE EJERCICIO
        return iguales==dim2;
    }
    else
    {
        for (int i = 0; i < dim2; i++)
        {
            for (int j = 0; j < dim1; j++)
            {
                if(v2[i] == v1[j])
                    iguales++;
            }
        }
        return (iguales==dim1);
    }
}

