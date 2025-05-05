#include "queueADT.h"

typedef struct node{
    elemType value;
    struct node * next;
} tNode;

struct queueCDT{
    tNode * first;
    tNode * last;
    tNode * iterator;
} queueCDT;

queueADT newQueue(void){
    return calloc(1,sizeof(queueCDT));
}

void queue(queueADT q, elemType n){
    tNode * node = calloc(1,sizeof(tNode));
    node->value = n;
    if(isEmpty(q)){
        q->first = node;
        q->last = node;
    } else{
        q->last->next = node;
        q->last = node;
    }
    return;

}

void dequeue(queueADT q, elemType * out){
    if(!isEmpty(q)){
        *out = q->first->value;
        tNode * currentFirst = q->first;
        if(currentFirst == q->last){
            q->first = q->last = NULL;
        }
        else{
            q->first = q->first->next;
        }
        free(currentFirst);
        return;
    }
}

static void freeRec(tNode * n){
    if(n == NULL){
        return;
    }
    free(n->next);
    free(n);
}

void freeQueue(queueADT q){
    freeRec(q->first);
    free(q);
}

int isEmpty(queueADT q){
    return q->first == NULL;
}

void toBegin(queueADT q){
    q->iterator = q->first;
}

int hasNext(queueADT q){
    return q->iterator != NULL;
}

elemType next(queueADT q){
    elemType elem = q->iterator->value;
    q->iterator = q->iterator->next;
    return elem;
}