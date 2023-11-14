#include <stdio.h>
#include <stdlib.h>

#ifndef complejoADT__H
#define complejoADT__H

typedef struct complejoCDT * complejoADT;

typedef float numType;

complejoADT nuevoComp(numType rePart, numType imPart);

numType parteRealComp(complejoADT n);

numType parteImagComp(complejoADT n);

complejoADT sumaComp(complejoADT a, complejoADT b);

complejoADT multiplicaComp(complejoADT a, complejoADT b);

complejoADT divideComp(complejoADT a, complejoADT b);

complejoADT conjugadoComp(complejoADT n);




#endif