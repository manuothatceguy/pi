#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ej17.h"
#include <assert.h>

struct frase{
    size_t len;
    char * phrase;

};

struct phrasesCDT{
    struct frase * frases;
    size_t cantFrases;
    size_t minKey;
    size_t maxKey;
};

phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo){
    if(keyTo < keyFrom || keyFrom <= 0 || keyTo <= 0){
        return NULL;
    }
    phrasesADT new = malloc(sizeof(struct phrasesCDT));
    new->maxKey = keyTo;
    new->minKey = keyFrom;
    new->frases = calloc((keyTo-keyFrom+1),sizeof(struct frase));
    return new;
}

#define BLOCK 20

// Recibe un string (puede ser NULL), la cantidad de bytes ya reservados y de ser necesario va creando mas espacio
// Si estamos trabajando con strings extensos no seria eficiente usar
// directamente strlen y malloc, por lo que copiamos de a bloques
static char * copy(char * s, const char *newS, size_t * len ) {
    char * ans = s;
    
    size_t reserved = *len;
    size_t i;
    for (i = 0; newS[i] != 0; i++) {
        // Si ya usamos todo el string original, entonces agrandamos
        if ( i == reserved) {
            reserved += BLOCK;
            ans = realloc(ans, reserved);
        }
        ans[i] = newS[i];
    }
    ans = realloc(ans, i+1);     // liberamos lo que usamos de mas
    ans[i]=0;
    *len = i; 
    return ans;
}

int put(phrasesADT ph, size_t key, const char * phrase) {
    if ( key < ph->minKey || key > ph->maxKey) {
        return 0;
    }
    size_t i = key - ph->minKey;
    if ( ph->frases[i].phrase == NULL) {
        ph->cantFrases++;
    }
    ph->frases[i].phrase = copy(ph->frases[i].phrase, phrase, &(ph->frases[i].len));
    
    return 1;
}



char * get(const phrasesADT ph, size_t key){
    if(key > ph->maxKey || key < ph->minKey)
        return NULL;
    struct frase aux = ph->frases[key - ph->minKey];
    char * ans = malloc((aux.len + 1)*sizeof(char));
    strcpy(ans,aux.phrase);
    return ans;
}

// Funcion auxiliar para usar tanto en concat como en concatAll
static char * copyPhrases(struct frase v[], size_t from, size_t to) {
    // tenemos la longitud de cada una, podemos hacer reallocs por cada frase y strcpy de cada una
    char * ans = NULL;
    size_t total = 0;
    for(size_t i=from; i<=to; i++) {
        size_t add = v[i].len;
        if ( add > 0) {
            ans = realloc(ans, total + add + 1);
            // podriamos usar strcat pero seria ineficiente, ya sabemos donde esta el final
            strcpy(ans + total, v[i].phrase);
            total += add;
        }
    }
    if (total==0) {
        ans = malloc(1);
        *ans=0;
    }
    return ans;
}

char * concat(const phrasesADT ph, size_t from, size_t to){
    if(from > to || from < ph->minKey || to > ph->maxKey)
        return NULL;
    return copyPhrases(ph->frases,from - ph->minKey,to - ph->minKey);
}

char * concatAll(const phrasesADT ph){
    return copyPhrases(ph->frases,0,ph->maxKey - ph->minKey + 1);
}

size_t size(const phrasesADT ph){
    return ph->cantFrases;
}

static void freeFrases(struct frase * vec, size_t dim){
    for(int i = 0; i < dim; i++){
        if(vec[i].phrase != NULL){
            free(vec[i].phrase);
        }
    }
}


void freePhrases(phrasesADT ph){
    freeFrases(ph->frases,ph->maxKey - ph->minKey + 1);
    free(ph->frases);
    free(ph);
}

