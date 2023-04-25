#include "main.h"
#include <stdarg.h>

/**
 * _printf - print formatted output to stdout
 * @format: format string containing conversion specifiers
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	char *str;
	char c;
	int i, count;

	count = 0;
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str != '\0')
					{
						_putchar(*str);
						count++;
						str++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					count++;
					_putchar(format[i]);
					count++;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
