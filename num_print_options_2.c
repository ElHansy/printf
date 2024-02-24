#include "main.h"

/**
 * conv - converter function from int to null terminated string
 * @number: number
 * @base: base
 * @flags: argument flags
 * @opt: paramater options
 * Return: string
 */

char *conv(long int number, int base, int flags, fmt_opt_t *opt)
{
	static char *arr;
	static char Buff[50];
	char sign = 0;
	char *p;
	unsigned long i = number;
	(void)opt;

	if (!(flags & CONV_UNSIGN) && number < 0)
	{
		i = -number;
		sign = '-';

	}
	arr = flags & CONV_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &Buff[49];
	*p = '\0';

	do	{
		*--p = arr[i % base];
		i /= base;
	} while (i != 0);

	if (sign)
		*--p = sign;
	return (p);
}


/**
 *  _printing_num - printvnumber with format options
 * @str: the base number as a string
 * @opt: the parameter struct
 * Return: chars printed
 */

int _printing_num(char *str, fmt_opt_t *opt)
{
	unsigned int i = STRlen(str);
	int neg = (!opt->u && *str == '-');

	if (!opt->preci && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (opt->preci != UINT_MAX)
		while (i++ < opt->preci)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!opt->minus)
		return (_printing_num_Rshift(str, opt));
	else
		return (_printing_num_Lshift(str, opt));
}

/**
 * _printing_num_Rshift - print number with format options
 * @str: the base number as a string
 * @opt: the parameter options
 * Return: chars printed
 */

int _printing_num_Rshift(char *str, fmt_opt_t *opt)
{
	unsigned int n = 0, neg, neg2, i = STRlen(str);
	char pad_char = ' ';

	if (opt->zero && !opt->minus)
		pad_char = '0';
	neg = neg2 = (!opt->u && *str == '-');
	if (neg && i < opt->w && pad_char == '0' && !opt->minus)
		str++;
	else
		neg = 0;
	if ((opt->plus && !neg2) ||
		(!opt->plus && opt->space && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += c_putchar('-');
	if (opt->plus && !neg2 && pad_char == '0' && !opt->u)
		n += c_putchar('+');
	else if (!opt->plus && opt->space && !neg2 &&
		!opt->u && opt->zero)
		n += c_putchar(' ');
	while (i++ < opt->w)
		n += c_putchar(pad_char);
	if (neg && pad_char == ' ')
		n += c_putchar('-');
	if (opt->plus && !neg2 && pad_char == ' ' && !opt->u)
		n += c_putchar('+');
	else if (!opt->plus && opt->space && !neg2 &&
		!opt->u && !opt->zero)
		n += c_putchar(' ');
	n += c_puts(str);
	return (n);
}

/**
 *  _printing_num_Lshift - prints a number with format options
 * @str: the base number as a string
 * @opt: the parameter struct
 * Return: chars printed
 */

int _printing_num_Lshift(char *str, fmt_opt_t *opt)
{
	unsigned int n = 0, neg, neg2, i = STRlen(str);
	char pad_char = ' ';

	if (opt->zero && !opt->minus)
		pad_char = '0';
	neg = neg2 = (!opt->u && *str == '-');
	if (neg && i < opt->w && pad_char == '0' && !opt->minus)
		str++;
	else
		neg = 0;

	if (opt->plus && !neg2 && !opt->u)
		n += c_putchar('+'), i++;
	else if (opt->space && !neg2 && !opt->u)
		n += c_putchar(' '), i++;
	n += c_puts(str);
	while (i++ < opt->w)
		n += c_putchar(pad_char);
	return (n);
}
