#ifndef __MULTISETADT_H_
#define __MULTISETADT_H_
#include <stdlib.h>

typedef struct multiSetCDT * multiSetADT;

typedef int elemType; // Tipo de elemento a insertar


/* Retorna un nuevo multiSet de elementos genéricos. Al inicio está vacío */
multiSetADT newMultiSet(void);


/* Agregamos el free para que el test corra con el sanitize.
** es opcional utizarlo. Pueden copiarlo de la solucion o comentarlo en el test. 
*/
void freeMultiSet(multiSetADT multiSet);

/* Inserta un elemento. Retorna cuántas veces está elem en el conjunto
** luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
unsigned int add(multiSetADT multiSet, elemType elem);

/* Retorna cuántas veces aparece el elemento en el multiSet */
unsigned int count ( const multiSetADT multiSet, elemType elem );

/* Retorna la cantidad de elementos ​distintos​ que hay en el multiSet */
unsigned int size( const multiSetADT multiSet);

/* Elimina una repetición del elemento. Retorna cuántas veces está elem el conjunto
** luego de haberlo borrado (si el elemento no estaba, retorna cero)
*/
int removeOne( multiSetADT multiSet, elemType elem );

/* Elimina todas las apariciones de un elemento. */
void removeAll( multiSetADT multiSet , elemType elem );

/* Retorna un vector con los elementos que menos aparecen en el conjunto
** Si el conjunto está vacío retorna NULL
** En el parámetro de salida dim almacena la cantidad de elementos del vector
*/
elemType * minElements( const multiSetADT multiSet , int *dim);

#endif