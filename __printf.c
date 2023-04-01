#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "__main.h"

/**
 * print_char - prints a character to stdout
 * @arg: variadic parameter
 *
 * Return: number of characters printed
 */

int print_char(va_list arg)
{
	char c = va_arg(arg, int);
	write(1, &c,1);
	return (1);
}

/**
 * print_str - prints a variadic string each per time to stdout
 * @arg: variadic parameter
 *
 * Return: number of characters printed on Success
 * upon failure -1
 */

int print_str(va_list arg)
{
	char *s = va_arg(arg, char *);
	int len = 0;

	if (s == NULL)
	{
		return (-1);
	}else{
		while (*s != '\0')
		{
			write(1, s, 1);
			s++;
			len++;
		}
	}
	return (len);
}

/**
 * print_pcent - prints character % to stdout
 * @arg: variadic parameter
 *
 * Return: number of characters printed
 */

int print_pcent(va_list arg)
{
	char c;
	(void)arg;
	c = '%';
	write(1, &c, 1);
	return (1);
}

/**
 * print_int - prints a given integer from variadic parameters
 * @arg: variadic parameter
 *
 * Return: number of characters printed on Success
 */

int print_int(va_list arg)
{
	int n = va_arg(arg, int);
	int len = 0;
	int ary[10];
	int i, j;

	if (n == 0)
	{
		char c = '0';
		write(1, &c, 1);
		len++;
	}
	if (n < 0)
	{
		char c = '-';
		write(1, &c, 1);
		n = -n;
		len++;
	}
	if (n > 0)
	{
		for (i = 0; n > 0; i++)
		{
			ary[i] = n % 10;
			n = n / 10;
		}
		for (j = i - 1; j >= 0; j--)
		{
			char c = ary[j] + '0';
			write(1, &c, 1);
			len++;
		}
	}

	return (len);
}

/**
 * print_dec - prints a given integer from variadic parameters to base 10
 * @arg: variadic parameter
 *
 * Return: number of characters printed on Success
 */

int print_dec(va_list arg)
{
	return (print_int(arg));
}

/**
 * check_spec - check that character is a valid specifier and
 * assigns an appropriate fucntion for its printing.
 * @format: the specifier (char*)
 *
 * Return: function specified for operation 
 * NULL to negate the int of the function being defined
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
		return (print_dec);
	}

	return (NULL);
}

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
			write (1, &c, 1);
			len ++;
		}

		format++;
	}

	va_end(arg);
	return (len);
}
