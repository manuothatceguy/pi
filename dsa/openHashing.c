#include <stdlib.h>
#include <stdio.h>
#include <avl.h>

#define INITIAL_LOOKUP_SIZE 10
#define THRESHOLD 0.75

typedef int keyType;
typedef int valueType;

typedef int (*prehashFun)(keyType);

struct openHashing {
    prehashFun prehash;
    size_t size;
    
};

struct slot {
    keyType key;
    valueType value;
};

static int hash(prehashFun prehash, keyType key){
    return prehash(key);
}

static struct slot getSlot(keyType key){

}