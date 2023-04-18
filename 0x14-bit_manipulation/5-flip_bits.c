#include "main.h"
#include <stdio.h>

/**
 * flip_bits - to flip bits to convert one number to another number
 * @num1: 1st number
 * @num2: 2nd number to convert to
 * Return: number of bits that was needed to flip
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
	unsigned long int diff;
	int bitCount;

	diff = num1 ^ num2;
	bitCount = 0;

	while (diff)
	{
		bitCount++;
		diff &= (diff - 1);
	}

	return (bitCount);
}

