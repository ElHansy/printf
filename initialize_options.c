#include <main.h>

/**
 * initialize_options - Clears structure fields and resets buffer.
 * @options: The format options structure.
 * @args: The variable argument list.
 *
 * Return: void.
 */
void initialize_options(format_options_t *options, va_list args)
{
	options->is_unsigned int = 0;
	options->use_plus_flag = 0;
	options->use_space_flag = 0;
	options->use_hashtag_flag = 0;
	options->use_zero_flag = 0;
	options->use_minus_flag = 0;
	options->field_width = 0;
	options->precision = UINT_MAX;
	options->use_h_modifier = 0;
	options->use_l_modifier = 0;
	(void)args;
}

