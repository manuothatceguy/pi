// Vectores
int num_aparece(const int v[], int n, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        if(v[i] == n)
            return 1;
    }
    return 0;
}
// Notación de punteros
int aparece_num(const int v[], int n, int dim)
{
    int *p = v;
    int existe = 0, fin = 0;
    while (!existe || !fin)
    {
        if (p == v+dim)
            fin = 1;
        else if (*p++ == n)
        {    
            existe = 1;
            return 1;
        }
    }
    return 0;
}