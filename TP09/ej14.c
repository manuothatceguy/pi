#include <stdio.h>
#include <assert.h>

int apareados(const char *texto){
    if(*texto == '\0')
        return 0;
    if(*texto == '('){
        int ret = apareados(texto+1);
        if(ret != 0){
            return ret;
        }
        return 1+ret;
    }
    
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