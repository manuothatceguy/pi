//
// ImplementaciÄ‚Ĺ‚n de algunas funciones de string.h
//
#include <assert.h>
#include <stdio.h>
#define MIN(x, y) ( ((x) < (y)) ? (x) : (y) )

int strlen(const char *s) {
    unsigned int len = 0;
    while(*s++)
        len++;
    return len;
}


char * strcpy(char * t, const char * s) {
    int i = 0;
    for (int i = 0; s[i] != 0; i++)
        t[i] = s[i];
    t[i] = 0;
    return t;
}
char * strcpy_punt(char * t, const char * s) {
    char * aux = t;
    while (*t++ = *s++) // versión super acotada, porque la asig. devuelve el valor
        ;

    return aux;
}

char * strncpy(char * t, const char * s, unsigned int n){
    char * aux = t;
    for (int i = 0; i < n; i++)
    {
        if(*s){
            *aux++=*s++;
        }
        else{
            *aux++='\0';
        }
    }
    return t;
}


char * strcat(char * t, const char * s){
    int n = strlen(t);
    strcpy(t+n,s);
    return t;
    
}

int strcmp(const char *t, const char *s){

    while(*t && *s){
        if(*t > *s)
            return 1;
        else if(*t < *s)
            return -1;
        else{
            t++;
            s++;
        }        
    }
    if(*t)
        return 1;
    else if(*s)
        return -1;
    return 0;
}

int strcmp2(const char *t, const char *s){
    while(*t == *s && *t != 0){
        t++;
        s++;
    }
    return *t - *s;
}

char * strncat(char * t, const char * s, int n) {
    char * aux = t;
    t += strlen(t);
    int cont = 0;
    while(*s && cont < n){
        *t++ = *s++;
        cont++;        
    }
    *t = 0;
    return aux;
}


int strncmp(const char * t, const char * s, unsigned int n) {
    int i = 0;
    while(*t == *s && *t != 0 && i<n){ //puede hacer && n y n-- en el if poner if(n==0) sería lo mismo
        t++;
        s++;
        i++;
    }
    if(i==n){ //si saltó el while porque son =
        return 0;
    }
    return *t - *s;


}

char * strchr(const char * s, char c){
    while(*s){
        if(*s == c){
            return (char *)s;
        }
        s++;
    }
    return NULL;
}

char * strchr2(const char * s, char c){
    for (int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == c)
            return s+i;
    }
    return NULL;
    
}

char * strrchr(const char * s, char c){
    char * direc = NULL;
    while(*s){
        if(*s == c){
            direc = (char *)s;
        }
        s++;
    }
    return direc;
}



int main(void) {
    char s[20] = {0};
    char * aux;
    aux = strcpy(s, "Prueba");
    assert(aux == s);
    assert(s[0]=='P');
    assert(s[1]=='r');
    assert(s[2]=='u');
    assert(s[3]=='e');
    assert(s[4]=='b');
    assert(s[6]==0);


    aux = strcpy(s, "");
    assert(aux[0]==0);


    aux = strncpy(s, "123", 10);
    assert(aux==s);
    assert(aux[0]=='1' && aux[1]=='2' && aux[2]=='3' && aux[3]==0 && aux[4]==0 && aux[5]==0);

    aux = strncpy(s, "xyz", 2);
    assert(aux==s);
    assert(aux[0]=='x' && aux[1]=='y' && aux[2]=='3' && aux[3]==0 && aux[4]==0 && aux[5]==0);


    aux = strcat(s, "bien");
    assert(aux==s);
    assert(aux[0]=='x' && aux[1]=='y' && aux[2]=='3' && aux[3]=='b' && aux[4]=='i' && aux[5]=='e');

    strcpy(s, "abcd");
    aux = strncat(s, "xyz", 2);
    assert(aux==s);
    assert(strlen(s)==6);
    assert(s[0]=='a');
    assert(s[3]=='d');
    assert(s[4]=='x');

    s[0]=0;
    strncat(s, "", 2);
    assert(strlen(s)==0);

    strncat(s, "abc", 0);
    assert(strlen(s)==0);

    /* Ejemplo que pisa memoria
    char s2[1];
    strncpy(s2, "1234567888888888888888746784657we65", 12);
    puts(s2);
    puts(s);
     */


    assert(strcmp("","")==0);
    assert(strcmp("ab", "ba")<0);
    assert(strcmp("abc", "abc")==0);
    assert(strcmp("abc", "abcd")<0);
    assert(strcmp("abcd", "abc")>0);
    assert(strcmp("abc", "Abc")>0);
    assert(strcmp("123", "1234")<0);


    assert(strncmp("abc", "abcd", 3) == 0);
    assert(strncmp("abc", "abc", 5) == 0);
    assert(strncmp("abc", "abcd", 5) < 0);
    assert(strncmp("Xbc", "abcd", 0) == 0);

    strcpy(s, "012345601");
    assert(strchr(s, 'x')==NULL);
    assert(strchr(s, '0')==s);
    assert(strchr(s, '1')==s+1);
    assert(strchr(s, '5')==s+5);

    assert(strrchr(s, 'x')==NULL);
    assert(strrchr(s, '0')==s+7);
    assert(strrchr(s, '1')==s+8);
    assert(strrchr(s, '5')==s+5);




    puts("OK!");
    return 0;
}