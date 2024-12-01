#include <stdio.h>
#include <assert.h>

#define COLS 4

int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 );
// Devuelve true si m1 es amiga de m2 y no revisa lo contrario.
int esAmiga(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 );
// Devuelve true si v es amigo de alguna fila de m
int vecEnMatriz(const int v[], const int m[][COLS], int fils);
// Devuelve true si v1 está contenido en v2
int contiene(const int v1[], const int v2[], int dim);

int 
main(void)
{
  int m1[][COLS] = {{0,1,2,3}, {4,4,5,6}, {7,8,8,9}};
  int m2[][COLS] = {{0,1,2,3}, {-3,7,8,9}, {-1,3,4,7}, {4,5,6,8}};
  int m3[][COLS] = {{2,3,3,7}};
  assert(sonAmigas(m1,3,m2,4)==1);
  assert(sonAmigas(m1,1,m2,4)==1);
  assert(sonAmigas(m1,2,m2,4)==1);
  assert(sonAmigas(m1,2,m2,2)==0);
  assert(sonAmigas(m2,4,m1,3)==2);
  assert(sonAmigas(m1,3,m3,1)==0);
  assert(sonAmigas(m3,1,m1,3)==0);
  int res = sonAmigas(m1,3,m1,3);
  assert(res==1 || res==2);
  
  printf("OK !\n");

  return 0;
}
/*int 
main(void)
{
  int m1[][COLS] = {{0,1,2,3}, {4,4,5,6}, {7,8,8,9}};
  int m2[][COLS] = {{0,1,2,3}, {-3,7,8,9}, {-1,3,4,7}, {4,5,6,8}};
  int m3[][COLS] = {{2,3,3,7}};
  printf("%d\n", sonAmigas(m1,3,m2,4)); // Imprime 1                 
  printf("%d\n", sonAmigas(m2,4,m1,3)); // Imprime 2 __
  printf("%d\n", sonAmigas(m1,3,m3,1)); // Imprime 0  __


  return 0;
}*/


//Esta función contiene funciona, pero no aprovecha que el anterior es menor o igual al siguiente
/*int contiene(const int v1[], const int v2[], int dim){
    for (int i = 0; i < dim; i++)
    {
        int found = 0;
        for (int j = 0; j < dim && !found; j++)
        {
            if(v1[i] == v2[j])
                found = 1;
        }
        if(!found)
            return 0;
    }
    return 1;
}*/


int contiene(const int v1[], const int v2[], int dim){
    int i = 0, j = 0;
    while (i < dim && j < dim)
    {
        if(v1[i] < v2[j])
            return 0;
        else if(v1[i] == v2[j])
            i++;
        else
            j++;
    }
    return (i == dim);
}

int vecEnMatriz(const int v[], const int m[][COLS], int fils){
    for (int i = 0; i < fils; i++)
    {
        if(contiene(v,m[i],COLS))
            return 1;
    }
    return 0;
    
}



int esAmiga(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 ){
    for (int i = 0; i < fils1; i++){
        if(!vecEnMatriz(m1[i],m2,fils2)) {
            return 0;
        }
    }
    return 1;
}


int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 ){
    if(esAmiga(m1,fils1,m2,fils2)){
        return 1;
    }
    if(esAmiga(m2,fils2,m1,fils1)){
        return 2;
    }
    return 0;
}
