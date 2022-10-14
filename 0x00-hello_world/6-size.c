#include<stdio.h>

/**
 * main - Entry point
 * Description: 'print datatype'
 * Return: Always 0 (Success)
 */
 
int main(void) 
{
int intType;
long int longIntType;
float floatType;
double doubleType;
char charType;

    
printf("Size of a char: %zu byte(s)\n", sizeof(charType));
printf("Size of an int: %zu byte(s)\n", sizeof(intType));
printf("Size of a long int: %zu byte(s)\n", sizeof(longIntType));
printf("Size of a long long int: %zu byte(s)\n", sizeof(doubleType));
printf("Size of a float: %zu byte(s)\n", sizeof(floatType));
    
return (0);
}
