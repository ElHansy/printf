#include <main.h>

/**
 * print_reversed - Print a reversed string
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_reversed(va_list args, format_options_t *options) {
    char *str = va_arg(args, char *);
    int length = 0;
    int str_len = string_length(str);

    if (options->use_minus_flag) {
        length += put_string(str);
        length += print_range(str, str - options->field_width + str_len, NULL);
    } else {
        length += print_range(str, str - options->field_width + str_len, NULL);
        length += put_string(str);
    }

    return length;
}

/**
 * print_rot13_encoded - Print a ROT13 encoded string
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_rot13_encoded(va_list args, format_options_t *options) {
    char *str = va_arg(args, char *);
    int length = 0;

    while (*str) {
        if (isalpha(*str)) {
            char base = isupper(*str) ? 'A' : 'a';
            put_char(((*str - base + 13) % 26) + base);
            length++;
        } else {
            put_char(*str);
            length++;
        }
        str++;
    }

    return length;
}

/**
 * print_right_shifted_number - Print a right-shifted number
 * @str: Number string
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_right_shifted_number(char *str, format_options_t *options) {
    int length = 0;
    int str_len = string_length(str);

    if (options->use_minus_flag) {
        length += put_string(str);
        length += print_range(str, str - options->field_width + str_len, NULL);
    } else {
        length += print_range(str, str - options->field_width + str_len, NULL);
        length += put_string(str);
    }

    return length;
}

/**
 * print_left_shifted_number - Print a left-shifted number
 * @str: Number string
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_left_shifted_number(char *str, format_options_t *options) {
    int length = 0;
    int str_len = string_length(str);

    if (options->use_minus_flag) {
        length += put_string(str);
        length += print_range(str, str + options->field_width - str_len, NULL);
    } else {
        length += print_range(str, str + options->field_width - str_len, NULL);
        length += put_string(str);
    }

    return length;
}
