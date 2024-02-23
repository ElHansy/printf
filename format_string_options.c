#include "main.h"

/**
 * get_print_func - finds the assosiated function
 * @s: pointed format string
 * @args: argument pointer
 * @opt: the parameters options
 * Return: count of bytes printed
 */

int get_print_func(char *s, va_list args, fmt_opt_t *opt)
{
	int (*f)(va_list, fmt_opt_t *) = get_speci(s);

	if (f)
		return (f(args, opt));
	return (0);
}

/**
 * get_f - finds matched flag function
 * @s: the format string
 * @opt: the parameters options
 * Return: count of bytes printed
 */

int get_f(char *s, fmt_opt_t *opt)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = opt->plus = 1;
			break;
		case ' ':
			i = opt->space = 1;
			break;
		case '#':
			i = opt->hash = 1;
			break;
		case '-':
			i = opt->minus = 1;
			break;
		case '0':
			i = opt->zero = 1;
			break;
	}
	return (i);
}

/**
 * get_m - finds the modifier matched function
 * @s: format string
 * @opt: the parameters struct
 * Return: count of bytes printed if true
 */

int get_m(char *s, fmt_opt_t *opt)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = opt->H = 1;
		break;
	case 'l':
		i = opt->L = 1;
		break;
	}
	return (i);
}

/**
 * get_w - get width from the format string
 * @s: format string
 * @opt: the parameters struct
 * @args: the argument pointer
 * Return: pointer
 */

char *get_w(char *s, fmt_opt_t *opt, va_list args)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(args, int);
		s++;
	}
	else
	{
		while (isDigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	opt->w = d;
	return (s);
}

/**
 * get_preci - get precision if available in format string
 * @p: format string
 * @opt: the parameters struct
 * @args: the argument pointer
 * Return: new pointer
 */

char *get_preci(char *p, fmt_opt_t *opt, va_list args)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(args, int);
		p++;
	}
	else
	{
		while (isDigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	opt->preci = d;
	return (p);
}
