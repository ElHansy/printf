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
	unsigned long n = number;
	(void)opt;

	if (!(flags & CONV_UNSIGN) && number < 0)
	{
		n = -number;
		sign = '-';

	}
	arr = flags & CONV_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &Buff[49];
	*p = '\0';

	do	{
		*--p = arr[n % base];
		n /= base;
	} while (n != 0);

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
	int negative = (!opt->u && *str == '-');

	if (!opt->preci && *str == '0' && !str[1])
		str = "";
	if (negative)
	{
		str++;
		i--;
	}
	if (opt->preci != UINT_MAX)
		while (i++ < opt->preci)
			*--str = '0';
	if (negative)
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
	unsigned int n = 0, negative, negative2, i = STRlen(str);
	char pad_char = ' ';

	if (opt->zero && !opt->minus)
		pad_char = '0';
	negative = negative2 = (!opt->u && *str == '-');
	if (negative && i < opt->w && pad_char == '0' && !opt->minus)
		str++;
	else
		negative = 0;
	if ((opt->plus && !negative2) ||
		(!opt->plus && opt->space && !negative2))
		i++;
	if (negative && pad_char == '0')
		n += c_putchar('-');
	if (opt->plus && !negative2 && pad_char == '0' && !opt->u)
		n += c_putchar('+');
	else if (!opt->plus && opt->space && !negative2 &&
		!opt->u && opt->zero)
		n += c_putchar(' ');
	while (i++ < opt->w)
		n += c_putchar(pad_char);
	if (negative && pad_char == ' ')
		n += c_putchar('-');
	if (opt->plus && !negative2 && pad_char == ' ' && !opt->u)
		n += c_putchar('+');
	else if (!opt->plus && opt->space && !negative2 &&
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
	unsigned int n = 0, negative, negative2, i = STRlen(str);
	char pad_char = ' ';

	if (opt->zero && !opt->minus)
		pad_char = '0';
	negative = negative2 = (!opt->u && *str == '-');
	if (negative && i < opt->w && pad_char == '0' && !opt->minus)
		str++;
	else
		negative = 0;

	if (opt->plus && !negative2 && !opt->u)
		n += c_putchar('+'), i++;
	else if (opt->space && !negative2 && !opt->u)
		n += c_putchar(' '), i++;
	n += c_puts(str);
	while (i++ < opt->w)
		n += c_putchar(pad_char);
	return (n);
}
