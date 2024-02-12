#include <main.h>

/**
 * print_hexadecimal - Prints a hexadecimal number.
 * @args: Variable args list.
 * @options: Format options.
 *
 * Return: (Number of chars printed).
 */

int print_hexadecimal(va_list args, format_options_t *options)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert_to_string(num, 16, 0, options);

	if (!str)
		return (-1);
	return (print_formatted_number(str, options));
}

/**
 * print_HEXadecimal - Prints a hexadecimal number in uppercase.
 * @args: Variable args list.
 * @options: Format options.
 *
 * Return: (Number of chars printed).
 */

int print_HEXadecimal(va_list args, format_options_t *options)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert_to_string(num, 16, CONVERT_LOWERCASE, options);

	if (!str)
		return (-1);
	return (print_formatted_number(str, options));
}

/**
 * print_binary_number - Prints a binary number.
 * @args: Variable args list.
 * @options: Format options.
 *
 * Return: (Number of chars printed).
 */

int print_binary_number(va_list args, format_options_t *options)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert_to_string(num, 2, 0, options);

	if (!str)
		return (-1);
	return (print_formatted_number(str, options));
}

/**
 * print_octal_number - Prints an octal number.
 * @args: Variable args list.
 * @options: Format options.
 *
 * Return: (Number of chars printed).
 */

int print_octal_number(va_list args, format_options_t *options)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert_to_string(num, 8, 0, options);

	if (!str)
		return (-1);
	return (print_formatted_number(str, options));
}

