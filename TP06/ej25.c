#include <stdio.h>
#include <assert.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

unsigned int copiaSubVector(const char * arregloIn, char * arregloOut, unsigned int desde, unsigned int hasta, unsigned int dimMax);

int main(void) {
  char s[100];

  assert(copiaSubVector("un texto", s,0,0,1)==0);
  assert(strcmp(s, "")==0);

  assert(copiaSubVector("un texto", s,0,0,10)==1);
  assert(strcmp(s, "u")==0);

  assert(copiaSubVector("un texto", s,0,10,1)==0);
  assert(strcmp(s, "")==0);

  assert(copiaSubVector("un texto", s,45,130,1)==0);

  assert(copiaSubVector("un texto", s,0,130,2)==1);
  assert(strcmp(s, "u")==0);

  assert(copiaSubVector("un texto", s,0,130,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,0,7,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,0,7,9)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,2,5,8)==4);
  assert(strcmp(s, " tex")==0);
  
  assert(copiaSubVector("un texto", s,45000,130000,10)==0);

  printf("OK!\n");
  return 0;
}

unsigned int copiaSubVector(const char * arregloIn, char * arregloOut, unsigned int desde, unsigned int hasta, unsigned int dimMax){
    int stop = FALSE, ValRet = 0;
    if(desde > dimMax-1 || desde > hasta || dimMax == 1){
        arregloOut[0] = '\0';
        return 0;
    }
        
    else if(hasta - desde > dimMax && dimMax > 1)
        stop = TRUE;

    switch (stop)
    {
    case 0:
        for (int i = desde, j = 0; i < hasta+1 && arregloIn[i] != '\0';)
        {
            arregloOut[j++] = arregloIn[i++];
            ValRet = j;
        }
        break;
    case 1:
        for (int i = desde, j = 0; i < dimMax-1 && arregloIn[i] != '\0';)
        {
            arregloOut[j++] = arregloIn[i++];
            ValRet = j;
        }
        break;
    }
    arregloOut[ValRet] = '\0';
    return ValRet;
}