/**
 * 
 * EN CLASE
 *  
elemType getListIter(listADT list, size_t idx){

    if(list->dim <= idx){
        exit(1);
    }
    TList aux = list->first;
    
    for(int i = 0; i < idx; i++, aux=aux->tail) // hasta no llegar al idx, me voy moviendo como lista
        ;
    return aux->head;
} */