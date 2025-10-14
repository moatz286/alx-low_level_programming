#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *prev;

	if (list == NULL)
		return (NULL);

	current = list;
	prev = NULL;

	/* Use express lane to jump ahead */
	while (current && current->express && current->n < value)
	{
		prev = current;
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n",
			current->index, current->n);
	}

	if (!current->express && current->n < value)
	{
		/* Reached end of express lane, but value might be in last block */
		prev = current;
		while (current->next)
			current = current->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, current->index);

	/* Linear search in the block */
	current = prev;
	while (current)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			current->index, current->n);
		if (current->n == value)
			return (current);
		if (current->n > value)
			break;
		current = current->next;
	}

	return (NULL);
}

