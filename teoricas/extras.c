#include <stdio.h>
#include <stdlib.h>

int removeBlanks(char * s){ //Saco los espacios de un string y devuelvo la cant. de espacios q saqué
    int j = 0,i;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] != ' ')
            s[j++] = s[i];
    }
    s[j] = '\0'; //hay que dejar un string -> copiar el cero final
    return (i-j);
}

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