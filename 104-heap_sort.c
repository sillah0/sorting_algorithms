#include "sort.h"

/**
 * sift_down - Sift down a node to maintain the max heap property
 * @array: Original array
 * @size: Size of the array
 * @start: Index of the node to sift down
 * @end: Index marking the end of the heap
 *
 */

void sift_down(int *array, size_t size, size_t start, size_t end)
{
size_t root = start;
size_t child, swap;
int temp;

while (2 * root + 1 <= end)
{
	child = 2 * root + 1;
	swap = root;

	if (array[swap] < array[child])
		swap = child;

	if (child + 1 <= end && array[swap] < array[child + 1])
		swap = child + 1;

	if (swap != root)
	{
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;

		print_array(array, size);
		root = swap;
	}
	else
		break;
}
}





/**
 * heap_sort - Sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 *
 */

void heap_sort(int *array, size_t size)
{
int i, temp;

if (!array || size < 2)
	return;

/* Build the max heap */
for (i = size / 2 - 1; i >= 0; i--)
	sift_down(array, size, i, size - 1);

/* Extract elements from the heap one by one */
for (i = size - 1; i > 0; i--)
{
	temp = array[0];
	array[0] = array[i];
	array[i] = temp;

	print_array(array, size);
	sift_down(array, size, 0, i - 1);
}
}
