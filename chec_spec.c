#include "main.h"

/**
 * check_spec - check that character is a valid specifier and
 * assigns an appropriate fucntion for its printing.
 * @format: the specifier (char*)
 *
 * Return: function specified for operation
 * NULL if no specifier found
 */

int (*check_spec(const char *format))(va_list)
{
	if (*format == 'c')
	{
		return (print_char);
	}
	if (*format == 's')
	{
		return (print_str);
	}
	if (*format == '%')
	{
		return (print_pcent);
	}
	if (*format == 'i')
	{
		return (print_int);
	}
	if (*format == 'd')
	{
		return (print_deci);
	}

	return (NULL);
}
