#include "sort.h"

/**
 * merge - Merge two sorted arrays
 * @array: Original array
 * @left: Left subarray
 * @right: Right subarray
 * @size_l: Size of the left subarray
 * @size_r: Size of the right subarray
 *
 */

void merge(int *array, int *left, int *right, size_t size_l, size_t size_r)
{
size_t i, j, k;
printf("Merging...\n");
printf("[left]: ");
print_array(left, size_l);
printf("[right]: ");
print_array(right, size_r);

i = j = k = 0;
while (i < size_l && j < size_r)
{
	if (left[i] <= right[j])
	{
		array[k] = left[i];
		i++;
	}
	else
	{
		array[k] = right[j];
		j++;
	}
	k++;
}

while (i < size_l)
{
	array[k] = left[i];
	i++;
	k++;
}

while (j < size_r)
{
	array[k] = right[j];
	j++;
	k++;
}
printf("[Done]: ");
print_array(array, size_l + size_r);
}

/**
 * split_array - Split the array into two subarrays
 * @array: Original array
 * @size: Size of the array
 * @left: Pointer to the left subarray
 * @right: Pointer to the right subarray
 *
 */

void split_array(int *array, size_t size, int **left, int **right)
{
size_t mid, i;

if (!array || size < 2)
	return;

mid = size / 2;
*left = malloc(sizeof(int) * mid);
*right = malloc(sizeof(int) * (size - mid));

if (!(*left) || !(*right))
{
	free(*left);
	free(*right);
}

for (i = 0; i < mid; i++)
	(*left)[i] = array[i];

for (i = mid; i < size; i++)
	(*right)[i - mid] = array[i];
}

/**
 * merge_sort_recursive - Recursive function to perform merge sort
 * @array: Original array
 * @size: Size of the array
 *
 */

void merge_sort_recursive(int *array, size_t size)
{
size_t mid;
int *left, *right;

if (size < 2)
	return;

mid = size / 2;
split_array(array, size, &left, &right);

merge_sort_recursive(left, mid);
merge_sort_recursive(right, size - mid);

merge(array, left, right, mid, size - mid);

free(left);
free(right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 *
 */

void merge_sort(int *array, size_t size)
{
if (!array || size < 2)
	return;

merge_sort_recursive(array, size);
}
