#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_SPACE 4
#define F_HASH 8
#define F_ZERO 16

/* Size specifiers */
#define S_DEFAULT 0
#define S_SHORT 1
#define S_LONG 2

/**
 * struct fmt - Structures operartion
 * @fmt: The format
 * @fn: The functions
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

/* Function prototypes */
int _printf(const char *format, ...);
int print_handler(const char *fmt, int *ind, va_list list,
		char buffer[], int flags, int width, int precision, int size);
/* Handle functions */
int handle_char(char c, char buffer[], int flags,
		int width, int precision, int size);
int handle_num(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int handle_number(int ind, char buffer[], int flags,
		int width, int prec, int length, char padd, char extra_c);
int handle_unsignd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int handle_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);

int print_char(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list specifiers, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int print_non_printable(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);

int print_reverse(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);

int print_rot13string(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);

int print_pointer(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size);
int get_format_flags(const char *format, int *i);
int get_format_width(const char *format, int *i, va_list list);
int get_format_precision(const char *format, int *i, va_list list);
int get_format_size(const char *format, int *i);


int is_printable(char c);
int append_hexa_code(char Ascii, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
void print_buffer(char buffer[], int *buff_ind);

#endif

