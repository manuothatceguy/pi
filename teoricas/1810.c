#include <stdio.h>
#include <stdlib.h>

// EJERCICIOS

/*MCD con algoritmo de euclides, lo hicimos ayer*/
int mcd(int n1, int n2){
    if(n2 == 0)
        return n1;
    return mcd(n2,n1 % n2);
}
/// @param num  Numero entero
/*Imprime un número en binario!, recursión de pila!!!*/
void whatIs(int num){
    if( num >= 2){
        whatIs(num / 2);
        putchar(num%2 + '0');
    }
    else
        putchar(num + '0');
}

/*Número combinatorio!*/


#define BLOCK 10
/*Imprimir al revés*/
void alresve(){
    int c, i = 0;
    char * s = NULL;

    while((c = getchar())!= EOF){
        if(i % BLOCK == 0)
            s = realloc(s,i+BLOCK);

        s[i++] = c;
    }
    // j = i-1 porque incrementamos de más!
    for(int j = i-1; j >= 0; j--){
        putchar(s[j]);
    }
    free(s);
}

// Todos los algoritmos se pueden pasar! Sean de cola o de pila, algunos obviamente son más fáciles que otros...

/* ver si un vector es vacío */
int
isNull(const int v[], size_t dim){
    if(dim == 0)
        return 1;
    else if(*v == 0)
        return isNull(v+1,dim-1);
    else
        return 0;
}

/*Ver si un vector es vacío, versión mejorada*/
int
isNull(const int v[], size_t dim){
    if(dim == 0)
        return 1;
    
    return (v[0] == 0 && isNull(v+1,dim-1));
}

#define IS_VOWEL(c) (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')

/*Devolver cantidad de vocales*/
int cuentaVocales(char * s){
    if(*s == '\0')
        return 0;
    return IS_VOWEL(*s) + cuentaVocales(s+1);
}