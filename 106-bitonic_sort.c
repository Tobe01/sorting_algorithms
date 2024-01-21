#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */

void bitonic_sort_seq(int *array, size_t size, int dir, size_t size_total)
{
	size_t k = size / 2;

	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, size_total,
	dir == 1 ? "UP" : "DOWN");
	print_array(array, size);
	bitonic_sort_rec(array, k, 1, size_total);
	bitonic_sort_rec(array + k, k, 0, size_total);
	bitonic_merge(array, size, dir, size_total);
	printf("Result [%lu/%lu] (%s):\n", size, size_total,
	dir == 1 ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_merge - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 * @dir: direction of the sort
 * @size_total: size of the array
*/

void bitonic_merge(int *array, size_t size, int dir, size_t size_total)
{
	size_t k = size / 2, i;

	if (size < 2)
		return;
	for (i = 0; i < k; i++)
		if (dir == (array[i] > array[i + k]))
			swap(&array[i], &array[i + k]);
	bitonic_merge(array, k, dir, size_total);
	bitonic_merge(array + k, k, dir, size_total);
}

