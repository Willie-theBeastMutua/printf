#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * print_R - prints a string in rot13
 * @ap: va_list containing a single argument of type char*
 *
 * Return: number of chars printed
 */
int print_R(va_list ap)
{
	char *str = va_arg(ap, char*);
	int count;
	char *found;

	if (str == NULL)
		str = "(ahyy)";

	count = 0;

	for (; *str; ++str)
	{
		char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
		found = strchr(in, *str);

		if (found != NULL)
		{
			char rot = out[found - in];

			_putchar(rot);
			count++;
		}
		else
		{
			_putchar(*str);
			count++;
		}
	}

	return (count);
}
