#include "main.h"

/**
 * get_format_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_format_precision(const char *format, int *i, va_list list)
{
	int current_index = *i + 1;
	int precision = -1;

	if (format[current_index] != '.')
		return (precision);

	precision = 0;

	current_index += 1;
	while (format[current_index] != '\0')
	{
		if (is_digit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;

		current_index++;
	}

	*i = current_index - 1;

	return (precision);
}

