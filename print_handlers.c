#include "main.h"

/**
 * handle_print - function that prints an argument based on its type
 *
 * @fmt: format
 *
 * @list: list of args
 *
 * @ind: index
 *
 * @buffer: Buffer
 *
 * @flags: flags
 *
 * @width: width.
 *
 * @precision: precision
 *
 * @size: size
 *
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int x, len = 0, chars = -1;
	fmt_t frmt_typ[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (x = 0; frmt_typ[x].fmt != '\0'; x++)
	{
		if (fmt[*ind] == frmt_typ[x].fmt)
			return (frmt_typ[x].fn(list, buffer, flags, width, precision, size));
	}
	if (frmt_typ[x].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len = len + write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
		{
			len = len + write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			{
				--(*ind);
			}
			if (fmt[*ind] == ' ')
			{
				--(*ind);
			}
			return (1);
		}
		len = len + write(1, &fmt[*ind], 1);
		return (len);
	}
	return (chars);
}
