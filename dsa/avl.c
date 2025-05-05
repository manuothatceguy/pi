#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node * left;
    struct node * right;
    dataType value;
    size_t height;
};

struct AVL {
    struct node * root;
    size_t numNodes;
    pFun cmp;
};

struct node * newLeaf(dataType val){
    struct node * ret = calloc(1,sizeof(struct node));
    // revisar null por si falla calloc
    ret->value = val;
    return ret;
}

AVLTree newAVL(pFun cmpfun){
    AVLTree ret = calloc(1,sizeof(struct AVL));
    // revisar null por si falla calloc
    ret->cmp = cmpfun;
    return ret;
}

#define MAX(x,y) (((x) > (y)) ? (x) : (y))

void updateHeight(struct node * root){
    if(root->left == NULL && root->right == NULL){
        root->height = 0;
    }
    else if(root->left == NULL){
        root->height = root->right->height + 1;
    } else if(root->right == NULL){
        root->height = root->left->height + 1;
    } else {
        root->height = MAX(root->left->height,root->right->height);
    }
}

struct node * leftRotate(struct node * pivot){
    struct node * newRoot = pivot->right;
    pivot->right = newRoot->left; // le entrego el puntero
    newRoot->left = pivot;

    updateHeight(pivot);
    updateHeight(newRoot);
    return newRoot;
}

struct node * rightRotate(struct node * pivot){
    struct node * newRoot = pivot->left;
    pivot->left = newRoot->right;
    newRoot->right = pivot;

    updateHeight(pivot);
    updateHeight(newRoot);
    return newRoot;
}

struct node * addNodeRec(AVLTree tree, struct node * curr, dataType node, pFun cmp){
    if(curr == NULL){
        tree->numNodes++;
        return newLeaf(node);
    }
    int c = cmp(curr->value,node);
    if(c == 0){
        // ver como resolver igualdad. por ahora es
        // nada! lol
    }
    else if(c < 0){
        curr->right = addNodeRec(tree,curr->right,node,cmp);
    } else {
        curr->left = addNodeRec(tree,curr->left,node,cmp);
    }

    int left, right;
    left = curr->left == NULL ? -1 : curr->left->height;
    right = curr->right == NULL ? -1 : curr->right->height;

    
    curr->height = 1 + MAX(left,right);

    int bf = left - right; // balance factor

    // 4 casos de rotación

    // left left
    if(bf > 1 && cmp(node,curr->left->value) < 0){
        return rightRotate(curr);
    }

    // right right
    if(bf < -1 && cmp(node,curr->right->value) > 0){
        return leftRotate(curr);
    }

    // left right
    if(bf > 1 && cmp(node,curr->left->value) > 0){
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }

    // right left
    if(bf < -1 && cmp(node,curr->right->value) <= 0){
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }

    return curr;
}


AVLTree addNode(AVLTree tree, dataType node){
    tree->root = addNodeRec(tree, tree->root, node, tree->cmp);
    return tree;
}

// inorder dump. to preserve order of nodes.
void dumpRec(struct node * curr, dataType * array, int * currentIndex){
    if(curr == NULL){
        return;
    }
    dumpRec(curr->left,array,currentIndex);
    array[(*currentIndex)++] = curr->value;
    dumpRec(curr->right,array,currentIndex);
}

// en len le cargo la longitud del array
dataType * dump(AVLTree tree, int * len){
    dataType * ret = malloc(tree->numNodes * sizeof(dataType));
    // revisar null por si falla malloc
    *len = tree->numNodes;
    int currIdx = 0;
    dumpRec(tree->root,ret,&currIdx);
    return ret;
}

char binarySearch(struct node * root, dataType value, pFun cmp){
    if(root == NULL){
        return 0;
    }
    int c = cmp(value,root->value);
    if(c == 0){
        return 1; // found it!
    } else if(c < 0){
        return binarySearch(root->left,value,cmp);
    } 
    return binarySearch(root->right,value,cmp);
}

char contains(AVLTree tree, dataType node){
    return binarySearch(tree->root,node,tree->cmp);
}

void freeNode(struct node * root){
    if(root == NULL){
        return;
    }
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}

void freeAVL(AVLTree avl){
    freeNode(avl->root);
    free(avl);
}

void printHierarchyRec(struct node *current, int space) {
    if (current == NULL) {
        for (int i = 0; i < space; i++) printf(" ");
        printf("└── null\n");
        return;
    }

    for (int i = 0; i < space; i++) printf(" ");
    printf("└── %d\n", current->value);

    printHierarchyRec(current->left, space + 4);
    printHierarchyRec(current->right, space + 4);
}

void printTree(AVLTree tree) {
    printHierarchyRec(tree->root, 0);
}