#include "main.h"

/**
 * initialize_options - initializes format options structure
 * @fo: format options structure
 * @args: variable argument list
 */

void initialize_options(format_options_t *fo, va_list my_args)
{
	*fo = DEFAULT_FORMAT_OPTIONS;
	(void)my_args;
}

/**
 * get_width - extracts the field width from the format string
 * @s: format string
 * @fo: format options structure
 * @args: variable argument list
 *
 * Return: pointer to the next position in the format string
 */
char *get_width(char *s, format_options_t *fo, va_list my_args)
{
	if (*s == '*')
	{
		fo->field_width = va_arg(my_args, int);
		return (s + 1);
	}
	else
	{
		fo->field_width = strtol(s, &s, 10);
		return (s);
	}
}

/**
 * get_flag - extracts flags from the format string
 * @s: format string
 * @fo: format options structure
 *
 * Return: 1 if a flag is found, 0 otherwise
 */
int get_flag(char *s, format_options_t *fo)
{
	int flag = 0;

	while (*s == '+' || *s == ' ' || *s == '#' || *s == '0' || *s == '-')
	{
		switch (*s)
		{
			case '+':
				fo->use_plus_flag = 1;
				break;
			case ' ':
				fo->use_space_flag = 1;
				break;
			case '#':
				fo->use_hashtag_flag = 1;
				break;
			case '0':
				fo->use_zero_flag = 1;
				break;
			case '-':
				fo->use_minus_flag = 1;
				break;
		}
		s++;
		flag = 1;
	}
	return (flag);
}

/**
 * get_modifier - extracts length modifiers from the format string
 * @s: format string
 * @fo: format options structure
 *
 * Return: 1 if a modifier is found, 0 otherwise
 */
int get_modifier(char *s, format_options_t *fo)
{
	if (*s == 'h')
	{
		fo->use_h_modifier = 1;
		if (*(s + 1) == 'h')
		{
			fo->use_h_modifier = 2;
			return (1);
		}
	}
	else if (*s == 'l')
	{
		fo->use_l_modifier = 1;
		if (*(s + 1) == 'l')
		{
			fo->use_l_modifier = 2;
			return (1);
		}
	}
	return (0);
}

/**
 * get_precision_field - extracts precision field from the format string
 * @p: format string
 * @fo: format options structure
 * @args: variable argument list
 *
 * Return: pointer to the next position in the format string
 */
char *get_precision_field(char *p, format_options_t *fo, va_list my_args)
{
	if (*p == '.')
	{
		p++;
		if (*p == '*')
		{
			fo->precision = va_arg(my_args, int);
			return (p + 1);
		}
		else
		{
			fo->precision = strtol(p, &p, 10);
			return (p);
		}
	}
	return (p);
}
