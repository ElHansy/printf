#include "main.h"

/**
 *  _printing_char - prints character
 * @args: arguments pointer
 * @opt: the parameters options
 * Return: number count of chars printed
 */

int _printing_char(va_list args, fmt_opt_t *opt)
{
	char pad_char = ' ';
	unsigned int pad_counter = 1, count = 0, character = va_arg(args, int);

	/*minus sign used to align the character to the left*/

	if (opt->minus)
		count += c_putchar(character);

	while (pad_counter < opt->w) /*print space pad after last char*/
	{
		count += c_putchar(pad_char);
		pad_counter++;
	}

	if (!opt->minus) /*if not true print char as it is*/
		count += c_putchar(character);
	return (count);
}

/**
 * _printing_int - prints integer
 * @args: arguments pointer
 * @opt: the parameters options
 * Return: number count of printed int
 */

int _printing_int(va_list args, fmt_opt_t *opt)
{
	long n;

	if (opt->L)
		n = va_arg(args, long);
	else if (opt->H)
		n = (short int)va_arg(args, int);
	else
		n = (int)va_arg(args, int);

	return (_printing_num(conv(n, 10, 0, opt), opt));
}

/**
 * _printing_string - prints pointed string
 * @args: arguments pointer
 * @opt: the parameters options
 * Return: number chars printed
 */

int _printing_string(va_list args, fmt_opt_t *opt)
{
	char *string = va_arg(args, char *), pad_char = ' ';
	unsigned int pad_counter = 0, count = 0, i = 0, j;

	(void)opt;

	switch ((int)(!string))
		case 1:
			string = NULL_STRING;

	j = pad_counter = STRlen(string);
	if (opt->preci < pad_counter)
		j = pad_counter = opt->preci;

	if (opt->minus)
	{
		if (opt->preci != UINT_MAX)
			for (i = 0; i < pad_counter; i++)
				count += c_putchar(*string++);
		else
			count += c_puts(string);
	}
	while (j++ < opt->w)
		count += c_putchar(pad_char);
	if (!opt->minus)
	{
		if (opt->preci != UINT_MAX)
			for (i = 0; i < pad_counter; i++)
				count += c_putchar(*string++);
		else
			count += c_puts(string);
	}
	return (count);
}

/**
 * _printing_pcent - prints percent char
 * @args: arguments pointer
 * @opt: the parameters options
 * Return: count %
 */
int _printing_pcent(va_list args, fmt_opt_t *opt)
{
	(void)args;
	(void)opt;
	return (c_putchar('%'));
}

/**
 * _printing_FMTspeci - print customized format specifier
 * @args: arguments pointer
 * @opt: the parameters options
 * Return: count customized format specifier
 */

int _printing_FMTspeci(va_list args, fmt_opt_t *opt)
{
	char *str = va_arg(args, char *);
	char *hex;
	int count = 0;

	if (!str)
		return (c_puts(NULL_STRING));

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			count += c_putchar('\\');
			count += c_putchar('x');
			hex = conv(*str, 16, 0, opt);
			if (!hex[1])
				count += c_putchar('0');
			count += c_puts(hex);
		}
		else
		{
			count += c_putchar(*str);
		}
	}
	return (count);
}
