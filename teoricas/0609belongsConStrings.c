#include <ctype.h>

int belongs(const char *s, char c){
    c = tolower(c);
    while(*s){
        if(tolower(*s++) == c)
            return 1;
    }
    return 0;
}