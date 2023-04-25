#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_integer - helper function to print an integer
 *
 * @n: the integer to print
 *
 * Return: the number of characters printed
 */
int print_integer(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_integer(num / 10);
	}

	putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * _printf - function that produces output according to a format
 *
 * @format: string format to be printed
 *
 * @...: variable number of arguments
 *
 * Return: The printed string
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char) va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				fputs(s, stdout);
				count = count + strlen(s);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int n = va_arg(args, int);
		
				count = count + print_integer(n);
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
