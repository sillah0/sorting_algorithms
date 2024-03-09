#include "sort.h"

/**
 * swap - a function to swap two ints
 *
 * @a: first int
 * @b: second int
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - a function that sorts an array of integers
 * in ascending order using the shell sort algorithm
 *
 * @array: pointer to an array of ints
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;
	bool flag = false;

	/*Error handling: can't sort an empty array or a singleton*/
	if (array == NULL || size <= 1)
		return;

	/*Generate the gap using the knuth sequence*/
	gap = 1;
	while (gap < size)
		gap = gap * 3 + 1;
	
	/*loop through until gap = 1 (inclusive) which is last round*/
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				swap(&array[j], &array[j - gap]);
				j -= gap;
			}
			flag = true;
			array[j] = temp;
		}
		/*decrement gap for next round*/
		gap = (gap - 1) / 3;

		if (flag)
			print_array(array, size);
	}
}
