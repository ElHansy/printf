#include "main.h"

/**
 * _printing_unsign - print unsigned int
 * @args: argument pointer
 * @opt: the parameters options
 * Return: bytes printed
 */

int _printing_unsign(va_list args, fmt_opt_t *opt)

{
	unsigned long l;

	if (opt->L)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (opt->H)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	opt->u = 1;

	return (_printing_num(conv(l, 10, CONV_UNSIGN, opt), opt));
}


/**
 * _printing_hex - prints lowercase unsigned hex number
 * @args: the argument pointer
 * @opt: the parameters options
 * Return: bytes printed
 */

int _printing_hex(va_list args, fmt_opt_t *opt)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (opt->L)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (opt->H)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = conv(l, 16, CONV_UNSIGN | CONV_LOWER, opt);

	if (opt->hash && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	opt->u = 1;
	return (c += _printing_num(str, opt));
}

/**
 * _printing_HEX - print uppercase unsigned hex numbers
 * @args: the argument pointer
 * @opt: the parameters options
 * Return: bytes printed
 */

int _printing_HEX(va_list args, fmt_opt_t *opt)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (opt->L)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (opt->H)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = conv(l, 16, CONV_UNSIGN, opt);

	if (opt->hash && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	opt->u = 1;
	return (c += _printing_num(str, opt));
}
/**
 * _printing_bin - print unsigned binary number
 * @args: the argument pointer
 * @opt: the parameters options
 * Return: bytes printed
 */

int _printing_bin(va_list args, fmt_opt_t *opt)
{
	unsigned int n = va_arg(args, unsigned int);
	char *str = conv(n, 2, CONV_UNSIGN, opt);
	int c = 0;

	if (opt->hash && n)
		*--str = '0';
	opt->u = 1;

	return (c += _printing_num(str, opt));
}

/**
 * _printing_oct - prints unsigned octal numbers
 * @args: the argument pointer
 * @opt: the parameters options
 * Return: bytes printed
 */

int _printing_oct(va_list args, fmt_opt_t *opt)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (opt->L)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (opt->H)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	str = conv(l, 8, CONV_UNSIGN, opt);

	if (opt->hash && l)
		*--str = '0';
	opt->u = 1;

	return (c += _printing_num(str, opt));
}
