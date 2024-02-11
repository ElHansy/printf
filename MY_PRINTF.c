#include "main.h"

/**
 * _printf - prints formatted output
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list args;
	char *p, *start;
	format_options_t fo = DEFAULT_FORMAT_OPTIONS;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		initialize_options(&fo, args);
		if (*p != '%')
		{
			sum += put_char(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &fo))
			p++;
		p = get_width(p, &fo, args);
		p = get_precision_field(p, &fo, args);
		if (get_modifier(p, &fo))
			p++;
		if (!get_format_specifier(p))
			sum += print_range(start, p, NULL);
		else
			sum += get_print_function(p, args, &fo);
	}
	put_char(BUFFER_FLUSH);
	va_end(args);
	return (sum);
}

