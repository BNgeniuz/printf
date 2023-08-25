#include "main.h"

/**
 * handle_write_char - char print str
 * @c: chr str
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec specifiers
 * @size: array size specifiers
 *
 * Return: 0 (printf char)
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{ /* left and paddind at buffer's right */
	int l = 0;
	char deep = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	deep = '0';

	buffer[l++] = c;
	buffer[l] = '\0';

	if (width > 1)
{
	buffer[BUFF_SIZE - 1] = '\0';
	for (l = 0; l < width - 1; l++)
		buffer[BUFF_SIZE - l - 2] = deep;

	if (flags & F_MINUS)
	return (write(1, &buffer[0], 1) +
	
			write(1, &buffer[BUFF_SIZE - l - 1], width - 1));
	else
	return (write(1, &buffer[BUFF_SIZE - l - 1], width - 1) +
	write(1, &buffer[0], 1));
}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - prints num str
 * @is_negative: kind of arg
 * @ers: chr kind
 * @buffer: array to print buffer
 * @flags: flags activators
 * @width: get width
 * @precision: prec specifiers
 * @size: size specifiers
 *
 * Return: 0 (print num)
 */
int write_number(int is_negative, int ers, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ers - 1;
	char deep = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	deep = '0';
	if (is_negative)
	extra_ch = '-';
	else if (flags & F_PLUS)
	extra_ch = '+';
	else if (flags & F_SPACE)
	extra_ch = ' ';

	return (write_num(ers, buffer, flags, width, precision,
	len, deep, extra_ch));
}

/**
 * write_num - prints numb by using bufffer
 * @ers: buffer index
 * @buffer: buffers
 * @flags: flags
 * @width: width
 * @prec: prec specifiers
 * @len: num of length
 * @deep: padding chr
 * @extra_c: more chr
 *
 * Return: 0 (num prints chas)
 */
int write_num(int ers, char buffer[],
	int flags, int width, int prec,
	int len, char deep, char extra_c)
{
	int l, deep_start = 1;

	if (prec == 0 && ers == BUFF_SIZE - 2 && buffer[ers] == '0' && width == 0)
	return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ers == BUFF_SIZE - 2 && buffer[ers] == '0')
	buffer[ers] = deep = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < len)
	deep = ' ';
	while (prec > len)
	buffer[--ers] = '0', len++;
	if (extra_c != 0)
	len++;
	if (width > len)
{
	for (l = 1; l < width - len + 1; l++)
	buffer[l] = deep;
	buffer[l] = '\0';
	if (flags & F_MINUS && deep == ' ')/* Asign extra char to left of buffer */
	{
	if (extra_c)
	buffer[--ers] = extra_c;
	return (write(1, &buffer[ers], len) + write(1, &buffer[1], l - 1));
}
	else if (!(flags & F_MINUS) && deep == ' ')/* extra char to left of buff */
	{
	if (extra_c)
	buffer[--ers] = extra_c;
return (write(1, &buffer[1], l - 1) + write(1, &buffer[ers], len));
}
	else if (!(flags & F_MINUS) && deep == '0')/* extra char to left of padd */
	{
	if (extra_c)
	buffer[--deep_start] = extra_c;
	return (write(1, &buffer[deep_start], l - deep_start) +
			write(1, &buffer[ers], len - (1 - deep_start)));
}
}
	if (extra_c)
	buffer[--ers] = extra_c;
	return (write(1, &buffer[ers], len));
	}

/**
 * write_unsgnd - unsigned number
 * @is_negative: indicating if a num is negative
 * @ers: input number starts in the buffer
 * @buffer: array of chrs
 * @flags: Flags specifier
 * @width: Width specifier
 * @precision: prec specifier
 * @size: size specifier
 *
 * Return: 0 (written chars)
 */
int write_unsgnd(int is_negative, int ers,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUFF_SIZE - ers - 1, l = 0;
	char deep = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ers == BUFF_SIZE - 2 && buffer[ers] == '0')
	return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < len)
	deep = ' ';

	while (precision > len)
	{
	buffer[--ers] = '0';
	len++;
}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	deep = '0';

	if (width > len)
	{
	for (l = 0; l < width - len; l++)
	buffer[l] = deep;

	buffer[l] = '\0';

	if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
	{
	return (write(1, &buffer[ers], len) + write(1, &buffer[0], l));
}
	else /* Asign extra char to left of padding [padd>buffer]*/
	{
	return (write(1, &buffer[0], l) + write(1, &buffer[ers], len));
}
}

	return (write(1, &buffer[ers], len));
}

/**
 * write_pointer - memory address
 * @buffer: arrays of chrs
 * @ers: input number starts in the buffer
 * @len: Length of num
 * @width: Width specifiers
 * @flags: flags specifiers
 * @deep: representing padding
 * @extra_c: extra char
 * @deep_start: input padding should start
 *
 * Return: 0 (written chr)
 */
int write_pointer(char buffer[], int ers, int len,
		int width, int flags, char deep, char extra_c, int deep_start)
{
	int l;

	if (width > len)
	{
	for (l = 3; l < width - len + 3; l++)
	buffer[l] = deep;
	buffer[l] = '\0';
	if (flags & F_MINUS && deep == ' ')/* Asign extra char to left of buffer */
	{
	buffer[--ers] = 'x';
	buffer[--ers] = '0';
	if (extra_c)
	buffer[--ers] = extra_c;
	return (write(1, &buffer[ers], len) + write(1, &buffer[3], l - 3));
}
	else if (!(flags & F_MINUS) && deep == ' ')/* extra char to left of buffer */
	{
	buffer[--ers] = 'x';
	buffer[--ers] = '0';
	if (extra_c)
		buffer[--ers] = extra_c;
	return (write(1, &buffer[3], l - 3) + write(1, &buffer[ers], len));
}
	else if (!(flags & F_MINUS) && deep == '0')/* extra char to left of padd */
	{
	if (extra_c)
	buffer[--deep_start] = extra_c;
	buffer[1] = '0';
	buffer[2] = 'x';
	return (write(1, &buffer[deep_start], l - deep_start) +
			write(1, &buffer[ers], len - (1 - deep_start) - 2));
}
}
	buffer[--ers] = 'x';
	buffer[--ers] = '0';
	if (extra_c)
	buffer[--ers] = extra_c;
	return (write(1, &buffer[ers], BUFF_SIZE - ers - 1));
}
