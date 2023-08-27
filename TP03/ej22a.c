#include <stdio.h>

int main()
{
    int c, isBlank = 0;
    while ((c = getchar()) != '\n'){
        if (c == ' '){
            isBlank += 1;
        }
        else if (c != ' '){
            printf("%s",isBlank?" ":"");
            isBlank = 0;
        }
        if (!(isBlank)){
            printf("%c",c);
        }
    }
    printf("\n");
    
    
    return 0;
}
