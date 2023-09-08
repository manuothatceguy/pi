#include <stdio.h>
#include <assert.h>

#define ALTO 6
#define ANCHO 5
#define MAX(x, y) ( ((x) > (y)) ? (x) : (y) )
#define MIN(x, y) ( ((x) < (y)) ? (x) : (y) )

void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w );

int equals(unsigned int cols, unsigned char m1[][cols], unsigned char m2[][cols], unsigned int rows) {
  for (int i=0; i < rows; i++) {
     for(int j=0; j < cols; j++) {
         if ( m1[i][j] != m2[i][j]) {
            return 0;
         }
     }
  }
  return 1;  
}

int main(void) {
  unsigned char bmp[ALTO][ANCHO] =    {
      {10,10,20,23,24},
      {10,12,18,25,23},
      {12,14,18,26,22},
      {12,14,19,20,22},
      {13,16,19,20,22},
      {14,14,19,21,23}};
 
  
  suavizar(bmp, 3);
  unsigned char suave[ALTO][ANCHO] =    {
      {10,13,18,22,23},
      {11,13,18,22,23},
      {12,14,18,21,23},
      {13,15,18,20,22},
      {13,15,18,20,21},
      {14,15,18,20,21}};

  assert(equals(ANCHO, bmp, suave, ALTO));

  // Ahora una con w=5
  unsigned char suave5[ALTO][ANCHO] =    {
	{14,16,17,19,20},
	{14,16,17,18,20},
	{14,16,17,18,20},
	{15,16,17,18,20},
	{15,16,17,18,20},
	{15,16,17,18,19}};

   suavizar(bmp, 5);
   assert(equals(ANCHO, bmp, suave5, ALTO));

  puts("OK!");
  return 0;
}

int valid(int i, int j){
    return (i >= 0 && j >= 0);
}

int promedio(unsigned char m[ALTO][ANCHO], int fil, int col, int w){
    w = w/2;
    int suma = 0, cant = 0;
    for (int i = MAX(0, fil - w); i <= MIN(ALTO - 1, fil + w); i++)
    {
        for (int j = MAX(0, col - w); j <= MIN(ANCHO - 1, col + w); j++)
        {
            suma += m[i][j];
            cant++;
        }
    }
    return suma/cant;
}



void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w ){
    if(w < 3 || w % 2 == 0)
        return;
    unsigned char aux[ALTO][ANCHO];

    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++)
        {
            aux[i][j] = promedio(imagen,i,j,w);
        }
    }
    
    for (int i = 0; i < ALTO; i++)
    {
        for (int j = 0; j < ANCHO; j++){
            imagen[i][j] = aux[i][j];
        }
    }
    return;
}