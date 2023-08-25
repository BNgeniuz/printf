#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function to printf
 * @format: type of format to use
 *
 * Return: 0 (prints xters)
 */

int _printf(const char *format, ...)
{
	int l, prints = 0, prints_chr = 0;
	int flags, width, precision, size, buff_ers = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (l = 0; format && format[l] != '\0'; l++)
	{
		if (format[l] != '%')
		{
			buffer[buff_ers++] = format[l];
			if (buff_ers == BUFF_SIZE)
				print_buffer(buffer, &buff_ers);
			/* write(1, &format[i], 1);*/
			prints_chr++;
		}
		else
		{
			print_buffer(buffer, &buff_ers);
			flags = get_flags(format, &l);
			width = get_width(format, &l, list);
			precision = get_precision(format, &l, list);
			size = get_size(format, &l);
			++l;
			prints = handle_print(format, &l, list, buffer,
				flags, width, precision, size);
			if (prints == -1)
				return (-1);
			prints_chr += prints;
		}
	}

	print_buffer(buffer, &buff_ers);

	va_end(list);

	return (prints_chr);
}

/**
 * print_buffer - prints existed buffer contents
 * @buffer: xter arrays
 * @buff_ers: input xter
 */

void print_buffer(char buffer[], int *buff_ers)
{
	if (*buff_ers > 0)
		write(1, &buffer[0], *buff_ers);

	*buff_ers = 0;
}

