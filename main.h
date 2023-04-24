#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

/**
 * struct specifiers - Struct specifiers
 *
 * @spec: The operator
 *
 * @f: The function associated
 */
typedef struct specifiers
{
	char *spec;
	int (*f)(va_list);
} spec_t;

#endif /* MAIN_H */

