#include <stdio.h>
#include <assert.h>
#include <string.h>

void
eliminaBlancos (char cadena[]);

int main(void) {
  char s[60] = "   "; // cant impar de blancos
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  strcpy(s,"  ");
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);
  
  strcpy(s," . . .  ");
  eliminaBlancos(s);
  assert(strcmp(s, " . . . ")==0);

  strcpy(s,"");
  eliminaBlancos(s);
  assert(strcmp(s, "")==0);

  strcpy(s,"sinblancos");
  eliminaBlancos(s);
  assert(strcmp(s, "sinblancos")==0);



  printf("OK!\n");
  return 0;
}

void eliminaBlancos (char cadena[]){
    char found = 0;
    int j = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] != ' '){
            found = 0;
            cadena[j++] = cadena[i];
        }
        else if(cadena[i] == ' ' && !found){
            found = 1;
            cadena[j++] = cadena[i];
        }
    }
    cadena[j] = '\0';
    return;
}