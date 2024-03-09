#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 * 
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap_int(int *a, int *b);
void insertion_sort_list(listint_t **list);
void swap_node(listint_t **head, listint_t **n1, listint_t *n2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
/**void swap(int *array, size_t size, int *a, int *b);*/
size_t lomuto(int *array, size_t low, size_t high, size_t size);
void recursive_sort(int *array, size_t low, size_t high, size_t size);


#endif /* SORT_H*/
