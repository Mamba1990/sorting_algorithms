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
 * selection_sort - Sorts an array of integers in ASCorder
 *                 by using the selection sort algorithm.
 * @array: integers' array.
 * @size: array's.
 *
 * Description: displayss the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *_min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		_min = array + j;
		for (k = j + 1; k < size; k++)
			_min = (array[k] < *_min) ? (array + k) : _min;

		if ((array + j) != _min)
		{
			swapInts(array + j, _min);
			print_array(array, size);
		}
	}
}
