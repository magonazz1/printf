#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - function that produces output according to a format
 *
 * @format: function parameter
 *
 * @...: variable number of arguments
 *
 * Return: Always 0 (success)
 */
int _printf(const char *format, ...)
{
	int len;
	va_list args;

	va_start(args, format);
	len = vprintf(format, args);
	va_end(args);

	return (len);
}
