#include "sort.h"

/**
 * swapInts - Swaps 2 integers in an array.
 * @n1: 1st integer to swap.
 * @n2: 2nd second integer to swap.
 * Description: swaps to ints
 */
void swapInts(int *n1, int *n2)
{
	int n;

	n = *n1;
	*n1 = *n2;
	*n2 = n;
}

/**
 * bubble_sort - Sorts an array of ints in ASC order.
 * @array: the array of integers to be sorted.
 * @size: The array's size.
 * Description: Displays the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t k, length = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (k = 0; k < length - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				swapInts(array + k, array + k + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		length--;
	}
}
