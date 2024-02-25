#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUT_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define NULL_STRING "(null)"
#define OPT_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONV_LOWER 1
#define CONV_UNSIGN 2

/**
 * struct fmt_opt - Format options
 * @u: Unsigned flag
 * @plus: Plus
 * @space: Space
 * @hash: Hashtag
 * @zero: Zero
 * @minus: Minus
 *
 * @w: Width
 * @preci: Precision
 *
 * @H: H modifier
 * @L: L modifier
 *
 */

typedef struct fmt_opt
{
	unsigned int u:     1;

	unsigned int plus:  1;
	unsigned int space: 1;
	unsigned int hash:  1;
	unsigned int zero:  1;
	unsigned int minus: 1;

	unsigned int w;
	unsigned int preci;

	unsigned int H:     1;
	unsigned int L:     1;
} fmt_opt_t;

/**
 *struct Speci - Format specifier
 *@s: Format token
 *@f: Associated function
 */

typedef struct Speci
{
	char *s;
	int (*f)(va_list, fmt_opt_t *);
} Speci;

/* basic_functions.c module */
int c_puts(char *str);
int c_putchar(int c);
int isDigit(int c);
int STRlen(char *s);

/*printing_options_1.c module */
int _printing_char(va_list args, fmt_opt_t *opt);
int _printing_int(va_list args, fmt_opt_t *opt);
int _printing_string(va_list args, fmt_opt_t *opt);
int _printing_pcent(va_list args, fmt_opt_t *opt);
int _printing_FMTspeci(va_list args, fmt_opt_t *opt);

/*printing_options_2.c module */
int _printing_range(char *start, char *stop, char *except);
int _printing_r(va_list args, fmt_opt_t *opt);
int _printing_R(va_list args, fmt_opt_t *opt);
int _printing_addr(va_list args, fmt_opt_t *opt);

/*format_string_options.c module */
int get_print_func(char *s, va_list args, fmt_opt_t *opt);
int get_f(char *s, fmt_opt_t *opt);
int get_m(char *s, fmt_opt_t *opt);
char *get_w(char *s, fmt_opt_t *opt, va_list args);
char *get_preci(char *p, fmt_opt_t *opt, va_list args);

/*num_print_options_1.c module */
int _printing_unsign(va_list args, fmt_opt_t *opt);
int _printing_hex(va_list args, fmt_opt_t *opt);
int _printing_HEX(va_list args, fmt_opt_t *opt);
int _printing_bin(va_list args, fmt_opt_t *opt);
int _printing_oct(va_list args, fmt_opt_t *opt);

/*num_print_options_2.c module */
char *conv(long int n, int base, int flags, fmt_opt_t *opt);
int _printing_num(char *str, fmt_opt_t *opt);
int _printing_num_Rshift(char *str, fmt_opt_t *opt);
int _printing_num_Lshift(char *str, fmt_opt_t *opt);

/*struct_options.c module */
void init_opt(fmt_opt_t *opt, va_list args);

/*specifier.c modoule */
int(*get_speci(char *s))(va_list args, fmt_opt_t *opt);

/*_printf.c module */
int _printf(const char *format, ...);

#endif
