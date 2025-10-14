#include "search_algos.h"

/**
 * binary_search_recursive - helper function for binary search
 * @array: pointer to the array
 * @left: left index
 * @right: right index
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid, i;

	if (left > right)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");

	mid = (left + right) / 2;

	if (array[mid] == value)
		return (mid);
	else if (array[mid] < value)
		return (binary_search_recursive(array, mid + 1, right, value));
	else
		return (binary_search_recursive(array, left, mid - 1, value));
}

/**
 * exponential_search - searches using exponential search algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, min;

	if (array == NULL || size == 0)
		return (-1);

	/* Find the range where value might be */
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	/* Determine the range to search */
	min = (bound < size) ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, min);

	/* Perform binary search in the found range */
	return (binary_search_recursive(array, bound / 2, min, value));
}

