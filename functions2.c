#include "main.h"

/**
 * print_pointer - value of ptr variable
 * @types: kinds of arg
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec specification
 * @size: size specifiers
 *
 * Return: 0 (pointers)
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, deep = ' ';
	int ers = BUFF_SIZE - 2, len = 2, deep_start = 1; /* length=2, for '0x' */
	unsigned long base_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	base_addrs = (unsigned long)addrs;
	while (base_addrs > 0)
	{
		buffer[ers--] = map_to[base_addrs % 16];
		base_addrs /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		deep = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;
	ers++;
	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ers, len,
				width, flags, deep, extra_c, deep_start));
}
/**
 * print_non_printable - ascii hexa of non printable chrs
 * @types: kind of arg
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec specification
 * @size: size specifiers
 *
 * Return: 0 (non hexa)
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int l = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[l] != '\0')
	{
		if (is_printable(str[l]))
			buffer[l + offset] = str[l];
		else
			offset += append_hexa_code(str[l], buffer, l + offset);
		l++;
	}
	buffer[l + offset] = '\0';
	return (write(1, buffer, l + offset));
}

/**
 * print_reverse - rev str
 * @types: kinds of arg
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec specification
 * @size: size specifiers
 *
 * Return: 0 (reverse print)
 */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int l, read = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (l = 0; str[l]; l++)
		;
	for (l = l - 1; l >= 0; l--)
	{
		char z = str[l];

		write(1, &z, 1);
		read++;
	}
	return (read);
}
/**
 * print_rot13string - str rot13.
 * @types: Lista of arg
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec specification
 * @size: size specifier
 *
 * Return: 0 (rot13)
 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char a;
	char *str;
	unsigned int p, y;
	int read = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (p = 0; str[p]; p++)
	{
		for (y = 0; in[y]; y++)
		{
			if (in[y] == str[p])
			{
				a = out[y];
				write(1, &a, 1);
				read++;
				break;
			}
		}
		if (!in[y])
		{
			a = str[p];
			write(1, &a, 1);
			read++;
		}
	}
	return (read);
}
