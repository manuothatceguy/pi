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
//obtener una línea como string de la entrada estándar, con tope en max. lo pone en v[] retorno longitud
int getline(char v[], size_t max){
    int c, i = 0;
    while((c = getchar()) != '\n' && c != EOF){
        if(i < max){
            v[i++] = c;
        }
    }
    v[i] = 0;
    return i; //devuelo la longitud sin incluir el 0, igual que strlen
}

char * getline(){
    int c;
    int dim = 1;
    int i = 0;
    char * v = malloc(dim+1);
    while((c = getchar()) != '\n' && (c != EOF)){
        if(i < dim){
            v[i++] = c;
        }
        if(i == dim){
            dim++;
            v = realloc(v,dim);
        }
    }
    v[i] = 0;
    return v;
}

