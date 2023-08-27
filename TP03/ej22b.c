#include <stdio.h>

int main()
{
    int c;

    while((c = getchar()) != '\n'){
        if (c == '\t'){
            printf("\\t");
        }
        else if (c == '\b'){
            printf("\\b");
        }
        else if(c == 92){
            printf("\\");
        }
        else{
            printf("%c",c);
        }   
    }
    return 0;
}
