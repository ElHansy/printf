#include "main.h"

/**
 * c_puts - print string input
 * @str: string to be printed
 * Return: bytes printed
 */

int c_puts(char *str)
{
	char *a = str;

	while (*str)
		c_putchar(*str++);
	return (str - a);
}

/**
 * c_putchar - write c to standard output
 * @c: The character to print
 * Return: On success 1 or -1 if error (by write function)
 */

int c_putchar(int c)
{
	static int i;
	static char Buffer_index[OUT_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || i >= OUT_BUFFER_SIZE)
	{
		write(1, Buffer_index, i);
		i = 0;
	}
	if (c != BUFFER_FLUSH)
		c = Buffer_index[i++];
	return (1);
}

/**
 * isDigit - to check whether the pointed character is digit
 * @c: the character to be check
 * Return: 1 if digit, 0 if no
 */

int isDigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * STRlen - returns length string
 * @s: the pointed string to be check
 * Return: int length
 */

int STRlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
