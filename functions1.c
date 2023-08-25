#include "main.h"

/**
 * print_unsigned - unsigned num
 * @types: kind of arg
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec  specifiers
 * @size: size specifiers
 *
 * Return: 0 (unsigned  print)
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int l = BUFF_SIZE - 2;
	unsigned long int base = va_arg(types, unsigned long int);

	base = convert_size_unsgnd(base, size);

	if (base == 0)
		buffer[l--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (base > 0)
	{
		buffer[l--] = (base % 10) + '0';
		base /= 10;
	}
	l++;
	return (write_unsgnd(0, 1, buffer, flags, width, precision, size));
}

/**
 * print_octal - unsigned number in octal
 * @types: kind of arg
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec  specifiers
 * @size: size specifiers
 *
 * Return: 0 (octal  print)
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int l = BUFF_SIZE - 2;
	unsigned long int base = va_arg(types, unsigned long int);
	unsigned long int init_base = base;

	UNUSED(width);
	base = convert_size_unsgnd(base, size);

	if (base == 0)
		buffer[l--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (base > 0)
	{
		buffer[l--] = (base % 8) + '0';
		base /= 8;
	}
	if (flags & F_HASH && init_base != 0)
		buffer[l--] = '0';
	l++;
	return (write_unsgnd(0, 1, buffer, flags, width, precision, size));
}


/**
 * print_hexadecimal - unsigned numb in hexadecimal
 * @types: kind of arg
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec  specifiers
 * @size: size specifiers
 *
 * Return: 0 (unsigned  print)
 */

int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - unsigned numb in upper hexadecimal
 * @types: kind of arg
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec  specifiers
 * @size: size specifiers
 *
 * Return: 0 (unsigned  print)
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
/**
 * print_hexa - hexadecimal numb in lower or upper
 * @map_to: array of values to map the number to
 * @flag_ch: Calculates active flags
 * @size: Size specification
 * @types: kind of arg
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec  specifiers
 * @size: size specifiers
 *
 * Return: 0 (unsigned  print)
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int l = BUFF_SIZE - 2;
	unsigned long int base = va_arg(types, unsigned long int);
	unsigned long int init_base = base;

	UNUSED(width);
	base = convert_size_unsgnd(base, size);

	if (base == 0)
		buffer[l--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (base > 0)
	{
		buffer[l--] = map_to[base % 16];
		base /= 16;
	}
	if (flags & F_HASH && init_base != 0)
	{
		buffer[l--] = flag_ch;
		buffer[l--] = '0';
	}
	l++;
	return (write_unsgnd(0, l, buffer, flags, width, precision, size));
}
