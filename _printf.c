#include "main.h"
#include <stdio.h>

/**
 * _printf - prints the string to the command line
 * @format: character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;

	while (format[i] != NULL)
	{
		if (format[i] == '%')
		{
		}
		else
		{
			putchar(format[i]);
			count += 1;
			i += 1;
		}
	}
	return (count);
}
