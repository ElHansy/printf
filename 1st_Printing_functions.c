#include "main.h"

/**
 * put_string - prints a string to stdout
 * @str: the string to print
 *
 * Return: number of characters printed
 */
int put_string(char *str)
{
	char *first = str;

	while (*str)
		put_char(*str++);
	return (str - first);
}

/**
 * put_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int put_char(int c)
{
	static int i;
	static char buf[OUTPUT_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= OUTPUT_BUFFER_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		buf[i++] = c;
	return (1);
}


/**
 * print_custom_string - prints a custom string
 * @args: the va_list
 * @options: the format options
 *
 * Return: number of characters printed
 */

int print_custom_string(va_list args, format_options_t *options)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = NULL_STRING;

	return (put_string(str));
}

/**
 * print_text - prints a string of text
 * @args: the va_list
 * @options: the format options
 *
 * Return: number of characters printed
 */

int print_text(va_list args, format_options_t *options)
{
	char *text = va_arg(args, char *);

	if (!text)
		text = NULL_STRING;

	return (put_string(text));
}

/**
 * print_char - prints a character
 * @args: the va_list
 * @options: the format options
 *
 * Return: number of characters printed
 */

int print_char(va_list args, format_options_t *options)
{
	char c = va_arg(args, int);

	return (put_char(c));
}

