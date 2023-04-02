#include "main.h"

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
	}

		while (*s != '\0')
		{
			write(1, s, 1);
			s++;
			len++;
		}

	return (len);
}
