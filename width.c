#include "main.h"

/**
 * get_width - function that computes width
 *
 * @list: args list
 *
 * @format: format
 *
 * @i: args
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int current_i, wide = 0;

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			wide = wide * 10;
			wide = wide + format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			currenti++;
			wide = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = current_i - 1;
	return (wide);
}
