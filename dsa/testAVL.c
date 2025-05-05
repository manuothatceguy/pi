#include "avl.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(int n1, int n2){
    return n1 - n2;
}

int main(int argc, char const *argv[])
{
    AVLTree tree = newAVL(cmp);
    puts("---");
    printTree(tree);
    addNode(tree,10);
    puts("---");
    printTree(tree);
    addNode(tree,12);
    puts("---");
    printTree(tree);
    addNode(tree,13);
    puts("---");
    printTree(tree);
    assert(contains(tree,10));
    assert(contains(tree,12));
    assert(contains(tree,13));
    int test[] = {10,12,13};
    int len = 0;
    int * ret = dump(tree,&len);
    assert(len == 3);
    for (int i = 0; i < 3; i++){
        assert(test[i] == ret[i]);
    }
    addNode(tree,14);
    printTree(tree);
    puts("---");
    addNode(tree,15);
    printTree(tree);
    puts("---");
    addNode(tree,16);
    printTree(tree);
    puts("---");
    addNode(tree,17);
    printTree(tree);
    puts("---");
    free(ret);
    freeAVL(tree);
    return 0;
}
