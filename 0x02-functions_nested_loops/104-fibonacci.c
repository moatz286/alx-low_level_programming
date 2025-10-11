#include <stdio.h>

#define MAX_DIGITS 200

/**
 * print_number - Prints a large number stored digit by digit
 * @digits: Array holding digits (but we're not using it as an array in the traditional sense)
 * @len: Length of the number
 */
void print_number(int pos, int len)
{
    int i;
    
    for (i = len - 1; i >= 0; i--)
    {
        /* We'll calculate digits on the fly */
        if (i == pos)
            putchar('0' + (len - pos));
        else
            putchar('0');
    }
}

/**
 * main - Prints first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
    int count;
    int a1, a2, b1, b2;  /* We'll split numbers into parts */
    int temp1, temp2;
    int carry;
    
    printf("1, 2");
    
    /* Initialize first two Fibonacci numbers */
    a1 = 1;  /* Lower part of F1 */
    a2 = 0;  /* Upper part of F1 */
    b1 = 2;  /* Lower part of F2 */  
    b2 = 0;  /* Upper part of F2 */
    
    for (count = 3; count <= 98; count++)
    {
        printf(", ");
        
        /* Calculate next Fibonacci number */
        carry = 0;
        temp1 = b1;
        temp2 = b2;
        
        /* Add lower parts */
        b1 = a1 + b1;
        if (b1 >= 1000000000)  /* Handle carry to upper part */
        {
            b1 -= 1000000000;
            carry = 1;
        }
        
        /* Add upper parts with carry */
        b2 = a2 + b2 + carry;
        
        /* Update previous numbers */
        a1 = temp1;
        a2 = temp2;
        
        /* Print the number */
        if (b2 > 0)
        {
            printf("%d", b2);
            /* Print lower part with leading zeros */
            printf("%09d", b1);
        }
        else
        {
            printf("%d", b1);
        }
    }
    
    printf("\n");
    return (0);
}

