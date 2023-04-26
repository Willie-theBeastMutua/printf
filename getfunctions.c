#include "main.h"

/**
 *getfunction - look for the specifier
 *@c: variable to the function
 *
 *Return: function
 */
int (*getfunction(char c))(va_list)
{
	int j = 0;
	spec arr[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_unsign},
		{NULL, NULL}
	};
	while (arr[j].valid)
	{
		if (c == arr[j].valid[0])
			return (arr[j].f);
		j++;
	}
	return (NULL);
}

