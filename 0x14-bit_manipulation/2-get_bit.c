#include "main.h"
#include <stdio.h>

/**
 * get_bit - used get the value of a bit at a given index
 * @num: no. to evaluate
 * @idx: index starting from 0, of the bit we want to get
 * Return: Value of bit at index, or -1 if error
 */
int get_bit(unsigned long int num, unsigned int idx)
{
	unsigned long int value;

	if (idx > 64)
		return (-1);

	value = num >> idx;

	return (value & 1);
}

