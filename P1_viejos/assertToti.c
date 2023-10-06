#include <assert.h>
#include <stdio.h>
#include <string.h>

int elimina(char * v);

int main()
{
    char s[] = "abcbc.cba";
    elimina(s);
    assert(strcmp(s,".cba") == 0);
    char t[] = "123456654321";
    elimina(t);
    assert(strcmp(t,"654321") == 0);
    elimina(t);
    assert(strcmp(t,"654321") == 0);
    char u[] = "Abc123aBC";
    assert(strcmp(u,"Abc123aBC") == 0);
    
    puts("OK!");

    return 0;
}
