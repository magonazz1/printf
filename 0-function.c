#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - prints a formatted string
 *
 * @format: format string
 *
 * @...: variable number of arguments
 *
 * Return: count of characters printed
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
			switch (*format)
			{
				case 'c':
					count = count + printf("%c", va_arg(args, int));
					break;
				case 's':
					count = count + printf("%s", va_arg(args, char*));
					break;
				case '%':
					count = count + printf("%%");
					break;
				default:

					break;
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
