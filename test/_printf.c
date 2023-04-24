#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
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
