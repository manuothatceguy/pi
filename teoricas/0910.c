#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK 100

char *getlineNoLimit()
{
    char *ans = NULL;
    char c;
    int i = 0;
    while ((c = getchar() != '\n') && c != EOF)
    {
        if (i % BLOCK == 0)
        { // En el TP hay que revisar que no se quede sin espacio, en la cursada no.
            ans = realloc(ans, i + BLOCK);
        }
        ans[i++] = c;
    }
    ans = realloc(ans, i + 1); // Programación defensiva, reservo por si no ingresó NADA el usr
    ans[i] = 0;

    return ans;
}

int *interseccion(const int *v1, const int *v2, size_t dim1, size_t dim2, size_t *dim)
{
    int *ans = NULL;
    int i, j;
    *dim = 0;
    for (i = j = 0; i < dim1 && j < dim2;)
    {
        if (v1[i] == v2[j])
        {
            if (*dim % BLOCK == 0)
            {
                ans = realloc(ans, (*dim + BLOCK) * sizeof(int)); // Lo llamo adentro para no llamar de más
            }

            ans[(*dim)++] = v1[i++];
            j++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    ans = realloc(ans, *dim * sizeof(int));
    return ans;
}

void copiarVec(const int *vSrc, int dimSrc, int *resp, int idx_start)
{
    for (int i = 0; i < dimSrc; i++)
    {
        resp[i + idx_start] = vSrc[i];
    }
    return;
}

int *concatenar(const int *v1, const int *v2, size_t dim1, size_t dim2, size_t *dim)
{
    *dim = dim1 + dim2;

    int *ans = malloc((*dim) * sizeof(int));

    copiarVec(v1, dim1, ans, 0);
    copiarVec(v2, dim2, ans, dim1);
    return ans;
}

int main()
{
    int v[] = {-1, 3, 5, 8, 10, 20, 200};
    int w[] = {-3, -1, 5, 6, 7, 8};
    size_t dimV = sizeof(v) / sizeof(v[0]);
    size_t dimW = sizeof(w) / sizeof(w[0]);
    int *resp;
    size_t dimResp;
    resp = concatenar(v, w, dimV, dimW, &dimResp);

    for (int i = 0; i < dimResp; i++)
    {
        printf("%d ", resp[i]);
    }
    free(resp);
    return 0;
}