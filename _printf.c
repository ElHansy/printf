#include "main.h"

/**
 * _printf - prints any input
 * @format: pointer to the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	char *p;
	char *begin = NULL;
	va_list args;
	fmt_opt_t opt = OPT_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_opt(&opt, args);

		if (*p != '%')
		{
			count += c_putchar(*p);
			continue;
		}
		p++;

		while (get_f(p, &opt))
			p++;
		p = get_w(p, &opt, args);
		p = get_preci(p, &opt, args);

		if (get_m(p, &opt))
			p++;
		if (!get_speci(p))
			count += _printing_range(begin, p, opt.L || opt.H ? p - 1 : (char *)0);
		else
			count += get_print_func(p, args, &opt);
	}
	c_putchar(BUFFER_FLUSH);
	va_end(args);
	return (count);
}
