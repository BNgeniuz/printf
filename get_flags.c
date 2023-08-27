#include "main.h"

/**
 * get_flags - prints all active flags
 * @format: Formatted string in which argument is printed
 * @i: take the parameter.
 * Return: all Flags.
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int y, blurr_l;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (blurr_l = *i + 1; format[blurr_l] != '\0'; blurr_l++)
	{
		for (y = 0; FLAGS_CH[y] != '\0'; y++)
			if (format[blurr_l] == FLAGS_CH[y])
			{
				flags |= FLAGS_ARR[y];
				break;
			}

		if (FLAGS_CH[y] == 0)
			break;
	}

	*i = blurr_l - 1;

	return (flags);
}
