#include "main.h"
#include <stdio.h>


/**
 * _printf - Prints a formatted string to stdout
 * @format: A string containing zero or more format specifiers
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;

	va_start(args, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					i++;
					break;
				case 's':
					{
					char *str = va_arg(args, char *);
					int j;

					if (str == NULL)
					{
						str = "(null)";
					}
					for (j = 0; str[j] != '\0'; j++)
					{
						_putchar(str[j]);
						count++;
					}
					i++;
					break;
					}
				case '%':
					_putchar('%');
					count++;
					i++;
					break;
				default:
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
