#include <stdio.h>

// EJERCICIO A

void palotes(unsigned int cant){
    if(cant == 1)
        puts("|");
    else
        palotes(cant-1);
}

// EJERCICIO B

int strlenRecursivo(char * v){
    if(*v == '\0')
        return 0;
    return 1 + strlenRecursivo(v+1);
}

// EJERCICIO C

char * strchrRecursivo(char * s, char c){
    if(*s == '\0')
        return NULL;
    else if (*s == c)
        return s;
    return strchrRecursivo(s+1,c);
}