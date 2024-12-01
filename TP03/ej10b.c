#include <stdio.h>

int main(){
    float y;
    for(y = .1; y != 1; y += .1)
        printf("%f\n",y);
    return 0;
}