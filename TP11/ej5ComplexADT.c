#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "ej5ComplexADT.h" 

#define EPS 0.01

typedef struct complejoCDT{
    numType r,i;
} complejoCDT;

complejoADT nuevoComp(numType rePart, numType imPart){
    complejoADT complex = malloc(sizeof(struct complejoCDT));
    complex->r = rePart;
    complex->i = imPart;
    return complex;
}

numType parteRealComp(complejoADT n){
    return n->r;
}

numType parteImagComp(complejoADT n){
    return n->i;
}

complejoADT sumaComp(complejoADT a, complejoADT b){
    complejoADT sum = malloc(sizeof(struct complejoCDT));
    sum->r = parteRealComp(a) + parteRealComp(b);
    sum->i = parteImagComp(a) + parteImagComp(b);
    return sum;
}

complejoADT multiplicaComp(complejoADT a, complejoADT b){
    complejoADT prod = malloc(sizeof(complejoCDT));
    prod->r = parteRealComp(a)*parteRealComp(b) - parteImagComp(a)*parteImagComp(b);
    prod->i = parteRealComp(a)*parteImagComp(b) + parteImagComp(a)*parteRealComp(b);
    return prod;
}

float moduloComp(complejoADT n){
    return sqrt( (n->r)*(n->r) + (n->i)*(n->i) );
}

complejoADT conjugadoComp(complejoADT n){
    complejoADT ans = malloc(sizeof(complejoCDT));
    ans->r = n->r;
    ans->i = (-1)*(n->i);
    return ans;
}

complejoADT divideComp(complejoADT a, complejoADT b){
    complejoADT conjB = conjugadoComp(b);
    complejoADT moduloB = nuevoComp(1/(moduloComp(b)*moduloComp(b)),0); // 1/modulo B es como dividirlo por eso!
    complejoADT resp = multiplicaComp(multiplicaComp(a,conjB),moduloB);
    return resp;
}

complejoADT restaComp(complejoADT a, complejoADT b){
    complejoADT resp = malloc(sizeof(struct complejoCDT));
    resp->r = parteRealComp(a) - parteRealComp(b);
    resp->i = parteImagComp(a) - parteImagComp(b);
    return resp;
}

void liberaComp(complejoADT n){
    free(n);
}

int main(void) {
  complejoADT comp1 = nuevoComp( 1, 2 ); // comp1 = 1 + 2i
	complejoADT comp2 = nuevoComp( 2, -3 ); // comp2 = 2 - 3i
	complejoADT ans;

	ans = sumaComp( comp1, comp2 );
	assert( parteRealComp(ans) - 3 < EPS && parteImagComp(ans) + 1 < EPS );
	liberaComp( ans );

	ans = restaComp( comp1, comp2 );
	assert( parteRealComp(ans) - 1 < EPS && parteImagComp(ans) - 5 < EPS );	
	liberaComp( ans );

	ans = multiplicaComp( comp1, comp2 );
	assert( parteRealComp(ans) - 8 < EPS && parteImagComp(ans) - 1 < EPS );
	liberaComp( ans );

	ans = divideComp( comp1, comp2 );
	assert( parteRealComp(ans) + 0.31 < EPS && parteImagComp(ans) - 0.54 < EPS );
	liberaComp( ans );

	ans = conjugadoComp( comp1 );
	assert( parteRealComp(ans) - 1 < EPS && parteImagComp(ans) + 2 < EPS );

	liberaComp( comp1 );
	liberaComp( comp2 );
	liberaComp( ans );

	printf("OK!\n");
}