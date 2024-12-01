#include <stdio.h>
#define DELTA ('a' - 'A')
// RESUELTO POR UN AYUDANTE EN VIDEO, LO ENTENDI.
int main()
{
    int c, countUp = 0, countLow = 0, lowest = 'z', isLowestUp, isCurrentUp;
    while(((c = getchar()) >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '){
        if (c != ' '){
            if (c >= 'A' && c <= 'Z')
            {
                countUp++;
                isCurrentUp = 1;
                c += DELTA;
            }
            else
            {
                countLow++;
                isCurrentUp = 0;
            }
            if (c < lowest)
            {
                lowest = c;
                isLowestUp = isCurrentUp;
            }    
        }
    }
    printf("\nNúmero de mayúsculas: %d\tNúmero de minúsculas: %d\n", countUp, countLow);
    printf("La menor alfabeticamente es %c\n", isLowestUp? lowest - DELTA : lowest);
    return 0;
}
