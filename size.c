#include "main.h"

/**
 * get_size - function that calculates size to cast the args
 *
 * @i: args to print
 *
 * @format: args format
 *
 * Return: the calculated size
 */
int get_size(const char *format, int *i)
{
	int current_i = *i + 1, size = 0;

	if (format[current_i] == 'l')
	{
		size = S_LONG;
	}
	else if (format[current_i] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*i = current_i - 1;
	}
	else
	{
		*i = current_i;
	}
	return (size);
}
