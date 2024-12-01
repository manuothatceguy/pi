#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "ej10.h"

void invierte(char * src, char * dest){
    if(*src == '\0')
        return;
    
    if(strlen(src) == 1)
        *dest = *src;
    else
    {
        invierte(src+1,dest);
        int i = 0;
        for(; *(dest + i) != '\0'; i++);
        dest[i] = *src;
    }
    

}

int main(void) {
	// Comentario agregado con VIM!
  char s[20] = {0};

  invierte("1234567890", s);
  assert(strcmp(s, "0987654321")==0);

  memset(s, 0, 20);
  invierte("", s);
  assert(strcmp(s, "")==0);

  memset(s, 0, 20);
  invierte("a", s);
  assert(strcmp(s, "a")==0);

  memset(s, 0, 20);
  invierte("ab", s);
  assert(strcmp(s, "ba")==0);
  
  memset(s, 0, 20);
  invierte("abc", s);
  assert(strcmp(s, "cba")==0);

  printf ("OK!\n");
  return 0;
}
