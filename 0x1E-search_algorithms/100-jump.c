#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array using jump search
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, prev, i;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	prev = 0;

	/* Jump ahead in steps */
	while (array[(step < size ? step : size - 1)] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev = step;
		step += sqrt(size);
		if (prev >= size)
			return (-1);
	}

	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	printf("Value found between indexes [%lu] and [%lu]\n", prev, step);

	/* Linear search in the block */
	for (i = prev; i <= (step < size ? step : size - 1); i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}

