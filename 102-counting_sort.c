#include "sort.h"

/**
 * getMax - returns the max value in an array of ints.
 * @arr:  array of ints.
 * @s: array's size.
 *
 * Return: maximum int in the array.
 */
int getMax(int *arr, int s)
{
	int maxi, j;

	for (maxi = arr[0], j = 1; j < s; j++)
	{
		if (arr[j] > maxi)
			maxi = arr[j];
	}

	return (maxi);
}

/**
 * counting_sort - Sorts array of ints in ASC order
 * @array: integers' array.
 * @size: The array's size.
 *
 * Description: Displays the counting array.
 */
void counting_sort(int *array, size_t size)
{
	int *ct, *_sorted, maxi, j;

	if (array == NULL || size < 2)
		return;

	_sorted = malloc(sizeof(int) * size);
	if (_sorted == NULL)
		return;
	maxi = getMax(array, size);
	ct = malloc(sizeof(int) * (maxi + 1));
	if (ct == NULL)
	{
		free(_sorted);
		return;
	}

	for (j = 0; j < (maxi + 1); j++)
		ct[j] = 0;
	for (j = 0; j < (int)size; j++)
		ct[array[j]] += 1;
	for (j = 0; j < (maxi + 1); j++)
		ct[j] += ct[j - 1];
	print_array(ct, maxi + 1);

	for (j = 0; j < (int)size; j++)
	{
		_sorted[ct[array[j]] - 1] = array[j];
		ct[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = _sorted[j];

	free(_sorted);
	free(ct);
}
