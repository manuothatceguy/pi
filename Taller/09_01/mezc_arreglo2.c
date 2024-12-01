#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../../random/random.h"
#include <time.h>
//sin dos ciclos, voy haciendo random con el indice que se incrementa.
// vers de octa
void mezcArr(int arr[]){
    int aux, idx;
    int i = 0;
    while(arr[i] != -1)
    {
        idx = randInt(0, i);
        aux = arr[idx];
        arr[idx] = arr[i];
        arr[i++] = aux; //el i++ es para pasar al sig
    }
}

//con dos ciclos
void mezclarArreglo2(int array[]){
    int aux,pos,aux2,dim = 0;
    
    for (int i = 0; array[i] != -1;dim++, i++);

    for (int i = 0; i < dim; i++)
    {
        pos = randInt(0,dim-1);
        aux = array[pos];
        aux2 = array[i];
        array[i] = aux; 
        array[pos] = aux2;
    }

}