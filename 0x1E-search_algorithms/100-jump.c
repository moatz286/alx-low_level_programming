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
	while (prev < size && array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += step;
	}

	/* Go back one step for the linear search range */
	i = (prev >= step) ? prev - step : 0;
	prev = (prev < size) ? prev : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", i, prev);

	/* Linear search in the block */
	for (; i <= prev && i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}

