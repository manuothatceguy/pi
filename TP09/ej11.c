#include <stdio.h>
#include <assert.h>

#define MAX 10

#define TRUE 1
#define FALSE !TRUE

void reemplazoRec(int matriz[][MAX], int dirF, int dirC, int fil, int col, int dim){
   int i = fil + dirF;
   int j = col + dirC;
   if(i >= 0 && i < dim && j >= 0 && j < dim){
      matriz[i][j] = matriz[i][j] ? FALSE:TRUE;
      reemplazoRec(matriz,dirF,dirC,i,j,dim);
   }
   else
   {
      return;
   }
   
}

void reemplazo(int matriz[][MAX], int dim, int fil, int col){

   reemplazoRec(matriz,-1,-1,fil,col,dim);
   reemplazoRec(matriz,-1,1,fil,col,dim);
   reemplazoRec(matriz,1,-1,fil,col,dim);
   reemplazoRec(matriz,1,1,fil,col,dim);

   matriz[fil][col] = matriz[fil][col] ? FALSE:TRUE;
   
   return;
}

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  reemplazo(m, 5, 1, 2);
  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}