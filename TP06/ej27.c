#include <stdio.h>
#include <assert.h>
#include <string.h>

#define CHARS_DIM 256

int analize(const char * text, char * chars);

int main(void) {
  char chars[CHARS_DIM];
  char chars2[CHARS_DIM];
  analize("El zorro mete la cola, pero no la pata!", chars);
  assert(strcmp(" !,Eacelmnoprtz", chars)==0);
  analize("ababababab", chars2);
  assert(strcmp("ab", chars2)==0);
  
  analize("", chars);
  assert(strcmp("", chars)==0);
  analize(".............................", chars);
  assert(strcmp(".", chars)==0);
  
  puts("OK");
  return 0;
}

void correspAscii(char s[], char t[]){ //Si hay un 1 en el vector de apariciones, copio su ASCII
    int j = 0;
    for (int i = 0; i < CHARS_DIM; i++)
    {
        if(s[i] == 1)
            t[j++] = i;
    }
    
}
void initVec(char v[], int len){
    for (int i = 0; i < len; i++)
    {
        v[i] = 0;
    }
}

int analize(const char * text, char * chars){
    int c;
    char caract[CHARS_DIM] = {0};
    initVec(chars,CHARS_DIM);
    for (int i = 0; text[i] != '\0'; i++)
    {
        c = text[i];
        caract[c] = 1;
    }
    correspAscii(caract,chars);
    return 0;

}