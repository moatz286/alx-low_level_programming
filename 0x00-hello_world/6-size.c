#include<stdio.h>

/**
 * main - Entry point
 * Description: 'print datatype'
 * Return: Always 0 (Success)
 */
 
int main(void) {
    int intType;
    long int longIntType;
    float floatType;
    double doubleType;
    char charType;

    
    printf("Size of a char: %zu byte\n", sizeof(charType));
    printf("Size of int: %zu bytes\n", sizeof(intType));
    printf("Size of a long int: %zu\n", sizeof(longIntType));
    printf("Size of a long long int: %zu bytes\n", sizeof(doubleType));
    printf("Size of a float: %zu bytes\n", sizeof(floatType));
    
    return (0);
}
