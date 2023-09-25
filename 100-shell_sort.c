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
 * shell_sort - Sorts an array of ints in ASC
 * @array: integers' array.
 * @size: array's size
 *
 * Description: it's Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gp, j, k;

	if (array == NULL || size < 2)
		return;

	for (gp = 1; gp < (size / 3);)
		gp = gp * 3 + 1;

	for (; gp >= 1; gp /= 3)
	{
		for (j = gp; j < size; j++)
		{
			k = j;
			while (k >= gp && array[k - gp] > array[k])
			{
				swapInts(array + k, array + (k - gp));
				k -= gp;
			}
		}
		print_array(array, size);
	}
}
