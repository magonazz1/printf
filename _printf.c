#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_integer - prints an integer to the standard output stream
*
* @n: the integer to print
*
* Return: the number of characters printed
*/
int print_integer(int n)
{
        int count = 0;

        if (n == 0)
        {
                putchar('0');
                count++;
        }
        else if (n < 0)
        {
                putchar('-');
                count++;
                n = -n;
        }
        if (n / 10)
        {
                count = count + print_integer(n / 10);
        }
        putchar(n % 10 + '0');
        count++;
        return (count);
}

/**
* print_binary - prints an unsigned integer in binary format
*
* @n: the unsigned integer to print
*
* Return: the number of characters printed
*/
int print_binary(unsigned int n)
{
        int count = 0;

        if (n > 1)
        {
                        count = count + print_binary(n >> 1);
        }
        count = count + putchar((n & 1) + '0');
        return (count);
}
/**
* _printf - prints a formatted string to the standard output stream
*
* @format: a pointer to a string containing zero or more format specifiers
*
* Return: the number of characters printed
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
				count += strlen(s);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				count = + print_integer(num);
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'b')
			{
				unsigned int n = va_arg(args, unsigned int);

				count = count + print_binary(n);
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