int main(void) {
    assert(newPhrasesADT(1200, 1100)==NULL);
    phrasesADT p = newPhrasesADT(1200, 1800);
    assert(p!=NULL);
    assert(put(p, 1199, "Hello" )==0);
    assert(size(p)==0);
    assert(put(p, 1200, "Hello" )==1);
    assert(put(p, 1210, ", " )==1);
    assert(put(p, 1220, "world" )==1);
    assert(size(p)==3);
    
    char * aux = get(p, 1100);
    assert(aux==NULL);
    aux= get(p, 1200);
    assert(strcmp(aux, "Hello")==0);
    free(aux);
    aux= get(p, 1210);
    assert(strcmp(aux, ", ")==0);
    free(aux);
    aux= get(p, 1220);
    assert(strcmp(aux, "world")==0);
    free(aux);
    
    aux = concatAll(p);
    assert(strcmp(aux, "Hello, world")==0);
    free(aux);
    
    aux = concat(p,1230, 1800);
    assert(strcmp(aux, "")==0);
    free(aux);
    
    aux = concat(p,1200, 1800);
    assert(strcmp(aux, "Hello, world")==0);
    free(aux);
    
    // reemplazamos "world" por otro texto
    assert(put(p, 1220, "mundo cruel." )==1);
    assert(size(p)==3);
    aux = concatAll(p);
    assert(strcmp(aux, "Hello, mundo cruel.")==0);
    free(aux);
    freePhrases(p);
 
    p = newPhrasesADT(1, 20);   
    put(p,1, "On the burning February morning Beatriz Viterbo died, after braving an agony that never for a single moment gave way to self-pity or fear, "
    "I noticed that the sidewalk billboards around Constitution Plaza were advertising some new brand or other of American cigarettes. "
    "The fact pained me, for I realised that the wide and ceaseless universe was already slipping away from her and that this slight change "
    "was the first of an endless series. The universe may change but not me, I thought with a certain sad vanity. "
    "I knew that at times my fruitless devotion had annoyed her; now that she was dead, I could devote myself to her memory, "
    "without hope but also without humiliation. I recalled that the thirtieth of April was her birthday; on that day to visit her house on Garay Street "
    "and pay my respects to her father and to Carlos Argentino Daneri, her first cousin, would be an irreproachable and perhaps unavoidable act of politeness. "
    "Once again I would wait in the twilight of the small, cluttered drawing room, once again I would study the details of her many photographs: "
    "Beatriz Viterbo in profile and in full colour; Beatriz wearing a mask, during the Carnival of 1921; "
    "Beatriz at her First Communion; Beatriz on the day of her wedding to Roberto Alessandri; "
    "Beatriz soon after her divorce, at a luncheon at the Turf Club; Beatriz at a seaside resort in Quilmes with Delia San Marco Porcel and Carlos Argentino; "
    "Beatriz with the Pekingese lapdog given her by Villegas Haedo; Beatriz, front and three-quarter views, smiling, hand on her chin... "
    "I would not be forced, as in the past, to justify my presence with modest offerings of books -- books whose pages I finally learned to cut beforehand, "
    "so as not to find out, months later, that they lay around unopened.");
    
    put(p,2, "Beatriz Viterbo died in 1929. From that time on, I never let a thirtieth of April go by without a visit to her house. "
    "I used to make my appearance at seven-fifteen sharp and stay on for some twenty-five minutes. "
    "Each year, I arrived a little later and stay a little longer. In 1933, a torrential downpour coming to my aid, "
    "they were obliged to ask me for dinner. Naturally, I took advantage of that lucky precedent. "
    "In 1934, I arrived, just after eight, with one of those large Santa Fe sugared cakes, and quite matter-of-factly I stayed to dinner. "
    "It was in this way, on these melancholy and vainly erotic anniversaries, that I came into the gradual confidences of Carlos Argentino Daneri." );
    
    put(p,3, "Be thou as chaste as ice, as pure as snow, thou shalt not escape calumny. Get thee to a nunnery, go.");
    assert(size(p)==3);
    
    put(p,10, "On the burning February morning Beatriz Viterbo died, after braving an agony that never for a single moment gave way to self-pity or fear, "
    "I noticed that the sidewalk billboards around Constitution Plaza were advertising some new brand or other of American cigarettes. "
    "The fact pained me, for I realised that the wide and ceaseless universe was already slipping away from her and that this slight change "
    "was the first of an endless series. The universe may change but not me, I thought with a certain sad vanity. "
    "I knew that at times my fruitless devotion had annoyed her; now that she was dead, I could devote myself to her memory, "
    "without hope but also without humiliation. I recalled that the thirtieth of April was her birthday; on that day to visit her house on Garay Street "
    "and pay my respects to her father and to Carlos Argentino Daneri, her first cousin, would be an irreproachable and perhaps unavoidable act of politeness. "
    "Once again I would wait in the twilight of the small, cluttered drawing room, once again I would study the details of her many photographs: "
    "Beatriz Viterbo in profile and in full colour; Beatriz wearing a mask, during the Carnival of 1921; "
    "Beatriz at her First Communion; Beatriz on the day of her wedding to Roberto Alessandri; "
    "Beatriz soon after her divorce, at a luncheon at the Turf Club; Beatriz at a seaside resort in Quilmes with Delia San Marco Porcel and Carlos Argentino; "
    "Beatriz with the Pekingese lapdog given her by Villegas Haedo; Beatriz, front and three-quarter views, smiling, hand on her chin... "
    "I would not be forced, as in the past, to justify my presence with modest offerings of books -- books whose pages I finally learned to cut beforehand, "
    "so as not to find out, months later, that they lay around unopened."
    "Beatriz Viterbo died in 1929. From that time on, I never let a thirtieth of April go by without a visit to her house. "
    "I used to make my appearance at seven-fifteen sharp and stay on for some twenty-five minutes. "
    "Each year, I arrived a little later and stay a little longer. In 1933, a torrential downpour coming to my aid, "
    "they were obliged to ask me for dinner. Naturally, I took advantage of that lucky precedent. "
    "In 1934, I arrived, just after eight, with one of those large Santa Fe sugared cakes, and quite matter-of-factly I stayed to dinner. "
    "It was in this way, on these melancholy and vainly erotic anniversaries, that I came into the gradual confidences of Carlos Argentino Daneri.");
    
    aux = get(p, 2);
    assert(strncmp(aux,"Beatriz Viterbo",15 )==0);
    
    assert(strlen(aux)==690);
    
    char *aux1 = get(p, 1);
    
    char aux12[strlen(aux1)+strlen(aux)+1];
    strcpy(aux12, aux1);
    strcat(aux12, aux);
    
    char * aux10 = get(p,10);
    assert(strcmp(aux12, aux10)==0);
    
    free(aux);
    free(aux1);
    free(aux10);
    
    freePhrases(p);
    puts("OK!");
    return 0;
}