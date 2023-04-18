#include "main.h"

/**
 * set_bit - to sets value of a bit to 1 at a given index
 * @num: decimal no. passed by pointer
 * @idx: index position to change, starting from 0
 * Return: 1 if it worked, -1 if error
 */
int set_bit(unsigned long int *num, unsigned int idx)
{
	unsigned long int power;

	if (idx > 64)
		return (-1);

	for (power = 1; idx > 0; idx--, power *= 2)
		;
	*num += power;

	return (1);
}

