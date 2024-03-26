#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints the string to the command line
 * @format: character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	/* op ops[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent}
	}; */
	va_list args;
	int i = 0, count = 0, is_args = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += 1;
			if (format[i] == 'c')
			{
				va_start(args, format);
				is_args = 1;
				count += print_char(&args);
			}
			else if (format[i] == 's')
			{
				va_start(args, format);
				is_args = 1;
				count += print_string(&args);
			}
			else if (format[i] == '%')
			{
				va_start(args, format);
				is_args = 1;
				count += print_percent(&args);
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				count += 2;
			}
			i += 1;
		}
		else
		{
			putchar(format[i]);
			count += 1;
			i += 1;
		}
	}

	if (is_args)
		va_end(args);

	return (count);
}
