#include "main.h"

/**
 * _printing_range - prints a range of chars from string beginning
 * @begin: starting point
 * @stop: stopping point
 * @xpt: except address
 * Return: count of bytes printed
 */

int _printing_range(char *begin, char *stop, char *xpt)
{
	int count = 0;

	while (begin <= stop)
	{
		if (begin != xpt)
			count += c_putchar(*begin);
		begin++;
	}
	return (count);
}

/**
 * _printing_r - print string in reverse format
 * @args: string format
 * @opt: the parameters options
 * Return: count of bytes printed
 */

int _printing_r(va_list args, fmt_opt_t *opt)
{
	int ln, count = 0;
	char *str = va_arg(args, char *);
	(void)opt;

	if (str)
	{
		for (ln = 0; *str; str++)
			ln++;
		str--;
		for (; ln > 0; ln--, str--)
			count += c_putchar(*str);
	}
	return (count);
}

/**
 * _printing_R - prints string format in rot13
 * @args: string
 * @opt: the parameters struct
 * Return: count of bytes printed
 */

int _printing_R(va_list args, fmt_opt_t *opt)
{
	int i, guide;
	int count = 0;
	char ar[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(args, char *);
	(void)opt;

	i = 0;
	guide = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			guide = a[i] - 65;
			count += c_putchar(ar[guide]);
		}
		else
			count += c_putchar(a[i]);
		i++;
	}
	return (count);
}

/**
 * _printing_addr - print address
 * @args: argument pointer
 * @opt: the parameters options
 * Return: count of bytes printed
 */

int _printing_addr(va_list args, fmt_opt_t *opt)
{
	unsigned long int a = va_arg(args, unsigned long int);
	char *str;

	if (!a)
		return (c_puts("(nil)"));

	str = conv(a, 16, CONV_UNSIGN | CONV_LOWER, opt);
	*--str = 'x';
	*--str = '0';

	return (_printing_num(str, opt));
}
