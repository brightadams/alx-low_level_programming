#include "main.h"
#include <stdio.h>

/**
 * print_binary - to print binary representation of a number
 * @num: decimal number to print as binary
 */
void print_binary(unsigned long int num)
{
    unsigned long int temp;
    int shift_count;

    if (num == 0)
    {
        printf("0");
        return;
    }

    for (temp = num, shift_count = 0; (temp >>= 1) > 0; shift_count++)
        ;

    for (; shift_count >= 0; shift_count--)
    {
        if ((num >> shift_count) & 1)
            printf("1");
        else
            printf("0");
    }
}

