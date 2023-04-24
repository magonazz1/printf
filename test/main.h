#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct print_func - struct to match format specifier with print function
 *
 * @specifier: format specifier
 *
 * @f: function pointer to corresponding print function
 */
typedef struct print_func
{
	char *specifier;
	int (*f)(va_list);
} print_func_t;

int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_integer(va_list arg);
int print_unsigned_integer(va_list arg);
int print_binary(va_list arg);
int print_octal(va_list arg);
int print_hex(va_list arg);
int print_hex_upper(va_list arg);

#endif /* MAIN_H */

