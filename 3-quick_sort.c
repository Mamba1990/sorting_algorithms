#include "sort.h"

void swapInts(int *n1, int *n2);
int lomutoPartition(int *arr, size_t s, int l, int r);
void lomutoSort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomutoPartition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme.
 * @arr: The integers'.
 * @s: array's size.
 * @l: starting index of the subset to be ordered.
 * @r: The ending index of the subset to be ordered.
 *
 * Return: The index's final partition.
 */
int lomutoPartition(int *arr, size_t s, int l, int r)
{
	int *piv, _above, _below;

	piv = arr + r;
	for (_above = _below = l; _below < r; _below++)
	{
		if (arr[_below] < *piv)
		{
			if (_above < _below)
			{
				swapInts(arr + _below, arr + _above);
				print_array(arr, s);
			}
			_above++;
		}
	}

	if (arr[_above] > *piv)
	{
		swapInts(arr + _above, piv);
		print_array(arr, s);
	}

	return (_above);
}

/**
 * lomutoSort - Implements a quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @s: The size of the array.
 * @l: The starting index of the array partition to order.
 * @r: The ending index of the array partition to order.
 *
 * Description: Lomuto partition scheme.
 */
void lomutoSort(int *arr, size_t s, int l, int r)
{
	int _part;

	if (r - l > 0)
	{
		_part = lomutoPartition(arr, s, l, r);
		lomutoSort(arr, s, l, _part - 1);
		lomutoSort(arr, s, _part + 1, r);
	}
}

/**
 * quick_sort - Sorts an array of inss in ASC
 *              order using the quicksort algorithm.
 * @array: integers' array.
 * @size: array's size.
 *
 * Description: Lomuto partition scheme. Displays
 *              the array after each swap of 2 els.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomutoSort(array, size, 0, size - 1);
}
