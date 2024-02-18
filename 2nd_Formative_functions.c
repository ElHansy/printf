#include "main.h"

/**
 * is_digit - checks if a character is a digit
 * @c: character to check
 *
 * Return: 1 if it's a digit, 0 otherwise
 */
int is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * string_length - calculates the length of a string
 * @s: string
 *
 * Return: length of the string
 */
int string_length(char *s)
{
	int len = 0;

	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @fo: format options structure
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, format_options_t *fo)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)fo;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @args: variable argument list
 * @fo: format options structure
 *
 * Return: bytes printed
 */
int print_unsigned(va_list my_args, format_options_t *fo)
{
	unsigned long l;

	if (fo->use_l_modifier)
		l = va_arg(args, unsigned long);
	else if (fo->use_h_modifier)
		l = (unsigned short int)va_arg(my_args, unsigned int);
	else
		l = (unsigned int)va_arg(my_args, unsigned int);

	fo->is_unsigned int = 1;
	return (print_formatted_number(convert(l, 10,
					CONVERT_UNSIGNED, fo), fo));
}

/**
 * print_memory_address - prints memory address
 * @args: variable argument list
 * @fo: format options structure
 *
 * Return: bytes printed
 */
int print_memory_address(va_list my_args, format_options_t *fo)
{
	unsigned long int n = va_arg(my_args, unsigned long int);
	char *str;

	if (!n)
		return (put_string("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, fo);
	*--str = 'x';
	*--str = '0';
	return (print_formatted_number(str, fo));
}

