#include <stdio.h>
#include <string.h>
#include <assert.h>

char *max(char *a, char *b) {
    return a > b ? a : b;
}

char * strrchrRec(char *s, char c){
    if(*s == '\0')
        return NULL;
    if(*s == c){
        return max(strrchrRec(s+1,c),s);
    }
        
    return strrchrRec(s+1,c);
}

int
main(void) {
	char * s = "vamos a buscar";

	for ( int i=0; s[i]; i++) {
		assert(strrchr(s, s[i]) == strrchrRec(s, s[i]));
	} 

	puts("OK!");
}