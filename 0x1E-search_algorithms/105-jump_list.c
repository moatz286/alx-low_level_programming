#include "search_algos.h"

/**
 * jump_forward - Jumps forward in the list by step size
 * @list: starting node
 * @step: number of steps to jump
 *
 * Return: pointer to node after jumping
 */
listint_t *jump_forward(listint_t *list, size_t step)
{
	size_t i = 0;

	while (list->next && i < step)
	{
		list = list->next;
		i++;
	}
	return (list);
}

/**
 * linear_search_list - Performs linear search in a linked list range
 * @start: starting node
 * @end: ending node
 * @value: value to search for
 *
 * Return: pointer to node with value, or NULL if not found
 */
listint_t *linear_search_list(listint_t *start, listint_t *end, int value)
{
	while (start && start->index <= end->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}
	return (NULL);
}

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
	size_t step;
	listint_t *current, *prev;

	if (list == NULL || size == 0)
		return (NULL);

	step = sqrt(size);
	current = list;
	prev = NULL;

	while (current && current->n < value)
	{
		prev = current;
		current = jump_forward(current, step);
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);
		if (current->next == NULL)
			break;
	}

	if (prev == NULL)
	{
		printf("Value found between indexes [0] and [%lu]\n",
		       current->index);
		return (linear_search_list(list, current, value));
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, current->index);
	return (linear_search_list(prev, current, value));
}

