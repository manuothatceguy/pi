#include <stdio.h>
#include <assert.h>
#include <string.h>

void deleteChars( char str1[], char str2[] ){
  int i = 0, j = 0, count1 = 0, count2 = 0;
  while( str1[i] || str2[j] ){
    if( str1[i] == str2[j] ){
      i++; j++;
    }
    else{
      if( str1[i] )
        str1[count1++] = str1[i++];
      if( str2[j] )
        str2[count2++] = str2[j++];
    }
  }
  str1[count1] = 0; str2[count2] = 0; // dejo el 0 final
}

int main(void) {

  char s3[] = "abc";
  char s4[] = "axc123456789012345678901234567890";
  deleteChars(s3,s4);
  assert(strcmp(s3, "b")==0);
  assert(strcmp(s4, "x123456789012345678901234567890")==0);

  char s1[] = "Hola, soy un string";
  char s2[] = "Yo soy otro string";

  deleteChars(s1, s2);
  assert(strcmp(s1, "Hla, sy un string")==0);
  assert(strcmp(s2, "Y soy tro string")==0);

  char empty[] = "";
  deleteChars(s1, empty);
  assert(strcmp(s1, "Hla, sy un string")==0);
  assert(strcmp(empty, "")==0);

  strcpy(s1, "ABCDE");
  strcpy(s2, "abcde");
  deleteChars(s1, s2);
  assert(strcmp(s1, "ABCDE")==0);
  assert(strcmp(s2, "abcde")==0);

    deleteChars(s1,s1);
    assert(strcmp(s1, "")==0);

  char s5[] = "abc";
  char s6[] = "axc123456789012345678901234567890";
  deleteChars(s5,s6);
  assert(strcmp(s5, "b")==0);
  assert(strcmp(s6, "x123456789012345678901234567890")==0);


  puts("OK!");
  return 0;
}

