#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int head;
    struct node * tail;
};

typedef struct node * List;

List strToListUpper(char * s, List list){
    if(*s == '\0'){
        list = malloc(sizeof(struct node));
        list->tail = NULL;
        return list;
    }
    if(isupper(*s)){
        if(list == NULL){
            List aux = malloc(sizeof(struct node));
            aux->head = *s;
            aux->tail = strToListUpper(s+1,list);
            list = aux;
        }
    }
    else{
        list = strToListUpper(s+1,list);
    }

    return list;
}

void showListStr(List list){
    if(list->tail == NULL)
        return;
    putchar(list->head);
    showListStr(list->tail);
}

void printfStr(char * s){
    while(*s){
        if(isupper(*s))
            putchar(*s);
        s++;
    }
    puts("");
}

int main(){

    char * s = "hola eeE MUnDooooOaeppp";
    printfStr(s);
    List list = NULL;
    list = strToListUpper(s,list);
    showListStr(list);
    puts("");

    return 0;
}