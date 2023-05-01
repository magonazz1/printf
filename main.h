#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct fmt - Format specifier and its associated handler function
 *
 * @fmt: format specifier character
 *
 * @fn: function pointer for handling the format
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * fmt_t - the typedef for struct fmt
 *
 * @fmt: format specifier character
 *
 * @fn: function pointer for handling the format.
 */
typedef struct fmt fmt_t;


int _printf(const char *format, ...);
int handle_print(const char *fmt,
		int *i, va_list list, char buffer[], int flags,
		int width, int precision, int size);

/* _PRINTF FUNCTION SUPPORT PROTOTYPES */
int is_printable(char);
int append_hexa_code(char ascii_code, char buffer[], int x);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

/* {width}  _PRINTF FUNCTION PROTOTYPE */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char store, char extra, int store_start);
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int dx, char bff[], int flags, int width, int precision,
	int length, char store, char extra);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_unsgnd(int is_negative, int ind,
		char buffer[], int flags, int width, int precision, int size);

/* {chars and int} _PRINTF FUNCTION PROTOTYPES */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* {numbers} _PRINTF FUNCTION PROTOTYPES */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types,
		char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size);

/* {non-printable characters} _PRINTF FUNCTION PROTOTYPE */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* {memory address} _PRINTF FUNCTION PROTOTYPE */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* {other specifiers} _PRINTF FUNCTION PROTOTYPE */
int get_width(const char *format, int *i, va_list list);
int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);


/* {strings} _PRINTF FUNCTION PROTOTYPE */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* _PRINTF FUNCTION FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* _PRINTF FUNCTION SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * file - name : "main.h"
 *
 * Colaborators: Martin M & Orlando Gama
 *
 * Description: Pair Programming >> Printf project
 */

#endif /* MAIN_H */
