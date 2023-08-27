int mayorDe3 (int a, int b, int c){
    int mayor = (((a>b)?a:b)>(c))?(a>b?a:b):(c);
    return mayor;
}

#include <assert.h>
#include <stdio.h>

int main()
{
    int a,b,c,m;
    a=1,b=2,c=3;
    m = mayorDe3(a,b,c);
    assert( m == c );
    a=3,b=2,c=1;
    m = mayorDe3(a,b,c);
    assert( m == a );
    a=2,b=3,c=1;
    m = (mayorDe3(a,b,c));
    assert( m == b );
    puts("OK");
    return 0;
}
