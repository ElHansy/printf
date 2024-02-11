/* Additional Printing Functions */

/**
 * print_char - Print a character
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_char(va_list args, format_options_t *options) {
    int c = va_arg(args, int);
    return put_char(c);
}

/**
 * print_integer - Print a signed integer
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args, format_options_t *options) {
    int num = va_arg(args, int);
    char *str = convert_to_string(num, 10, 0, options);
    return print_formatted_number(str, options);
}

/**
 * print_unsigned_integer - Print an unsigned integer
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_unsigned_integer(va_list args, format_options_t *options) {
    unsigned int num = va_arg(args, unsigned int);
    char *str = convert_to_string(num, 10, CONVERT_UNSIGNED, options);
    return print_formatted_number(str, options);
}

/**
 * print_memory_address - Print a memory address
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_memory_address(va_list args, format_options_t *options) {
    void *ptr = va_arg(args, void *);
    char *str = convert_to_string((long int)ptr, 16, 0, options);
    return print_formatted_number(str, options);
}

/**
 * print_hexadecimal - Print a lowercase hexadecimal number
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list args, format_options_t *options) {
    unsigned int num = va_arg(args, unsigned int);
    char *str = convert_to_string(num, 16, CONVERT_LOWERCASE, options);
    return print_formatted_number(str, options);
}

/**
 * print_HEXadecimal - Print an uppercase hexadecimal number
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_HEXadecimal(va_list args, format_options_t *options) {
    unsigned int num = va_arg(args, unsigned int);
    char *str = convert_to_string(num, 16, 0, options);
    return print_formatted_number(str, options);
}

/**
 * print_binary_number - Print a binary number
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_binary_number(va_list args, format_options_t *options) {
    unsigned int num = va_arg(args, unsigned int);
    char *str = convert_to_string(num, 2, 0, options);
    return print_formatted_number(str, options);
}

/**
 * print_octal_number - Print an octal number
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_octal_number(va_list args, format_options_t *options) {
    unsigned int num = va_arg(args, unsigned int);
    char *str = convert_to_string(num, 8, 0, options);
    return print_formatted_number(str, options);
}

/**
 * print_text - Print a string of characters
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_text(va_list args, format_options_t *options) {
    char *str = va_arg(args, char *);
    return put_string(str);
}

/**
 * print_percent - Print a percent character
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_percent(va_list args, format_options_t *options) {
    return put_char('%');
}

/**
 * print_custom_string - Print a custom string
 * @args: Argument list
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_custom_string(va_list args, format_options_t *options) {
    char *str = va_arg(args, char *);
    return put_string(str);
}

/* Helper functions */

/**
 * put_string - Output a string to stdout
 * @str: String to be printed
 *
 * Return: Number of characters printed
 */
int put_string(char *str) {
    int length = 0;
    while (*str != '\0') {
        put_char(*str);
        str++;
        length++;
    }
    return length;
}

/**
 * put_char - Output a character to stdout
 * @c: Character to be printed
 *
 * Return: Number of characters printed (1)
 */
int put_char(int c) {
    putchar(c);
    return 1;
}

/**
 * print_range - Print a range of characters excluding some
 * @start: Start of the range
 * @stop: End of the range
 * @except: Characters to be excluded
 *
 * Return: Number of characters printed
 */
int print_range(char *start, char *stop, char *except) {
    int length = 0;
    while (start < stop) {
        if (except == NULL || strchr(except, *start) == NULL) {
            put_char(*start);
            length++;
        }
        start++;
    }
    return length;
}

/**
 * print_formatted_number - Print a formatted number
 * @str: Number string
 * @options: Format options
 *
 * Return: Number of characters printed
 */
int print_formatted_number(char *str, format_options_t *options) {
    int length = 0;
    if (options->use_minus_flag) {
        length += put_string(str);
        length += print_range(str, str + options->field_width - string_length(str), NULL);
    } else {
        length += print_range(str, str + options->field_width - string_length(str), NULL);
        length += put_string(str);
    }
    return length;
}

/**
 * string_length - Calculate the length of a string
 * @s: String
 *
 * Return: Length of the string
 */
int string_length(char *s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}
