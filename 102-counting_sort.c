#include "sort.h"

/**
 * initialize_array - Initializes array elements to 0
 *
 * @arr: Array to be initialized
 * @size: Size of the array
 *
 */

void initialize_array(int *arr, int size)
{
int i = 0;

while (i < size)
{
	arr[i] = 0;
	i++;
}
}

/**
 * count_occurrences - Count occurrences of each element in the array
 *
 * @arr: The array to be counted
 * @size: Number of elements in the array
 * @position: Array to store occurrences
 *
 */

void count_occurrences(const int *arr, size_t size, int *position)
{
size_t i;

for (i = 0; i < size; i++)
{
	position[arr[i]] += 1;
}
}

/**
 * calculate_cumulative_sum - Calculate the cumulative sum of counts
 *
 * @position: Array storing occurrences
 * @size: Size of the array
 * @sum_position: Array to store cumulative sum
 *
 */

void calculate_cumulative_sum(int *position, size_t size, int *sum_position)
{
size_t j;
sum_position[0] = position[0];

for (j = 1; j < size; j++)
{
	sum_position[j] = position[j] + sum_position[j - 1];
}
}

/**
 * build_sorted_array - Build the sorted array using sum_position
 *
 * @arr: The original array
 * @size: Size of the array
 * @sum_position: Array storing cumulative sum
 * @sorted: Array to store the sorted array
 *
 */

void build_sorted_array(int *arr, size_t size, int *sum_position, int *sorted)
{
size_t i = 0;

while (i < size) /* Get the sorted array */
{
	sum_position[arr[i]] -= 1;
	sorted[sum_position[arr[i]]] = arr[i];
	i++;
}
}

/**
 * counting_sort - Sorts an array using the counting sort algorithm
 *
 * @arr: Initial array
 * @size: Size of the array
 *
 */

void counting_sort(int *arr, size_t size)
{
int max_value = 0, *position, *sum_position, *sorted;
size_t i;

if (size < 2)
	return;

for (i = 0; i < size; i++)
{
	if (arr[i] > max_value)
		max_value = arr[i];
}
position = malloc(sizeof(int) * (max_value + 1));
if (!position)
	return;
initialize_array(position, max_value + 1);

sum_position = malloc(sizeof(int) * (max_value + 1));
if (!sum_position)
{
	free(position);
}
initialize_array(sum_position, max_value + 1);
count_occurrences(arr, size, position);
calculate_cumulative_sum(position, max_value + 1, sum_position);
print_array(sum_position, max_value + 1);
sorted = malloc(sizeof(int) * size);
if (!sorted)
{
	free(position);
	free(sum_position);
}
initialize_array(sorted, size);
build_sorted_array(arr, size, sum_position, sorted);
for (i = 0; i < size; i++)
	arr[i] = sorted[i];
free(position);
free(sum_position);
free(sorted);
}
