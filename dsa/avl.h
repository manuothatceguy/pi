#ifndef AVL_H
#define AVL_H

typedef int dataType;

typedef struct AVL * AVLTree;

typedef int (*pFun)(dataType, dataType);

AVLTree newAVL(pFun cmp);

AVLTree addNode(AVLTree tree, dataType node);

// en len le cargo la longitud del array
dataType * dump(AVLTree tree, int * len);

char contains(AVLTree tree, dataType node);

void printTree(AVLTree tree);

void freeAVL(AVLTree avl);



#endif // AVL_H

