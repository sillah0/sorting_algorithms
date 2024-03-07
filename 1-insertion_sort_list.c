#include "sort.h"

/**
 * swap_node - swap two nodes in a listint_t doubly-linked list
 * @head: pointer to head of the doubly linked list
 * @n1: first node to swap
 * @n2: second node to swap
 */

void swap_node(listint_t **head, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sort a doubly linked list of integers
 * @list: pointer to head of a doubly-linked list in integers
 *
 * Description: print a list after each swap
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *it, *ins, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (it = (*list)->next; it != NULL; it = tmp)
	{
		tmp = it->next;
		ins = it->prev;
		while (ins != NULL && it->n < ins->n)
		{
			swap_node(list, &ins, it);
			print_list((const listint_t *)*list);
		}
	}
}
