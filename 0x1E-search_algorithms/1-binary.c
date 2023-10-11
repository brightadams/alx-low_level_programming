#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - searches for a value i with binary search algor
 * @array: pointer to array
 * @size: size of array
 * @value: value to find
 * Return: first index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i = 0, l = 0, r = size - 1, m;

	if (!array)
		return (-1);
	while (l <= r)
	{
		printf("Searching in array: ");
		for (i = l; i <= r; i++)
		{
			printf("%d", array[i]);
			if (i < r)
				printf(", ");
			else
				printf("\n");
		}
		m = (l + r) / 2;
		if (array[m] < value)
			l = m + 1;
		else if (array[m] > value)
			r = m - 1;
		else
			return (m);
	}
	return (-1);
}
