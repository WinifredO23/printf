#include "main.h"
/**
 * print_char - Prints a char
 * @specifiers: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(specifiers, int);

	return (handle_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - Prints a string
 * @specifiers: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(specifiers, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "       ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			i = width - length;
			while (i > 0)
			write(1, "\t", 1);
			i--;
			return (width);
		}
		else
		{
			i = width - length;
			while (i > 0)
			write(1, "\t", 1);
			i--;
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
/**
 * print_percent - Prints a percent sign
 * @specifiers: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list specifiers, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(specifiers);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
