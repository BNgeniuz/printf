#include "main.h"
/**
 * handle_print - Prints argmnt on its type.
 * @fmt: Format string in which arguments are printed.
 * @list: List of all arguments printed.
 * @idx: index.
 * @buffer: Buffer handling all print.
 * @flags: Calculates all active flags
 * @width: width used.
 * @precision: Precision specification used.
 * @size: Size specifier used.
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *idx, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int l, unkn_len = 0, prints_chrs = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'y', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (l = 0; fmt_types[l].fmt != '\0'; l++)
		if (fmt[*idx] == fmt_types[l].fmt)
			return (fmt_types[l].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[l].fmt == '\0')
	{
		if (fmt[*idx] == '\0')
			return (-1);
		unkn_len += write(1, "%%", 1);
		if (fmt[*idx - 1] == ' ')
			unkn_len += write(1, " ", 1);
		else if (width)
		{
			--(*idx);
			while (fmt[*idx] != ' ' && fmt[*idx] != '%')
				--(*idx);
			if (fmt[*idx] == ' ')
				--(*idx);
			return (1);
		}
		unkn_len += write(1, &fmt[*idx], 1);
		return (unkn_len);
	}
	return (prints_chrs);
}
