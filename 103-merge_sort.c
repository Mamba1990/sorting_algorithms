#include "sort.h"

void mergeSubarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void mergeSortRcursive(int *_subarr, int *_buff, size_t _front, size_t _back);
void merge_sort(int *array, size_t size);

/**
 * mergeSubarr - Sorts a subarray of ints
 * @_subarr: subarray of an array of ints to be sorted.
 * @_buff: buffer to store subarray.
 * @_front: the array's front index.
 * @_mid: the array'middle index.
 * @_back: the array's back index.
 */
void mergeSubarr(int *_subarr, int *_buff, size_t _front, size_t _mid,
		size_t _back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(_subarr + _front, _mid - _front);

	printf("[right]: ");
	print_array(_subarr + _mid, _back - _mid);

	for (i = _front, j = _mid; i < _mid && j < _back; k++)
		_buff[k] = (_subarr[i] < _subarr[j]) ? _subarr[i++] : _subarr[j++];
	for (; i < _mid; i++)
		_buff[k++] = _subarr[i];
	for (; j < _back; j++)
		_buff[k++] = _subarr[j];
	for (i = _front, k = 0; i < _back; i++)
		_subarr[i] = _buff[k++];

	printf("[Done]: ");
	print_array(_subarr + _front, _back - _front);
}

/**
 * mergeSortRecursive - to merge sort algorithm through recursion.
 * @_subarr: subarray of an array of ints to be sorted.
 * @_buff: to store the sorted result.
 * @_front: the subarray's front index.
 * @_back: the subarray's back index.
 */
void mergeSortRecursive(int *_subarr, int *_buff, size_t _front, size_t _back)
{
	size_t _mid;

	if (_back - _front > 1)
	{
		_mid = _front + (_back - _front) / 2;
		mergeSortRecursive(_subarr, _buff, _front, _mid);
		mergeSortRecursive(_subarr, _buff, _mid, _back);
		mergeSubarr(_subarr, _buff, _front, _mid, _back);
	}
}

/**
 * merge_sort - Sorts array of ints in ASC order
 * @array: An array of ints.
 * @size: the array's size.
 *
 * Description: sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *_buff;

	if (array == NULL || size < 2)
		return;

	_buff = malloc(sizeof(int) * size);
	if (_buff == NULL)
		return;

	mergeSortRecursive(array, _buff, 0, size);

	free(_buff);
}
