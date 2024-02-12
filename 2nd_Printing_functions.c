#include <main.h>


/**
 * print_integer - Converts and prints a formatted integer.
 * @args: Variable arguments list.
 * @options: Format options.
 *
 * Return: Number of characters printed or -1 on failure.
 */

int print_integer(va_list args, format_options_t *options)
{
	long num = va_arg(args, int);
	char *str = convert_to_string(num, 10, 0, options);

	if (!str)
		return (-1);
	return (print_formatted_number(str, options));
}

/**
 * print_unsigned_integer - Converts and prints a formatted unsigned integer.
 * @args: Variable arguments list.
 * @options: Format options.
 *
 * Return: Number of characters printed or -1 on failure.
 */

int print_unsigned_integer(va_list args, format_options_t *options)
{
	unsigned int num = va_arg(args, unsigned int);
	char *str = convert_to_string(num, 10, CONVERT_UNSIGNED, options);

	if (!str)
		return (-1);
	return (print_formatted_number(str, options));
}

/**
 * print_memory_address - Converts and prints a formatted memory address.
 * @args: Variable arguments list.
 * @options: Format options.
 *
 * Return: Number of characters printed or -1 on failure.
 */

int print_memory_address(va_list args, format_options_t *options)
{
	void *address = va_arg(args, void *);
	char *str = convert_to_string((unsigned long)address, 16,
			CONVERT_UNSIGNED, options);

	if (!str)
		return (-1);
	options->use_hashtag_flag = 1;
	return (print_formatted_number(str, options));
}

/**
 * print_percent - Prints a percent character.
 * @args: Variable arguments list (unused).
 * @options: Format options (unused).
 *
 * Return: Always returns the character count (1), as there is no failure.
 */

int print_percent(va_list args, format_options_t *options)
{
	(void)args;
	(void)options;
	return (put_char('%'));
}

/**
 * print_formatted_number - Prints a formatted number.
 * @str: The number as a string.
 * @options: Format options.
 *
 * Return: Number of characters printed.
 */

int print_formatted_number(char *str, format_options_t *options)
{
	int len = string_length(str), num_digits = (options->precision > len) ?
		options->precision : len,
		total_width = (options->field_width > num_digits) ?
			options->field_width : num_digits,
		printed_chars = 0;

	if (!options->use_minus_flag)
		printed_chars += print_range(" ", NULL, NULL);
	printed_chars += (options->use_plus_flag) ? put_char('+') :
						(options->use_space_flag) ? put_char(' ') : 0;
	printed_chars += (options->use_hashtag_flag && str[0] != '0') ?
						put_char('0') + put_char('x') : 0;
	printed_chars += print_right_shifted_number(str, options);
	if (options->use_minus_flag)
		printed_chars += print_range(NULL, " ", NULL);

	return (printed_chars);
}

