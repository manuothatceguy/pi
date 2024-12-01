#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int sumar(long num){
    if(num == 0)
        return 0;
    return num%10 + sumar(num/10);
}

int suma(long num){
    return sumar(labs(num));
}

int main(void) {

  assert(suma(0)==0);
  assert(suma(1)==1);
  assert(suma(12)==3);
  assert(suma(100000)==1);
  assert(suma(123456)==21);
  assert(suma(-123456)==21);
  assert(suma(999999)==54);

  printf ("OK!\n");
  return 0;
}