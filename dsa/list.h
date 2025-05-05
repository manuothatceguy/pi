#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Lista simplemente encadenada con orden determinado por un comparador
 */

typedef struct ListCDT* ListADT;

typedef int keyType;

// Para setear orden en la lista
typedef int (*comparator)(keyType, keyType);

typedef int (*filter(keyType));

/**
 * @brief Crea lista vacía
 * @param cmp función que compara elementos para el orden
 * @param rep si acepta repetidos o no
 */
ListADT new_ListADT(comparator cmp, char rep);

/**
 * @brief Crea lista a partir de un array no necesariamente ordenado
 * @param cmp función que compara elementos para el orden
 * @param rep si acepta repetidos o no
 */
ListADT fromArray_ListADT(comparator cmp, char rep, keyType * arr, size_t count);

/**
 * Agrega un elemento a la lista
 * @returns elemento agregado
 */
keyType add_ListADT(ListADT list, keyType elem);

/**
 * @brief Delete. Elimina la primera o única aparición (depende de si acepta repetidos o no)
 * @returns elemento eliminado
 */
keyType delete_listADT(ListADT list, keyType elem);


/**
 * Retorna una lista recortada cerrado a izquierda abierto a derecha
 */
ListADT slice_listADT(ListADT list, int lower, int upper);


/**
 * Retorna una lista con los elementos que cumplan con el filtro
 */
ListADT filter_listADT(ListADT list, filter f);

/**
 * Retorna una nueva lista mezclando las dos
 */
ListADT merge_listADT(ListADT list1, ListADT list2, comparator cmp);

#endif // LIST_H