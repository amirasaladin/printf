#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - prints a string in a formatted way
 * @format: string to print (char *)
 * @...: variadic parameters (unknown)
 *
 * Return: number of characters printed
 */


int _printf(const char *format, ...)
{
	int (*func)(va_list);
	va_list arg;
	int len = 0;

	va_start(arg, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			func = check_spec(format);

			if (func == NULL)
			{
				char c = *format;

				write(1, &c, 1);
				len++;
			}
			else
			{
				len = len + func(arg);
			}
		}
		else
		{
			char c = *format;

			write(1, &c, 1);
			len++;
		}

		format++;
	}

	va_end(arg);
	return (len);
}
