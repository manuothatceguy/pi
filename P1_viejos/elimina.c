#include <stdio.h>
#include <assert.h>
#include <string.h>

void elimina(char * s1, char * s2, char * s3){
    int i = 0, j = 0, fin2 = 0, fin3 = 0, i2 = 0, i3 = 0;    
    while(s1[i] != '\0'){
        fin2 = (s2[i2] == 0);
        fin3 = (s3[i3] == 0);    
        if(!fin2 && s1[i] == s2[i2]){
            i++;       
        }

        else if(!fin3 && s1[i] == s3[i3]){
            i++;
        }
            
        else{
            s1[j++] = s1[i++];
        }
        i2 += (!fin2);
        i3 += (!fin3);
    }
    s1[j] = 0;
}


int
main(){
    char s1[] = "holaMundo";
    char * s2 = "BuenMartes";
    char * s3 = "hilo";
    elimina(s1,s2,s3);
    assert(strcmp(s1,"oaundo") == 0);

    char s4[] = "Graciela";
    char * s5 = "Beatriz";
    char * s6 = "Grande";
    elimina(s4,s5,s6);
    assert(strcmp(s4,"cila") == 0);
    printf("OK\n");

    return 0;
}