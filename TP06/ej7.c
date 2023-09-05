#include <stdio.h>
#include <stdlib.h>

int unionfunc(int vec1[], int vec2[], int res[], int num){

int i=0, j=0, r=0;

while (vec1[i] != -1 || vec2[j] != -1)
{
    while (vec1[i]==vec1[i+1])
    {
        i++;
    }
    while (vec2[j]==vec2[j+1])
    {
        j++;
    }

    if ((vec1[i] < vec2[j] && vec1[i]!=-1) || vec2[j]==-1)
    {
        res[r++] = vec1[i++];
    }
    else if ((vec1[i]>vec2[j] && vec2[j]!=-1) || vec1[i]==-1)
    {
        res[r++] = vec2[j++];
    }
    else if (vec1[i]==vec2[j])
    {
        res[r++] = vec1[i++];
        j++;
    }
}
res[r]=-1;

return res[num];
}

int main(){

    int v1[4]={2,2,2,-1};

    int v2[6]={2,2,3,3,3,-1};

    int r[7];

    for (int i = 0; i < 6; i++)
    {
        printf("\n%d", unionfunc(v1, v2, r, i));
    }
    putchar('\n');
    return 0;
}