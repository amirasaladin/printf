#include "main.h"

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
