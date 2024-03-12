#include "sort.h"


/**
 * swap_nodes - Swaps the nodes in a doubly linked list
 *
 * @list: Pointer to the first node in the doubly linked list
 * @first: Address of the first node being swapped
 * @second: Address of the second node being swapped
 *
 */

void swap_nodes(listint_t **list, listint_t *first, listint_t *second)
{
if (list == NULL || first == NULL || second == NULL)
	return;
/* If first node is NULL, make second the head of the list */
if (first->prev == NULL)
	*list = second;
else /* Otherwise, the next node should be second */
	first->prev->next = second;

second->prev = first->prev;

/* If second has a next node, update prev pointer of the next node to first */
if (second->next)
	second->next->prev = first;

/* Swap the nodes */
first->prev = second;
first->next = second->next;
second->next = first;
}




/**
 * cocktail_sort_list - application of the cocktail sort algorithm
 * to sort numbers
 *
 * @list: first node of doubly linked list
 *
 */

void cocktail_sort_list(listint_t **list)
{
listint_t *current;
int swap = 1;

if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

do {
	swap = 0;
	current = *list;

	while (current->next)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			print_list(*list);
			swap = 1;
			continue;
		}
		current = current->next;
	}
	if (!swap)
		break;

	swap = 0;
	current = current->prev;
	do {
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
			swap = 1;
			continue;
		}
		current = current->prev;
	} while (current && current->prev);

} while (swap);
}
