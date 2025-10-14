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
	listint_t *current, *prev, *temp;

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

		printf("Value checked at index [%lu] = [%d]\n",
			current->index, current->n);

		if (current->n >= value)
			break;
	}

	/* Determine the search range */
	if (prev == NULL)
	{
		/* Value is smaller than first element */
		printf("Value found between indexes [0] and [%lu]\n", step);
		temp = list;
	}
	else
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);
		temp = prev;
	}

	/* Linear search in the block */
	while (temp && temp->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			temp->index, temp->n);
		if (temp->n == value)
			return (temp);
		temp = temp->next;
	}

	return (NULL);
}
