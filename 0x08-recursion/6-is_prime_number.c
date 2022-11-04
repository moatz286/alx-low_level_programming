#include "main.h"

/**
 * is_prime_number - fuction the check if a number is a prime.
 * @n: number to be tested.
 *
 * Return: 1 if a Prime else 0
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_number(n, n - 1));
}

