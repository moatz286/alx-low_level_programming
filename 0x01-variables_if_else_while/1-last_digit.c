#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/**
 * main - Entry point
 * Description: 'print positive or negative value'
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 5)
	{
		printf("Last digit of %d is  and is greater than 5\n", n);
	}
	else if (n < 5 && n > 0)
	{
		printf("Last digit of %d is  and is less than 6 and not 0\n", n);
	}
	else
	{
		printf("Last digit of %d is  and is 0\n", n);
	}
	return (0);
}
