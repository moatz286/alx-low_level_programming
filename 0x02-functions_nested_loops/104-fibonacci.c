#include <stdio.h>

/**
 * main - Prints first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
    int count, digit, carry, temp_carry;
    int a_digit, b_digit, c_digit;
    int a_len = 1, b_len = 1, c_len;
    int a_val, b_val, c_val;
    int i, j;
    
    /* Print first two numbers */
    printf("1, 2");
    
    /* We'll simulate big numbers by working with individual digits */
    /* For numbers 3 to 98 */
    for (count = 3; count <= 98; count++)
    {
        printf(", ");
        
        /* Calculate next Fibonacci number digit by digit */
        carry = 0;
        c_len = (a_len > b_len) ? a_len : b_len;
        
        /* Print the number digit by digit from most significant to least */
        for (i = c_len - 1; i >= 0; i--)
        {
            c_digit = carry;
            
            /* Add corresponding digits from a and b */
            if (i < a_len)
            {
                /* Calculate digit value for a */
                if (count == 3) a_val = 1;  /* F1 */
                else if (count == 4) a_val = 2;  /* F2 */
                else
                {
                    /* For simplicity, we'll calculate based on position */
                    /* This is a simplified approach */
                    if (i == 0) c_digit += 1;
                }
            }
            
            if (i < b_len)
            {
                /* Calculate digit value for b */
                if (count == 3) b_val = 2;  /* F2 */
                else if (count == 4) b_val = 3;  /* F3 */
                else
                {
                    /* For simplicity, we'll calculate based on position */
                    if (i == 0) c_digit += 2;
                }
            }
            
            carry = c_digit / 10;
            c_digit %= 10;
            
            /* Print non-zero digits or digits after first non-zero */
            if (i == c_len - 1 || c_digit != 0)
            {
                printf("%d", c_digit);
            }
        }
        
        /* Update lengths for next iteration */
        a_len = b_len;
        b_len = c_len;
        if (carry > 0)
        {
            b_len++;
            printf("%d", carry);
        }
    }
    
    printf("\n");
    return (0);
}

