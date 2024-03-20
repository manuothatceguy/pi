#include "hangmanADT.h"
#include <string.h>

#define BLOCK 10

typedef struct TLevel{
    char ** words;
    size_t cantw;
}TLevel;

typedef struct hangmanCDT{

    TLevel * level;
    size_t maxLevel;

} hangmanCDT;

hangmanADT newHangman(unsigned int maxLevel){
    if(maxLevel == 0)
        return NULL;
    srand(time(NULL));
    hangmanCDT * new = malloc(sizeof(hangmanCDT));
    new->level = calloc(maxLevel, sizeof(TLevel));
    new->maxLevel = maxLevel;
    return new;
}

int size(const hangmanADT h, unsigned int level){
    if(level > 0 && level <= h->maxLevel)
        return h->level[level-1].cantw;
    return -1;
}

static int wordExistsIn(TLevel level, char * word){
    for(int i = 0; i < level.cantw; i++){
        if(strcmp(level.words[i],word)==0)
            return 1;
    }
    return 0;
}

int addWords(hangmanADT h, char* words[], unsigned int level){
    if(level > h->maxLevel)
        return -1;
    int added = 0;
    for(int i = 0; words[i] != NULL; i++){
        if(!wordExistsIn(h->level[level - 1],words[i])){
            if(h->level[level - 1].cantw % BLOCK == 0){
                h->level[level - 1].words = realloc(h->level[level - 1].words,(h->level[level - 1].cantw + BLOCK)*sizeof(char*));
            }
            h->level[level - 1].words[h->level[level - 1].cantw] = words[i];
            h->level[level - 1].cantw++;
            added++;
        }
    }
    return added;
}

char * word(const hangmanADT h, unsigned int level){
    if(level > h->maxLevel || level <= 0 || h->level[level-1].cantw == 0)
        return NULL;
    int i = (rand() / ((double)RAND_MAX + 1) ) * h->level[level-1].cantw;
    return h->level[level-1].words[i];
}

char ** words(const hangmanADT h, unsigned int level){
    if( level > 0 && level <= h->maxLevel ){
        char ** w = malloc(sizeof(char *) * (h->level[level-1].cantw + 1));
        int i;
        for(i=0 ; i<h->level[level-1].cantw ; i++)  
            w[i] = h->level[level-1].words[i];
        w[i] = NULL;
        return w;
    }
    return NULL;
}