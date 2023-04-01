#ifndef MAIN_H
#define MAIN_H
int print_char(va_list arg);
int print_str(va_list arg);
int print_cent(va_list arg);
int print_int(va_list arg);
int print_dec(va_list arg);
int (*check_specifier(const char *format))(va_list);
int my_printf(const char *format, ...);
#endif
