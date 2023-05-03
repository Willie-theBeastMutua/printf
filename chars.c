#include "main.h"
#include <stdlib.h>

/**
 * print_c - prints a char
 * @c: char to print
 *
 * Return: always 1
 */
int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	return (_putchar(ch));
}

/**
 * print_s - prints a string
 * @s: string to print
 *
 * Return: number of chars printed
 */
int print_s(va_list s)
{
	int count = 0;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		count += _putchar(*str++);
	}
	return (count);
}

/**
 * hex_print - prints a char's ascii value in uppercase hex
 * @c: char to print
 *
 * Return: number of chars printed (always 2)
 */
int hex_print(char c)
{
	int count = 0;
	char diff = 'A' - ':';
	char d[2];
	int i;

	d[0] = c / 16;
	d[1] = c % 16;
	for (i = 0; i < 2; i++)
	{
		if (d[i] >= 10)
			count += _putchar('0' + diff + d[i]);
		else
			count += _putchar('0' + d[i]);
	}
	return (count);
}

/**
 * print_S - prints a string and nonprintable character ascii values
 * @S: string to print
 *
 * Return: number of chars printed
 */
int print_S(va_list S)
{
	int count = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += hex_print(*str++);
		}
		else
		{
			count += _putchar(*str++);
		}
	}
	return (count);
}

/**
 * print_r - prints astring in reverse
 * @r: string to print
 *
 * Return: number of chars printed
 */
int print_r(va_list r)
{
	char *str;
	int count = 0;
	int i;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		count++;
	for (i = count - 1; i >= 0; i--)
		count += _putchar(str[i]);
	return (count);
}
