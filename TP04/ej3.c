#include <stdio.h>
#define PI 3.14
#define VOLUMEN(radio) (4/3)*(PI)*(radio)*(radio)*(radio)


int main(){
    printf("Radio\tVolumen\n");
    for (int rad = 1; rad <= 10; rad++){
        printf("%d\t%g\n",rad,VOLUMEN(rad));
    }
    return 0;
}
