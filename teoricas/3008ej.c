int eliminaCeros(const int v[], int n, int dest[]){
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != 0)
        {
            dest[j++] = v[i];
        }
        
    }
    
    return j;
}