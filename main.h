#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/**
 * struct format_options - Structure to store format options
 * @is_unsigned: Flag indicating if the value is unsigned
 * @use_plus_flag: Flag to specify the plus_flag
 * @use_space_flag: Flag to specify the space_flag
 * @use_hashtag_flag: Flag to specify the hashtag_flag
 * @use_zero_flag: Flag to specify the zero_flag
 * @use_minus_flag: Flag to specify the minus_flag
 * @field_width: Field width specified
 * @precision: Field precision specified
 * @use_h_modifier: Flag to specify the h_modifier
 * @use_l_modifier: Flag to specify the l_modifier
 */

typedef struct format_options
{
	unsigned int is_unsigned	: 1;
	unsigned int use_plus_flag	: 1;
	unsigned int use_space_flag	: 1;
	unsigned int use_hashtag_flag	: 1;
	unsigned int use_zero_flag	: 1;
	unsigned int use_minus_flag	: 1;
	unsigned int field_width;
	unsigned int precision;
	unsigned int use_h_modifier	: 1;
	unsigned int use_l_modifier	: 1;
} format_options_t;

#define DEFAULT_FORMAT_OPTIONS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define OUTPUT_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

#define NULL_STRING "(null)"
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2


/**
 * struct format_specifier - Structure representing a format specifier
 * @specifier: Format token
 * @function: Associated function
 */

typedef struct format_specifier
{
	char *specifier;
	int (*function)(va_list my_args, format_options_t *);
} format_specifier_t;


/* Supportive_Functions Prototypes */
void init_opt(params_t *pars, va_list my_args);
char *num2str(long int num, int base, int flags, format_options_t *options);
int is_digit(int c);
int str_len(char *s);

int get_print_func(char *s, va_list my_args, format_options_t *options);
int (*get_speci(char *s))(va_list my_args, format_options_t *options);
int get_f(char *s, format_options_t *options);
int get_m(char *s, format_options_t *options);
char *get_w(char *s, format_options_t *options, va_list my_args);
char *get_prec(char *p, params_t *params, va_list my_args);

/* Printing_Functions Prototypes */
int _printf(const char *format, ...);
int print_char(va_list my_args, format_options_t *options);
int print_custom_string(va_list my_args, format_options_t *options);
int print_integer(va_list my_args, format_options_t *options);
int print_unsigned_integer(va_list my_args, format_options_t *options);
int print_memory_address(va_list my_args, format_options_t *options);
int print_hexadecimal(va_list my_args, format_options_t *options);
int print_HEXadecimal(va_list my_args, format_options_t *options);
int print_binary_number(va_list my_args, format_options_t *options);
int print_octal_number(va_list my_args, format_options_t *options);
int print_text(va_list my_args, format_options_t *options);
int print_percent(va_list my_args, format_options_t *options);

int put_string(char *str);
int put_char(int c);

int print_range(char *start, char *stop, char *except);
int print_reversed(va_list my_args, format_options_t *options);
int print_rot13_encoded(va_list my_args, format_options_t *options);
int print_formatted_number(char *str, format_options_t *options);
int print_right_shifted_number(char *str, format_options_t *options);
int print_left_shifted_number(char *str, format_options_t *options);

#endif

