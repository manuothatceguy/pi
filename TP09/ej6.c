#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


int capicuaRecursiva(const char * s, int dim){
    if(dim <= 1)
        return 1;
    if(s[0] != s[dim-1])
        return 0;
    return capicuaRecursiva(s+1,dim-2); // dim-2 porque saco las 2 puntas!!
}

int palindromo(const char *s) {
    return capicuaRecursiva(s,strlen(s));
}


int main(void) {

    assert(palindromo("a")==1);
    assert(palindromo("")==1);
    assert(palindromo("neuquen")==1);
    assert(palindromo("abba")==1);
    assert(palindromo("12345654321")==1);

    assert(palindromo("abab")==0);
    assert(palindromo("123456")==0);
    

    printf ("OK!\n");
  return 0;
}