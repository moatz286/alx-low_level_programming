#include "search_algos.h"

/**
 * interpolation_search - searches using interpolation search algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (array == NULL || size == 0)
		return (-1);

	low = 0;
	high = size - 1;

	while (low <= high)
	{
		pos = low + (((double)(high - low) /
			(array[high] - array[low])) * (value - array[low]));

		if (pos >= size)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);
		}

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	return (-1);
}

