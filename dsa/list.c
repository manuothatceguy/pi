#include "list.h"

typedef struct ListCDT {
    Node * first;
    size_t count;
    comparator cmp;
    char rep;
} ListCDT;

typedef struct Node {
    keyType head;
    Node * tail;
} Node;

ListADT new_ListADT(comparator cmp, char rep){
    ListADT toReturn = malloc(sizeof(ListCDT));
    toReturn->cmp = cmp;
    toReturn->rep = rep;
    toReturn->count = 0;
    toReturn->first = NULL;
    return toReturn;
}

ListADT fromArray_ListADT(comparator cmp, char rep, keyType * arr, size_t count){
    
}

keyType add_ListADT(ListADT list, keyType elem){
    if(list->count == 0){
        list->first = malloc(sizeof(Node));

    }
}

keyType delete_listADT(ListADT list, keyType elem);

ListADT slice_listADT(ListADT list, int lower, int upper);

ListADT filter_listADT(ListADT list, filter f);

ListADT merge_listADT(ListADT list1, ListADT list2, comparator cmp);