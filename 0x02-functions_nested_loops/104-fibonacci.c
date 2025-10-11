#include <stdio.h>

int main(void)
{
    int count;
    unsigned long a_h = 0, a_l = 1;  /* Split F1 into high and low parts */
    unsigned long b_h = 0, b_l = 2;  /* Split F2 into high and low parts */
    unsigned long c_h, c_l, carry;
    
    printf("1, 2");
    
    for (count = 3; count <= 98; count++)
    {
        printf(", ");
        
        /* Add the two numbers: c = a + b */
        carry = 0;
        c_l = a_l + b_l;
        if (c_l < a_l || c_l < b_l)  /* Check for overflow */
            carry = 1;
        
        c_h = a_h + b_h + carry;
        
        /* Handle the case where we need to print a very large number */
        if (c_h > 0)
        {
            printf("%lu", c_h);
            /* Print lower part with leading zeros if needed */
            unsigned long temp = c_l;
            int digits = 0;
            while (temp > 0)
            {
                digits++;
                temp /= 10;
            }
            /* Add leading zeros */
            for (int i = 0; i < 18 - digits; i++)
                printf("0");
            printf("%lu", c_l);
        }
        else
        {
            printf("%lu", c_l);
        }
        
        /* Update for next iteration */
        a_h = b_h;
        a_l = b_l;
        b_h = c_h;
        b_l = c_l;
    }
    
    printf("\n");
    return (0);
}

