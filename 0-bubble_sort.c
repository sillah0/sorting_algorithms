#include "sort.h"

/**
 * swap_int - sort an array of integers in ascending order
 * @a: first integer
 * @b: second integer
 */

void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sort an array of integers in ascending order
 * @array: an array of integers to sort
 * @size: size of the array
 *
 * Description: print the array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(&array[j], &array[j + 1]);
			       print_array(array, size);
			}
		}
	}
}

