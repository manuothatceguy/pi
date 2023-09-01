

int inter(const int v1[], const int v2[], int dim1, int dim2, int res[]){
    int DimRes = 0;
    for (int i = 0; i < dim1 ; i++){
        int Nencon = 0
        for (int j = 0; j < dim2 && Nencon == 0 ; j++){
            if( v1[i] == v2[j]){
                Nencon = 1;
                res[DimRes] = v1[i];
                DimRes++;
            }
        }
    }
    return DimRes;
}

int inter2(const int v1[], const int v2[], int dim1, int dim2, int res[]){
    int DimRes = 0;
    int i, j;
    for ( i = 0, j = 0 ; i < dim1 && j < dim2; ){
       if ( v1[i] > v2[j]){
           j++;
       }
       if ( v2[j] > v1[i] ){
           i++;
       }
       if ( v1[i] == v2[j] ) {
          res[DimRes] = v1[i];
          i++;
          j++;
          DimRes++;
       }
    }
    return DimRes;
}



