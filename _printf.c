#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that produces output according to a format.
 * @format: format of argument
 *
 *  Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	int char_count = 0;
	char ch;

	va_start(arg_list, format);
	while ((ch = *format++) != '\0')
	{
		if (ch == '%')
		{
			switch (*format++)
			{
				case 'c':
					putchar(va_arg(arg_list, int));
					char_count++;
					break;
				case 's':
					char_count += printf(va_arg(arg_list, char*));
					break;
				case '%':
					putchar('%');
					char_count++;
					break;
				default:
					break;
			}
		}
		else
		{
			putchar(ch);
			char_count++;
		}
	}
	va_end(arg_list);
	return (char_count);
}
