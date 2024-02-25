#include "main.h"

/**
 * get_speci - finds the format specifier function
 * @s: format string
 * Return: count number of bytes printed
 */

int(*get_speci(char *s))(va_list args, fmt_opt_t *opt)
{
	Speci_t specifier_array[] = {
		{"c", _printing_char},
		{"d", _printing_int},
		{"i", _printing_int},
		{"s", _printing_string},
		{"%", _printing_pcent},
		{"b", _printing_bin},
		{"o", _printing_oct},
		{"u", _printing_unsign},
		{"x", _printing_hex},
		{"X", _printing_HEX},
		{"p", _printing_addr},
		{"S", _printing_FMTspeci},
		{"r", _printing_r},
		{"R", _printing_R},
		{NULL, NULL}
	};
	int i = 0;

	while (specifier_array[i].sp)
	{
		if (*s == specifier_array[i].sp[0])
		{
			return (specifier_array[i].f);
		}
		i++;
	}
	return (NULL);
}
