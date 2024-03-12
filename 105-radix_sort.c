#include "sort.h"

/**
* get_max - a function to get max element in array
* @array: the array to be sorted
* @size: the size of the array
*
* Return: the max element
*/

int get_max(int array[], size_t size)
{
	int max;
	size_t i;

	/* Error Handling: array can't be empty */
	if (size <= 0)
		return (-1);

	max = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}


/**
* count_sort - a function to sort an array using the count sort alogrithm
*
* @array: the array to be sorted
* @size: the size of the array
* @place_val: the plave value to be sorted
*/

void count_sort(int array[], size_t size, int place_val)
{
	/* declare and init count array to hold freq of digits */
	int count[10] = {0};
	int *temp;
	size_t i;

	temp = malloc(sizeof(int) * size);

	/* populate freq array */
	for (i = 0; i < size; i++)
		++count[(array[i] / place_val) % 10];

	/* get the actueal postions from count */
	for (i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];

	/* build new processed array L-R to maintain stability */
	for (i = size - 1; (int)(i) >= 0; i--)
		temp[--count[((array[i] / place_val) % 10)]] = array[i];

	/* populate initial array in sorted order */
	for (i = 0; i < size; i++)
		array[i] = temp[i];

	free(temp);

}

/**
* radix_sort - a function that sorts an array
* of integers in ascending order using the Radix sort algorithm
*
* @array: the array to be sorted
* @size: the size of the array
*/

void radix_sort(int *array, size_t size)
{
	int max, place_val;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	/* loop through all the place values in max */
	for (place_val = 1; max / place_val > 0; place_val *= 10)
	{
		count_sort(array, size, place_val);
		print_array(array, size);
	}
}