#include "main.h"
/**
 * spec_d_i - print d, print i
 * @value: argument
 * Return: void
 */

void spec_d_i(int value)
{
	int i, divisor, digits, digit;
	int printed_chars = 0;

        if (value < 0)
        {
          _putchar('-');
          printed_chars++;
          value = -value;
        }
        divisor = 1;
        digits = 1;
        while (value / divisor >= 10)
        {
          divisor *= 10;
          digits++;
        }
        for (i = 0; i < digits; i++)
        {
          digit = value / divisor;
          _putchar('0' + digit);
          printed_chars++;
          value %= divisor;
          divisor /= 10;
        }
}
