#include "main.h"

/**
 * is_printable - function that checks a char if it is printable
 *
 * @c: character to check
 *
 * Return: 1 if c is printable,if not, return 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}

/**
 * append_hexa_code - function to append ASCCI code
 *
 * @buffer: buffer
 *
 * @x: starting point
 *
 * @ascii_code: the ASSCI code
 *
 * Return: Always 3 (success)
 */
int append_hexa_code(char ascii_code, char buffer[], int x)
{
	char map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}

	buffer[x++] = '\\';
	buffer[x++] = 'x';
	buffer[x++] = map[ascii_code / 16];
	buffer[x] = map[ascii_code % 16];

	return (3);
}

/**
 * is_digit - function that checks if char is digit
 *
 * @c: character to check
 *
 * Return: 1 if c is a digit, if not, return 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - function for casting number
 *
 * @num: casted number
 *
 * @size: size
 *
 * Return: the value of the number after casting
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
 * convert_size_unsgnd - function for casting number to specified size
 *
 * @num: casted number
 *
 * @size: size
 *
 * Return: the value of the number after casting
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
