#include "main.h"

/**
 * get_width - Calculates width for the printing
 * @format: Format string in which arguments are printed.
 * @i: List of arguments printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int blurr_l;
	int width = 0;

	for (blurr_l = *i + 1; format[blurr_l] != '\0'; blurr_l++)
	{
		if (is_digit(format[blurr_l]))
		{
			width *= 10;
			width += format[blurr_l] - '0';
		}
		else if (format[blurr_l] == '*')
		{
			blurr_l++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = blurr_l - 1;

	return (width);
}
