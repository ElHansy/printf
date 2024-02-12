#include "main.h"

/**
 * initialize_options - initializes format options structure
 * @options: format options structure
 * @args: variable argument list
 */
void initialize_options(format_options_t *options, va_list args)
{
	*options = DEFAULT_FORMAT_OPTIONS;
	options->field_width = va_arg(args, int);
	options->precision = va_arg(args, int);
}

/**
 * get_width - extracts the field width from the format string
 * @s: format string
 * @options: format options structure
 * @args: variable argument list
 *
 * Return: pointer to the next position in the format string
 */
char *get_width(char *s, format_options_t *options, va_list args)
{
	if (*s == '*')
	{
		options->field_width = va_arg(args, int);
		return (s + 1);
	}
	else
	{
		options->field_width = strtol(s, &s, 10);
		return (s);
	}
}

/**
 * get_flag - extracts flags from the format string
 * @s: format string
 * @options: format options structure
 *
 * Return: 1 if a flag is found, 0 otherwise
 */
int get_flag(char *s, format_options_t *options)
{
	int flag = 0;

	while (*s == '+' || *s == ' ' || *s == '#' || *s == '0' || *s == '-')
	{
		switch (*s)
		{
			case '+':
				options->use_plus_flag = 1;
				break;
			case ' ':
				options->use_space_flag = 1;
				break;
			case '#':
				options->use_hashtag_flag = 1;
				break;
			case '0':
				options->use_zero_flag = 1;
				break;
			case '-':
				options->use_minus_flag = 1;
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
 * @options: format options structure
 *
 * Return: 1 if a modifier is found, 0 otherwise
 */
int get_modifier(char *s, format_options_t *options)
{
	if (*s == 'h')
	{
		options->use_h_modifier = 1;
		if (*(s + 1) == 'h')
		{
			options->use_h_modifier = 2;
			return (1);
		}
	}
	else if (*s == 'l')
	{
		options->use_l_modifier = 1;
		if (*(s + 1) == 'l')
		{
			options->use_l_modifier = 2;
			return (1);
		}
	}
	return (0);
}

/**
 * get_precision_field - extracts precision field from the format string
 * @p: format string
 * @options: format options structure
 * @args: variable argument list
 *
 * Return: pointer to the next position in the format string
 */
char *get_precision_field(char *p, format_options_t *options, va_list args)
{
	if (*p == '.')
	{
		p++;
		if (*p == '*')
		{
			options->precision = va_arg(args, int);
			return (p + 1);
		}
		else
		{
			options->precision = strtol(p, &p, 10);
			return (p);
		}
	}
	return (p);
}
