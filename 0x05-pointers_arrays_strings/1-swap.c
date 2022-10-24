#include "main.h"

/**
 * swap_int - swap the value of two integers.
 *
 * @a: the first int.
 * @b: the second int.
 */
void swap_int(int *a, int *b)
{
	int t;

	t = *a;

	*a = *b;
	*b = t;
}
