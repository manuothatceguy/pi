#define DIM 50
#include <stdio.h>
#include <stdlib.h>

int readArray(float v[]){
    int cant;
    do
    {
        cant = getint("Ingrese la cantidad de elementos: ");
    } while ((cant <= DIM) && (cant > 0));
    
    float num;
    for (int i = 0; i < cant; i++)
    {
        do
        {
            num = getfloat("Ingrese un float positivo: ");
        } while (num <= 0);
        
        v[i] = num;
        
    }
    return cant;
}

int main()
{
    float v[DIM] = {0};
    int cant = readArray(v);
    for (int i = 0; i < cant; i++)
    {
        printf("[%d] = %.1f",i,v[i]);
    }
    return 0;
}
