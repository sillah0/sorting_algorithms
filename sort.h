#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **list, listint_t *first, listint_t *second);
void initialize_array(int *arr, int size);
void count_occurrences(const int *arr, size_t size, int *position);
void calculate_cumulative_sum(int *position, size_t size, int *sum_position);
void build_sorted_array(int *arr, size_t size, int *sum_position, int *sorted);
void counting_sort(int *arr, size_t size);
void merge(int *array, int *left, int *right, size_t size_l, size_t size_r);
void split_array(int *array, size_t size, int **left, int **right);
void merge_sort_recursive(int *array, size_t size);
void merge_sort(int *array, size_t size);

#endif /* SORT_H*/
