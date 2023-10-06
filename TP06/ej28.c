#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5

int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n);
char esVocal(char c);

int main(void) {
  int m[6][CANT_VOCAL];
  char s[] = "las buenas ideas escasean, si";

  assert(elimVocales(s, m, 6)==EXITO);
  assert(strcmp(s, "ls bns ds scsn, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == 23);
  assert(m[5][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  strcpy(s, "las buenas ideas escasean, si");
  assert(elimVocales(s, m, 1)==ERROR);
  assert(strcmp(s, "las buenas ideas escasean, si")==0);
  assert(m[0][0]==-1);
  assert(m[0][1]==-1);
  assert(m[0][2]==-1);
  assert(m[0][3]==-1);
  assert(m[0][4]==-1);

  assert(elimVocales(s, m, 5)==ERROR);
  assert(strcmp(s, "ls bns ds scsan, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  printf("OK!\n");
  return 0;
}

int elimVocales(char * str, int matriz[][CANT_VOCAL], unsigned int n)
{
    int flag = EXITO;
    int vocales[] = {0,0,0,0,0};
    int strpos=0; // Posicion del string
    // Recorro el string y si encuentro vocales las almaceno en la matriz
    for(int j=0; str[j] != '\0' && n>1; j++)
    {
        // Lo agrego en la matriz, usando un switch
        switch ( toupper(str[j]) )
            {
            case 'A':
                flag = asignacion(matriz, str, vocales[0], 0, n, strpos, j);
                (vocales[0])++;
                break;
            case 'E':
                flag = asignacion(matriz, str, vocales[1], 1, n, strpos, j);
                (vocales[1])++;
                break;
            case 'I':
                flag = asignacion(matriz, str, vocales[2], 2, n, strpos, j);
                (vocales[2])++;
                break;
            case 'O':
                flag = asignacion(matriz, str, vocales[3], 3, n, strpos, j);
                (vocales[3])++;
                break;
            case 'U':
                flag = asignacion(matriz, str, vocales[4], 4, n, strpos, j);
                (vocales[4])++;
                break;
            default:
                str[strpos++] = str[j];
                break;
            }
    }

    // Cierro la matriz con -1
    for(int l=0; l<CANT_VOCAL; l++)
    {
        matriz[vocales[l]][l] = -1;
    }

    if( n > 1 )
      str[strpos] = '\0';

    return ( n > 1 ? flag : ERROR );
}


int asignacion(int matriz[][CANT_VOCAL], char * str, int fila, int col, int n, int posNueva, int posOriginal)
{
    int flag = EXITO;
    if( fila < (n-1) )
    {
        matriz[fila][col] = posOriginal; // aca tenia error: matriz[fila][0] --> no cambiaba de col
        fila++;
    } else {
        flag = ERROR;
        str[posNueva++] = str[posOriginal];
    }

    return flag;
}