#include <stdio.h>
#include <assert.h>
 
int esPrimo(int);
 
int
main(void) {
    assert(!esPrimo(0)); // 0 no es primo (no es natural)
    assert(!esPrimo(1)); // 1 no es primo
    assert(esPrimo(2)); // 2 es primo
    assert(esPrimo(3));
    assert(!esPrimo(4));
    assert(esPrimo(5));
    assert(!esPrimo(6)); // Equivalente a assert(esPrimo(6) == 0)
    assert(esPrimo(7)); // Equivalente a assert(esPrimo(7) == 1)
    printf("OK!\n");
    return 0;
}
 