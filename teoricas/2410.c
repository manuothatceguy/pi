#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int capicuaRecursiva(const char * s, int dim){
    if(dim <= 1)
        return 1;
    if(s[0] != s[dim-1])
        return 0;
    return capicuaRecursiva(s+1,dim-2); // dim-2 porque saco las 2 puntas!!
}

int palindromo(const char *s) {
    return capicuaRecursiva(s,strlen(s));
}

void regla(int h){
    if(h == 0){
        return;
    }
    if(h == 1){
        printf(" %d ",h);
    }
    else{ // La parte difícil es pensar en forma recursiva, este ej te obliga a pensar en forma recursiva.
        // pensar como caso base de induccion. 
        regla(h/2);
        printf(" %d ",h);
        regla(h/2);
    }
}

int branches(int h, int min){
    if(h < min)
        return 0;
    return 1 + 2*(branches(h/2,min));
}

void factorial(int n, int * resp){ // Primero la llamada desp la accion --> recursion de pila!
    if(n <= 1)
        *resp = 1;
    
    else{
        factorial(n-1,resp);
        *resp *= n;
    }
}

int cociente(int dividendo, int divisor, int * resto){
    if(divisor > dividendo){
        *resto = dividendo;
        return 0;
    }
    return 1 + cociente(dividendo-divisor,divisor,resto);
}

void sumatoria(int vec[], int dim, int * suma){
    if(dim == 0)
        return;
    if(dim == 1)
        *suma = vec[0];
    else
    {
        sumatoria(vec+1,dim-1,suma);
        *suma += vec[0];
    }
    
}

void branchesVoid(float h, float min, int * br){
    if(h < min)
        *br = 0;
    else{
        branchesVoid(h/2,min,br);
        *br = 1 + 2*(*br);
    }
        
}

// Hay mas en un ppt, revisarlo y hacer los ejercicios!

int main(){
    // regla(5);
    // puts("");

    //printf("%d\n",branches(6,5));

    // int resp;
    // factorial(4,&resp);
    // printf("%d ",resp);

    // int res,div;
    // div = cociente(12,8,&res);
    // printf("cociente: %d, resto: %d",div,res);

    // int vec[] = {9,3,2,3},suma;
    // sumatoria(vec,4,&suma);
    // printf("Sumatoria: %d\n",suma);

    // int n;
    // branchesVoid(7,1,&n);
    // printf("Cantidad de ramas: %d = %d\n",n,branches(7,1));
    
    

    
    return 0;
}