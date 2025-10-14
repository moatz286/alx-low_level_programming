#include "search_algos.h"

/**
 * advanced_binary_recursive - recursive helper for advanced binary search
 * @array: pointer to the array
 * @left: left index
 * @right: right index
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
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

	if (left == right)
		return (array[left] == value ? (int)left : -1);

	mid = (left + right) / 2;

	if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, right, value));
	else if (array[mid] > value)
		return (advanced_binary_recursive(array, left, mid, value));
	else
	{
		/* If we found the value, check if it's the first occurrence */
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (advanced_binary_recursive(array, left, mid, value));
	}
}

/**
 * advanced_binary - searches for first occurrence using binary search
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}

