#include <stdio.h>
#include <assert.h>

#define MAX 10

#define TRUE 1
#define FALSE !TRUE

void reemplazo(int matriz[][MAX], int dim, int fil, int col){
   if(dim == 0)
      return;
   if(dim == 1){
      matriz[fil][col] = (matriz[fil][col])?FALSE:TRUE;
      return;
   }
   reemplazo(matriz,dim-1,fil,col);


   
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