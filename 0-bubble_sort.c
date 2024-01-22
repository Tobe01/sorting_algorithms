#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order.
 * @array: array of integers to sort.
 * @size: size of the array.
 * Return: void
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				swap_ints(array + i, array + i + 1);
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}

