#include "main.h"

/**
 * print_number - prints a number
 * @n: number to print
 * @base: base to use for printing
 * @digits: number of digits to print
 * @is_signed: indicates whether the number is signed or unsigned
 * @pad_char: character to use for padding
 *
 * Return: number of chars and digits printed
 */
static int print_number(unsigned int n, int base, int digits,
		int is_signed, char pad_char)
{
	int a[10];
	int j, m, sum, count;

	count = 0;
	if (is_signed && (int)n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	m = 1;
	for (j = 0; j < digits - 1; j++)
		m *= base;
	for (j = 0; j < digits; j++)
	{
		a[j] = n / m;
		n = n % m;
		m /= base;
	}
	for (j = 0, sum = 0; j < digits; j++)
	{
		sum += a[j];
		if (sum != 0 || j == digits - 1)
		{
			_putchar('0' + a[j]);
			count++;
		}
		else
		{
			_putchar(pad_char);
			count++;
		}
	}
	return (count);
}

/**
 * print_i - prints an integer
 * @i: integer to print
 *
 * Return: number of chars and digits printed
 */
int print_i(va_list i)
{
	int n = va_arg(i, int);

	return (print_number((unsigned int)n, 10, 10, 1, '0'));
}

/**
 * print_d - prints a decimal
 * @d: decimal to print
 *
 * Return: number of chars and digits printed
 */
int print_d(va_list d)
{
	int n = va_arg(d, int);

	return (print_number((unsigned int)n, 10, 10, 1, '0'));
}
