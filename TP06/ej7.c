void union_de_arreglos(int v1[], int v2[], int union_resultado[]) {
    int i = 0, j = 0, k = 0, valorAnt = -1, valorAct;

    while (v1[i] != -1 || v2[j] != -1) {
        if ( v1[i] < v2[j] )
            valorAct = v1[i++];
        else
            valorAct = v2[j++];
        if ( valorAct != valorAnt)
            {
                union_resultado[k++] = valorAct;
                valorAnt = valorAct;
            }
    }
    union_resultado[k] = -1;
}