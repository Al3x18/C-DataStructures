#include "list.h"

/*
 * Restituisce l'elemento che compare più volte nella lista 'l'.
 *
 * Comportamento:
 *   - Se la lista è vuota, restituisce NULLITEM.
 *   - Altrimenti, restituisce l'elemento che compare più volte nella lista.
 */
item max_duplicazioni(list l);

/*
 * Restituisce l'elemento centrale della lista 'l' e lo rimuove dalla lista.
 *
 * Comportamento:
 *   - Se la lista è vuota, restituisce NULLITEM.
 *   - Altrimenti, restituisce l'elemento in posizione floor(n/2), dove n è la lunghezza della lista.
 *     Questo elemento viene rimosso dalla lista.
 */
item itemCentrale(list l);

/*
 * Inverti gli estremi della lista 'l'.
 *
 * Comportamento:
 *   - Se la lista è vuota o ha un solo elemento, non fa nulla.
 *   - Altrimenti, inverte il primo e l'ultimo elemento della lista.
 */
int invertiEstremi(list l);