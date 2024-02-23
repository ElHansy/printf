#include "main.h"

/**
 * init_opt - clear struct options and reset buffer
 * @opt: the parameters options
 * @args: the argument pointer
 * Return: void
 */

void init_opt(fmt_opt_t *opt, va_list args)
{
	opt->u = 0;

	opt->plus = 0;
	opt->space = 0;
	opt->hash = 0;
	opt->zero = 0;
	opt->minus = 0;

	opt->w = 0;
	opt->preci = UINT_MAX;

	opt->H = 0;
	opt->L = 0;
	(void)args;
}
