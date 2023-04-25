#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
* print_char - prints a character
* 
* @c: character to print
* 
* Return: number of characters printed (always 1)
*/
int print_char(char c)
{
	putchar(c);
	return (1);
}

/**
* print_string - prints a string
* 
* @s: string to print
* 
* Return: number of characters printed
*/
int print_string(char *s)
{
	int i = 0;

	if (s == NULL)
	{
		s = "(null)";
	}
	while (s[i] != '\0')
	{
			putchar(s[i]);
			i++;
	}
	return (i);
}

/**
* print_integer - prints an integer
* 
* @n: integer to print
* 
* Return: number of characters printed
*/
int print_integer(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
			count += print_char('-');
			num = -n;
	}
	else
	{
			num = n;
	}

	if (num / 10)
	{
		count = count + print_integer(num / 10);
	}
	count = count + print_char(num % 10 + '0');

	return (count);
}

/**
* print_unsigned - prints an unsigned integer
* 
* @n: unsigned integer to print
* 
* Return: number of characters printed
*/
int print_unsigned(unsigned n)
{
	int count = 0;

	if (n / 10)
	{
	    count = count + print_unsigned(n / 10);
	}
	count = count + print_char(n % 10 + '0');

	return (count);
}

/**
* print_binary - prints an unsigned int in binary
* 
* @n: unsigned integer to print
* 
* Return: number of characters printed
*/
int print_binary(unsigned int n)
{
	int count = 0;
	int i;
	unsigned int mask = 1 << ((sizeof(unsigned int) * CHAR_BIT) - 1);

	for (i = 0; i < (int)(sizeof(unsigned int) * CHAR_BIT); i++)
	{
		if ((n & mask) == 0)
		{
		    count = count + print_char('0');
		}
		else
		{
		    count = count + print_char('1');
	    }
	    n <<= 1;
	}
	return (count);
}

/**
* print_hex - prints an unsigned int in lowercase hex
* 
* @n: unsigned integer to print
* 
* Return: number of characters printed
*/
int print_hex(unsigned int n)
{
	int count = 0;
	char hex_digits[] = "0123456789abcdef";

	if (n / 16)
	{
		count = count + print_hex(n / 16);
	}
	count = count + print_char(hex_digits[n % 16]);

	return (count);
}

/**
* print_hex_upper - prints an unsigned int in uppercase hex
* 
* @n: unsigned integer to print
* 
* Return: number of characters printed
*/
int print_hex_upper(unsigned int n)
{
	int count = 0;
	char hex_digits[] = "0123456789ABCDEF";

	if (n / 16)
	{
		count += print_hex_upper(n / 16);
	}
	count += print_char(hex_digits[n % 16]);

	return (count);
}

/**
* _printf - prints a formatted string
* 
* @format: format string
* 
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
		    format++;
	        switch (*format)
		    {
				case 'c':
				{
					char c = (char) va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char *);
					fputs(s, stdout);
					count += strlen(s);
					break;
				}
				case 'd':
				case 'i':
				{
					int n = va_arg(args, int);
					count = count + print_integer(n);
					break;
				}
				case 'u':
				{
					unsigned int u = va_arg(args, unsigned int);
					count = count + print_unsigned_int(u, 10);
					break;
				}
				case 'o':
				{
					unsigned int o = va_arg(args, unsigned int);
					count = count + print_unsigned_int(o, 8);
					break;
				}
				case 'x':
				{
					unsigned int x = va_arg(args, unsigned int);
					count = count + print_hex(x, 0);
					break;
				}
				case 'X':
				{
					unsigned int X = va_arg(args, unsigned int);
					count += print_hex(X, 1);
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
				default:
				{
					putchar(*format);
					count++;
					break;
				}
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
