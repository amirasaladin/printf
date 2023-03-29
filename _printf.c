#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>
/**
 * _putchar - prints characters
 * _printf - prints a string in a formatted way
 * @format: string to print (char *)
 * @...: variadic parameters (unknown)
 *
 * Return: number of characters printed
 */

int _putchar(char c)
{
   return write(1, &c, 1);

}

int _printf(const char *format, ...)
{
  int i, divisor, digits, digit;
  int printed_chars = 0;
  va_list arg_list;
  va_start(arg_list, format);
/*whie liip*/
  while (*format)
  {
    if (*format == '%')
    {
      format++;
      if (*format == 'd' || *format == 'i')
      {
        int value = va_arg(arg_list, int);
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
      else
      {
        _putchar('%');
        _putchar(*format);
        printed_chars += 2;
      }
    }
    else
    {
      _putchar(*format);
      printed_chars++;
    }
    format++;
  }

  va_end(arg_list);
  return printed_chars;
}
