#include "main.h"

/**
 * get_format_flags - Calculates active flags from the format string
 * @format: Formatted string in which to find the flags
 * @i: Current index position in the format string
 * Return: Flags calculated based on format string
 */
int get_format_flags(const char *format, int *i)
{
	int j, current_index;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	current_index = *i + 1;
	while (format[current_index] != '\0')
	{
		j = 0;
		while (FLAGS_CH[j] != '\0')
		{
			if (format[current_index] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
			j++;
		}

		if (FLAGS_CH[j] == 0)
			break;

		current_index++;
	}

	*i = current_index - 1;

	return flags;
}
