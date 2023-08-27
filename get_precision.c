#include "main.h"

/**
 * get_precision - Calculate precisely.
 * @format: Format string where argument prints
 * @i: List of arguments printed.
 * @list: list of all arguments.
 *
 * Return: Precisely.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int blurr_l = *i + 1;
	int prec = -1;

	if (format[blurr_l] != '.')
		return (prec);

	prec = 0;

	for (blurr_l += 1; format[blurr_l] != '\0'; blurr_l++)
	{
		if (is_digit(format[blurr_l]))
		{
			prec *= 10;
			prec += format[blurr_l] - '0';
		}
		else if (format[blurr_l] == '*')
		{
			blurr_l++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = blurr_l - 1;

	return (prec);

}
