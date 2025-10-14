#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list using jump search
 * @list: pointer to the head of the list
 * @size: number of nodes in list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located, or NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, i;
	listint_t *current, *prev;

	if (list == NULL || size == 0)
		return (NULL);

	step = sqrt(size);
	current = list;
	prev = NULL;

	/* Jump ahead in steps */
	while (current && current->n < value)
	{
		prev = current;
		for (i = 0; current->next && i < step; i++)
			current = current->next;

		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	if (!current || current->n >= value)
	{
		if (!prev)
			return (NULL);

		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev->index, current ? current->index : size - 1);

		/* Linear search in the block */
		current = prev;
		while (current && current->n <= value)
		{
			printf("Value checked at index [%lu] = [%d]\n",
				   current->index, current->n);
			if (current->n == value)
				return (current);
			current = current->next;
		}
	}

	return (NULL);
}

