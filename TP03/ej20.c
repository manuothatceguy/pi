#include <stdio.h>

int factorialOfNumber(int number){
    int factorial = 1;
    for(;number!=0;number--){
        if(number < 0){
            return -1;
        }
        factorial *= number;
    }
    return factorial;
}

int main()
{
    int count = 0;
    double e = 0;
    printf("N\te\n");
    for(count=0;1;count++){
        e += 1.0/(factorialOfNumber(count));
        if(e + 1.0/(factorialOfNumber(count)) == e){
            break;
        }
        else{
            printf("%d\t%g\n",count,e);
        }
        
    }
    
    return 0;
}
