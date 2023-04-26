#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed, or -1 on failure
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	for (; *format; format++)
		if (*format == '%')
		{
			if (*++format == '%')
				char_count += _putchar('%');
			else if (!*format)
			{
				va_end(args);
				return (-1);
			}
			else if (*format == 'c')
				char_count += _putchar(va_arg(args, int));
			else if (*format == 's')
			{
				char *str_arg = va_arg(args, char *);

				if (!str_arg)
					str_arg = "(null)";
				for (; *str_arg; str_arg++)
					char_count += _putchar(*str_arg);
			}
			else
			{
				char_count += _putchar('%');
				char_count += _putchar(*format);
			}
		}
		else
			char_count += _putchar(*format);
	va_end(args);
	return (char_count);
}

