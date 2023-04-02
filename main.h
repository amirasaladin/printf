#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int (*check_spec(const char *format))(va_list);
int _printf(const char *format, ...);
int print_char(va_list);
int print_str(va_list);
int print_pcent(va_list);
int print_int(va_list);
int print_deci(va_list);

#endif
