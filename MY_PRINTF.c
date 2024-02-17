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
	char *p, *start;
	format_options_t fo = DEFAULT_FORMAT_OPTIONS;

	va_start(my_args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		initialize_options(&fo, my_args);
		if (*p != '%')
		{
			sum += put_char(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &fo))
		{
			p++;
		}
		p = get_width(p, &fo, my_args);
		p = get_precision_field(p, &fo, my_args);
		if (get_modifier(p, &fo))
			p++;
		if (!get_format_specifier(p))
			sum += print_range(start, p, NULL);
		else
			sum += get_print_function(p, my_args, &fo);
	}
	put_char(BUFFER_FLUSH);
	va_end(my_args);
	return (sum);
}

