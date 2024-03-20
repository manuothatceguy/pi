#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "ej8SetADT.h"
#include "listADT.h"
 // incluye elemType

/* Usamos internamente la lista para manejar la colección de elementos
** Usamos una lista ordenada que no acepta repetidos, caso contrario tendríamos que
** verificar -antes de insertar- si el elemento está o no, para no agregarlo
** dos veces
*/
typedef const char * elemType;
typedef struct setCDT {
	listADT list;
	compare cmp;
} setCDT;

setADT
newSet(compare cmp) {
	setADT set = malloc(sizeof(struct setCDT));
	if (set == NULL)
		return NULL;

	set->list = newList(cmp);
	set->cmp = cmp;
	return set;
}

void freeSet(setADT set) {
	/* Debemos liberar primero la lista */
	freeListADT(set->list);
	free(set);
}

int isEmptySet(setADT set) {
	return isEmptyList(set->list);
}

int setContains(setADT set, elemType element) {
	return belongsList(set->list, element);
}

int addElement(setADT set, elemType element) {
	return addList(set->list, element);
}

int deleteElement(setADT set, elemType element) {
	return delete (set->list, element);
}

int sizeSet(setADT set) {
	return sizeList(set->list);
}

setADT
unionSet(setADT set1, setADT set2) {
    // Asumimos que la funcion de comparacion es la misma en ambos conjuntos
	setADT set;
	listADT l1, l2;

	set = newSet(set1->cmp);
	if (set == NULL)
		return NULL;

	l1 = set1->list;
	toBegin(l1);

	/* Si set1 y set2 son el mismo conjunto, no podemos iterar como
    ** si fueran dos conjuntos distintos (se mezclarían los iteradores)
	*/
	if (set1 == set2) 	{
		while (hasNext(l1))
			addElement(set, next(l1));
		return set;
	}

	/* Podríamos agregar todos los elementos de l1 y luego todos los de l2
    ** pero no sería muy eficiente
    */
	l2 = set2->list;
	toBegin(l2);

	if (hasNext(l1) || hasNext(l2)) {
		elemType e1, e2;

		int has1, has2;

		if (has1 = hasNext(l1))
			e1 = next(l1);
		if (has2 = hasNext(l2))
			e2 = next(l2);

		while (has1 || has2) 		{
			if (!has2 || (has1 && set1->cmp(e1, e2) < 0)) {
				addElement(set, e1);
				if (has1 = hasNext(l1))
					e1 = next(l1);
			} else if (!has1 || (has2 && set1->cmp(e1, e2) > 0)) {
				addElement(set, e2);
				if (has2 = hasNext(l2))
					e2 = next(l2);
			} else { // son iguales
				addElement(set, e1);
				if (has1 = hasNext(l1))
					e1 = next(l1);
				if (has2 = hasNext(l2))
					e2 = next(l2);
			}
		}
	}
	return set;
}

setADT
intersectionSet(setADT set1, setADT set2) {
	setADT set;
	listADT l1, l2;

	set = newSet(set1->cmp);
	if (set == NULL)
		return NULL;

	l1 = set1->list;
	toBegin(l1);

	/* Si set1 y set2 son el mismo conjunto, no podemos iterar como
    ** si fueran dos conjuntos
	*/
	if (set1 == set2) {
		while (hasNext(l1))
			addElement(set, next(l1));
		return set;
	}
	l2 = set2->list;
	toBegin(l2);

	elemType e1, e2;
	int has1=hasNext(l1), has2=hasNext(l2);
	if ( has1 && has2 ) {
		e1 = next(l1);
		e2 = next(l2);
	}

	while (has1 && has2) {
		if (set1->cmp(e1, e2) < 0) {
		    if ( has1 = hasNext(l1))
			    e1 = next(l1);
		} else if (set1->cmp(e2, e1) < 0) {
		    if ( has2 = hasNext(l2))
			    e2 = next(l2);
		}else {
			addElement(set, e1);
			if ( has2 = hasNext(l2))
			    e2 = next(l2);
		    if ( has1 = hasNext(l1))
	    		e1 = next(l1);
		}
	}
	return set;
}

setADT
diffSet(setADT set1, setADT set2) {
	elemType e1, e2;
	setADT set;
	listADT l1, l2;

	set = newSet(set1->cmp);

	/* Si son el mismo conjunto, retornar conjunto vacío */
	if (set == NULL || set1 == set2)
		return set;

	l1 = set1->list;
	l2 = set2->list;

	toBegin(l1);
	toBegin(l2);

    int has1, has2;
	if (has2 = hasNext(l2))
		e2 = next(l2);

	if (has1 = hasNext(l1))
		e1 = next(l1);

	int c;
	while (has1) {
		if (!has2 || (c = set1->cmp(e1, e2)) < 0) {
			addElement(set, e1);
			if ( has1 = hasNext(l1))
			    e1 = next(l1);
		} else if (c > 0) {
		    if ( has2 = hasNext(l2)) 
			    e2 = next(l2);
		} else {
		    if ( has1 = hasNext(l1))
			    e1 = next(l1);
			if ( has2 = hasNext(l2)) 
			    e2 = next(l2);
		}
	}
	return set;
}

/* Utilizamos char * como elemType y strcmp como compare */
int main(void) {
	setADT set1 = newSet(strcmp);
	setADT set2 = newSet(strcmp);
	setADT ans;
	int ok;
	ok = addElement( set1, "amelia" );
	assert( ok && setContains( set1, "amelia" ) );
	ok = addElement( set1, "amelia" );
	assert( ok == 0 );
	addElement( set1, "belen" );
	addElement( set1, "carlos" ); // set1 = {"amelia", "belen", "carlos"}
	addElement( set2, "carlos" );
	addElement( set2, "daniel" );
	addElement( set2, "emilia" ); // set2 = {"carlos", "daniel", "emilia"}

	ans = unionSet( set1, set2 ); 
	assert( setContains(ans, "amelia") && setContains(ans, "daniel"));
	freeSet(ans);

	ans = intersectionSet( set1, set2 );
	assert( setContains(ans, "carlos") && setContains(ans, "amelia") == 0 );
	freeSet(ans);

	ans = diffSet( set1, set2 );
	assert( setContains(ans, "amelia") && setContains(ans, "carlos") == 0 );
	freeSet(ans);

	deleteElement( set1, "carlos" );
	ans = intersectionSet(set1, set2);
	assert( isEmptySet(ans) );

	freeSet(set1);
	freeSet(set2);
	freeSet(ans);
	
	// test con conjuntos de un elemento
	set1 = newSet(strcmp);
	set2 = newSet(strcmp);
	ok = addElement( set1, "amelia" );
	ok = addElement( set2, "amelia" );
	ans = intersectionSet( set1, set2 );
	assert( setContains(ans, "amelia") == 1 );
	assert(sizeSet(ans)==1);
	freeSet(ans);
	
	ans = unionSet( set1, set2 );
	assert( setContains(ans, "amelia") == 1 );
	assert(sizeSet(ans)==1);
	freeSet(ans);

    // Diferencia de un conjunto con un solo elemento
	freeSet(set2);
	set2 = newSet(strcmp);
	ans = diffSet( set1, set2 );
	assert(sizeSet(ans)==1);

    freeSet(ans);
    freeSet(set1);
	freeSet(set2);
	
	puts("OK!");
}