#include "main.h"

/**
 * print_range - Prints chars in [start, stop), excluding 'except'.
 * @start: Starting char.
 * @stop: Stopping char.
 * @except: Char to exclude.
 *
 * Return: (Number of chars printed).
 */

int print_range(char *start, char *stop, char *except)
{
	char c;
	int count = 0;

	while ((c = *start++))
	{
		if (c == *except)
			continue;

		if (c == *stop)
			break;

		count += put_char(c);
	}

	return (count);
}

/**
 * print_reversed - Prints a reversed string.
 * @args: Variable args list.
 * @options: Format options (unused).
 *
 * Return: (Number of chars printed).
 */

int print_reversed(va_list args, format_options_t *options)
{
	char *str = va_arg(args, char *);
	int len = string_length(str);
	int printed_chars = 0;

	while (--len >= 0)
		printed_chars += put_char(str[len]);

	return (printed_chars);
}

/**
 * print_rot13_encoded - Prints a string encoded with ROT13.
 * @args: Variable args list.
 * @options: Format options (unused).
 *
 * Return: (Number of chars printed).
 */

int print_rot13_encoded(va_list args, format_options_t *options)
{
	char *str = va_arg(args, char *);
	int count = 0;

	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			count += put_char((*str - 'A' + 13) % 26 + ((*str >= 'a') ? 'a' : 'A'));
		else
			count += put_char(*str);

		str++;
	}

	return (count);
}

/**
 * print_right_shifted_number - Prints right-shifted number with spaces.
 * @str: The number as a string.
 * @options: Format options.
 *
 * Return: (Number of chars printed).
 */

int print_right_shifted_number(char *str, format_options_t *options)
{
	int printed_chars = 0;
	int len = string_length(str);

	while (options->field_width-- > len)
		printed_chars += put_char(' ');

	printed_chars += put_range(NULL, str, NULL);

	return (printed_chars);
}

/**
 * print_left_shifted_number - Prints left-shifted number with spaces.
 * @str: The number as a string.
 * @options: Format options.
 *
 * Return: (Number of chars printed).
 */

int print_left_shifted_number(char *str, format_options_t *options)
{
	int printed_chars = put_range(str, NULL, NULL);

	while (options->field_width-- > string_length(str))
		printed_chars += put_char(' ');

	return (printed_chars);
}

