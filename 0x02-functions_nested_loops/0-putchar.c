#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *ch = "_putchar\n";

	while (*ch)
	{
		_putchar(*ch);
		ch++;
	}
	return (0);
}
