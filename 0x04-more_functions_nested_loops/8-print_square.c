#include "main.h"

/**
 * print_square - print a square to a given size.
 * @size: size square to print
 *
 */
void print_square(int size)
{
	int v, h;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (v = size ; v > 0 ; v--)
	{
		for (h = size ; h > 0 ; h--)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
