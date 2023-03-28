#include "main.h"
#include "stdarg.h"
#include "_putchar"
#include "_strlen"
void spec_c(int arg)
{
	_putchar(arg);
}

void spec_s(char *arg)
{
	int i;
	for (i = 0; i < _strlen(arg); i++)
	{
		_putchar(arg[i]);
	}
}
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
	int c;
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
			i = i + 1;
		}
	}
	va_end(ap);
	return (0);
}
