#include "main.h"

/**
 * _printf - prints all input data
 * @format: the format string
 * Return: number of bytes that printed on std output
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list my_args;
	char *ptr, *start;
	format_options_t fo = DEFAULT_FORMAT_OPTIONS;

	va_start(my_args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = (char *)format; *ptr; ptr++)
	{
		init_opt(&fo, my_args);
		if (*ptr != '%')
		{
			sum += put_char(*ptr);
			continue;
		}
		start = ptr;
		ptr++;
		while (get_flag(ptr, &fo))
		{
			ptr++;
		}
		ptr = get_width(ptr, &fo, my_args);
		ptr = get_precision_field(ptr, &fo, my_args);
		if (get_modifier(ptr, &fo))
			ptr++;
		if (!get_format_specifier(ptr))
			sum += print_range(start, ptr, NULL);
		else
			sum += get_print_function(ptr, my_args, &fo);
	}
	put_char(BUFFER_FLUSH);
	va_end(my_args);
	return (sum);
}

