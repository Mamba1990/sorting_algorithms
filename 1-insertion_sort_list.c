#include "sort.h"

/**
 * swapNodes - Swaps 2 nodes in the doubly-linked list.
 * @head: An address of the head of the doubly-linked list.
 * @n_1: An address to the 1st node to  be swapped.
 * @n_2: The second node to swap.
 */
void swapNodes(listint_t **head, listint_t **n_1, listint_t *n_2)
{
	(*n_1)->next = n_2->next;
	if (n_2->next != NULL)
		n_2->next->prev = *n_1;
	n_2->prev = (*n_1)->prev;
	n_2->next = *n_1;
	if ((*n_1)->prev != NULL)
		(*n_1)->prev->next = n_2;
	else
		*head = n_2;
	(*n_1)->prev = n_2;
	*n_1 = n_2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *it, *insert, *t;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (it = (*list)->next; it != NULL; it = t)
	{
		t = it->next;
		insert = it->prev;
		while (insert != NULL && it->n < insert->n)
		{
			swapNodes(list, &insert, it);
			print_list((const listint_t *)*list);
		}
	}
}
