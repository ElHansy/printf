#ifndef _MY_PRINTF_H
#define _MY_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define NULL_STRING "(null)"
#define DEFAULT_FORMAT_OPTIONS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

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
	unsigned int is_unsigned;
	unsigned int use_plus_flag;
	unsigned int use_space_flag;
	unsigned int use_hashtag_flag;
	unsigned int use_zero_flag;
	unsigned int use_minus_flag;
	unsigned int field_width;
	unsigned int precision;
	unsigned int use_h_modifier;
	unsigned int use_l_modifier;
} format_options_t;

/**
 * struct format_specifier - Structure representing a format specifier
 * @specifier: Format token
 * @function: Associated function
 */
typedef struct format_specifier
{
	char *specifier;
	int (*function)(va_list args, format_options_t *);
} format_specifier_t;

/* Supportive_Functions Prototypes */
void initialize_options(format_options_t *options, va_list args);
char *get_width(char *s, format_options_t *options, va_list args);
int get_flag(char *s, format_options_t *options);
int get_modifier(char *s, format_options_t *options);
char *get_precision_field(char *p, format_options_t *options, va_list args);
int is_digit(int c);
int string_length(char *s);
char *convert_to_string(long int num, int base, int flags,
		format_options_t *options);
int (*get_format_specifier(char *s))(va_list args, format_options_t *options);
int get_print_function(char *s, va_list args, format_options_t *options);

/* Printing_Functions Prototypes */
int _printf(const char *format, ...);
int print_char(va_list args, format_options_t *options);
int print_integer(va_list args, format_options_t *options);
int print_unsigned_integer(va_list args, format_options_t *options);
int print_memory_address(va_list args, format_options_t *options);
int print_hexadecimal(va_list args, format_options_t *options);
int print_HEXadecimal(va_list args, format_options_t *options);
int print_binary_number(va_list args, format_options_t *options);
int print_octal_number(va_list args, format_options_t *options);
int print_text(va_list args, format_options_t *options);
int print_percent(va_list args, format_options_t *options);
int print_custom_string(va_list args, format_options_t *options);
int put_string(char *str);
int put_char(int c);
int print_range(char *start, char *stop, char *except);
int print_reversed(va_list args, format_options_t *options);
int print_rot13_encoded(va_list args, format_options_t *options);
int print_formatted_number(char *str, format_options_t *options);
int print_right_shifted_number(char *str, format_options_t *options);
int print_left_shifted_number(char *str, format_options_t *options);

#endif

