#include <stdio.h>

/**
 * main - Entry point
 * Description: print alpha..
 * Return: Always 0 (Sucess)
 */
int main(void)
{
	char c;

	for (c = 'a' ; c <= 'z' ; c++)
	{
		putchar(c);
	}
	putchar('\n');
	return (0);
}
