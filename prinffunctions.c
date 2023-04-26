#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - prints a character
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	int ch = va_arg(args, int);

	return (_putchar(ch));
}

/**
* print_string - prints a string
* @args: list of arguments
* Return: number of characters printed
*/
int print_string(va_list args)
{
	int i, count = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
		 count++;
	}

	return (count);
}

/**
* print_percent - prints a percent character
* @args: list of arguments
* Return: number of characters printed
*/
int print_percent(va_list args)
{
	(void)args;

	return (_putchar('%'));
}

/**
* print_int - prints an integer
* @args: list of arguments
* Return: number of characters printed
*/
int print_int(va_list args)
{
	unsigned int abs_val, aux, count_num, count = 0;
	int n = va_arg(args, int);

	if (n < 0)
	{
		abs_val = (n * -1);
		count += _putchar('-');
	}
	else
	{
		abs_val = n;
	}
	aux = abs_val;
	count_num = 1;
	while (aux > 9)
	{
		aux /= 10;
		count_num *= 10;
	}
	while (count_num >= 1)
	{
		count += _putchar(((abs_val / count_num) % 10) + '0');
		count_num /= 10;
	}
	return (count);
}

/**
* print_unsign - prints an unsigned integer
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_unsign(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int countu = 0;

	if (num == 0)
	{
		countu += _putchar('0');
		return (countu);
	}

	if (num / 10)
	{
		countu += print_unsign(args);
	}
	countu += _putchar((num % 10) + '0');
	return (countu);
}
