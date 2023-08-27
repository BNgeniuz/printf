#include "main.h"

/**
 * get_sze - prints size to cast arg
 * @format: inputt str
 * @i: input of arg
 *
 * Return: Precisely.
 */
int get_sze(const char *format, int *i)
{
	int blurr_l = *i + 1;
	int size = 0;

	if (format[blurr_l] == 'l')
		size = S_LONG;
	else if (format[blurr_l] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = blurr_l - 1;
	else
		*i = blurr_l;

	return (size);
}
