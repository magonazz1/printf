#include "main.h"

/**
 * handle_write_char - function that prints a string
 *
 * @size: Size specifier
 *
 * @width: get width.
 *
 * @c: char types.
 *
 * @buffer: Buffer
 *
 * @flags: flags
 *
 * @precision: precision
 *
 * Return: string
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = 0;
	char store = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		store = '0';

	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer[BUFF_SIZE - x - 2] = store;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - x - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - function that prints a string
 *
 * @is_negative: .....
 *
 * @ind: .....
 *
 * @buffer: Buffer
 *
 * @flags: flags
 *
 * @width: width
 *
 * @precision: precision
 *
 * @size: Size
 *
 * Return: chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char store = ' ', extra = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		store = '0';
	if (is_negative)
		extra = '-';
	else if (flags & F_PLUS)
		extra = '+';
	else if (flags & F_SPACE)
		extra = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		len, store, extra));
}

/**
 * write_num - function that Writes number using a bufffer
 *
 * @dx: .....
 *
 * @buffer: Buffer
 *
 * @flags: Flags
 *
 * @width: width
 *
 * @precision: Precision
 *
 * @length: length
 *
 * @store: store
 *
 * @extra: Extra
 *
 * Return: Number of printed chars.
 */
int write_num(int dx, char buffer[], int flags, int width, int precision,
	int length, char store, char extra)
{
	int x, store_start = 1;

	if (precision == 0 && dx == BUFF_SIZE -	2 && buffer[dx] == '0' && width == 0)
		return (0);
	if (precision == 0 && dx == BUFF_SIZE - 2 && buffer[dx] == '0')
		buffer[dx] = store = ' ';
	if (precision > 0 && precision < length)
		store = ' ';
	while (precision > length)
		buffer[--dx] = '0', length++;
	if (extra != 0)
		length++;
	if (width > length)
	{
		for (x = 1; x < width - length + 1; x++)
			buffer[x] = store;
		buffer[x] = '\0';
		if (flags & F_MINUS && store == ' ')
		{
			if (extra)
				buffer[--dx] = extra;
			return (write(1, &buffer[dx], length) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & F_MINUS) && store == ' ')
		{
			if (extra)
				buffer[--dx] = extra;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[dx], length));
		}
		else if (!(flags & F_MINUS) && store == '0')
		{
			if (extra)
				buffer[--store_start] = extra;
			return (write(1, &buffer[store_start], x - store_start) +
				write(1, &buffer[dx], length - (1 - store_start)));
		}
	}
	if (extra)
		buffer[--dx] = extra;
	return (write(1, &buffer[dx], length));
}

/**
 * write_unsgnd - function that prints unsigned number
 *
 * @is_negative: negative
 *
 * @ind: .....
 *
 * @buffer: buffer
 *
 * @flags: Flags
 *
 * @width: Width
 *
 * @precision: Precision
 *
 * @size: Size
 *
 * Return: always 0 (success)
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, x = 0;
	char store = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		store = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		store = '0';

	if (width > length)
	{
		for (x = 0; x < width - length; x++)
			buffer[x] = store;

		buffer[x] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], x));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - function that Writes a memory address
 *
 * @buffer: buffer
 *
 * @ind: .....
 *
 * @length: Length
 *
 * @width: Width
 *
 * @flags: Flags
 *
 * @store: store
 *
 * @extra: extra
 *
 * @store_start: store_start
 *
 * Return: Always 0 (Success)
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char store, char extra, int store_start)
{
	int x;

	if (width > length)
	{
		for (x = 3; x < width - length + 3; x++)
			buffer[x] = store;
		buffer[x] = '\0';
		if (flags & F_MINUS && store == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra)
				buffer[--ind] = extra;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], x - 3));
		}
		else if (!(flags & F_MINUS) && store == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra)
				buffer[--ind] = extra;
			return (write(1, &buffer[3], x - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && store == '0')
		{
			if (extra)
				buffer[--store_start] = extra;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[store_start], x - store_start) +
				write(1, &buffer[ind], length - (1 - store_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra)
		buffer[--ind] = extra;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
