#include "main.h"

/**
 * print_char - prints a character to stdout
 * @arg: variadic parameter
 *
 * Return: number of characters printed
 */

int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
	return (1);
}

