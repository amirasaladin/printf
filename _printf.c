#include "main.h"
#include <stdarg.h>
/**
 * _printf - function similar to C printf
 * @format: is a character string. The format string is composed
 * of zero or more directives.
 * Return: int.
*/

int _printf(const char *format, ...)
{
	int i;
	va_list ap;
	int c;/*stuff*/
	char spec;

	va_start(ap, format);
	for (i = 0; i < _strlen(format); i++)
	{
		c = format[i];
		if (c != '%')
		{
			_putchar(format[i]);
		}
		else
		{
			spec = format[i + 1];
			if (spec == 'c')
				spec_c(va_arg(ap, int));
			else if (spec == 's')
				spec_s(va_arg(ap, char *));
			else if (spec == 'd' || spec == 'i')
				spec_d_i(va_arg(ap, int));
			i = i + 1;
		}
	}
	va_end(ap);
	return (0);
}
