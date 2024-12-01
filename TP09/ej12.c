#include <stdio.h>
#include <assert.h>

int balance(const char *texto){
    if(*texto == '\0')
        return 0;
    if(*texto == '(')
        return (1 + balance(texto + 1));
    if(*texto == ')')
        return (-1 + balance(texto + 1));

    return balance(texto+1);
}


int main(void) {

  assert(balance("")==0);
  assert(balance("((()))")==0);
  assert(balance(")(")==0);
  assert(balance("()()")==0);
  assert(balance(")))(((")==0);
  assert(balance("))) ((( ))( ()() ()()(")==0);
  
  assert(balance(")")!=0);
  assert(balance("(")!=0);
  assert(balance(")()")!=0);
  assert(balance(" ) ")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

  printf ("OK!\n");
  return 0;
}