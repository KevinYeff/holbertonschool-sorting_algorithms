#include "sort.h"
/**
 * insertion_sort_list - Function that sorts a doubly linked list of integers
 *                       in ascending order.
 * @list:                List to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL; /* elemento actual */
	listint_t *prev = NULL; /* elemento anterior */

	if (list == NULL)
		return;

	curr = *list;/* Iteramos sobre la lista*/
	while (curr)
	{
		prev = curr;
		/*Si el elemento anterior es mayor que el actual, intercambiamos*/
		while (prev->prev && (prev->n < prev->prev->n))
		{/*Actualizamos los enlaces entre los elementos */
			(prev->prev)->next = prev->next;
			if (prev->next != NULL)
				(prev->next)->prev = prev->prev;
			prev->next = prev->prev;
			prev->prev = (prev->prev)->prev;
			(prev->next)->prev = prev;
			/* Si el elemento actual es el nuevo inicio de la lista */
			if (prev->prev != NULL)
				(prev->prev)->next = prev; /*actualizamos list */
			else
				*list = prev;

			print_list(*list);/* Imprimimos la lista actualizada*/
			if (!prev->prev)/*actualizamos lista*/
				*list = prev;
		}
		prev = curr;/*Actualizamos el elemento anterior*/
		curr = curr->next;/* Avanzamos al siguiente elemento */
	}
}
