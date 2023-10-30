#include <stdio.h>
#include <assert.h>

int apareados(const char *texto){
    if(*texto == '\0')
        return 0;
    int aux = apareados(texto+1);
    if(aux > 0)
        return aux;
    if(*texto == ')')
        aux -= 1;
    else
        aux += 1;
    return aux;
    
}

int main(void) {

  assert(apareados("")==0);
  assert(apareados("()")==0);
  assert(apareados("(())()(()())")==0);
  assert(apareados("((((()))))")==0);

  assert(apareados("(")!=0);
  assert(apareados(")")!=0);
  assert(apareados("(")!=0);
  assert(apareados("())")!=0);
  assert(apareados("()(")!=0);
  assert(apareados("((()))())(")!=0);
  
  printf ("OK!\n");
  return 0;
}