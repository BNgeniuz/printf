#include "main.h"

/**
 * ls_printable - Evaluates if chr is printable.
 * @p: Chr to be evaluated.
 *
 * Return: 1 if p is printable, 0 otherwise
 */
int ls_printable(char p)
{
	if (p >= 32 && p < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascii in hexa decimal code to buffer.
 * @buffer: Array of characters.
 * @l: Index at which appending is done.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int l)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa code will always be 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[l++] = '\\';
	buffer[l++] = 'x';

	buffer[l++] = map_to[ascii_code / 16];
	buffer[l] = map_to[ascii_code % 16];

	return (3);
}

/**
 * ls_digit - Verifies if chr is digit.
 * @p: Character to be evaluated
 *
 * Return: 1 if p is a digit, 0 otherwise
 */
int ls_digit(char p)
{
	if (p >= '0' && p <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_base - Shares a base to the specified size
 * @base: Base to be shared.
 * @size: Base indicating type shared.
 *
 * Return: Shared base
 */
long int convert_size_base(long int base, int size)
{
	if (size == S_LONG)
		return (base);
	else if (size == S_SHORT)
		return ((short)base);

	return ((int)base);
}

/**
 * convert_size_unsigned - Shares base to  specified size
 * @base: Base to be shared
 * @size: Base indicatn type shared
 *
 * Return: Shared value of bse
 */
long int convert_size_unsigned(unsigned long int base, int size)
{
	if (size == S_LONG)
		return (base);
	else if (size == S_SHORT)
		return ((unsigned short)base);

	return ((unsigned int)base);
}
