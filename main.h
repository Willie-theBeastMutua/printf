#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_unsign(va_list args);
int (*getfunction(char c))(va_list);

typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec;

#endif
