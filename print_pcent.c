#include "main.h"

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
