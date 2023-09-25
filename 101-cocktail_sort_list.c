#include "sort.h"

void swapNodeAhead(listint_t **_list, listint_t **_tail, listint_t **_shaker);
void swapNodeBehind(listint_t **_list, listint_t **_tail, listint_t **_shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swapNodeAhead - Swaps a node doubly-linked list
 * @_list: An address of the head of a doubly-linked list of integers.
 * @_tail: An address of doubly-linked list's tail.
 * @_shaker: An address for the current swapping no
 */
void swapNodeAhead(listint_t **_list, listint_t **_tail, listint_t **_shaker)
{
	listint_t *t = (*_shaker)->next;

	if ((*_shaker)->prev != NULL)
		(*_shaker)->prev->next = t;
	else
		*_list = t;
	t->prev = (*_shaker)->prev;
	(*_shaker)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *_shaker;
	else
		*_tail = *_shaker;
	(*_shaker)->prev = t;
	t->next = *_shaker;
	*_shaker = t;
}

/**
 * swapNodeBehind - Swaps a node in  doubly-linked
 * @_list: A address to the head of a doubly-linked list of ints.
 * @_tail: An address to the tail of the doubly-linked list.
 * @_shaker: An address to the current swapping node
 */
void swapNodeBehind(listint_t **_list, listint_t **_tail, listint_t **_shaker)
{
	listint_t *t = (*_shaker)->prev;

	if ((*_shaker)->next != NULL)
		(*_shaker)->next->prev = t;
	else
		*_tail = t;
	t->next = (*_shaker)->next;
	(*_shaker)->prev = t->prev;
	if (t->prev != NULL)
		t->prev->next = *_shaker;
	else
		*_list = *_shaker;
	(*_shaker)->next = t;
	t->prev = *_shaker;
	*_shaker = t;
}

/**
 * cocktail_sort_list - Sorts a doubly-linked list of ints in ASC order
 * @list: A pointer to the head of a listint_t doubly-linked list.
 * Description: cocktail sort list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *_tail, *_shaker;
	bool shakenNotStirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (_tail = *list; _tail->next != NULL;)
		_tail = _tail->next;

	while (shakenNotStirred == false)
	{
		shakenNotStirred = true;
		for (_shaker = *list; _shaker != _tail; _shaker = _shaker->next)
		{
			if (_shaker->n > _shaker->next->n)
			{
				swapNodeAhead(list, &_tail, &_shaker);
				print_list((const listint_t *)*list);
				shakenNotStirred = false;
			}
		}
		for (_shaker = _shaker->prev; _shaker != *list;
				_shaker = _shaker->prev)
		{
			if (_shaker->n < _shaker->prev->n)
			{
				swapNodeBehind(list, &_tail, &_shaker);
				print_list((const listint_t *)*list);
				shakenNotStirred = false;
			}
		}
	}
}
